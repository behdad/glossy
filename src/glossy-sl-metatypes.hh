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

template <typename T, int n, int n0>
struct ConstSwizzle1 {
  inline operator T (void) const {
    return v[n0];
  }
  T v[n];
};
template <typename T, int n, int n0>
struct Swizzle1 : ConstSwizzle1<T,n,n0> {
  inline Swizzle1<T,n,n0> & operator = (const T &o) {
    this->v[n0] = o;
    return *this;
  }
};
template <typename T, int n, int n0, int n1>
struct ConstSwizzle2 {
  inline operator gvec<T,2> (void) const {
    return gvec<T,2> (v[n0], v[n1]);
  }
  T v[n];
};
template <typename T, int n, int n0, int n1>
struct Swizzle2 : ConstSwizzle2<T,n,n0,n1> {
  inline Swizzle2<T,n,n0,n1> & operator = (const gvec<T,2> &o) {
    this->v[n0] = o.v[0];
    this->v[n1] = o.v[1];
    return *this;
  }
};
template <typename T, int n, int n0, int n1, int n2>
struct ConstSwizzle3 {
  inline operator gvec<T,3> (void) const {
    return gvec<T,3> (v[n0], v[n1], v[n2]);
  }
  T v[n];
};
template <typename T, int n, int n0, int n1, int n2>
struct Swizzle3 : ConstSwizzle3<T,n,n0,n1,n2> {
  inline Swizzle3<T,n,n0,n1,n2> & operator = (const gvec<T,3> &o) {
    this->v[n0] = o.v[0];
    this->v[n1] = o.v[1];
    this->v[n2] = o.v[2];
    return *this;
  }
};
template <typename T, int n, int n0, int n1, int n2, int n3>
struct ConstSwizzle4 {
  inline operator gvec<T,4> (void) const {
    return gvec<T,4> (v[n0], v[n1], v[n2], v[n3]);
  }
  T v[n];
};
template <typename T, int n, int n0, int n1, int n2, int n3>
struct Swizzle4 : ConstSwizzle4<T,n,n0,n1,n2,n3> {
  inline Swizzle4<T,n,n0,n1,n2,n3> & operator = (const gvec<T,4> &o) {
    this->v[n0] = o.v[0];
    this->v[n1] = o.v[1];
    this->v[n2] = o.v[2];
    this->v[n3] = o.v[3];
    return *this;
  }
};



/* Define the vector metatypes */
#define n 2
#include "glossy-sl-metatypes-vec.hh"
#undef n
#define n 3
#include "glossy-sl-metatypes-vec.hh"
#undef n
#define n 4
#include "glossy-sl-metatypes-vec.hh"
#undef n


template <typename T, int n>
class gmat {
};


}}} /* namespace GLossy::SL::MetaTypes */

#endif /* GLOSSY_SL_METATYPES_HH */
