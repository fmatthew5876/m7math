#ifndef M7_MATH_TRANSFORM_HPP
#define M7_MATH_TRANSFORM_HPP

#include <m7/math/types.hh>
#include <m7/math/types.hh>
#include <m7/math/rotate.hh>
#include <m7/math/rotate.hh>
#include <m7/math/scale.hh>
#include <m7/math/scale.hh>
#include <m7/math/translate.hh>
#include <m7/math/translate.hh>
#include <m7/math/affine3d.hh>
#include <m7/math/affine3d.hh>
#include <m7/math/mat4.hh>
#include <m7/math/mat4.hh>

namespace m7 {
namespace math {

template <typename T>
void make_look_at(mat4<T>& m, const vec3<T>& eye, const vec3<T>& center, const vec3<T>& up) {
}

template <typename T>
void make_look_at(affine3d<T>& m, const vec3<T>& eye, const vec3<T>& center, const vec3<T>& up) {
}

template <typename T>
vec3<T> project(const vec3<T>& obj, const mat4<T>& modelview, const mat4<T>& projection, const vec4i& viewport) {
  vec4<T> win = projection * modelview * vec4<T>(obj, 1);
  win[0] = viewport[0] + viewport[2] * (win[0] + 1) / T(2.0);
  win[1] = viewport[1] + viewport[3] * (win[1] + 1) / T(2.0);
  win[2] = (win[2] + 1) / T(2.0);
  return win.xyz;
}

template <typename T>
vec3<T> project(const vec3<T>& obj, const affine3d<T>& modelview, const mat4<T>& projection, const vec4i& viewport) {
  vec4<T> win = projection * modelview * vec4<T>(obj, 1);
  win[0] = viewport[0] + viewport[2] * (win[0] + 1) / T(2.0);
  win[1] = viewport[1] + viewport[3] * (win[1] + 1) / T(2.0);
  win[2] = (win[2] + 1) / T(2.0);
  return win.xyz;
}

template <typename T>
vec3<T> un_project(const vec3<T>& win, const mat4<T>& modelview, const mat4<T>& projection, const vec4i& viewport) {
  vec4<T> obj;
  obj[0] = ((T(2.0) * (win[0] - viewport[0])) / viewport[2]) - 1;
  obj[1] = ((T(2.0) * (win[1] - viewport[1])) / viewport[3]) - 1;
  obj[2] = T(2.0) * win[2] -1;
  obj[3] = 1;
  mat4<T> ipm = projection * modelview;
  inverse_eq(ipm);
  l_mult_eq(obj, ipm);
  return obj.xyz;
}

template <typename T>
vec3<T> un_project(const vec3<T>& win, const affine3d<T>& modelview, const mat4<T>& projection, const vec4i& viewport) {
  vec4<T> obj;
  obj[0] = ((T(2.0) * (win[0] - viewport[0])) / viewport[2]) - 1;
  obj[1] = ((T(2.0) * (win[1] - viewport[1])) / viewport[3]) - 1;
  obj[2] = T(2.0) * win[2] -1;
  obj[3] = 1;
  mat4<T> ipm = projection * modelview;
  inverse_eq(ipm);
  l_mult_eq(obj, ipm);
  return obj.xyz;
}

template <typename T>
void make_pick_matrix(mat4<T>& m, const vec2<T>& center, const vec2<T>& delta, const vec4i& viewport) {
}

};
}:


#endif
