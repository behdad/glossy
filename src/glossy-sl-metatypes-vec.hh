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

/* Intentionally left with no guards */

/* n is defined to the vec len */
template <typename T>
struct vec<T,n> : public ComponentWiseOperators<vec<T,n> >
{
  typedef T ElementType;
  enum { Size = n, Len = n, Dim = 1 };

  inline vec (void)
  {
    memset (this, 0, sizeof (*this));
  }
  inline vec (T o)
  {
    for (unsigned int i = 0; i < GLOSSY_ARRAY_LENGTH (v); i++)
      v[i] = o;
  }

  /* Assorted constructors */
  GLOSSY_PASTE (GLOSSY_SL_METATYPES_CTORS_VEC, n)

  inline T operator [] (unsigned int i) const {
    assert (i < GLOSSY_ARRAY_LENGTH (v));
    return v[i];
  }
  inline T& operator [] (unsigned int i) {
    assert (i < GLOSSY_ARRAY_LENGTH (v));
    return v[i];
  }

  /* Cast out */
  template <typename T2>
  inline operator vec<T2,n> (void) const {
    vec<T2,n> o;
    for (unsigned int i = 0; i < GLOSSY_ARRAY_LENGTH (v); i++)
      o[i] = v[i];
    return o;
  }

  union {
    T v[Len];
    /* Assorted swizzles */
    GLOSSY_PASTE (GLOSSY_SL_METATYPES_SWIZZLE, n)
  };
};
