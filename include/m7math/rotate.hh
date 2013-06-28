#ifndef M7_MATH_ROTATE_HPP
#define M7_MATH_ROTATE_HPP

#include <m7/math/types.hh>
#include <m7/math/types.hh>

namespace m7 {
namespace math {

template <typename T>
void make_rotate(mat3<T>& m, T euler_x, T euler_y, T euler_z) {
}

template <typename T>
void make_rotate(mat4<T>& m, T euler_x, T euler_y, T euler_z) {
}

template <typename T>
void make_rotate(affine3d<T>& m, T euler_x, T euler_y, T euler_z) {
}

template <typename T>
void make_rotate(mat3<T>& m, T angle, vec3<T> axis) {
}

template <typename T>
void make_rotate(mat4<T>& m, T angle, vec3<T> axis) {
}

template <typename T>
void make_rotate(affine3d<T>& m, T angle, vec3<T> axis) {
}



};
};


#endif
