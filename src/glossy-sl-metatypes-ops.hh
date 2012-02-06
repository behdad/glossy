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
  inline bool operator == (const T &o) const
  {
    const T &t = _this ();
    for (unsigned int i = 0; i < len (); i++)
      if (t.v[i] != o.v[i])
        return false;
    return true;
  }
  inline bool operator != (const T &o) const
  {
    const T &t = *reinterpret_cast<const T *> (this);
    return !(t == o);
  }
#if 0
  inline bool operator != (const Point &p) const;
  inline Point& operator+= (const Vector &v);
  inline Point& operator-= (const Vector &v);
  inline const Point operator+ (const Vector &v) const;
  inline const Point operator- (const Vector &v) const;
  inline const Vector operator- (const Point &p) const;
#endif

private:
  unsigned int len (void) const { return GLOSSY_ARRAY_LENGTH (_this().v); }
  const T & _this (void) const { return *reinterpret_cast<const T *> (this); }
};


}}} /* namespace GLossy::SL::MetaTypes */

#endif /* GLOSSY_SL_METATYPES_OPS_HH */
