/**
 * @file
 * String format functions
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

#ifndef A_UTIL_UTIL_STRINGS_STRINGS_FORMAT_HEADER_INCLUDED
#define A_UTIL_UTIL_STRINGS_STRINGS_FORMAT_HEADER_INCLUDED

#include <cstddef> //std::size_t
#include <string>  //std::string

namespace a_util
{
namespace strings
{

std::string format(const char* str_format, ...);
// always pass size + 1 for terminating 0-character
std::string format(std::size_t initial_buffer_size, const char* str_format, ...);

/**
 * @brief
 * @param[in,out] buffer Must fit to shrink after final call
 */
std::string& format(std::string& buffer, std::size_t& pos, const char* str_format, ...);

std::string toString(std::int8_t from);
std::string toString(std::int16_t from);
std::string toString(std::int32_t from);
std::string toString(std::int64_t from);
std::string toString(std::uint8_t from);
std::string toString(std::uint16_t from);
std::string toString(std::uint32_t from);
std::string toString(std::uint64_t from);
std::string toString(float from);
std::string toString(double from);
std::string toString(bool from);

} // namespace strings
} // namespace a_util

#endif // A_UTIL_UTIL_STRINGS_STRINGS_FORMAT_HEADER_INCLUDED
