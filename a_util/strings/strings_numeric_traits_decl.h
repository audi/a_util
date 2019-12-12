/**
 * @file
 * String numeric traits functions
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

#ifndef A_UTIL_UTIL_STRINGS_STRINGS_NUMERIC_TRAITS_DECL_HEADER_INCLUDED
#define A_UTIL_UTIL_STRINGS_STRINGS_NUMERIC_TRAITS_DECL_HEADER_INCLUDED

#include <string> //std::string

namespace a_util
{
namespace strings
{

bool isInt8(const std::string& str);
bool isInt16(const std::string& str);
bool isInt32(const std::string& str);
bool isInt64(const std::string& str);
bool isUInt8(const std::string& str);
bool isUInt16(const std::string& str);
bool isUInt32(const std::string& str);
bool isUInt64(const std::string& str);
bool isFloat(const std::string& str);
bool isDouble(const std::string& str);
bool isBool(const std::string& str);

bool isInt8(const char* str);
bool isInt16(const char* str);
bool isInt32(const char* str);
bool isInt64(const char* str);
bool isUInt8(const char* str);
bool isUInt16(const char* str);
bool isUInt32(const char* str);
bool isUInt64(const char* str);
bool isFloat(const char* str);
bool isDouble(const char* str);
bool isBool(const char* str);

struct IsNumericConvertible
{
    static bool check(const char* from, const std::int8_t&);
    static bool check(const char* from, const std::int16_t&);
    static bool check(const char* from, const std::int32_t&);
    static bool check(const char* from, const std::int64_t&);

    static bool check(const char* from, const std::uint8_t&);
    static bool check(const char* from, const std::uint16_t&);
    static bool check(const char* from, const std::uint32_t&);
    static bool check(const char* from, const std::uint64_t&);

    static bool check(const char* from, const float&);
    static bool check(const char* from, const double&);
    static bool check(const char* from, const bool&);
};

template <typename Numeric>
bool isNumeric(const char* str);

template <typename Numeric>
bool isNumeric(const std::string& str);

} // namespace strings
} // namespace a_util

#endif // A_UTIL_UTIL_STRINGS_STRINGS_NUMERIC_TRAITS_DECL_HEADER_INCLUDED
