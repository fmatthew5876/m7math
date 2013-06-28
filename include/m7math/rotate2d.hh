#ifndef M7_MATH_ROTATE2D_HPP
#define M7_MATH_ROTATE2D_HPP

#include <m7/math/types.hh>
#include <m7/math/types.hh>
#include <m7/math/math.hh>
#include <m7/math/math.hh>

namespace m7 {
namespace math {

template <typename T>
  inline void make_rotate2d(mat2<T>& m, T angle) {
    T s, c;
    sincos(angle, s, c);
    m.mn[0][0] = c;
    m.mn[0][1] = s;

    m.mn[1][0] = -s;
    m.mn[1][1] = c;
  }

template <typename T>
  inline void make_rotate2d(mat3<T>& m, T angle) {
    T s, c;
    sincos(angle, s, c);
    m.mn[0][0] = c;
    m.mn[0][1] = s;
    m.mn[0][2] = 0;

    m.mn[1][0] = -s;
    m.mn[1][1] = c;
    m.mn[1][2] = 0;

    m.mn[2][0] = m.mn[2][1] = 0;
    m.mn[2][2] = 1;
  }

template <typename T>
  inline void make_rotate2d(mat4<T>& m, T angle) {
    T s, c;
    sincos(angle, s, c);

    m.mn[0][0] = c;
    m.mn[0][1] = s;
    m.mn[0][2] = m.mn[0][3] = 0;

    m.mn[1][0] = -s;
    m.mn[1][1] = c;
    m.mn[1][2] = m.mn[1][3] = 0;

    m.mn[2][0] = m.mn[2][1] = 0;
    m.mn[2][2] = 1;
    m.mn[2][3] = 0;

    m.mn[3][0] = m.mn[3][1] = m.mn[3][2] = 0;
    m.mn[3][3] = 1;
  }

template <typename T>
  inline void make_rotate2d(affine2d<T>& a, T angle) {
    make_rotate2d(a.rs, angle);
    a.t[0] = a.t[1] = 0;
  }

//==================================================================

template <typename T>
  inline void make_inverse_rotate2d(mat2<T>& m, T angle) {
    T s, c;
    sincos(angle, s, c);

    m.mn[0][0] = c;
    m.mn[0][1] = -s;
    m.mn[1][0] = s;
    m.mn[1][1] = c;
  }

template <typename T>
  inline void make_inverse_rotate2d(mat3<T>& m, T angle) {
    T s, c;
    sincos(angle, s, c);

    m.mn[0][0] = c;
    m.mn[0][1] = -s;
    m.mn[0][2] = 0;

    m.mn[1][0] = s;
    m.mn[1][1] = c;
    m.mn[1][2] = 0;

    m.mn[2][0] = m.mn[2][1] = 0;
    m.mn[2][2] = 1;
  }

template <typename T>
  inline void make_inverse_rotate2d(mat4<T>& m, T angle) {
    T s, c;
    sincos(angle, s, c);

    m.mn[0][0] = c;
    m.mn[0][1] = -s;
    m.mn[0][2] = m.mn[0][3] = 0;

    m.mn[1][0] = s;
    m.mn[1][1] = c;
    m.mn[1][2] = m.mn[1][3] = 0;

    m.mn[2][0] = m.mn[2][1] = 0;
    m.mn[2][2] = 1;
    m.mn[2][3] = 0;

    m.mn[3][0] = m.mn[3][1] = m.mn[3][2] = 0;
    m.mn[3][3] = 1;
  }

template <typename T>
  inline void make_inverse_rotate2d(affine2d<T>& a, T angle) {
    make_inverse_rotate2d(a.rs, angle);
    a.t[0] = a.t[1] = 0;
  }

//==================================================================

template <typename T>
  mat2<T> rotate2d(const mat2<T>& m, T angle) {
    T s, c;
    sincos(angle, s, c);

    mat2<T> res;
    res[0][0] = c * m[0][0] - s * m[0][1];
    res[0][1] = s * m[0][0] + c * m[0][1];
    res[1][0] = c * m[1][0] - s * m[1][1];
    res[1][1] = s * m[1][0] + c * m[1][1];
    return res;
  }

template <typename T>
  mat3<T> rotate2d(const mat3<T>& m, T angle) {
    T s, c;
    sincos(angle, s, c);

    mat3<T> res;
    res[0][0] = c * m[0][0] - s * m[0][1];
    res[0][1] = s * m[0][0] + c * m[0][1];
    res[0][2] = m[0][2];

    res[1][0] = c * m[1][0] - s * m[1][1];
    res[1][1] = s * m[1][0] + c * m[1][1];
    res[1][2] = m[1][2];

    res[2][0] = c * m[2][0] - s * m[2][1];
    res[2][1] = s * m[2][0] + c * m[2][1];
    res[2][2] = m[2][2];

    return res;
  }

template <typename T>
  mat4<T> rotate2d(const mat4<T>& m, T angle) {
    T s, c;
    sincos(angle, s, c);

    mat3<T> res;
    res[0][0] = c * m[0][0] - s * m[0][1];
    res[0][1] = s * m[0][0] + c * m[0][1];
    res[0][2] = m[0][2];
    res[0][3] = m[0][3];

    res[1][0] = c * m[1][0] - s * m[1][1];
    res[1][1] = s * m[1][0] + c * m[1][1];
    res[1][2] = m[1][2];
    res[1][3] = m[1][3];

    res[2][0] = c * m[2][0] - s * m[2][1];
    res[2][1] = s * m[2][0] + c * m[2][1];
    res[2][2] = m[2][2];
    res[2][3] = m[2][3];

    res[3][0] = c * m[3][0] - s * m[3][1];
    res[3][1] = s * m[3][0] + c * m[3][1];
    res[3][2] = m[3][2];
    res[3][3] = m[3][3];

    return res;
  }

template <typename T>
  affine2d<T> rotate2d(const affine2d<T>& a, T angle) {
    T s, c;
    sincos(angle, s, c);

    affine2d<T> res;
    res.rs[0][0] = c * a.rs[0][0] - s * a.rs[0][1];
    res.rs[0][1] = s * a.rs[0][0] + c * a.rs[0][1];
    res.rs[1][0] = c * a.rs[1][0] - s * a.rs[1][1];
    res.rs[1][1] = s * a.rs[1][0] + c * a.rs[1][1];
    res.t[0] = c * a.t[0] - s * a.t[1];
    res.t[1] = s * a.t[0] + c * a.t[1];
  }

//==================================================================

template <typename T>
  mat2<T> inverse_rotate2d(const mat2<T>& m, T angle) {
    T s, c;
    sincos(angle, s, c);

    mat2<T> res;
    res.mn[0][0] = m.mn[0][0] * c - m.mn[1][0] * s;
    res.mn[0][1] = m.mn[0][1] * c - m.mn[1][1] * s;
    res.mn[1][0] = m.mn[0][0] * s + m.mn[1][0] * c;
    res.mn[1][1] = m.mn[0][1] * s + m.mn[1][1] * c;
    return res;
  }

template <typename T>
  mat3<T> inverse_rotate2d(const mat3<T>& m, T angle) {
    T s, c;
    sincos(angle, s, c);

    mat3<T> res;
    res.mn[0][0] = m.mn[0][0] * c - m.mn[1][0] * s;
    res.mn[0][1] = m.mn[0][1] * c - m.mn[1][1] * s;
    res.mn[0][2] = m.mn[0][2] * c - m.mn[1][2] * s;

    res.mn[1][0] = m.mn[0][0] * s + m.mn[1][0] * c;
    res.mn[1][1] = m.mn[0][1] * s + m.mn[1][1] * c;
    res.mn[1][2] = m.mn[0][2] * s + m.mn[1][2] * c;

    res.mn[2][0] = m.mn[2][0];
    res.mn[2][1] = m.mn[2][1];
    res.mn[2][2] = m.mn[2][2];
    return res;
  }

template <typename T>
  mat4<T> inverse_rotate2d(const mat4<T>& m, T angle) {
    T s, c;
    sincos(angle, s, c);

    mat3<T> res;
    res.mn[0][0] = m.mn[0][0] * c - m.mn[1][0] * s;
    res.mn[0][1] = m.mn[0][1] * c - m.mn[1][1] * s;
    res.mn[0][2] = m.mn[0][2] * c - m.mn[1][2] * s;
    res.mn[0][3] = m.mn[0][3] * c - m.mn[1][3] * s;

    res.mn[1][0] = m.mn[0][0] * s + m.mn[1][0] * c;
    res.mn[1][1] = m.mn[0][1] * s + m.mn[1][1] * c;
    res.mn[1][2] = m.mn[0][2] * s + m.mn[1][2] * c;
    res.mn[1][3] = m.mn[0][3] * s + m.mn[1][3] * c;

    res.mn[2][0] = m.mn[2][0];
    res.mn[2][1] = m.mn[2][1];
    res.mn[2][2] = m.mn[2][2];
    res.mn[2][3] = m.mn[2][3];

    res.mn[3][0] = m.mn[3][0];
    res.mn[3][1] = m.mn[3][1];
    res.mn[3][2] = m.mn[3][2];
    res.mn[3][3] = m.mn[3][3];

    return res;
  }

template <typename T>
  affine2d<T> inverse_rotate2d(const affine2d<T>& a, T angle) {
    T s, c;
    sincos(angle, s, c);

    affine2d<T> res;
    res.rs[0][0] = a.rs[0][0] * c - a.rs[1][0] * s;
    res.rs[0][1] = a.rs[0][1] * c - a.rs[1][1] * s;

    res.rs[1][0] = a.rs[0][0] * s + a.rs[1][0] * c;
    res.rs[1][1] = a.rs[0][1] * s + a.rs[1][1] * c;

    res.t = a.t;
    return res;
  }

//==================================================================

template <typename T>
  mat2<T> rotate2d_right(const mat2<T>& m, T angle);

template <typename T>
  mat3<T> rotate2d_right(const mat3<T>& m, T angle);

template <typename T>
  mat4<T> rotate2d_right(const mat4<T>& m, T angle);

template <typename T>
  affine2d<T> rotate2d_right(const affine2d<T>& m, T angle);

//==================================================================

template <typename T>
  mat2<T> inverse_rotate2d_left(const mat2<T>& m, T angle);

template <typename T>
  mat3<T> inverse_rotate2d_left(const mat3<T>& m, T angle);

template <typename T>
  mat4<T> inverse_rotate2d_left(const mat4<T>& m, T angle);

template <typename T>
  affine2d<T> inverse_rotate2d_left(const affine2d<T>& m, T angle);

//==================================================================

template <typename T>
   T extract_rotation2d(const mat2<T>& m) {
      return atan2(m[0][1], m[1][1]);
   }

template <typename T>
   T extract_rotation2d(const mat3<T>& m) {
      return atan2(m[0][1], m[1][1]);
   }

template <typename T>
   T extract_rotation2d(const mat4<T>& m) {
      return atan2(m[0][1], m[1][1]);
   }

template <typename T>
   T extract_rotation2d(const affine2d<T>& m) {
      return extract_rotation2d(m.rs);
   }


};
};


#endif
