#ifndef M7MATH_AFFINE2D_HH
#define M7MATH_AFFINE2D_HH

#include <m7/math/types.hh>

namespace m7 {
namespace math {

template <typename T>
  void make_identity(affine2d<T>& a) {
    a.rs[1] = a.rs[2] = 0;
    a.rs[0] = a.rs[3] = 1;
    a.t[0] = a.t[1] = 0;
  }

template <typename T>
  inline T trace(const affine2d<T>& a) {
    return a.rs[0] + a.rs[3] + 1;
  }

template <typename T>
  inline T det(const affine2d<T>& a) {
    return a.rs[0] * a.rs[3] - a.rs[2] * a.rs[1];
  }

template <typename T>
  mat3<T> to_matrix(const affine2d<T>& a) {
    mat3<T> ret;
    ret[0] = a.rs[0];
    ret[1] = a.rs[1];
    ret[2] = 0;

    ret[3] = a.rs[2];
    ret[4] = a.rs[3];
    ret[5] = 0;

    ret[6] = a.t[0];
    ret[7] = a.t[1];
    ret[8] = 1;
    return ret;
  }

template <typename T>
  mat3<T> to_matrix_transpose(const affine2d<T>& a) {
    mat3<T> ret;
    ret[0] = a.rs[0];
    ret[3] = a.rs[1];
    ret[6] = 0;

    ret[1] = a.rs[2];
    ret[4] = a.rs[3];
    ret[7] = 0;

    ret[2] = a.t[0];
    ret[5] = a.t[1];
    ret[8] = 1;
    return ret;
  }

template <typename T>
  affine2d<T> inverse(const affine2d<T>& a) {
    affine2d<T> ret;
    ret.rs[0] = a.rs[3];
    ret.rs[1] = -a.rs[1];
    ret.rs[2] = -a.rs[2];
    ret.rs[3] = a.rs[0];
    ret.t[0] = a.t[1] * a.rs[2] - a.rs[3] * a.t[0];
    ret.t[1] = a.rs[1] * a.t[0] - a.t[1] * a.rs[0];

    T d = det(a);
    ret.rs[0] /= d;
    ret.rs[1] /= d;
    ret.rs[2] /= d;
    ret.rs[3] /= d;
    ret.t[0] /= d;
    ret.t[1] /= d;
    return ret;
  }

template <typename T>
  void inverse_eq(affine2d<T>& a) {
    T t = a.t[0];

    a.t[0] = a.t[1] * a.rs[2] - a.rs[3] * t;
    a.t[1] = a.rs[1] * t - a.t[1] * a.rs[0];

    t = a.rs[0];
    a.rs[0] = a.rs[3];
    a.rs[1] = -a.rs[1];
    a.rs[2] = -a.rs[2];
    a.rs[3] = t;

    T d = det(a);
    a.rs[0] /= d;
    a.rs[1] /= d;
    a.rs[2] /= d;
    a.rs[3] /= d;
    a.t[0] /= d;
    a.t[1] /= d;
  }

template <typename T>
  void l_mult_eq(affine2d<T>& M7_RESTRICT a, affine2d<T>& M7_RESTRICT l) {
    m7assert(&l != &a);
    T ta = a.rs[0];

    a.rs[0] = l.rs[0] * ta + l.rs[2] * a.rs[1];
    a.rs[1] = l.rs[1] * ta + l.rs[3] * a.rs[1];

    ta = a.rs[2];
    a.rs[2] = l.rs[0] * ta + l.rs[2] * a.rs[3];
    a.rs[3] = l.rs[1] * ta + l.rs[3] * a.rs[3];

    ta = a.t[0];
    a.t[0] = l.rs[0] * ta + l.rs[2] * a.t[1] + l.t[0];
    a.t[1] = l.rs[1] * ta + l.rs[3] * a.t[1] + l.t[1];
  }

template <typename T>
  void r_mult_eq(affine2d<T>& M7_RESTRICT a, affine2d<T>& M7_RESTRICT r) {
    m7assert(&r != &a);
    a.t[0] = a.rs[0] * r.t[0] + a.rs[2] * r.t[1] + a.t[0];
    a.t[1] = a.rs[1] * r.t[0] + a.rs[3] * r.t[1] + a.t[1];

    T ta = a.rs[0];
    a.rs[0] = ta * r.t[0] + a.rs[2] * r.rs[1];
    a.rs[2] = ta * r.t[2] + a.rs[2] * r.rs[3];

    ta = a.rs[1];
    a.rs[1] = ta * r.t[0] + a.rs[3] * r.rs[1];
    a.rs[3] = ta * r.t[2] + a.rs[3] * r.rs[3];
  }

template <typename T>
  affine2d<T> mult(const affine2d<T>& l, const affine2d<T>& r) {
    affine2d<T> d;
    d.rs[0] = l.rs[0] * r.rs[0] + l.rs[2] * r.rs[1];
    d.rs[1] = l.rs[1] * r.rs[0] + l.rs[3] * r.rs[1];

    d.rs[2] = l.rs[0] * r.rs[2] + l.rs[2] * r.rs[3];
    d.rs[3] = l.rs[1] * r.rs[2] + l.rs[3] * r.rs[3];

    d.t[0] = l.rs[0] * r.t[0] + l.rs[2] * r.t[1] + l.t[0];
    d.t[1] = l.rs[1] * r.t[0] + l.rs[3] * r.t[1] + l.t[1];

    return d;
  }

template <typename T>
  inline affine2d<T> operator*(const affine2d<T>& l, const affine2d<T>& r) {
    return mult(l, r);
  }

template <typename T>
  vec2<T> mult(const affine2d<T>& l, const vec2<T>& r) {
    vec2<T> d;
    d[0] = l.rs[0] * r[0] + l.rs[2] * r[1] + l.t[0];
    d[1] = l.rs[1] * r[0] + l.rs[3] * r[1] + l.t[1];
    return d;
  }

template <typename T>
  inline vec2<T> operator*(const affine2d<T>& l, const vec2<T>& r) {
    return mult(l, r);
  }

template <typename T>
  void l_mult_eq(vec2<T>& v, const affine2d<T>& l) {
    T ta = v[0];
    v[0] = l.rs[0] * ta + l.rs[2] * v[1] + l.t[0];
    v[1] = l.rs[1] * ta + l.rs[3] * v[1] + l.t[1];
  }

template <typename T>
  mat3<T> mult(const mat3<T>& l, const affine2d<T>& r) {
  }

template <typename T>
  inline mat3<T> operator*(const mat3<T>& l, const affine2d<T>& r) {
    return mult(l, r);
  }

template <typename T>
  mat3<T> mult(const affine2d<T>& l, const mat3<T>& r) {
  }

template <typename T>
  inline mat3<T> operator*(const affine2d<T>& l, const mat3<T>& r) {
    return mult(l, r);
  }


template <typename T>
  void l_mult_eq(mat3<T>& m, const affine2d<T>& l) {
    T ta = m[0];
    m[0] = l.rs[0] * ta + l.rs[2] * m[1] + l.t[0] * m[2];
    m[1] = l.rs[1] * ta + l.rs[3] * m[1] + l.t[1] * m[2];

    ta = m[3];
    m[3] = l.rs[0] * ta + l.rs[2] * m[3] + l.t[0] * m[5];
    m[4] = l.rs[1] * ta + l.rs[3] * m[3] + l.t[1] * m[5];

    ta = m[6];
    m[6] = l.rs[0] * ta + l.rs[2] * m[6] + l.t[0] * m[8];
    m[7] = l.rs[1] * ta + l.rs[3] * m[7] + l.t[1] * m[8];
  }

template <typename T>
  void r_mult_eq(mat3<T>& m, const affine2d<T>& r) {
    T ta = m[0];
    T tb = m[3];
    m[0] = ta * r.rs[0] + tb * r.rs[1];
    m[3] = ta * r.rs[2] + tb * r.rs[3];
    m[6] = ta * r.t[0] + tb * r.t[1] + m[6];

    ta = m[1];
    tb = m[4];
    m[1] = ta * r.rs[0] + tb * r.rs[1];
    m[4] = ta * r.rs[2] + tb * r.rs[3];
    m[7] = ta * r.t[0] + tb * r.t[1] + m[7];

    ta = m[2];
    tb = m[5];
    m[2] = ta * r.rs[0] + tb * r.rs[1];
    m[5] = ta * r.rs[2] + tb * r.rs[3];
    m[8] = ta * r.t[0] + tb * r.t[1] + m[8];
  }

};
};

#endif
