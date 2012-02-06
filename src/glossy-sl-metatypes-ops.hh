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

#ifndef GLOSSY_SL_METATYPES_OPS_HH
#define GLOSSY_SL_METATYPES_OPS_HH

#include "glossy-common.hh"

namespace GLossy {
namespace SL {
namespace MetaTypes {


template <typename T>
struct ComponentWiseOperators
{
  /* In order of precedence */

  inline const T operator++ (int) // postfix
  {
    const T &t = _this ();
    T v = t;
    ++t;
    return v;
  }
  inline const T operator-- (int) // postfix
  {
    const T &t = _this ();
    T v = t;
    --t;
    return v;
  }
  inline T& operator++ (void) // prefix
  {
    T &t = _this ();
    for (unsigned int i = 0; i < len (); i++)
      ++t.v[i];
    return t;
  }
  inline T& operator-- (void) // prefix
  {
    T &t = _this ();
    for (unsigned int i = 0; i < len (); i++)
      --t.v[i];
    return t;
  }
  inline const T operator+ (void) // unary
  {
    return _this ();
  }
  inline const T operator- (void) // unary
  {
    const T &t = _this ();
    T v;
    for (unsigned int i = 0; i < len (); i++)
      v.v[i] = -t.v[i];
    return v;
  }
  inline const T operator* (const T &o) const
  {
    const T &t = _this ();
    T v;
    for (unsigned int i = 0; i < len (); i++)
      v.v[i] = t.v[i] * o.v[i];
    return v;
  }
  inline const T operator/ (const T &o) const
  {
    const T &t = _this ();
    T v;
    for (unsigned int i = 0; i < len (); i++)
      v.v[i] = t.v[i] / o.v[i];
    return v;
  }
  inline const T operator+ (const T &o) const
  {
    const T &t = _this ();
    T v;
    for (unsigned int i = 0; i < len (); i++)
      v.v[i] = t.v[i] + o.v[i];
    return v;
  }
  inline const T operator- (const T &o) const
  {
    const T &t = _this ();
    T v;
    for (unsigned int i = 0; i < len (); i++)
      v.v[i] = t.v[i] - o.v[i];
    return v;
  }
  inline bool operator< (const T &o) const
  {
    const T &t = _this ();
    for (unsigned int i = 0; i < len (); i++)
      if (t.v[i] >= o.v[i])
        return false;
    return true;
  }
  inline bool operator> (const T &o) const
  {
    const T &t = _this ();
    for (unsigned int i = 0; i < len (); i++)
      if (t.v[i] <= o.v[i])
        return false;
    return true;
  }
  inline bool operator<= (const T &o) const
  {
    const T &t = *reinterpret_cast<const T *> (this);
    return !(t > o);
  }
  inline bool operator>= (const T &o) const
  {
    const T &t = *reinterpret_cast<const T *> (this);
    return !(t < o);
  }
  inline bool operator== (const T &o) const
  {
    const T &t = _this ();
    for (unsigned int i = 0; i < len (); i++)
      if (t.v[i] != o.v[i])
        return false;
    return true;
  }
  inline bool operator!= (const T &o) const
  {
    const T &t = *reinterpret_cast<const T *> (this);
    return !(t == o);
  }
  inline T& operator+= (const T &o)
  {
    T &t = _this ();
    return t = t + o;
  }
  inline T& operator-= (const T &o)
  {
    T &t = _this ();
    return t = t - o;
  }
  inline T& operator*= (const T &o)
  {
    T &t = _this ();
    return t = t * o;
  }
  inline T& operator/= (const T &o)
  {
    T &t = _this ();
    return t = t / o;
  }

private:
  unsigned int len (void) const { return GLOSSY_ARRAY_LENGTH (_this().v); }
  const T & _this (void) const { return *reinterpret_cast<const T *> (this); }
  T & _this (void) { return *reinterpret_cast<T *> (this); }
};


}}} /* namespace GLossy::SL::MetaTypes */

#endif /* GLOSSY_SL_METATYPES_OPS_HH */
