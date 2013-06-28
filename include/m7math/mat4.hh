#ifndef M7_MATH_MAT4_HPP
#define M7_MATH_MAT4_HPP

#include <m7/math/types.hh>
#include <m7/math/types.hh>

namespace m7 {
namespace math {
template <typename T>
  T det(const mat4<T>& m) {
    return
      (m.m[0] * m.m[5] - m.m[1] * m.m[4]) *
      (m.m[10] * m.m[15] - m.m[11] * m.m[14])
      -
      (m.m[0] * m.m[9] - m.m[1] * m.m[8]) *
      (m.m[6] * m.m[15] - m.m[7] * m.m[14])
      +
      (m.m[0] * m.m[13] - m.m[1] * m.m[12]) *
      (m.m[6] * m.m[11] - m.m[7] * m.m[10])
      +
      (m.m[4] * m.m[9] - m.m[5] * m.m[8]) *
      (m.m[2] * m.m[15] - m.m[3] * m.m[14])
      -
      (m.m[4] * m.m[13] - m.m[5] * m.m[12]) *
      (m.m[2] * m.m[11] - m.m[3] * m.m[10])
      +
      (m.m[8] * m.m[13] - m.m[9] * m.m[12]) *
      (m.m[2] * m.m[7] - m.m[3] * m.m[6]);
  }

template <typename T>
  mat4<T> adjoint(const mat4<T>& m) {
    mat4<T> a;

    T s0 = m.m[0] * m.m[5] - m.m[1] * m.m[4];
    T s1 = m.m[0] * m.m[9] - m.m[1] * m.m[8];
    T s2 = m.m[0] * m.m[13] - m.m[1] * m.m[12];
    T s3 = m.m[4] * m.m[9] - m.m[5] * m.m[8];
    T s4 = m.m[4] * m.m[13] - m.m[5] * m.m[12];
    T s5 = m.m[8] * m.m[13] - m.m[9] * m.m[12];

    T c5 = m.m[10] * m.m[15] - m.m[11] * m.m[14];
    T c4 = m.m[6] * m.m[15] - m.m[7] * m.m[14];
    T c3 = m.m[6] * m.m[11] - m.m[7] * m.m[10];
    T c2 = m.m[2] * m.m[15] - m.m[3] * m.m[14];
    T c1 = m.m[2] * m.m[11] - m.m[3] * m.m[10];
    T c0 = m.m[2] * m.m[7] - m.m[3] * m.m[6];

    a[0]  = m.m[5]  * c5 - m.m[9] * c4 + m.m[13] * c3;
    a[1]  = -m.m[1] * c5 + m.m[9] * c2 - m.m[13] * c1;
    a[2]  = m.m[1]  * c4 - m.m[5] * c2 + m.m[13] * c0;
    a[3]  = -m.m[1] * c3 + m.m[5] * c1 - m.m[9] * c0;

    a[4]  = -m.m[4] * c5 + m.m[8] * c4 - m.m[12] * c3;
    a[5]  =  m.m[0] * c5 - m.m[8] * c2 + m.m[12] * c1;
    a[6]  = -m.m[0] * c4 + m.m[4] * c2 - m.m[12] * c0;
    a[7]  = m.m[0]  * c3 - m.m[4] * c1 + m.m[8] * c0;

    a[8]  = m.m[7]  * s5 - m.m[11] * s4 + m.m[15] * s3;
    a[9]  = -m.m[3] * s5 + m.m[11] * s2 - m.m[15] * s1;
    a[10] = m.m[3]  * s4 - m.m[7]  * s2 + m.m[15] * s0;
    a[11] = -m.m[3] * s3 + m.m[7]  * s1 - m.m[11] * s0;

    a[12] = -m.m[6] * s5 + m.m[10] * s4 - m.m[14] * s3;
    a[13] = m.m[2]  * s5 - m.m[10] * s2 + m.m[14] * s1;
    a[14] = -m.m[2] * s4 + m.m[6]  * s2 - m.m[14] * s0;
    a[15] = m.m[2]  * s3 - m.m[6]  * s1 + m.m[10] * s0;

    return a;

  }
template <typename T>
  void adjoint_eq(mat4<T>& m) {
    T s0 = m.m[0] * m.m[5] - m.m[1] * m.m[4];
    T s1 = m.m[0] * m.m[9] - m.m[1] * m.m[8];
    T s2 = m.m[0] * m.m[13] - m.m[1] * m.m[12];
    T s3 = m.m[4] * m.m[9] - m.m[5] * m.m[8];
    T s4 = m.m[4] * m.m[13] - m.m[5] * m.m[12];
    T s5 = m.m[8] * m.m[13] - m.m[9] * m.m[12];

    T c5 = m.m[10] * m.m[15] - m.m[11] * m.m[14];
    T c4 = m.m[6] * m.m[15] - m.m[7] * m.m[14];
    T c3 = m.m[6] * m.m[11] - m.m[7] * m.m[10];
    T c2 = m.m[2] * m.m[15] - m.m[3] * m.m[14];
    T c1 = m.m[2] * m.m[11] - m.m[3] * m.m[10];
    T c0 = m.m[2] * m.m[7] - m.m[3] * m.m[6];

    T ta = m.m[0];
    T tb = m.m[5];
    T tc = m.m[6];
    T td = m.m[7];
    T te = m.m[3];
    T tf = m.m[13];

    m.m[0]  =  tb  * c5 - m.m[9] * c4 + m.m[13] * c3;
    m.m[5]  =  ta    * c5 - m.m[8] * c2 + m.m[12] * c1;
    m.m[6]  = -ta    * c4 + m.m[4] * c2 - m.m[12] * c0;
    m.m[7]  =  ta    * c3 - m.m[4] * c1 + m.m[8] * c0;

    ta = m.m[2];

    m.m[2]  = m.m[1]  * c4 - tb * c2 + m.m[13] * c0;
    m.m[3]  = -m.m[1] * c3 + tb * c1 - m.m[9] * c0;

    tb = m.m[12];

    m.m[12] = -tc    * s5 + m.m[10] * s4 - m.m[14] * s3;
    m.m[4]  = -m.m[4] * c5 + m.m[8] * c4 - tb * c3;

    tb = m.m[14];

    m.m[14] = -ta * s4 + tc  * s2 - m.m[14] * s0;
    m.m[13] = ta  * s5 - m.m[10] * s2 + tb * s1;
    m.m[1]  = -m.m[1] * c5 + m.m[9] * c2 - tf * c1;

    tb = m.m[15];
    m.m[15] = ta  * s3 - tc  * s1 + m.m[10] * s0;

    m.m[9]  = -te * s5 + m.m[11] * s2 - tb * s1;
    m.m[8]  = td  * s5 - m.m[11] * s4 + tb * s3;
    m.m[11] = -te * s3 + td  * s1 - m.m[11] * s0;
    m.m[10] = te  * s4 - td  * s2 + tb * s0;
  }


template <typename T>
  mat4<T> inverse(const mat4<T>& m) {
    mat4<T> i;

    T s0 = m.m[0] * m.m[5] - m.m[1] * m.m[4];
    T s1 = m.m[0] * m.m[9] - m.m[1] * m.m[8];
    T s2 = m.m[0] * m.m[13] - m.m[1] * m.m[12];
    T s3 = m.m[4] * m.m[9] - m.m[5] * m.m[8];
    T s4 = m.m[4] * m.m[13] - m.m[5] * m.m[12];
    T s5 = m.m[8] * m.m[13] - m.m[9] * m.m[12];

    T c5 = m.m[10] * m.m[15] - m.m[11] * m.m[14];
    T c4 = m.m[6] * m.m[15] - m.m[7] * m.m[14];
    T c3 = m.m[6] * m.m[11] - m.m[7] * m.m[10];
    T c2 = m.m[2] * m.m[15] - m.m[3] * m.m[14];
    T c1 = m.m[2] * m.m[11] - m.m[3] * m.m[10];
    T c0 = m.m[2] * m.m[7] - m.m[3] * m.m[6];

    i.m.m[0]  = m.m[5]  * c5 - m.m[9] * c4 + m.m[13] * c3;
    i.m.m[1]  = -m.m[1] * c5 + m.m[9] * c2 - m.m[13] * c1;
    i.m.m[2]  = m.m[1]  * c4 - m.m[5] * c2 + m.m[13] * c0;
    i.m.m[3]  = -m.m[1] * c3 + m.m[5] * c1 - m.m[9] * c0;

    i.m.m[4]  = -m.m[4] * c5 + m.m[8] * c4 - m.m[12] * c3;
    i.m.m[5]  =  m.m[0] * c5 - m.m[8] * c2 + m.m[12] * c1;
    i.m.m[6]  = -m.m[0] * c4 + m.m[4] * c2 - m.m[12] * c0;
    i.m.m[7]  = m.m[0]  * c3 - m.m[4] * c1 + m.m[8] * c0;

    i.m.m[8]  = m.m[7]  * s5 - m.m[11] * s4 + m.m[15] * s3;
    i.m.m[9]  = -m.m[3] * s5 + m.m[11] * s2 - m.m[15] * s1;
    i.m.m[10] = m.m[3]  * s4 - m.m[7]  * s2 + m.m[15] * s0;
    i.m.m[11] = -m.m[3] * s3 + m.m[7]  * s1 - m.m[11] * s0;

    i.m.m[12] = -m.m[6] * s5 + m.m[10] * s4 - m.m[14] * s3;
    i.m.m[13] = m.m[2]  * s5 - m.m[10] * s2 + m.m[14] * s1;
    i.m.m[14] = -m.m[2] * s4 + m.m[6]  * s2 - m.m[14] * s0;
    i.m.m[15] = m.m[2]  * s3 - m.m[6]  * s1 + m.m[10] * s0;

    T invdet = 1.0 / (s0*c5 - s1*c4 + s2*c3 + s3*c2 - s4*c1 + s5*c0);

    i.m.m[0]  *= invdet;
    i.m.m[1]  *= invdet;
    i.m.m[2]  *= invdet;
    i.m.m[3]  *= invdet;
    i.m.m[4]  *= invdet;
    i.m.m[5]  *= invdet;
    i.m.m[6]  *= invdet;
    i.m.m[7]  *= invdet;
    i.m.m[8]  *= invdet;
    i.m.m[9]  *= invdet;
    i.m.m[10] *= invdet;
    i.m.m[11] *= invdet;
    i.m.m[12] *= invdet;
    i.m.m[13] *= invdet;
    i.m.m[14] *= invdet;
    i.m.m[15] *= invdet;

    return i;
  }

template <typename T>
  void inverse_eq(mat4<T>& m) {
    T s0 = m.m[0] * m.m[5] - m.m[1] * m.m[4];
    T s1 = m.m[0] * m.m[9] - m.m[1] * m.m[8];
    T s2 = m.m[0] * m.m[13] - m.m[1] * m.m[12];
    T s3 = m.m[4] * m.m[9] - m.m[5] * m.m[8];
    T s4 = m.m[4] * m.m[13] - m.m[5] * m.m[12];
    T s5 = m.m[8] * m.m[13] - m.m[9] * m.m[12];

    T c5 = m.m[10] * m.m[15] - m.m[11] * m.m[14];
    T c4 = m.m[6] * m.m[15] - m.m[7] * m.m[14];
    T c3 = m.m[6] * m.m[11] - m.m[7] * m.m[10];
    T c2 = m.m[2] * m.m[15] - m.m[3] * m.m[14];
    T c1 = m.m[2] * m.m[11] - m.m[3] * m.m[10];
    T c0 = m.m[2] * m.m[7] - m.m[3] * m.m[6];

    T ta = m.m[0];
    T tb = m.m[5];
    T tc = m.m[6];
    T td = m.m[7];
    T te = m.m[3];
    T tf = m.m[13];

    m.m[0]  =  tb  * c5 - m.m[9] * c4 + m.m[13] * c3;
    m.m[5]  =  ta    * c5 - m.m[8] * c2 + m.m[12] * c1;
    m.m[6]  = -ta    * c4 + m.m[4] * c2 - m.m[12] * c0;
    m.m[7]  =  ta    * c3 - m.m[4] * c1 + m.m[8] * c0;

    ta = m.m[2];

    m.m[2]  = m.m[1]  * c4 - tb * c2 + m.m[13] * c0;
    m.m[3]  = -m.m[1] * c3 + tb * c1 - m.m[9] * c0;

    tb = m.m[12];

    m.m[12] = -tc    * s5 + m.m[10] * s4 - m.m[14] * s3;
    m.m[4]  = -m.m[4] * c5 + m.m[8] * c4 - tb * c3;

    tb = m.m[14];

    m.m[14] = -ta * s4 + tc  * s2 - m.m[14] * s0;
    m.m[13] = ta  * s5 - m.m[10] * s2 + tb * s1;
    m.m[1]  = -m.m[1] * c5 + m.m[9] * c2 - tf * c1;

    tb = m.m[15];
    m.m[15] = ta  * s3 - tc  * s1 + m.m[10] * s0;

    m.m[9]  = -te * s5 + m.m[11] * s2 - tb * s1;
    m.m[8]  = td  * s5 - m.m[11] * s4 + tb * s3;
    m.m[11] = -te * s3 + td  * s1 - m.m[11] * s0;
    m.m[10] = te  * s4 - td  * s2 + tb * s0;

    T invdet = 1.0 / (s0*c5 - s1*c4 + s2*c3 + s3*c2 - s4*c1 + s5*c0);

    m.m[0]  *= invdet;
    m.m[1]  *= invdet;
    m.m[2]  *= invdet;
    m.m[3]  *= invdet;
    m.m[4]  *= invdet;
    m.m[5]  *= invdet;
    m.m[6]  *= invdet;
    m.m[7]  *= invdet;
    m.m[8]  *= invdet;
    m.m[9]  *= invdet;
    m.m[10] *= invdet;
    m.m[11] *= invdet;
    m.m[12] *= invdet;
    m.m[13] *= invdet;
    m.m[14] *= invdet;
    m.m[15] *= invdet;
  }

template <typename T>
  void l_mult_eq(mat4<T>& M7_RESTRICT m, const mat4<T>& M7_RESTRICT l) {
    m7assert(&m != &l);
    T ta = m.m[0];
    T tb = m.m[1];
    T tc = m.m[2];

    m.m[0] = l[0] * ta + l[4] * tb + l[8] * tc + l[12] * m.m[3];
    m.m[1] = l[1] * ta + l[5] * tb + l[9] * tc + l[13] * m.m[3];
    m.m[2] = l[2] * ta + l[6] * tb + l[10] * tc + l[14] * m.m[3];
    m.m[3] = l[3] * ta + l[7] * tb + l[11] * tc + l[15] * m.m[3];

    ta = m.m[4];
    tb = m.m[5];
    tc = m.m[6];

    m.m[4] = l[0] * ta + l[4] * tb + l[8] * tc + l[12] * m.m[7];
    m.m[5] = l[1] * ta + l[5] * tb + l[9] * tc + l[13] * m.m[7];
    m.m[6] = l[2] * ta + l[6] * tb + l[10] * tc + l[14] * m.m[7];
    m.m[7] = l[3] * ta + l[7] * tb + l[11] * tc + l[15] * m.m[7];

    ta = m.m[8];
    tb = m.m[9];
    tc = m.m[10];

    m.m[8] = l[0] * ta + l[4] * tb + l[8] * tc + l[12] * m.m[11];
    m.m[9] = l[1] * ta + l[5] * tb + l[9] * tc + l[13] * m.m[11];
    m.m[10] = l[2] * ta + l[6] * tb + l[10] * tc + l[14] * m.m[11];
    m.m[11] = l[3] * ta + l[7] * tb + l[11] * tc + l[15] * m.m[11];

    ta = m.m[12];
    tb = m.m[13];
    tc = m.m[14];

    m.m[12] = l[0] * ta + l[4] * tb + l[8] * tc + l[12] * m.m[15];
    m.m[13] = l[1] * ta + l[5] * tb + l[9] * tc + l[13] * m.m[15];
    m.m[14] = l[2] * ta + l[6] * tb + l[10] * tc + l[14] * m.m[15];
    m.m[15] = l[3] * ta + l[7] * tb + l[11] * tc + l[15] * m.m[15];
  }

template <typename T>
  void r_mult_eq(mat4<T>& M7_RESTRICT m, const mat4<T>& M7_RESTRICT r) {
    m7assert(&m != &r);
    T ta = m.m[0];
    T tb = m.m[4];
    T tc = m.m[8];
    m.m[0] = ta * r[0] + tb * r[1] + tc * r[2] + m.m[12] * r[3];
    m.m[4] = ta * r[4] + tb * r[5] + tc * r[6] + m.m[12] * r[7];
    m.m[8] = ta * r[8] + tb * r[9] + tc * r[10] + m.m[12] * r[11];
    m.m[12] = ta * r[12] + tb * r[13] + tc * r[14] + m.m[12] * r[15];

    ta = m.m[1];
    tb = m.m[5];
    tc = m.m[9];
    m.m[1] = ta * r[0] + tb * r[1] + tc * r[2] + m.m[13] * r[3];
    m.m[5] = ta * r[4] + tb * r[5] + tc * r[6] + m.m[13] * r[7];
    m.m[9] = ta * r[8] + tb * r[9] + tc * r[10] + m.m[13] * r[11];
    m.m[13] = ta * r[12] + tb * r[13] + tc * r[14] + m.m[13] * r[15];

    ta = m.m[2];
    tb = m.m[6];
    tc = m.m[10];
    m.m[2] = ta * r[0] + tb * r[1] + tc * r[2] + m.m[14] * r[3];
    m.m[6] = ta * r[4] + tb * r[5] + tc * r[6] + m.m[14] * r[7];
    m.m[10] = ta * r[8] + tb * r[9] + tc * r[10] + m.m[14] * r[11];
    m.m[14] = ta * r[12] + tb * r[13] + tc * r[14] + m.m[14] * r[15];

    ta = m.m[3];
    tb = m.m[7];
    tc = m.m[11];
    m.m[3] = ta * r[0] + tb * r[1] + tc * r[2] + m.m[15] * r[3];
    m.m[7] = ta * r[4] + tb * r[5] + tc * r[6] + m.m[15] * r[7];
    m.m[11] = ta * r[8] + tb * r[9] + tc * r[10] + m.m[15] * r[11];
    m.m[15] = ta * r[12] + tb * r[13] + tc * r[14] + m.m[15] * r[15];
  }
template <typename T>
  void l_mult_transpose_eq(mat4<T>& m, const mat4<T>& l) {
    T ta = m.m[0];
    T tb = m.m[1];
    T tc = m.m[2];

    m.m[0] = l[0] * ta + l[1] * tb + l[2] * tc + l[3] * m.m[3];
    m.m[1] = l[4] * ta + l[5] * tb + l[6] * tc + l[7] * m.m[3];
    m.m[2] = l[8] * ta + l[9] * tb + l[10] * tc + l[11] * m.m[3];
    m.m[3] = l[12] * ta + l[13] * tb + l[14] * tc + l[15] * m.m[3];

    ta = m.m[4];
    tb = m.m[5];
    tc = m.m[6];

    m.m[4] = l[0] * ta + l[1] * tb + l[2] * tc + l[3] * m.m[7];
    m.m[5] = l[4] * ta + l[5] * tb + l[6] * tc + l[7] * m.m[7];
    m.m[6] = l[8] * ta + l[9] * tb + l[10] * tc + l[11] * m.m[7];
    m.m[7] = l[12] * ta + l[13] * tb + l[14] * tc + l[15] * m.m[7];

    ta = m.m[8];
    tb = m.m[9];
    tc = m.m[10];

    m.m[8] = l[0] * ta + l[1] * tb + l[2] * tc + l[3] * m.m[11];
    m.m[9] = l[4] * ta + l[5] * tb + l[6] * tc + l[7] * m.m[11];
    m.m[10] = l[8] * ta + l[9] * tb + l[10] * tc + l[11] * m.m[11];
    m.m[11] = l[12] * ta + l[13] * tb + l[14] * tc + l[15] * m.m[11];

    ta = m.m[12];
    tb = m.m[13];
    tc = m.m[14];

    m.m[12] = l[0] * ta + l[1] * tb + l[2] * tc + l[3] * m.m[15];
    m.m[13] = l[4] * ta + l[5] * tb + l[6] * tc + l[7] * m.m[15];
    m.m[14] = l[8] * ta + l[9] * tb + l[10] * tc + l[11] * m.m[15];
    m.m[15] = l[12] * ta + l[13] * tb + l[14] * tc + l[15] * m.m[15];
  }

template <typename T>
  void r_mult_transpose_eq(mat4<T>& m, const mat4<T>& r) {
    T ta = m.m[0];
    T tb = m.m[4];
    T tc = m.m[8];
    m.m[0] = ta * r[0] + tb * r[4] + tc * r[8] + m.m[12] * r[12];
    m.m[4] = ta * r[1] + tb * r[5] + tc * r[9] + m.m[12] * r[13];
    m.m[8] = ta * r[2] + tb * r[6] + tc * r[10] + m.m[12] * r[14];
    m.m[12] = ta * r[3] + tb * r[7] + tc * r[11] + m.m[12] * r[15];

    ta = m.m[1];
    tb = m.m[5];
    tc = m.m[9];
    m.m[1] = ta * r[0] + tb * r[4] + tc * r[8] + m.m[13] * r[12];
    m.m[5] = ta * r[1] + tb * r[5] + tc * r[9] + m.m[13] * r[13];
    m.m[9] = ta * r[2] + tb * r[6] + tc * r[10] + m.m[13] * r[14];
    m.m[13] = ta * r[3] + tb * r[7] + tc * r[11] + m.m[13] * r[15];

    ta = m.m[2];
    tb = m.m[6];
    tc = m.m[10];
    m.m[2] = ta * r[0] + tb * r[4] + tc * r[8] + m.m[14] * r[12];
    m.m[6] = ta * r[1] + tb * r[5] + tc * r[9] + m.m[14] * r[13];
    m.m[10] = ta * r[2] + tb * r[6] + tc * r[10] + m.m[14] * r[14];
    m.m[14] = ta * r[3] + tb * r[7] + tc * r[11] + m.m[14] * r[15];

    ta = m.m[3];
    tb = m.m[7];
    tc = m.m[11];
    m.m[3] = ta * r[0] + tb * r[4] + tc * r[8] + m.m[15] * r[12];
    m.m[7] = ta * r[1] + tb * r[5] + tc * r[9] + m.m[15] * r[13];
    m.m[11] = ta * r[2] + tb * r[6] + tc * r[10] + m.m[15] * r[14];
    m.m[15] = ta * r[3] + tb * r[7] + tc * r[11] + m.m[15] * r[15];
  }

template <typename T>
  void l_mult_eq(vec4<T>& M7_RESTRICT v, const mat4<T>& M7_RESTRICT l) {
  }
};
};

#define MTYPE mat4
#define VTYPE vec4
#include <m7/math/_internal/common.hh>
#include <m7/math/_internal/common.hh>
#include <m7/math/_internal/mat_common.hh>
#include <m7/math/_internal/mat_common.hh>
#undef MTYPE
#undef VTYPE


#endif
