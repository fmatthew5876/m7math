#ifndef M7_MATH_VEC2_HPP
#define M7_MATH_VEC2_HPP

#include <m7/m7.hh>
#include <m7/m7.hh>
#include <m7/math/types.hh>
#include <m7/math/types.hh>

namespace m7 {
namespace math {

///Returns a copy of the vector
template <typename T>
vec2<T> operator+(const vec2<T>& l);

///Negates a vector
template <typename T>
vec2<T> operator-(const vec2<T>& l);

///Component wise addition
template <typename T>
vec2<T> operator+(const vec2<T>& l, const vec2<T>& r);

///Component wise subtraction
template <typename T>
vec2<T> operator-(const vec2<T>& l, const vec2<T>& r);

};
};

#define MTYPE vec2
#include <m7/math/_internal/common.hh>
#include <m7/math/_internal/common.hh>
#include <m7/math/_internal/vec_common.hh>
#include <m7/math/_internal/vec_common.hh>
#undef MTYPE

#endif
