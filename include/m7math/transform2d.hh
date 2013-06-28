#ifndef M7_MATH_TRANSFORM2D
#define M7_MATH_TRANSFORM2D

#include <m7/math/types.hh>
#include <m7/math/types.hh>
#include <m7/math/math.hh>
#include <m7/math/math.hh>
#include <m7/math/rotate2d.hh>
#include <m7/math/rotate2d.hh>
#include <m7/math/scale2d.hh>
#include <m7/math/scale2d.hh>
#include <m7/math/translate2d.hh>
#include <m7/math/translate2d.hh>
#include <m7/math/affine2d.hh>
#include <m7/math/affine2d.hh>

namespace m7 {
namespace math {

template <typename T>
  void make_transform2d(mat3<T>& m, T rotation, const vec2<T>& translation) {
  }

template <typename T>
  void make_transform2d(mat3<T>& m, T rotation, const vec2<T>& translation, const vec2<T>& scale) {
  }

template <typename T>
  void make_ortho2d(mat4<T>& m, T left, T right, T bottom, T top);

template <typename T>
   void extract_transform2d(const mat3<T>& m,
         T& rotation, vec2<T>& translation, vec2<T>& scale) {
      translation = extract_translation2d(m);
      rotation = extract_rotation2d(m);
      scale = extract_scale2d(m);
   }

template <typename T>
   void extract_transform2d(const mat4<T>& m,
         T& rotation, vec2<T>& translation, vec2<T>& scale) {
      translation = extract_translation2d(m);
      rotation = extract_rotation2d(m);
      scale = extract_scale2d(m);
   }



}; /* namespace math */
}; /* namespace m7 */

#endif
