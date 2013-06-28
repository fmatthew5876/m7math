//Operators should be operatorfoo(const Bar& l, const Bar& r)
//RVO does not work with function parameters
//Centralizes copy operations
//
//FIXME: Figure out pass by value or by const reference??
//FIXME: Does this depend on the arch??
//FIXME: Does not matter if inlined
//FIXME: Also configure inline??
#ifndef MTYPE
#error Do not include this header directly!!
#endif

#include <type_traits>

namespace m7 {
namespace math {

template <typename T>
  inline void make_zero(MTYPE<T>& m) {
    for(int i = 0; i < MTYPE<T>::size; ++i) {
      m.m[i] = 0;
    }
  }

template <typename T>
  inline void copy(MTYPE<T>& m, T* p) {
    for(int i = 0; i < MTYPE<T>::size; ++i) {
      m.m[i] = p[i];
    }
  }

template <typename T>
  inline T* begin(MTYPE<T>& m) {
    return m.ptr();
  }

template <typename T>
  inline const T* begin(const MTYPE<T>& m) {
    return m.ptr();
  }

template <typename T>
  inline T* end(MTYPE<T>& m) {
    return m.ptr() + MTYPE<T>::size;
  }

template <typename T>
  inline const T* end(const MTYPE<T>& m) {
    return m.ptr() + MTYPE<T>::size;
  }

#define MAKE_OP_M(X) \
template <typename T>\
MTYPE<T> operator X(const MTYPE<T>& m) {\
  MTYPE<T> res;\
  for(int i = 0; i < MTYPE<T>::size; ++i) {\
    res.m[i] = X m.m[i];\
  }\
  return res;\
} \
namespace

#define MAKE_OP_MM(X)\
  template <typename T>\
MTYPE<T> operator X(const MTYPE<T>& l, const MTYPE<T>& r) {\
  MTYPE<T> res;\
  for(int i = 0; i < MTYPE<T>::size; ++i) {\
    res.m[i] = l.m[i] X r.m[i];\
  }\
  return res;\
}\
namespace

#define MAKE_OP_MT(X)\
  template <typename T>\
MTYPE<T> operator X(const MTYPE<T>& l, typename MTYPE<T>::value_type r) {\
  MTYPE<T> res;\
  for(int i = 0; i < MTYPE<T>::size; ++i) {\
    res.m[i] = l.m[i] X r;\
  }\
  return res;\
}\
namespace

#define MAKE_OP_TM(X)\
  template <typename T>\
MTYPE<T> operator X(typename MTYPE<T>::value_type l, const MTYPE<T>& r) {\
  MTYPE<T> res;\
  for(int i = 0; i < MTYPE<T>::size; ++i) {\
    res.m[i] = l X r.m[i];\
  }\
  return res;\
}\
namespace

//Unary plus
MAKE_OP_M(+) {}

//Negation
MAKE_OP_M(-) {}

//Component wise addition
MAKE_OP_MM(+) {}
MAKE_OP_MM(-) {}

MAKE_OP_MT(*) {}
MAKE_OP_TM(*) {}

MAKE_OP_MT(/) {}
MAKE_OP_TM(/) {}

MAKE_OP_MT(%) {}
MAKE_OP_TM(%) {}

MAKE_OP_MM(&) {}
MAKE_OP_MT(&) {}
MAKE_OP_TM(&) {}

MAKE_OP_MM(|) {}
MAKE_OP_MT(|) {}
MAKE_OP_TM(|) {}

MAKE_OP_MM(^) {}
MAKE_OP_MT(^) {}
MAKE_OP_TM(^) {}

MAKE_OP_M(~) {}

MAKE_OP_MT(<<) {}
MAKE_OP_MT(>>) {}

#undef MAKE_OP_M
#undef MAKE_OP_MM
#undef MAKE_OP_MT
#undef MAKE_OP_TM

#define MAKE_OPEQ_M(X) \
  template <typename T>\
MTYPE<T>& operator X(MTYPE<T>& l, const MTYPE<T>& r) \
{\
  for(int i = 0; i < MTYPE<T>::size; ++i) {\
    l.m[i] X r.m[i];\
  }\
  return l;\
}\
namespace

#define MAKE_OPEQ_T(X) \
  template <typename T>\
MTYPE<T>& operator X(MTYPE<T>& l, T r) \
{\
  for(int i = 0; i < MTYPE<T>::size; ++i) {\
    l.m[i] X r;\
  }\
  return l;\
}\
namespace

MAKE_OPEQ_M(+=) {}
MAKE_OPEQ_M(-=) {}

MAKE_OPEQ_T(*=) {}
MAKE_OPEQ_T(/=) {}

MAKE_OPEQ_T(%=) {}

MAKE_OPEQ_T(>>=) {}
MAKE_OPEQ_T(<<=) {}
MAKE_OPEQ_T(&=) {}
MAKE_OPEQ_T(^=) {}
MAKE_OPEQ_T(|=) {}

MAKE_OPEQ_M(&=) {}
MAKE_OPEQ_M(^=) {}
MAKE_OPEQ_M(|=) {}

#undef MAKE_OPEQ_M
#undef MAKE_OPEQ_T

template <typename T>
bool operator==(const MTYPE<T>& l, const MTYPE<T>& r) {
  for(int i = 0; i < MTYPE<T>::size; ++i) {
    if(l.m[i] != r.m[i]) {
      return false;
    }
  }
  return true;
}

template <typename T>
bool operator!=(const MTYPE<T>& l, const MTYPE<T>& r) {
  for(int i = 0; i < MTYPE<T>::size; ++i) {
    if(l.m[i] == r.m[i]) {
      return false;
    }
  }
  return true;
}

#define MAKE_COMP_WISE(N, X) \
template <typename T>\
MTYPE<T> comp_wise_##N(const MTYPE<T>& l, const MTYPE<T>& r) {\
  MTYPE<T> res;\
  for(int i = 0; i < MTYPE<T>::size; ++i) {\
    res.m[i] = l.m[i] X r.m[i];\
  }\
  return res;\
}\
namespace

MAKE_COMP_WISE(mult, *) {}
MAKE_COMP_WISE(div, /) {}

#undef MAKE_COMP_WISE

template <typename T>
void comp_wise_mult_eq(MTYPE<T>& l, const MTYPE<T>& r) {
  for(int i = 0; i < MTYPE<T>::size; ++i) {
    l.m[i] *= r.m[i];
  }
}

template <typename T>
void comp_wise_div_eq(MTYPE<T>& l, const MTYPE<T>& r) {
  for(int i = 0; i < MTYPE<T>::size; ++i) {
    l.m[i] /= r.m[i];
  }
}

};
};
