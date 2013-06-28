#ifndef M7_MATH_TYPES_HPP
#define M7_MATH_TYPES_HPP

#include <initializer_list>
#include <type_traits>

#include <m7/config.hh>
#include <m7/config.hh>

//FIXME: Experiment with alignas(16) for vectorization when it becomes available
//FIXME: If we use alignas() we will break Affine structs!
//FIXME: We also break unions!

namespace m7 {

///The math namespace, containing math functions and classes.
///This namespace contains template functions and classes for 
///basic linear algebra used in graphics programming.
namespace math {
template <typename T>
  ///A linear algebra vector containing 2 elements of type T.
  ///This class has value symmantics. It contains only its elements and can be converted to and from a pointer.
  struct vec2 {
    enum Constants {
      size = 2, ///< Number of elements stored in this object
    };

    typedef T value_type; ///< Typedef to T

    ///Default uninitialized constructor
    vec2() = default;

    ///Initialize all members to v
    explicit vec2(T v) : m{v, v} {}

    ///Initialize [v[0], v[1]], v must point to at least 2 T's
    explicit vec2(const T* v) : m{v[0], v[1]} {}

    ///Initialize to [xx, yy]
    vec2(T xx, T yy) : m{xx, yy} {}

    ///Initialize from initializer list. Must be of size 2.
    vec2(const std::initializer_list<T>& l) {
      static_assert(l.size() == 2, "Initializer list for vec2 must be of size 2!");
      int i = 0;
      for(auto& v : l) {
        m[i++] = v;
      }
    }

    ///Copy constructor.
    vec2(const vec2<T>& v) = default;

    ///Assignment.
    vec2<T>& operator=(const vec2<T>& v) = default; ///< default assignment operator

    ///Return element i.
    T& operator[](int i) { m7assert(i >= 0 && i < 2); return m[i]; }

    ///Return element i.
    const T& operator[](int i) const { m7assert(i >= 0 && i < 2); return m[i]; }

    ///Return pointer to element storage.
    T* ptr() { return m; }
    ///Return pointer to element storage.
    const T* ptr() const { return m; }

    ///Copy v into this.
    void set(const vec2<T>& v) { *this = v; }

    ///Set elements to [xx, yy].
    void set(T xx, T yy) { m[0] = xx; m[1] = yy; }

    ///Set elements to [v[0], v[1]], v must point to at least 2 T's.
    void set(const T* v) { m[0] = v[0]; m[1] = v[1]; }

    union {
      T m[vec2<T>::size]; ///< Array element access
      struct {
        T x; ///< Alias to the first element
        T y; ///< Alias to the second element
      };
      struct {
        T r; ///< Alias to the first element
        T g; ///< Alias to the second element
      };
      struct {
        T u; ///< Alias to the first element
        T v; ///< Alias to the second element
      };
    };
  };

typedef vec2<float> vec2f;
typedef vec2<double> vec2d;
typedef vec2<int> vec2i;
typedef vec2<unsigned int> vec2ui;
typedef vec2<short> vec2s;
typedef vec2<unsigned short> vec2us;
typedef vec2<char> vec2b;
typedef vec2<unsigned char> vec2ub;

template <typename T>
  struct vec3 {
    enum Constants {
      size = 3,
    };
    typedef T value_type;

    vec3() = default;
    explicit vec3(T v) : m{v, v, v} {}
    explicit vec3(const T* v) : m{v[0], v[1], v[2]} {}
    vec3(T xx, T yy, T zz) : m{xx, yy, zz} {}
    vec3(const vec2<T>& xy, T zz) : m{xy.m[0], xy.m[1], zz} {}
    vec3(T xx, const vec2<T>& yz) : m{xx, yz.m[0], yz.m[1]} {}
    vec3(const std::initializer_list<T>& l) {
      static_assert(l.size() == 3, "Initializer list for vec3 must be of size 3!");
      int i = 0;
      for(auto& v : l) {
        m[i++] = v;
      }
    }

    vec3(const vec3<T>&) = default;
    vec3& operator=(const vec3<T>&) = default;

    T& operator[](int i) { m7assert(i >= 0 && i < 3); return m[i]; }
    const T& operator[](int i) const { m7assert(i >= 0 && i < 3); return m[i]; }

    T* ptr() { return m; }
    const T* ptr() const { return m; }

