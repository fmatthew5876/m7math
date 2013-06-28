
#ifndef MTYPE
#error Do not include this header directly!
#endif

namespace m7 {
namespace math {

template <typename T> struct MTYPE;
template <typename T> struct VTYPE;

template <typename T>
  inline void make_identity(MTYPE<T>& m) {
    for(int i = 0; i < MTYPE<T>::size; ++i) {
      m.m[i] = 0;
    }
    for(int i = 0; i < MTYPE<T>::size; i+= MTYPE<T>::num_cols + 1) {
      m.m[i] = 1;
    }
  }

template <typename T>
  inline T trace(const MTYPE<T>& m) {
    T t = 0;
    for(int i = 0; i < MTYPE<T>::size; i += MTYPE<T>::num_cols) {
      t+= m.m[i];
    }
    return t;
  }

template <typename T>
  inline MTYPE<T> transpose(const MTYPE<T>& m) {
    MTYPE<T> res;
    for(int i = 0; i < MTYPE<T>::num_cols; ++i) {
      for(int j = 0; j < MTYPE<T>::num_rows; ++j) {
        res.mn[j][i] = m.mn[i][j];
      }
    }
    return res;
  }

template <typename T>
  inline void transpose_eq(const MTYPE<T>& m) {
    for(int i = 0; i < MTYPE<T>::num_cols; ++i) {
      for(int j = i+1; j < MTYPE<T>::num_rows; ++j) {
        T t = m.mn[i][j];
        m.mn[i][j] = m.mn[j][i];
        m.mn[j][i] = t;
      }
    }
  }

template <typename T>
inline MTYPE<T> mult(const MTYPE<T>& l, const MTYPE<T>& r) {
  MTYPE<T> res;
  for(int i = 0; i < MTYPE<T>::num_cols; ++i) {
    for(int j = 0; j < MTYPE<T>::num_rows; ++j) {
      T t = 0;
      for(int k = 0; k < MTYPE<T>::num_rows; ++k) {
        t += l.mn[k][j] * r.mn[i][k];
      }
      res.mn[i][j] = t;
    }
  }
}

template <typename T>
inline MTYPE<T> mult_matrix_transpose(const MTYPE<T>& l, const MTYPE<T>& r) {
  MTYPE<T> res;
  for(int i = 0; i < MTYPE<T>::num_cols; ++i) {
    for(int j = 0; j < MTYPE<T>::num_rows; ++j) {
      T t = 0;
      for(int k = 0; k < MTYPE<T>::num_rows; ++k) {
        t += l.mn[k][j] * r.mn[k][j];
      }
      res.mn[i][j] = t;
    }
  }
}

template <typename T>
inline MTYPE<T> mult_transpose_matrix(const MTYPE<T>& l, const MTYPE<T>& r) {
  MTYPE<T> res;
  for(int i = 0; i < MTYPE<T>::num_cols; ++i) {
    for(int j = 0; j < MTYPE<T>::num_rows; ++j) {
      T t = 0;
      for(int k = 0; k < MTYPE<T>::num_rows; ++k) {
        t += l.mn[i][k] * r.mn[i][k];
      }
      res.mn[i][j] = t;
    }
  }
}

template <typename T>
inline MTYPE<T> mult_transpose_transpose(const MTYPE<T>& l, const MTYPE<T>& r) {
  MTYPE<T> res;
  for(int i = 0; i < MTYPE<T>::num_cols; ++i) {
    for(int j = 0; j < MTYPE<T>::num_rows; ++j) {
      T t = 0;
      for(int k = 0; k < MTYPE<T>::num_rows; ++k) {
        t += l.mn[i][k] * r.mn[k][j];
      }
      res.mn[i][j] = t;
    }
  }
}

template <typename T>
inline MTYPE<T> operator*(const MTYPE<T>& l, const MTYPE<T>& r) {
  return mult(l, r);
}

template <typename T>
inline MTYPE<T> square(const MTYPE<T>& m) {
  return mult(m, m);
}

template <typename T>
inline void square_eq(const MTYPE<T>& m) {
  m *= m;
}

template <typename T>
inline void pow(const MTYPE<T>& m, int p) {
  MTYPE<T> res;
  if(p == 0) {
    make_identity(res);
    return res;
  }
  if(p < 0) {
    res = inverse(m);
    p *= -1;
  } else {
    res = m;
  }
  int d = 2;
  while(p > d) {
    square_eq(res);
    p /= 2;
    p += p % 2;
    d *= 2;
  }
  while(p > 0) {
    res = mult(m);
    --p;
  }
  return res;
}

template <typename T>
inline void pow_eq(MTYPE<T>& m, int p) {
  m = pow(m, p);
}

template <typename T>
inline VTYPE<T> mult(MTYPE<T>& l, VTYPE<T>& r) {
  VTYPE<T> res;
  for(int i = 0; i < MTYPE<T>::num_cols; ++i) {
    T t = 0;
    for(int k = 0; k < VTYPE<T>::size; ++k) {
      t += l.mn[k][i] * r.m[k];
    }
    res[i] = t;
  }
  return res;
}

template <typename T>
inline VTYPE<T> mult_transpose(const MTYPE<T>& l, const VTYPE<T>& r) {
  VTYPE<T> res;
  for(int i = 0; i < MTYPE<T>::num_rows; ++i) {
    T t = 0;
    for(int k = 0; k < VTYPE<T>::size; ++k) {
      t += l.mn[i][k] * r.m[k];
    }
    res[i] = t;
  }
  return res;
}

template <typename T>
inline VTYPE<T> operator*(const MTYPE<T>& l, const VTYPE<T>& r) {
  return mult(l, r);
}

template <typename T>
inline MTYPE<T> outer_product(const VTYPE<T>& l, const VTYPE<T>& r) {
  MTYPE<T> res;
  for(int i = 0; i < MTYPE<T>::num_rows; ++i) {
    for(int j = 0; j < MTYPE<T>::num_cols; ++j) {
      res.mn[i][j] = l.m[j]*r.m[i];
    }
  }
}

};
};

