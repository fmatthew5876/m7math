#ifndef M7_MAT3_HPP
#define M7_MAT3_HPP

#include <m7/math/types.hh>
#include <m7/math/types.hh>

namespace m7 {
namespace math {

template <typename T>
  inline T det(const mat3<T>& m) {
    T d = m[0] * m[4] * m[8];
    d  += m[3] * m[7] * m[2];
    d  += m[6] * m[1] * m[5];
    d  -= m[6] * m[4] * m[2];
    d  -= m[3] * m[1] * m[8];
    d  -= m[0] * m[7] * m[5];
    return d;
  }

template <typename T>
  mat3<T> inverse(const mat3<T>& m) {
    mat3<T> i;
    i.m[0] = m.m[8]*m[4]-m.m[5]*m.m[7];
    i.m[1] = m.m[7]*m[2]-m.m[1]*m.m[8];
    i.m[2] = m.m[1]*m.m[5]-m.m[4]*m.m[2];

    i.m[3] = m.m[6]*m.m[5]-m.m[8]*m.m[3];
    i.m[4] = m.m[8]*m.m[0]-m.m[2]*m.m[6];
    i.m[5] = m.m[3]*m.m[2]-m.m[5]*m.m[0];

    i.m[6] = m.m[3]*m.m[7]-m.m[6]*m.m[4];
    i.m[7] = m.m[6]*m.m[1]-m.m[0]*m.m[7];
    i.m[8] = m.m[4]*m.m[0]-m.m[1]*m.m[3];

    T invdet = 1.0 / (m.m[0] * i[0] + m.m[3] * i[1] + m.m[6] * i[2]);

    i.m[0] *= invdet;
    i.m[1] *= invdet;
    i.m[2] *= invdet;
    i.m[3] *= invdet;
    i.m[4] *= invdet;
    i.m[5] *= invdet;
    i.m[6] *= invdet;
    i.m[7] *= invdet;
    i.m[8] *= invdet;

    return i;
  }

template <typename T>
  void inverse_eq(mat3<T>& m) {
    T ta = m.m[1];
    T tb = m.m[2];
    T tc = m.m[7];
    T td = m.m[8];
    T te = m.m[5];
    T tf = m.m[0];
    m.m[1] =  tc  * tb  - ta* td;
    m.m[2] =  ta  * te  -m.m[4]* tb;
    m.m[7] = m.m[6]* ta  -m.m[0]* tc;
    m.m[8] = m.m[4]*m.m[0]- ta*m.m[3];

    ta = m.m[4];

    m.m[4] = td   *m.m[0]- tb*m.m[6];
    m.m[5] = m.m[3]* tb- te *m.m[0];

    tb = m.m[6];
    m.m[6] = m.m[3]* tc - tb * ta;

    m.m[0] =  td  * ta - te * tc;

    tc = m.m[3];
    m.m[3] =  tb * te - td *m.m[3];


    T invdet = 1.0 / (tf * m.m[0] + tc * m.m[1] + tb * m.m[2]);

    m.m[0] *= invdet;
    m.m[1] *= invdet;
    m.m[2] *= invdet;
    m.m[3] *= invdet;
    m.m[4] *= invdet;
    m.m[5] *= invdet;
    m.m[6] *= invdet;
    m.m[7] *= invdet;
    m.m[8] *= invdet;
  }

template <typename T>
  inline void l_mult_eq(mat3<T>& M7_RESTRICT m, const mat3<T>& M7_RESTRICT left) {
  }

template <typename T>
  inline void r_mult_eq(mat3<T>& M7_RESTRICT m, const mat3<T>& M7_RESTRICT right) {
  }

template <typename T>
  inline void l_mult_transpose_eq(mat3<T>& M7_RESTRICT m, const mat3<T>& M7_RESTRICT left) {
  }

template <typename T>
  inline void r_mult_transpose_eq(mat3<T>& M7_RESTRICT m, const mat3<T>& M7_RESTRICT right) {
  }

template <typename T>
  mat3<T> adjoint(const mat3<T>& m) {
  }

template <typename T>
  void adjoint_eq(mat3<T>& m) {
  }

template <typename T>
  void l_mult_eq(vec3<T>& M7_RESTRICT v, const mat3<T>& M7_RESTRICT l) {
    m7assert(&v != &(l.cv[0]) && v != &(l.cv[1]));
    T t = v[0];
    v[0] = l[0] * t + l[2] * v[1];
    v[1] = l[1] * t + l[3] * v[1];
  }

};
};

#define MTYPE mat3
#define VTYPE vec3
#include <m7/math/_internal/common.hh>
#include <m7/math/_internal/common.hh>
#include <m7/math/_internal/mat_common.hh>
#include <m7/math/_internal/mat_common.hh>
#undef MTYPE
#undef VTYPE



#endif
