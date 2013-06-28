#ifndef M7_MATH_TRANSLATE_HPP
#define M7_MATH_TRANSLATE_HPP

#include <m7/math/types.hh>
#include <m7/math/types.hh>

namespace m7 {
namespace math {

template <typename T>
void make_translate(mat4<T>& m, T x, T y, T z) {
  m[0] = 1;
  m[1] = m[2] = m[3] = m[4] = 0;
  m[5] = 1;
  m[6] = m[7] = m[8] = m[9] = 0;
  m[10] = 1;
  m[11] = 0;

  m[12] = x;
  m[13] = y;
  m[14] = z;
  m[15] = 1;
}

template <typename T>
inline void make_translate(mat4<T>& m, vec3<T>& translate) {
  make_translate(m, translate[0], translate[1], translate[2]);
}

template <typename T>
void make_translate(affine3d<T>& a, T x, T y, T z) {
  a.rs[0] = 1;
  a.rs[1] = a.rs[2] = a.rs[3] = 0;
  a.rs[4] = 1;
  a.rs[5] = a.rs[6] = a.rs[7] = 0;
  a.rs[8] = 1;
  a.t[0] = x;
  a.t[1] = y;
  a.t[2] = z;
}

template <typename T>
inline void make_translate(affine3d<T>& a, vec3<T>& translate) {
  make_translate(a, translate[0], translate[1], translate[2]);
}
};
};

#endif
