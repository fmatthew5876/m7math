#ifndef M7_MATH_SCALE_HPP
#define M7_MATH_SCALE_HPP

#include <m7/math/types.hh>
#include <m7/math/types.hh>

namespace m7 {
namespace math {

template <typename T>
void make_scale(mat3<T>& m, T scale_x, T scale_y, T scale_z) {
  m[1] = m[2] = m[3] = m[5] = m[6] = m[7] = 0;
  m[0] = scale_x;
  m[1] = scale_y;
  m[2] = scale_z;
}

template <typename T>
inline void make_scale(mat3<T>& m, const vec3<T>& scale) {
  make_scale(m, scale[0], scale[1], scale[2]);
}

template <typename T>
void make_scale(mat4<T>& m, T scale_x, T scale_y, T scale_z) {
  m[1] = m[2] = m[3] = m[4] = 0;
  m[6] = m[7] = m[8] = m[9] = 0;
  m[11] = m[12] = m[13] = m[14] = 0;
  m[0] = scale_x;
  m[5] = scale_y;
  m[10] = scale_z;
  m[15] = 1;
}

template <typename T>
inline void make_scale(mat4<T>& m, const vec3<T>& scale) {
  make_scale(m, scale[0], scale[1], scale[2]);
}

template <typename T>
inline void make_scale(affine3d<T>& a, T scale_x, T scale_y, T scale_z) {
  make_scale(a.rs, scale_x, scale_y, scale_z);
  a.t[0] = a.t[1] = a.t[2] = 0;
}

template <typename T>
inline void make_scale(affine3d<T>& a, const vec3<T>& scale) {
  make_scale(a, scale[0], scale[1], scale[2]);
}

};
};

#endif
