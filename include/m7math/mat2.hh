#ifndef M7_MAT2_HPP
#define M7_MAT2_HPP

#include <m7/math/types.hh>
#include <m7/math/types.hh>

namespace m7 {
namespace math {

template <typename T>
  inline T det(const mat2<T>& m) {
    return m[0] * m[3] - m[2] * m[1];
  }

template <typename T>
  inline mat2<T> inverse(const mat2<T>& m) {
    T invdet = 1.0 / (m[0] * m[3] - m[2] * m[1]);
    mat2<T> i;
    i[0] = m[3] * invdet;
    i[1] = -m[1] * invdet;
    i[2] = -m[2] * invdet;
    i[3] = m[0] * invdet;
    return i;
  }

template <typename T>
  inline void inverse_eq(const mat2<T>& m) {
    T invdet = 1.0 / (m[0] * m[3] - m[2] * m[1]);
    T t = m[0];
    m[0] = m[3] * invdet;
    m[1] = -m[1] * invdet;
    m[2] = -m[2] * invdet;
    m[3] = t * invdet;
  }

template <typename T>
  inline void transpose_eq(mat2<T>& m) {
    T t = m[1];
    m[1] = m[2];
    m[2] = t;
  }

template <typename T>
  inline void l_mult_eq(mat2<T>& M7_RESTRICT m, const mat2<T>& M7_RESTRICT left) {
    m7assert(&m != &left);
    T ta = m[0];
    m[0] = left[0] * ta + left[2] * m[1];
    m[1] = left[1] * ta + left[3] * m[1];

    ta = m[3];
    m[2] = left[0] * ta + left[2] * m[3];
    m[3] = left[1] * ta + left[3] * m[3];
  }

template <typename T>
  inline void r_mult_eq(mat2<T>& M7_RESTRICT m, const mat2<T>& M7_RESTRICT right) {
    m7assert(&m != &right);
    T ta = m[0];
    m[0] = ta * right[0] + m[2] * right[1];
    m[2] = ta * right[2] + m[2] * right[3];

    ta = m[1];
    m[1] = ta * right[0] + m[3] * right[1];
    m[3] = ta * right[2] + m[3] * right[3];
  }

template <typename T>
  inline void l_mult_transpose_eq(mat2<T>& M7_RESTRICT m, const mat2<T>& M7_RESTRICT left) {
    m7assert(&m != &left);
    T ta = m[0];
    m[0] = left[0] * ta + left[1] * m[1];
    m[1] = left[2] * ta + left[3] * m[1];

    ta = m[3];
    m[2] = left[0] * ta + left[1] * m[3];
    m[3] = left[2] * ta + left[3] * m[3];
  }

template <typename T>
  inline void r_mult_transpose_eq(mat2<T>& M7_RESTRICT m, const mat2<T>& M7_RESTRICT right) {
    m7assert(&m != &right);
    T ta = m[0];
    m[0] = ta * right[0] + m[2] * right[2];
    m[2] = ta * right[1] + m[2] * right[3];

    ta = m[1];
    m[1] = ta * right[0] + m[3] * right[2];
    m[3] = ta * right[1] + m[3] * right[3];
  }


template <typename T>
  mat2<T> adjoint(const mat2<T>& m) {
    return mat2<T>(m[3], -m[1], -m[2], m[0]);
  }
template <typename T>
  inline void adjoint_eq(mat2<T>& m) {
    T t = m[3];
    m[0] = m[3];
    m[3] = t;
    m[1] = -m[1];
    m[2] = -m[2];
  }


template <typename T>
  void l_mult_eq(vec2<T>& M7_RESTRICT v, const mat2<T>& M7_RESTRICT l) {
    m7assert(&v != &(l.cv[0]) && v != &(l.cv[1]));
    T t = v[0];
    v[0] = l[0] * t + l[2] * v[1];
    v[1] = l[1] * t + l[3] * v[1];
  }

};
};

#define MTYPE mat2
#define VTYPE vec2
#include <m7/math/_internal/common.hh>
#include <m7/math/_internal/common.hh>
#include <m7/math/_internal/mat_common.hh>
#include <m7/math/_internal/mat_common.hh>
#undef MTYPE
#undef VTYPE


#endif
