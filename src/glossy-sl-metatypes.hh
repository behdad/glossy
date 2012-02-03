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
#include "glossy-sl-metatypes-swizzle.hh"

namespace GLossy {
namespace SL {
namespace MetaTypes {


template <typename T, int n> class gvec;

template <typename T, int i>
struct Swizzle1 {
  inline Swizzle1<T,i> & operator = (const T &o) {
    T *p = reinterpret_cast <T *> (this);
    p[i] = o;
    return *this;
  }
  inline operator T (void) const {
    const T *p = reinterpret_cast <const T *> (this);
    return p[i];
  }
};
template <typename T, int i, int j>
struct Swizzle2 {
  inline Swizzle2<T,i,j> & operator = (const gvec<T,2> &o) {
    T *p = reinterpret_cast <T *> (this);
    p[i] = o.v[0];
    p[j] = o.v[1];
    return *this;
  }
  inline operator gvec<T,2> (void) const {
    const T *p = reinterpret_cast <const T *> (this);
    return gvec<T,2> (p[i], p[j]);
  }
};
template <typename T, int n0, int n1, int n2>
struct Swizzle3 {
  inline Swizzle3<T,n0,n1,n2> & operator = (const gvec<T,3> &o) {
    T *p = reinterpret_cast <T *> (this);
    p[n0] = o.v[0];
    p[n1] = o.v[1];
    p[n2] = o.v[2];
    return *this;
  }
  inline operator gvec<T,3> (void) const {
    const T *p = reinterpret_cast <const T *> (this);
    return gvec<T,3> (p[n0], p[n1], p[n2]);
  }
};
template <typename T, int n0, int n1, int n2, int n3>
struct Swizzle4 {
  inline Swizzle4<T,n0,n1,n2,n3> & operator = (const gvec<T,4> &o) {
    T *p = reinterpret_cast <T *> (this);
    p[n0] = o.v[0];
    p[n1] = o.v[1];
    p[n2] = o.v[2];
    p[n3] = o.v[3];
    return *this;
  }
  inline operator gvec<T,4> (void) const {
    const T *p = reinterpret_cast <const T *> (this);
    return gvec<T,4> (p[n0], p[n1], p[n2], p[n3]);
  }
};



template <typename T, int n>
class gvec {
  union {
    T v[n];
  };
};

template <typename T>
struct gvec<T,2> {
  inline gvec (T v0, T v1)
  { v[0] = v0; v[1] = v1; }
  // TODO add vector constructors
  inline T operator [] (unsigned int i) const {
    assert (i < GLOSSY_ARRAY_LENGTH (v));
    return v[i];
  }
  union {
    T v[2];
    SWIZZLE2
  };
};

template <typename T>
struct gvec<T,3> {
  inline gvec (T v0, T v1, T v2)
  { v[0] = v0; v[1] = v1; v[2] = v2; }
  // TODO add vector constructors
  inline T operator [] (unsigned int i) const {
    assert (i < GLOSSY_ARRAY_LENGTH (v));
    return v[i];
  }
  union {
    T v[3];
    SWIZZLE3
  };
};

template <typename T>
struct gvec<T,4> {
  inline gvec (T v0, T v1, T v2, T v3)
  { v[0] = v0; v[1] = v1; v[2] = v2; v[3] = v3; }
  // TODO add vector constructors
  inline T operator [] (unsigned int i) const {
    assert (i < GLOSSY_ARRAY_LENGTH (v));
    return v[i];
  }
  union {
    T v[4];
    SWIZZLE4
  };
};


template <typename T, int n>
class gmat {
};


}}} /* namespace GLossy::SL::MetaTypes */

#endif /* GLOSSY_SL_METATYPES_HH */