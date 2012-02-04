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

typedef MetaTypes::vec<float, 2> vec2;
typedef MetaTypes::vec<float, 3> vec3;
typedef MetaTypes::vec<float, 4> vec4;
typedef MetaTypes::vec<bool,  2> bvec2;
typedef MetaTypes::vec<bool,  3> bvec3;
typedef MetaTypes::vec<bool,  4> bvec4;
typedef MetaTypes::vec<int,   2> ivec2;
typedef MetaTypes::vec<int,   3> ivec3;
typedef MetaTypes::vec<int,   4> ivec4;
typedef MetaTypes::mat<float, 2> mat2;
typedef MetaTypes::mat<float, 3> mat3;
typedef MetaTypes::mat<float, 4> mat4;


}}}} /* namespace GLossy::SL::GLES2SL100::BasicTypes */

#endif /* GLOSSY_SL_HH */
