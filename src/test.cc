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

#include <stdio.h>

#include <glossy-sl.hh>

using namespace GLossy::SL::GLES2SL100::BasicTypes;
using namespace GLossy::SL::MetaTypes;

int
main (void)
{
  {// 3.4 Preprocessor
    // __LINE__
    // __FILE__
    assert (100 == __VERSION__);
    assert (1 == GL_ES);
  }
  {// 4.1.2 Booleans
    bool success;
    // declare “success” to be a Boolean
    bool done = false; // declare and initialize “done”
  }
  {// 4.1.3 Integers
    int i, j = 42;
  }
  {// 4.1.4 Floats
    float a, b = 1.5;
  }
  {// 4.1.5 Vectors
    vec2 texcoord1, texcoord2;
    vec3 position;
    vec4 myRGBA;
    ivec2 textureLookup;
    bvec3 lessThan;
  }
  {// 4.1.6 Matrices
    mat2 mat2D;
    mat3 optMatrix;
    mat4 view, projection;
  }
  {// 4.1.8 Structures
    struct light {
      float intensity;
      vec3 position;
    } lightVar;

    light lightVar2;

    struct T
    {
      int a;
    };
    struct S
    {
      T t;
      int b;
    };
  }
  {// 4.1.9 Arrays
    float frequencies[3];
    uniform vec4 lightPosition[4];

    struct light {
      float intensity;
      vec3 position;
    };
    const int numLights = 2;
    light lights[numLights];
  }
  {// 4.2.2 Types of Scope
    int x = 1;
    {
      int x = 2 /* 2nd x visible here */, y = x; // y is initialized to 2
      assert (2 == y);
    }
    {
      int x = x;
      // XFAIL scoping is different in C++
      //assert (1 == x);
    }

    struct S
    {
      int x;
      int y;
    };
    {
      // XFAIL in C++, S doesn't have any constructors
      //S S = S(0,0); // 'S' is only visible as a struct and constructor
      // XFAIL scoping is different in C++
      //S;            // 'S' is now visible only as a variable}
    }
  }
  {// Redeclarations and Redefinitions Within the Same Scope
    {
      int f();                 // declaration;
      // XFAIL this has to be in the outer scope
      //int f() {return 0;}      // declaration and definition
      int x;                   // declaration and definition
      int a[4];                // array declaration and definition
      struct S {int x;};       // structure declaration and definition
    }
    {
      // XFAIL these have to be in the outer scope
      //void f(int) {...}
      //void f(float) {...}      // function overloading allowed
    }
    {
      // XFAIL these have to be in the outer scope
      //void f(int);
      //void f(int) {...}        // single definition allowed
    }
  }
  {// 4.3.2 Constant Qualifier
    const vec3 zAxis = vec3 (0.0, 0.0, 1.0);
  }
  {// 4.3.3 Attribute
    attribute vec4 position;
    attribute vec3 normal;
    attribute vec2 texCoord;
  }
  {// 4.3.4 Uniform
    uniform vec4 lightPosition;
  }
  {// 4.3.5 Varying
    varying vec3 normal;
  }
  {// 4.5.2 Precision Qualifiers
    {
      lowp float color;
      varying mediump vec2 Coord;
      lowp ivec2 foo(lowp mat3);
      highp mat4 m;
    }
    {
      uniform highp float h1;
      highp float h2 = 2.3 * 4.7; // operation and result are highp precision
      mediump float m;
      m = 3.7 * h1 * h2;          // all operations are highp precision
      h2 = m * h1;                // operation is highp precision
      m = h2 - h1;                // operation is highp precision
      h2 = m + m;                 // addition and result at mediump precision
      void f(highp float p);
      // XFAIL actually define a function
      //f(3.3);                     // 3.3 will be passed in at highp precision
    }
  }
  {// 4.5.3 Default Precision Qualifiers
    precision highp float;
    precision highp int;
    precision lowp sampler2D;
    precision lowp samplerCube;
  }
  {// 4.5.4 Available Precision Qualifiers
    assert (1 == GL_FRAGMENT_PRECISION_HIGH);
  }
  {// 4.6.1 The Invariant Qualifier
    {
      // XFAIL Not sure if we can support this
      //invariant gl_Position; // make existing gl_Position be invariant

      varying mediump vec3 Color;
      // XFAIL same here
      //invariant Color;  // make existing Color be invariant
    }
    {
      invariant varying mediump vec3 Color;
    }
  }
  {// 5.4.2 Vector and Matrix Constructors
    vec4 color = vec4(0.0, 1.0, 0.0, 1.0);
    vec4 rgba = vec4(1.0);           // sets each component to 1.0
    vec3 rgb = vec3(color); // drop the 4th component
  }
  {// 5.4.3 Structure Constructors
    struct light {
      float intensity;
      vec3 position;
    };
    // XFAIL C++ doesn't support this syntax :(
    //light lightVar = light(3.0, vec3(1.0, 2.0, 3.0));
  }
  {// 5.5 Vector Components
    {
      vec2 pos;
      pos.x; // is legal
    }
    {
      vec4 v4;
      v4.rgba;  // is a vec4 and the same as just using v4,
      v4.rgb;   // is a vec3,
      v4.b;     // is a float,
      v4.xy;    // is a vec2,
    }
    {
      vec4 pos = vec4(1.0, 2.0, 3.0, 4.0);
      vec4 swiz= pos.wzyx; // swiz = (4.0, 3.0, 2.0, 1.0)
      assert ((vec4(4.0, 3.0, 2.0, 1.0) == swiz));
      vec4 dup = pos.xxyy; // dup = (1.0, 1.0, 2.0, 2.0)
      assert ((vec4(1.0, 1.0, 2.0, 2.0) == dup));
    }
    {
      vec4 pos = vec4(1.0, 2.0, 3.0, 4.0);
      pos.xw = vec2(5.0, 6.0);         // pos = (5.0, 2.0, 3.0, 6.0)
      assert ((vec4(5.0, 2.0, 3.0, 6.0) == pos));
      pos.wx = vec2(7.0, 8.0);         // pos = (8.0, 2.0, 3.0, 7.0)
      assert ((vec4(8.0, 2.0, 3.0, 7.0) == pos));
      assert (3.0 == pos[2]);
    }
  }
  {// 5.6 Matrix Components
    mat4 m;
    m[1] = vec4(2.0);        // sets the second column to all 2.0
    m[0][0] = 1.0;           // sets the upper left element to 1.0
    m[2][3] = 2.0;           // sets the 4th element of the third column to 2.0
  }


  const vec3 v (1., 2., 3.);
  vec2 x = v.br;
  ivec4 iv(9.);
  vec4 y = v.rbbr;
  vec3 kk (iv);
  vec3 q(3);
  q == kk;
  y.g = v[2];
  y.rg = v.rg;
  y[3] = 8;

  mat2 m (1,2,3,4);
  mat2 mm (m);

  y = y * 2;
  y *= 1.3;
  mm -= 1;
  y = 3. * y;

  float f = y.g;

  x = m[1];
  f = x[1];
  printf ("%f\n", (float) f);

  for (unsigned_int i = 0; i < 3; i++)
    printf ("%f\n", (float) vec2(v.gr).r);
}
