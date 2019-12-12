/**
 * @file
 * Global Error Definitions.
 *
 * @copyright
 * @verbatim
   Copyright @ 2017 Audi Electronics Venture GmbH. All rights reserved.

       This Source Code Form is subject to the terms of the Mozilla
       Public License, v. 2.0. If a copy of the MPL was not distributed
       with this file, You can obtain one at https://mozilla.org/MPL/2.0/.

   If it is not possible or desirable to put the notice in a particular file, then
   You may include the notice in a location (such as a LICENSE file in a
   relevant directory) where a recipient would be likely to look for such a notice.

   You may add additional accurate notices of copyright ownership.
   @endverbatim
*/

#ifndef A_UTIL_UTIL_RESULT_ERROR_DEF_HEADER_INCLUDED
#define A_UTIL_UTIL_RESULT_ERROR_DEF_HEADER_INCLUDED

#include "3rdparty/boost/boost_1_64_0/boost/current_function.hpp"
#include "a_util/result/result_type.h"
#include "a_util/strings/strings_format.h"

#ifndef A_UTIL_CURRENT_FUNCTION
#define A_UTIL_CURRENT_FUNCTION BOOST_CURRENT_FUNCTION
#endif // !A_UTIL_CURRENT_FUNCTION

/// using a printf like parameter list for detailed error description
#define RETURN_ERROR_DESCRIPTION(_errcode, ...)                                                    \
    return a_util::result::Result(_errcode,                                                        \
                                  a_util::strings::format(__VA_ARGS__).c_str(),                    \
                                  __LINE__,                                                        \
                                  __FILE__,                                                        \
                                  A_UTIL_CURRENT_FUNCTION)

#endif // A_UTIL_UTIL_RESULT_ERROR_DEF_HEADER_INCLUDED