    void set(T v) { m[0] = m[1] = m[2] = v; }
    void set(const T* v) { memcpy(m, v, sizeof(m)); }
    void set(T xx, T yy, T zz) { m[0] = xx; m[1] = yy; m[2] = zz; }
    void set(const vec2<T>& xy, T zz) { m[0] = xy[0]; m[1] = xy[1]; m[2] = zz; }
    void set(T xx, const vec2<T>& yz) { m[0] = xx; m[1] = yz[0]; m[2] = yz[1]; }
    void set(const vec2<T>& xyz) { *this = xyz; }

    union {
      T m[vec3<T>::size];
      vec2<T> xy;
      struct {
        T x;
        union {
          struct {
            T y;
            T z;
          };
          vec2<T> yz;
        };
      };
      vec2<T> rg;
      struct {
        T r;
        union {
          vec2<T> gb;
          struct {
            T g;
            T b;
          };
        };
      };
      vec2<T> uv;
      struct {
        T u;
        union {
          vec2<T> vs;
          struct {
            T v;
            T s;
          };
        };
      };
    };
  };

typedef vec3<float> vec3f;
typedef vec3<double> vec3d;
typedef vec3<int> vec3i;
typedef vec3<unsigned int> vec3ui;
typedef vec3<short> vec3s;
typedef vec3<unsigned short> vec3us;
typedef vec3<char> vec3b;
typedef vec3<unsigned char> vec3ub;

template <typename T>
  struct vec4 {
    enum Constants {
      size = 4,
    };
    typedef T value_type;

    vec4() = default;
    explicit vec4(T v) : m{v, v, v, v} {}
    vec4(T xx, T yy, T zz, T ww) : m{xx, yy, zz, ww} {}
    vec4(const vec2<T>& xy, T zz, T ww) : m{xy.m[0], xy.m[1], zz, ww} {}
    vec4(T xx, const vec2<T>& yz, T ww) : m{xx, yz.m[0], yz.m[1], ww} {}
    vec4(T xx, T yy, const vec2<T>& zw) : m{xx, yy, zw.m[0], zw.m[1]} {}
    vec4(const vec2<T>& xy, const vec2<T>& zw) : m{xy.m[0], xy.m[1], zw.m[0], zw.m[1]} {}
    vec4(const vec3<T>& xyz, T ww) : m{xyz.m[0], xyz.m[1], xyz[2], ww} {}
    vec4(T xx, const vec3<T>& yzw) : m{xx, yzw.m[0], yzw.m[1], yzw.m[2]} {}
    explicit vec4(const T* v) : m{v[0], v[1], v[2], v[3]} {}

    vec4(const vec4<T>&) = default;
    vec4& operator=(const vec4<T>&) = default;

    vec4(const std::initializer_list<T>& l) {
      static_assert(l.size() == 4, "Initializer list for vec4 must be of size 4!");
      int i = 0;
      for(auto& v : l) {
        m[i++] = v;
      }
    }

    T& operator[](int i) { m7assert(i >= 0 && i < 4); return m[i]; }
    const T& operator[](int i) const { m7assert(i >= 0 && i < 4); return m[i]; }

    T* ptr() { return m; }
    const T* ptr() const { return m; }

    void set(T v) { m[0] = m[1] = m[2] = m[3] = v; }
    void set(const T* v) { memcpy(m, v, sizeof(m)); }
    void set(T xx, T yy, T zz, T ww) { m[0] = xx; m[1] = yy; m[2] = zz; m[3] = ww; }
    void set(const vec2<T>& xy, T zz, T ww) { m[0] = xy[0]; m[1] = xy[2]; m[2] = zz; m[3] = ww; }
    void set(T xx, const vec2<T>& yz, T ww) { m[0] = xx; m[1] = yz[0]; m[2] = yz[2]; m[3] = ww; }
    void set(T xx, T yy, const vec2<T>& zw) { m[0] = xx; m[1] = yy; m[2] = zw[0]; m[3] = zw[1]; }
    void set(const vec2<T>& xy, const vec2<T>& zw) { m[0] = xy[0]; m[1] = xy[1]; m[2] = zw[0]; m[3] = zw[1]; }
    void set(const vec3<T>& xyz, T ww) { m[0] = xyz[0]; m[1] = xyz[1]; m[2] = xyz[2]; m[3] = ww; }
    void set(T xx, const vec3<T>& xyz) { m[0] = xx; m[1] = xyz[0]; m[2] = xyz[1]; m[3] = xyz[2]; }
    void set(const vec4<T>& xyzw) { *this = xyzw; }

