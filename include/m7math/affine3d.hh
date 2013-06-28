#ifndef M7_MATH_AFFINE3D_HPP
#define M7_MATH_AFFINE3D_HPP

#include <m7/math/types.hh>
#include <m7/math/types.hh>

namespace m7 {
namespace math {

template <typename T>
void make_identity(affine3d<T>& a) {
  a.rs[1] = a.rs[2] = a.rs[3] = a.rs[5] = a.rs[6] = a.rs[7] = 0;
  a.rs[0] = a.rs[4] = a.rs[8] = 1;
  a.t[0] = a.t[1] = a.t[2] = 0;
}

};
};

#endif
