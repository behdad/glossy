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

/* n is defined to the mat size */
template <typename T>
struct mat<T,n>
{
  inline mat (T o)
  {
    memset (*this, 0, sizeof (*this));
    for (unsigned int i = 0; i < GLOSSY_ARRAY_LENGTH (v); i += n + 1)
      v[i] = o;
  }

  /* Assorted constructors */
  GLOSSY_PASTE (GLOSSY_SL_METATYPES_CTORS_MAT, n)

  inline vec<T,n> operator [] (unsigned int i) const {
    assert (i < GLOSSY_ARRAY_LENGTH (c));
    return c[i];
  }
  inline vec<T,n>& operator [] (unsigned int i) {
    assert (i < GLOSSY_ARRAY_LENGTH (c));
    return c[i];
  }

  union {
    T v[n * n];
    vec<T,n> c[n]; /* Columns */
  };
};
