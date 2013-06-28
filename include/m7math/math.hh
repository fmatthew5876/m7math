#ifndef M7_MATHBASE_HPP
#define M7_MATHBASE_HPP

#include <m7/config.hh>
#include <m7/config.hh>
#define _GNU_SOURCE_
#include <cmath>

namespace m7 {
   namespace math {
      inline void sincos(float angle, float& s, float& c) {
         ::sincosf(angle, &s, &c);
      }
      inline void sincos(double angle, double& s, double& c) {
         ::sincos(angle, &s, &c);
      }
#if 0
      void sincos(float angle, float& s, float& c) {
         s = sin(angle);
         c = cos(angle);
      }
      void sincos(double angle, double& s, double& c) {
         s = sin(angle);
         c = cos(angle);
      }
#endif
   };
};

#endif