    union {
      T m[vec4<T>::size];
      vec3<T> xyz;
      vec2<T> xy;
      struct {
        T x;
        union {
          vec3<T> yzw;
          vec2<T> yz;
          struct {
            T y;
            union {
              vec2<T> zw;
              struct {
                T z;
                T w;
              };
            };
          };
        };
      };
      vec3<T> rgb;
      vec2<T> rb;
      struct {
        T r;
        union {
          vec3<T> gba;
          vec2<T> gb;
          struct {
            T g;
            union {
              vec2<T> ba;
              struct {
                T b;
                T a;
              };
            };
          };
        };
      };
      vec3<T> uvs;
      vec2<T> uv;
      struct {
        T u;
        union {
          vec3<T> vst;
          vec2<T> vs;
          struct {
            T v;
            union {
              vec2<T> st;
              struct {
                T s;
                T t;
              };
            };
          };
        };
      };
    };
  };

typedef vec4<float> vec4f;
typedef vec4<double> vec4d;
typedef vec4<int> vec4i;
typedef vec4<unsigned int> vec4ui;
typedef vec4<short> vec4s;
typedef vec4<unsigned short> vec4us;
typedef vec4<char> vec4b;
typedef vec4<unsigned char> vec4ub;

template <typename T>
  struct mat2 {
    enum Constants {
      size = 4,
      num_cols = 2,
      num_rows = 2,
    };
    typedef T value_type;

    mat2() = default;
    explicit mat2(T v) : m{v, v, v, v} {}
    mat2(T m0, T m1, T m2, T m3) : m{m0, m1, m2, m3} {}
    mat2(const vec2<T>& v0, const vec2<T>& v1) : cv{v0, v1} {}
    explicit mat2(const T* mm) : m{mm[0], mm[1], mm[2], mm[3]} {}

    mat2(const std::initializer_list<T>& l) {
      static_assert(l.size() == 4, "Initializer_list<T> for mat2 must be of size 4!");
      int i = 0;
      for(auto& v : l) {
        m[i++] = v;
      }
    }
    mat2(const std::initializer_list<vec2<T>>& l) {
      static_assert(l.size() == 2, "Initializer_list<vec2<T>> for mat2 must be of size 2!");
      int i = 0;
      for(auto& v : l) {
        cv[i++] = v;
      }
    }

    mat2(const mat2&) = default;
    mat2& operator=(const mat2&) = default;

    T& operator[](int i) { m7assert(i >= 0 && i < 4); return m[i]; }
    const T& operator[](int i) const { m7assert(i >= 0 && i < 4); return m[i]; }

    T& get(int col, int row) { m7assert(col >= 0 && col < num_cols); m7assert(row >= 0 && row < num_rows); return mn[col][row]; }
    const T& get(int col, int row) const { m7assert(col >= 0 && col < num_cols); m7assert(row >= 0 && row < num_rows); return mn[col][row]; }

    T* ptr() { return m; }
    const T* ptr() const { return m; }

    vec2<T>& col_alias(int i) { m7assert(i >= 0 && i < 2); return cv[i]; }
    const vec2<T>& col_alias(int i) const { m7assert(i >= 0 && i < 2); return cv[i]; }

    vec2<T> col(int i) const { m7assert(i >= 0 && i < 2); return cv[i]; }
    vec2<T> row(int i) const { m7assert(i >= 0 && i < 2); return vec2<T>(m[i], m[2+i]); }

    void set(T v) { m[0] = m[1] = m[2] = m[3] = v; }
    void set(T m0, T m1, T m2, T m3) { m[0] = m0; m[1] = m1; m[2] = m2; m[3] = m3; }
    void set(const vec2<T>& v0, const vec2<T>& v1) { cv[0] = v0; cv[1] = v1; }
    void set(const T* mm) { memcpy(m, mm, sizeof(m)); }

    union {
      T m[4];
      T mn[2][2];
      vec2<T> cv[2];
    };

  };

#define MAT2_IDENTITY { 1, 0,  0, 1 }

typedef mat2<float> mat2f;
typedef mat2<double> mat2d;
typedef mat2<int> mat2i;
typedef mat2<unsigned int> mat2ui;
typedef mat2<short> mat2s;
typedef mat2<unsigned short> mat2us;
typedef mat2<char> mat2b;
typedef mat2<unsigned char> mat2ub;

template <typename T>
  struct mat3 {
    enum Constants {
      size = 9,
      num_cols = 3,
      num_rows = 3,
    };
    typedef T value_type;

