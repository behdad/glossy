/*
 * Copyright 2012 Google, Inc. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Google Author(s): Behdad Esfahbod
 */

#ifndef GLOSSY_SL_METATYPES_HH
#define GLOSSY_SL_METATYPES_HH

#include "glossy-common.hh"
#include "glossy-sl-metatypes-ctors.hh"
#include "glossy-sl-metatypes-swizzle.hh"

namespace GLossy {
namespace SL {
namespace MetaTypes {


template <typename T, int n> class gvec;

template <typename T, int n, int i>
struct ConstSwizzle1 {
  inline operator T (void) const {
    return v[i];
  }
  T v[n];
};
template <typename T, int n, int i>
struct Swizzle1 {
  inline Swizzle1<T,n,i> & operator = (const T &o) {
    v[i] = o;
    return *this;
  }
  inline operator T (void) const {
    return v[i];
  }
  T v[n];
};
template <typename T, int n, int i, int j>
struct ConstSwizzle2 {
  inline operator gvec<T,2> (void) const {
    return gvec<T,2> (v[i], v[j]);
  }
  T v[n];
};
template <typename T, int n, int i, int j>
struct Swizzle2 {
  inline Swizzle2<T,n,i,j> & operator = (const gvec<T,2> &o) {
    v[i] = o.v[0];
    v[j] = o.v[1];
    return *this;
  }
  inline operator gvec<T,2> (void) const {
    return gvec<T,2> (v[i], v[j]);
  }
  T v[n];
};
template <typename T, int n, int n0, int n1, int n2>
struct ConstSwizzle3 {
  inline operator gvec<T,3> (void) const {
    return gvec<T,3> (v[n0], v[n1], v[n2]);
  }
  T v[n];
};
template <typename T, int n, int n0, int n1, int n2>
struct Swizzle3 {
  inline Swizzle3<T,n,n0,n1,n2> & operator = (const gvec<T,3> &o) {
    v[n0] = o.v[0];
    v[n1] = o.v[1];
    v[n2] = o.v[2];
    return *this;
  }
  inline operator gvec<T,3> (void) const {
    return gvec<T,3> (v[n0], v[n1], v[n2]);
  }
  T v[n];
};
template <typename T, int n, int n0, int n1, int n2, int n3>
struct ConstSwizzle4 {
  inline operator gvec<T,4> (void) const {
    return gvec<T,4> (v[n0], v[n1], v[n2], v[n3]);
  }
  T v[n];
};
template <typename T, int n, int n0, int n1, int n2, int n3>
struct Swizzle4 {
  inline Swizzle4<T,n,n0,n1,n2,n3> & operator = (const gvec<T,4> &o) {
    v[n0] = o.v[0];
    v[n1] = o.v[1];
    v[n2] = o.v[2];
    v[n3] = o.v[3];
    return *this;
  }
  inline operator gvec<T,4> (void) const {
    return gvec<T,4> (v[n0], v[n1], v[n2], v[n3]);
  }
  T v[n];
};



template <typename T>
struct gvec<T,2> {
  inline gvec (T o)
  { for (unsigned int i = 0; i < GLOSSY_ARRAY_LENGTH (v); i++) v[i] = o; }
  GLOSSY_SL_METATYPES_CTORS2

  inline T operator [] (unsigned int i) const {
    assert (i < GLOSSY_ARRAY_LENGTH (v));
    return v[i];
  }
  inline T& operator [] (unsigned int i) {
    assert (i < GLOSSY_ARRAY_LENGTH (v));
    return v[i];
  }
  union {
    T v[2];
    GLOSSY_SL_METATYPES_SWIZZLE2
  };
};

template <typename T>
struct gvec<T,3> {
  inline gvec (T o)
  { for (unsigned int i = 0; i < GLOSSY_ARRAY_LENGTH (v); i++) v[i] = o; }
  GLOSSY_SL_METATYPES_CTORS3

  inline T operator [] (unsigned int i) const {
    assert (i < GLOSSY_ARRAY_LENGTH (v));
    return v[i];
  }
  inline T& operator [] (unsigned int i) {
    assert (i < GLOSSY_ARRAY_LENGTH (v));
    return v[i];
  }
  union {
    T v[3];
    GLOSSY_SL_METATYPES_SWIZZLE3
  };
};

template <typename T>
struct gvec<T,4> {
  inline gvec (T o)
  { for (unsigned int i = 0; i < GLOSSY_ARRAY_LENGTH (v); i++) v[i] = o; }
  GLOSSY_SL_METATYPES_CTORS4

  inline T operator [] (unsigned int i) const {
    assert (i < GLOSSY_ARRAY_LENGTH (v));
    return v[i];
  }
  inline T& operator [] (unsigned int i) {
    assert (i < GLOSSY_ARRAY_LENGTH (v));
    return v[i];
  }
  union {
    T v[4];
    GLOSSY_SL_METATYPES_SWIZZLE4
  };
};


template <typename T, int n>
class gmat {
};


}}} /* namespace GLossy::SL::MetaTypes */

#endif /* GLOSSY_SL_METATYPES_HH */
