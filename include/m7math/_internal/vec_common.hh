#ifndef MTYPE
#error Do not include this header directly!!
#endif

namespace m7 {
namespace math {

template <typename T>
MTYPE<T> length2(const MTYPE<T>& m) {
  T len = 0;
  for(int i = 0; i < MTYPE<T>::size; ++i) {
    len += m[i] * m[i];
  }
  return len;
}

template <typename T>
MTYPE<T> length(const MTYPE<T>& m) {
  return sqrt(length2(m));
}

//Return normalized vector
template <typename T>
  inline MTYPE<T> normal(const MTYPE<T>& v) {
    MTYPE<T> res;
    T l = length(v);
    for(int i = 0; i < MTYPE<T>::size; ++i) {
      res[i] = v[i] / l;
    }
    return res;
  }

//Normalize this vector
template <typename T>
  inline void normalize(MTYPE<T>& v) {
    T l = length(v);
    for(int i = 0; i < MTYPE<T>::size; ++i) {
      v[i] /= l;
    }
  }

//Dot product
template <typename T>
  inline T dot(const MTYPE<T>& l, const MTYPE<T>& r)
  {
    T d = 0;
    for(int i = 0; i < MTYPE<T>::size; ++i) {
      d += l[i] * r[i];
    }
    return d;
  }

//Distance squared
template <typename T>
  T dist2(const MTYPE<T>& l, const MTYPE<T>& r) {
    T d = 0;
    for(int i = 0; i < MTYPE<T>::size; ++i) {
      T x = l[i] - r[i];
      d += x * x;
    }
    return d;
  }

//Distance
template <typename T>
  inline T dist(const MTYPE<T>& l, const MTYPE<T>& r) {
    return sqrt(dist2(l, r));
  }

//Angle between 2 vectors
template <typename T>
  T angle(const MTYPE<T>& l, const MTYPE<T>& r) {
    return acos(dot(l, r) / (length(l) * length(r)));
  }

//Angle between 2 unit vectors
template <typename T>
  T angle_unit(const MTYPE<T>& l, const MTYPE<T>& r) {
    return acos(dot(l, r));
  }

//Scalar projection
template <typename T>
  T scalar_project(const MTYPE<T>& v, T angle) {
    return length(v) * cos(angle);
  }

//Scalar projection
template <typename T>
  T scalar_project(const MTYPE<T>& vec, const MTYPE<T>& onto) {
    return dot(vec, onto) / length(onto);
  }

//Scalar projection of unit vectors
template <typename T>
  T scalar_project_unit(const MTYPE<T>& vec, const MTYPE<T>& onto) {
    return dot(vec, onto);
  }

//Vector projection
template <typename T>
  MTYPE<T> vector_project(const MTYPE<T>& vec, const MTYPE<T>& onto) {
    return  (dot(vec, onto) / length2(onto)) * onto;
  }

template <typename T>
  MTYPE<T> vector_project_unit(const MTYPE<T>& vec, const MTYPE<T>& onto) {
    return  dot(vec, onto) * onto;
  }
template <typename T>
  inline MTYPE<T> vector_reject(const MTYPE<T>& vec, const MTYPE<T>& onto) {
    return vec - vector_project(vec, onto);
  }
template <typename T>
  inline MTYPE<T> vector_reject_unit(const MTYPE<T>& vec, const MTYPE<T>& onto) {
    return vec - vector_project_unit(vec, onto);
  }

};
};
