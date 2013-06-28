#ifndef M7_MATH_GRAM_SCHMIDT_HPP
#define M7_MATH_GRAM_SCHMIDT_HPP

#include <m7/math/vec2.hh>
#include <m7/math/vec2.hh>
#include <m7/math/vec3.hh>
#include <m7/math/vec3.hh>
#include <m7/math/vec4.hh>
#include <m7/math/vec4.hh>

namespace m7 {
namespace math {

template <typename T>
  void gram_schmidt(vec2<T>& v0, vec2<T>& v1) {
    v0.normalize();
    v1 = vector_reject(v1, v0);
    v1.normalize();
  }

template <typename T>
  inline void gram_schmidt(mat2<T>& m) {
    return gram_schmidt(m.col_alias(0), m.col_alias(1));
  }

template <typename T>
  void gram_schmidt_unit(vec2<T>& v0, vec2<T>& v1) {
    v1 = vector_reject_unit(v1, v0);
    v1.normalize();
  }

template <typename T>
  inline void gram_schmidt_unit(mat2<T>& m) {
    return gram_schmidt_unit(m.col_alias(0), m.col_alias(1));
  }

template <typename T>
  void gram_schmidt(vec3<T>& v0, vec3<T>& v1, vec3<T>& v2) {
    v0.normalize();
    v1 = vector_reject(v1, v0);
    v2 = vector_reject(v2, v0);
    v1.normalize();
    v2 = vector_reject(v2, v1);
    v2.normalize();
  }

template <typename T>
  inline void gram_schmidt(mat3<T>& m) {
    return gram_schmidt(m.col_alias(0), m.col_alias(1), m.col_alias(2));
  }

template <typename T>
  void gram_schmidt_unit(vec3<T>& v0, vec3<T>& v1, vec3<T>& v2) {
    v1 = vector_reject_unit(v1, v0);
    v2 = vector_reject_unit(v2, v0);
    v1.normalize();
    v2 = vector_reject(v2, v1);
    v2.normalize();
  }

template <typename T>
  inline void gram_schmidt_unit(mat3<T>& m) {
    return gram_schmidt_unit(m.col_alias(0), m.col_alias(1), m.col_alias(2));
  }

template <typename T>
  void gram_schmidt(vec4<T>& v0, vec4<T>& v1, vec4<T>& v2, vec4<T>& v3) {
    v0.normalize();
    v1 = vector_reject(v1, v0);
    v2 = vector_reject(v2, v0);
    v3 = vector_reject(v3, v0);
    v1.normalize();
    v2 = vector_reject(v2, v1);
    v3 = vector_reject(v3, v1);
    v2.normalize();
    v3 = vector_reject(v3, v2);
    v3.normalize();
  }

template <typename T>
  inline void gram_schmidt(mat4<T>& m) {
    return gram_schmidt(m.col_alias(0), m.col_alias(1), m.col_alias(2), m.col_alias(3));
  }

template <typename T>
  void gram_schmidt_unit(vec4<T>& v0, vec4<T>& v1, vec4<T>& v2, vec4<T>& v3) {
    v1 = vector_reject_unit(v1, v0);
    v2 = vector_reject_unit(v2, v0);
    v3 = vector_reject_unit(v3, v0);
    v1.normalize();
    v2 = vector_reject(v2, v1);
    v3 = vector_reject(v3, v1);
    v2.normalize();
    v3 = vector_reject(v3, v2);
    v3.normalize();
  }

template <typename T>
  inline void gram_schmidt_unit(mat4<T>& m) {
    return gram_schmidt_unit(m.col_alias(0), m.col_alias(1), m.col_alias(2), m.col_alias(3));
  }

};
};

#endif