    mat3() = default;
    explicit mat3(T v)
      : m{v, v, v, v, v, v, v, v} {}
    mat3(T m0, T m1, T m2, T m3, T m4, T m5, T m6, T m7, T m8)
      : m{m0, m1, m2, m3, m4, m5, m6, m7, m8} {}
    mat3(const vec3<T>& v0, const vec3<T>& v1, const vec3<T>& v2)
      : cv{v0, v1, v2} {}
    mat3(const T* mm)
      : m{mm[0], mm[1], mm[2], mm[3], mm[4], mm[5], mm[6], mm[7], mm[8]} {}

    mat3(const std::initializer_list<T>& l) {
      static_assert(l.size() == 9, "Initializer_list<T> for mat3 must be of size 9!");
      int i = 0;
      for(auto& v : l) {
        m[i++] = v;
      }
    }
    mat3(const std::initializer_list<vec3<T>>& l) {
      static_assert(l.size() == 3, "Initializer_list<vec3<T>> for mat3 must be of size 3!");
      int i = 0;
      for(auto& v : l) {
        cv[i++] = v;
      }
    }

    mat3(const mat3<T>&) = default;
    mat3& operator=(const mat3<T>&) = default;

    T& get(int col, int row) { m7assert(col >= 0 && col < num_cols); m7assert(row >= 0 && row < num_rows); return mn[col][row]; }
    const T& get(int col, int row) const { m7assert(col >= 0 && col < num_cols); m7assert(row >= 0 && row < num_rows); return mn[col][row]; }

    T& operator[](int i) { m7assert(i >= 0 && i < 9); return m[i]; }
    const T& operator[](int i) const { m7assert(i >= 0 && i < 9); return m[i]; }

    T* ptr() { return m; }
    const T* ptr() const { return m; }

    void set(T v) { m[0] = m[1] = m[2] = m[3] = m[4] = m[5] = m[6] = m[7] = m[8] = v; }
    void set(T m0, T m1, T m2, T m3, T m4, T m5, T m6, T m7, T m8) {
      m[0] = m0; m[1] = m1; m[2] = m2;
      m[3] = m3; m[4] = m4; m[5] = m5;
      m[6] = m6; m[7] = m7; m[8] = m8;
    }
    void set(const vec3<T>& v0, const vec3<T>& v1, const vec3<T>& v2) { cv[0] = v0; cv[1] = v1; cv[2] = v2; }
    void set(const T* v) { memcpy(m, v, sizeof(m)); }

    vec3<T>& col_alias(int i) { m7assert(i >= 0 && i < 3); return cv[i]; }
    const vec3<T>& col_alias(int i) const { m7assert(i >= 0 && i < 3); return cv[i]; }

    vec3<T> col(int i) const { m7assert(i >= 0 && i < 3); return cv[i]; }
    vec3<T> row(int i) const { m7assert(i >= 0 && i < 3); return vec3<T>(m[i], m[3+i], m[6+i]); }

    union {
      T m[9];
      T mn[3][3];
      vec3<T> cv[3];
    };
  };

#define MAT3_IDENTITY { 1, 0, 0,  0, 1, 0,  0, 0, 1 }

typedef mat3<float> mat3f;
typedef mat3<double> mat3d;
typedef mat3<int> mat3i;
typedef mat3<unsigned int> mat3ui;
typedef mat3<short> mat3s;
typedef mat3<unsigned short> mat3us;
typedef mat3<char> mat3b;
typedef mat3<unsigned char> mat3ub;

template <typename T>
  struct mat4 {
    enum Constants {
      size = 16,
      num_cols = 4,
      num_rows = 4,
    };
    typedef T value_type;

