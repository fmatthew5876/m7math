#ifndef M7_MATH_TRANSLATE2D
#define M7_MATH_TRANSLATE2D

#include <m7/math/types.hh>
#include <m7/math/types.hh>

namespace m7 {
namespace math {

template <typename T>
  void make_translate2d(mat3<T>& m, const vec2<T>& v) {
    m[0] = 1;
    m[1] = 0;
    m[2] = 0;

    m[3] = 0;
    m[4] = 1;
    m[5] = 0;

    m[6] = v[0];
    m[7] = v[1];
    m[8] = 1;
  }

template <typename T>
  void make_translate2d(mat4<T>& m, const vec2<T>& v) {
    m[0] = 1;
    m[1] = 0;
    m[2] = 0;
    m[3] = 0;

    m[4] = 0;
    m[5] = 1;
    m[6] = 0;
    m[7] = 0;

    m[8] = 0;
    m[9] = 0;
    m[10] = 1;
    m[11] = 0;

    m[12] = v[0];
    m[13] = v[1];
    m[14] = 0;
    m[15] = 1;
  }

template <typename T>
  mat3<T> translate2d(const mat3<T>& m, const vec2<T>& v);

template <typename T>
  mat4<T> translate2d(const mat4<T>& m, const vec2<T>& v);

template <typename T>
  mat3<T> translate2d_prepend(const mat3<T>& m, const vec2<T>& v);

template <typename T>
  mat4<T> translate2d_prepend(const mat4<T>& m, const vec2<T>& v);

template <typename T>
   vec2<T> extract_translation2d(const mat3<T>& m) {
      return vec2<T>(m[6], m[7]);
   }

template <typename T>
   vec2<T> extract_translation2d(const mat4<T>& m) {
      return vec2<T>(m[8], m[9]);
   }


};
};

#endif
