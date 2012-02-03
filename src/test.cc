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

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <glossy-sl.hh>

#include <stdio.h>

using namespace GLossy::SL::GLES2SL100::BasicTypes;

int
main (void)
{
  const vec3 v (1., 2., 3.);
  vec2 x = v.br;
  vec4 y = v.rbbr;
  y.g = v[2];
  y[3] = 8;
  float f = y.g;
  printf ("%f\n", (float) f);

  for (unsigned int i = 0; i < 3; i++)
    printf ("%f\n", (float) vec2(v.gr).r);
}