    mat4() = default;
    explicit mat4(T v)
      : m{v, v, v, v,
        v, v, v, v,
        v ,v, v, v,
        v, v, v, v} {}
    mat4(T m0, T m1, T m2, T m3,
        T m4, T m5, T m6, T m7,
        T m8, T m9, T m10, T m11,
        T m12, T m13, T m14, T m15)
      : m{m0, m1, m2, m3, m4, m5, m6, m7, m8,
        m9, m10, m11, m12, m13, m14, m15} {}
    mat4(const vec4<T>& v0, const vec4<T>& v1,
        const vec4<T>& v2, const vec4<T>& v3)
      : cv{v0, v1, v2, v3} {}
    explicit mat4(const T* mm)
      : m{mm[0], mm[1], mm[2], mm[3], mm[4], mm[5], mm[6], mm[7], mm[8],
        mm[9], mm[10], mm[11], mm[12], mm[13], mm[14], mm[15] } {}

    mat4(const std::initializer_list<T>& l) {
      static_assert(l.size() == 16, "Initializer_list<T> for mat4 must be of size 16!");
      int i = 0;
      for(auto& v : l) {
        m[i++] = v;
      }
    }
    mat4(const std::initializer_list<vec4<T>>& l) {
      static_assert(l.size() == 4, "Initializer_list<vec4<T>> for mat4 must be of size 4!");
      int i = 0;
      for(auto& v : l) {
        cv[i++] = v;
      }
    }

    mat4(const mat4&) = default;
    mat4& operator=(const mat4&) = default;

    T& get(int col, int row) { m7assert(col >= 0 && col < num_cols); m7assert(row >= 0 && row < num_rows); return mn[col][row]; }
    const T& get(int col, int row) const { m7assert(col >= 0 && col < num_cols); m7assert(row >= 0 && row < num_rows); return mn[col][row]; }

    T& operator[](int i) { m7assert(i >= 0 && i < 16); return m[i]; }
    const T& operator[](int i) const { m7assert(i >= 0 && i < 16); return m[i]; }

    T* ptr() { return m; }
    const T* ptr() const { return m; }

    void set(T v) { m[0] = m[1] = m[2] = m[3] =
      m[4] = m[5] = m[6] = m[7] =
        m[8] = m[9] = m[10] = m[11] =
        m[12] = m[13] = m[14] = m[15]; }
    void set(const T* v) { memcpy(m, v, sizeof(m)); }
    void set(const vec4<T>& v0, const vec4<T>& v1,
        const vec4<T>& v2, const vec4<T>& v3) {
      cv[0] = v0; cv[1] = v1; cv[2] = v2; cv[3] = v3;
    }
    void set(T m0, T m1, T m2, T m3, T m4, T m5, T m6, T m7,
        T m8, T m9, T m10, T m11, T m12, T m13, T m14, T m15) {
      m[0] = m0; m[1] = m1; m[2] = m2; m[3] = m3;
      m[4] = m4; m[4] = m4; m[5] = m5; m[6] = m6;
      m[7] = m7; m[8] = m8; m[9] = m9; m[10] = m10;
      m[11] = m11; m[12] = m12; m[13] = m13; m[14] = m14;
    }

    vec4<T>& col_alias(int i) { m7assert(i >= 0 && i < 4); return cv[i]; }
    const vec4<T>& col_alias(int i) const { m7assert(i >= 0 && i < 4); return cv[i]; }

    vec4<T> col(int i) const { m7assert(i >= 0 && i < 4); return cv[i]; }
    vec4<T> row(int i) const { m7assert(i >= 0 && i < 4); return vec4<T>(m[i], m[4+i], m[8+i], m[12+i]); }

    //Data begins here
    union {
      T m[16];
      T mn[4][4];
      vec4<T> cv[4];
    };

  };

#define MAT4_IDENTITY { 1, 0, 0, 0,  0, 1, 0, 0,  0, 0, 1, 0,  0, 0, 0, 1 }

typedef mat4<float> mat4f;
typedef mat4<double> mat4d;
typedef mat4<int> mat4i;
typedef mat4<unsigned int> mat4ui;
typedef mat4<short> mat4s;
typedef mat4<unsigned short> mat4us;
typedef mat4<char> mat4b;
typedef mat4<unsigned char> mat4ub;

template <typename T>
  struct affine2d {
    typedef T value_type;

    affine2d() = default;

    mat2<T> rs; //rotation,scale
    vec2<T> t; //translation
  };

template <typename T>
  struct affine3d {
    typedef T value_type;

    affine3d() = default;

    mat3<T> rs; //rotation, scale
    vec3<T> t; //translation
  };

template <typename T>
  struct quat {
    typedef T value_type;

    quat() = default;

    vec4<T> q;
  };

};
};

#endif
