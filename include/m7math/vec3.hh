#ifndef M7_VEC3_HPP
#define M7_VEC3_HPP

#include <m7/math/types.hh>
#include <m7/math/types.hh>

namespace m7 {
namespace math {

template <typename T>
  vec3<T> cross(const vec3<T>& l, const vec3<T>& r) {
    vec3<T> res;
    res[0] = l[1] * r[2] - l[2] * r[1];
    res[1] = l[2] * r[0] - l[0] * r[2];
    res[2] = l[0] * r[1] - l[1] * r[0];
    return res;
  }

template <typename T>
  void cross_eq(vec3<T>& l, const vec3<T>& r) {
    T a = l[0];
    T b = l[1];
    l[0] = b *    r[2] - l[2] * r[1];
    l[1] = l[2] * r[0] - a *    r[2];
    l[2] = a *    r[1] - b *    r[0];
  }

template <typename T>
  T triple_product(const vec3<T>& a, const vec3<T>& b, const vec3<T>& c) {
    T res;
    res = a[0] * (b[1] * c[2] - b[2] * c[1]);
    res += a[1] * (b[2] * c[0] - b[0] * c[2]);
    res += a[2] * (b[0] * c[1] - b[1] * c[0]);
    return res;
  }

};
};

#define MTYPE vec3
#include <m7/math/_internal/common.hh>
#include <m7/math/_internal/common.hh>
#include <m7/math/_internal/vec_common.hh>
#include <m7/math/_internal/vec_common.hh>
#undef MTYPE


#endif
