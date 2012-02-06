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

#ifndef GLOSSY_SL_HH
#define GLOSSY_SL_HH

#include "glossy-common.hh"
#include "glossy-sl-metatypes.hh"


namespace GLossy {
namespace SL {
namespace GLES2SL100 {

namespace BasicTypes {

  /* We have to use defines instead of typedef for the vec/mat types
   * to pickup the right precision int/float at the usage site. */
# define vec2	vec<Float,2>
# define vec3	vec<Float,3>
# define vec4	vec<Float,4>
# define bvec2	vec<Bool,2>
# define bvec3	vec<Bool,3>
# define bvec4	vec<Bool,4>
# define ivec2	vec<Int,2>
# define ivec3	vec<Int,3>
# define ivec4	vec<Int,4>
# define mat2	mat<Float,2>
# define mat3	mat<Float,3>
# define mat4	mat<Float,4>


  namespace PrecisionHigh {
    using namespace MetaTypes;
    typedef bool Bool;
    typedef int Int;
    typedef float Float;

    struct Sampler2D {};
    struct SamplerCube {};

  } /* namespace PrecisionHigh */

  namespace PrecisionLow {
  using namespace PrecisionHigh;
  } /* namespace PrecisionLow */

  namespace PrecisionMedium {
  using namespace PrecisionHigh;
  } /* namespace PrecisionMedium */

  namespace VertexShader {
    using PrecisionHigh::Float;
    using PrecisionHigh::Int;
    using PrecisionLow::Sampler2D;
    using PrecisionLow::SamplerCube;
  } /* namespace VertexShader */

  namespace FragmentShader {
    /* ES2 doesn't have a default float type in fragment shader.
     * Users must declare one. */
    using PrecisionMedium::Int;
    using PrecisionLow::Sampler2D;
    using PrecisionLow::SamplerCube;
  } /* namespace FragmentShader */

  /* Default to highp */
  using namespace PrecisionHigh;

} /* namespace BasicTypes */



}}} /* namespace GLossy::SL::GLES2SL100 */

/* TODO move these to the proper place */
#define GL_ES 1
#undef __VERSION__
#define __VERSION__ 100

/* For now, these don't do anything */
#define uniform
#define attribute
#define varying

#define in const
#define out ERR /* Can't implement this :( */
#define inout ERR /* Can't implement this :( */

#define GL_FRAGMENT_PRECISION_HIGH 1
#define precision  using
#define highp      PrecisionHigh::
#define mediump    PrecisionMedium::
#define lowp       PrecisionLow::

typedef int int_;
typedef unsigned int unsigned_int;
typedef float float_;
#define int Int
#define float Float
#define sampler2D Sampler2D
#define samplerCube SamplerCube

#endif /* GLOSSY_SL_HH */
