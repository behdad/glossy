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
 * Google Author(s): Behdad Esfahbod, Maysum Panju
 */

#ifndef GLOSSY_COMMON_HH
#define GLOSSY_COMMON_HH

#include <math.h>
#include <assert.h>
#include <string.h>

#define GLOSSY_ARRAY_LENGTH(__array) ((signed int) (sizeof (__array) / sizeof (__array[0])))

#define _GLOSSY_ASSERT_STATIC1(_line, _cond) typedef int _static_assert_on_line_##_line##_failed[(_cond)?1:-1]
#define _GLOSSY_ASSERT_STATIC0(_line, _cond) _GLOSSY_ASSERT_STATIC1 (_line, (_cond))
#define GLOSSY_ASSERT_STATIC(_cond) _GLOSSY_ASSERT_STATIC0 (__LINE__, (_cond))

#define _GLOSSY_PASTE(a,b) a##b
#define GLOSSY_PASTE(a,b) _GLOSSY_PASTE (a,b)

#define _GLOSSY_STRINGIZE(a) #a
#define GLOSSY_STRINGIZE(a) _GLOSSY_STRINGIZE (a)

#endif /* GLOSSY_COMMON_HH */
