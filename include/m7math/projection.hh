#ifndef M7_MATH_PROJECTION_HPP
#define M7_MATH_PROJECTION_HPP

#include <m7/math/types.hh>
#include <m7/math/types.hh>

namespace m7 {
namespace math {

template <typename T>
  void make_frustum(mat4<T>& m, T left, T right, T bottom, T top, T near, T far) {
    T d = far - near;
    T b = top - bottom;
    T r = right - left;

    m.m[0] = 2 * near / r;
    m.m[1] = 0;
    m.m[2] = 0;
    m.m[3] = 0;

    m.m[4] = 0;
    m.m[5] = 2 * near / b;
    m.m[6] = 0;
    m.m[7] = 0;

    m.m[8] = (right + left) / r;
    m.m[9] = (top + bottom) / b;
    m.m[10] = -(far + near) / d;
    m.m[11] = -1;

    m.m[12] = 0;
    m.m[13] = 0;
    m.m[14] = -(2.0 * far * near ) / d;
    m.m[15] = 0;
  }

template <typename T>
  void make_perspective(mat4<T>& m, T fov, T aspect_ratio, T near, T far) {
    T e = 1 / tan(fov / 2);
    T f = far - near;

    m.m[0] = e;
    m.m[1] = 0;
    m.m[2] = 0;
    m.m[3] = 0;

    m.m[4] = 0;
    m.m[5] = e / aspect_ratio;
    m.m[6] = 0;
    m.m[7] = 0;

    m.m[8] = 0;
    m.m[9] = 0;
    m.m[10] = -(far + near) / f;
    m.m[11] = -1;

    m.m[12] = 0;
    m.m[13] = 0;
    m.m[14] = -2 * far * near / (f);
    m.m[15] = 0;
  }

template <typename T>
  void make_perspective_fov(mat4<T>& m, T fov, T width, T height, T near, T far) {
  }

template <typename T>
  void make_infinite_perspective(mat4<T>& m, T fovy, T aspect, T near) {
  }

template <typename T>
  void make_tweaked_infinite_perspective(mat4<T>& m, T fovy, T aspect, T near) {
  }

template <typename T>
  void make_ortho(mat4<T>& m, T left, T right, T bottom,
      T top, T near, T far) {
    T r = right - left;
    T b = top - bottom;
    T f = far - near;

    m.m[0] = 2 / r;
    m.m[1] = 0;
    m.m[2] = 0;
    m.m[3] = 0;

    m.m[4] = 0;
    m.m[5] = 2 / b;
    m.m[6] = 0;
    m.m[7] = 0;

    m.m[8] = 0;
    m.m[9] = 0;
    m.m[10] = -2 / f;
    m.m[11] = 0;

    m.m[12] = -(right + left) / r;
    m.m[13] = -(top + bottom) / b;
    m.m[14] = -(far + near) / f;
    m.m[15] = 1;
  }

template <typename T>
  void make_ortho2d(mat4<T>& m, T left, T right, T bottom, T top) {
    T r = right - left;
    T b = top - bottom;

    m.m[0] = 2 / r;
    m.m[1] = 0;
    m.m[2] = 0;
    m.m[3] = 0;

    m.m[4] = 0;
    m.m[5] = 2 / b;
    m.m[6] = 0;
    m.m[7] = 0;

    m.m[8] = 0;
    m.m[9] = 0;
    m.m[10] = -1;
    m.m[11] = 0;

    m.m[12] = -(right + left) / r;
    m.m[13] = -(top + bottom) / b;
    m.m[14] = 0;
    m.m[15] = 1;
  }

};
};

#endif
