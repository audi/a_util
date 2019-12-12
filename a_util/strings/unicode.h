/**
 * @file
 * Unicode functions
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

#ifndef A_UTIL_UTIL_STRINGS_UNICODE_INCLUDED
#define A_UTIL_UTIL_STRINGS_UNICODE_INCLUDED

#include <string>

namespace a_util
{
namespace strings
{
namespace unicode
{

/**
 * Converts a utf8 string to utf16 wstring
 *
 * @note Throws std::invalid_argument on invalid utf8 code points
 * @param [in] utf8_str The utf8 string
 * @retval Converted utf16 string
 */
std::wstring utf8ToUtf16(const std::string& utf8_str);

/**
 * Converts a utf16 wstring to utf8 string
 *
 * @note Throws std::invalid_argument on invalid utf16 code points
 * @param [in] utf16_str The utf16 wstring
 * @retval Converted utf8 string
 */
std::string utf16ToUtf8(const std::wstring& utf16_str);

} // namespace unicode
} // namespace strings
} // namespace a_util

#endif // A_UTIL_UTIL_STRINGS_UNICODE_INCLUDED
