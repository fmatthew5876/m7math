#ifndef M7_MATH_SCALE2D_HPP
#define M7_MATH_SCALE2D_HPP

#include <m7/math/types.hh>
#include <m7/math/types.hh>

namespace m7 {
namespace math {

template <typename T>
  void make_scale2d(mat2<T>& m, const vec2<T>& s) {
    m[0][0] = s[0];
    m[0][1] = 0;
    m[1][0] = 0;
    m[1][1] = s[1];
  }

template <typename T>
  void make_scale2d(mat3<T>& m, const vec2<T>& s) {
    m[0][0] = s[0];
    m[0][1] = 0;
    m[0][2] = 0;

    m[1][0] = 0;
    m[1][1] = s[1];
    m[1][2] = 0;

    m[2][0] = m[2][1] = 0;
    m[2][2] = 1;
  }

template <typename T>
  void make_scale2d(mat4<T>& m, const vec2<T>& s) {
    m[0][0] = s[0];
    m[0][1] = 0;
    m[0][2] = 0;
    m[0][3] = 0;

    m[1][0] = 0;
    m[1][1] = s[1];
    m[1][2] = 0;
    m[1][3] = 0;

    m[2][0] = m[2][1] = 0;
    m[2][2] = 1;
    m[2][3] = 0;

    m[3][0] = m[3][1] = m[3][2] = 0;
    m[3][3] = 1;
  }

template <typename T>
  void make_inverse_scale2d(mat2<T>& m, const vec2<T>& s) {
    m[0][0] = 1.0 / s[0];
    m[0][1] = 0;
    m[1][0] = 0;
    m[1][1] = 1.0 / s[1];
  }

template <typename T>
  void make_inverse_scale2d(mat3<T>& m, const vec2<T>& s) {
    m[0][0] = 1.0 / s[0];
    m[0][1] = 0;
    m[0][2] = 0;

    m[1][0] = 0;
    m[1][1] = 1.0 / s[1];
    m[1][2] = 0;

    m[2][0] = m[2][1] = 0;
    m[2][2] = 1;
  }

template <typename T>
  void make_inverse_scale2d(mat4<T>& m, const vec2<T>& s) {
    m[0][0] = 1.0 / s[0];
    m[0][1] = 0;
    m[0][2] = 0;
    m[0][3] = 0;

    m[1][0] = 0;
    m[1][1] = 1.0 / s[1];
    m[1][2] = 0;
    m[1][3] = 0;

    m[2][0] = m[2][1] = 0;
    m[2][2] = 1;
    m[2][3] = 0;

    m[3][0] = m[3][1] = m[3][2] = 0;
    m[3][3] = 1;
  }

template <typename T>
  mat2<T> scale2d(const mat2<T>& m, vec2<T> s) {
    mat2<T> res;
    res[0] = s[0] * m[0];
    res[1] = s[1] * m[1];
    res[2] = s[0] * m[2];
    res[3] = s[1] * m[3];
    return res;
  }



template <typename T>
  mat3<T> scale2d(const mat3<T>& m, vec2<T> s);

template <typename T>
  mat4<T> scale2d(const mat4<T>& m, vec2<T> s);

template <typename T>
  mat2<T> scale2d_prepend(const mat2<T>& m, vec2<T> s) {
    mat2<T> res;
    res[0] = m[0] * s[0];
    res[1] = m[1] * s[0];
    res[2] = m[2] * s[1];
    res[3] = m[2] * s[2];
    return res;
  }

template <typename T>
  mat3<T> scale2d_prepend(const mat3<T>& m, vec2<T> s);

template <typename T>
  mat4<T> scale2d_prepend(const mat4<T>& m, vec2<T> s);

template <typename T>
  void make_scale2d(mat2<T>& m, T s) {
    m[0] = s;
    m[1] = 0;
    m[3] = s;
    m[4] = 0;
  }

template <typename T>
  void make_scale2d(mat3<T>& m, T s) {
    m[0] = s;
    m[1] = 0;
    m[2] = 0;

    m[3] = 0;
    m[4] = s;
    m[5] = 0;

    m[6] = 0;
    m[7] = 0;
    m[8] = 1;
  }

template <typename T>
  void make_scale2d(mat4<T>& m, T s) {
    m[0] = s;
    m[1] = m[2] = m[3] = 0;

    m[4] = 0;
    m[5] = s;
    m[6] = m[7] = 0;

    m[8] = m[9] = 0;
    m[10] = 1;
    m[11] = 0;

    m[12] = m[13] = m[14] = 0;
    m[15] = 1;
  }

template <typename T>
  mat2<T> scale2d(const mat2<T>& m, T s);

template <typename T>
  mat3<T> scale2d(const mat3<T>& m, T s);

template <typename T>
  mat4<T> scale2d(const mat4<T>& m, T s);

template <typename T>
  mat2<T> scale2d_prepend(const mat2<T>& m, T s);

template <typename T>
  mat3<T> scale2d_prepend(const mat3<T>& m, T s);

template <typename T>
  mat4<T> scale2d_prepend(const mat4<T>& m, T s);

template <typename T>
   vec2<T> extract_scale2d(const mat2<T>& m) {
      vec2<T> res;
      res.x = copysign(sqrt(m[0] * m[0] + m[2] * m[2]), m[0]);
      res.y = copysign(sqrt(m[1] * m[1] + m[2] * m[2]), m[2]);
      return res;
   }

template <typename T>
   T extract_scale2d(const mat3<T>& m) {
      vec2<T> res;
      res.x = copysign(sqrt(m[0] * m[0] + m[3] * m[3]), m[0]);
      res.y = copysign(sqrt(m[1] * m[1] + m[4] * m[4]), m[4]);
      return res;
   }

template <typename T>
   T extract_scale2d(const mat4<T>& m) {
      vec2<T> res;
      res.x = copysign(sqrt(m[0] * m[0] + m[4] * m[4]), m[0]);
      res.y = copysign(sqrt(m[1] * m[1] + m[5] * m[5]), m[5]);
      return res;
   }



};
};

#endif
