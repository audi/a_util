/**
 * @file
 * String convert function declarations
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

#ifndef A_UTIL_UTIL_STRINGS_STRINGS_CONVERT_DECL_HEADER_INCLUDED
#define A_UTIL_UTIL_STRINGS_STRINGS_CONVERT_DECL_HEADER_INCLUDED

#include <string>

namespace a_util
{
namespace strings
{

bool toInt8(const std::string& from, std::int8_t& to);
bool toInt16(const std::string& from, std::int16_t& to);
bool toInt32(const std::string& from, std::int32_t& to);
bool toInt64(const std::string& from, std::int64_t& to);
bool toUInt8(const std::string& from, std::uint8_t& to);
bool toUInt16(const std::string& from, std::uint16_t& to);
bool toUInt32(const std::string& from, std::uint32_t& to);
bool toUInt64(const std::string& from, std::uint64_t& to);
bool toFloat(const std::string& from, float& to);
bool toDouble(const std::string& from, double& to);
bool toBool(const std::string& from, bool& to);

bool toInt8(const char* from, std::int8_t& to);
bool toInt16(const char* from, std::int16_t& to);
bool toInt32(const char* from, std::int32_t& to);
bool toInt64(const char* from, std::int64_t& to);
bool toUInt8(const char* from, std::uint8_t& to);
bool toUInt16(const char* from, std::uint16_t& to);
bool toUInt32(const char* from, std::uint32_t& to);
bool toUInt64(const char* from, std::uint64_t& to);
bool toFloat(const char* from, float& to);
bool toDouble(const char* from, double& to);
bool toBool(const char* from, bool& to);

std::int8_t toInt8(const std::string& from);
std::int16_t toInt16(const std::string& from);
std::int32_t toInt32(const std::string& from);
std::int64_t toInt64(const std::string& from);
std::uint8_t toUInt8(const std::string& from);
std::uint16_t toUInt16(const std::string& from);
std::uint32_t toUInt32(const std::string& from);
std::uint64_t toUInt64(const std::string& from);
float toFloat(const std::string& from);
double toDouble(const std::string& from);
bool toBool(const std::string& from);

std::int8_t toInt8(const char* from);
std::int16_t toInt16(const char* from);
std::int32_t toInt32(const char* from);
std::int64_t toInt64(const char* from);
std::uint8_t toUInt8(const char* from);
std::uint16_t toUInt16(const char* from);
std::uint32_t toUInt32(const char* from);
std::uint64_t toUInt64(const char* from);
float toFloat(const char* from);
double toDouble(const char* from);
bool toBool(const char* from);

struct ToNumericConverter
{
    static bool convert(const char* from, std::int8_t& to);
    static bool convert(const char* from, std::int16_t& to);
    static bool convert(const char* from, std::int32_t& to);
    static bool convert(const char* from, std::int64_t& to);

    static bool convert(const char* from, std::uint8_t& to);
    static bool convert(const char* from, std::uint16_t& to);
    static bool convert(const char* from, std::uint32_t& to);
    static bool convert(const char* from, std::uint64_t& to);

    static bool convert(const char* from, float& to);
    static bool convert(const char* from, double& to);
    static bool convert(const char* from, bool& to);
};

template <typename Numeric>
bool toNumeric(const char* from, Numeric& to);

template <typename Numeric>
bool toNumeric(const std::string& from, Numeric& to);

template <typename Numeric>
Numeric toNumeric(const char* from);

template <typename Numeric>
Numeric toNumeric(const std::string& from);

} // namespace strings
} // namespace a_util

#endif // A_UTIL_UTIL_STRINGS_STRINGS_CONVERT_DECL_HEADER_INCLUDED
