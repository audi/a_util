/**
 * @file
 * Shared smart pointer file for compilers with @c std::shared_ptr
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

#ifndef A_UTIL_UTIL_MEMORY_DETAIL_SHARED_PTR_CXX11_HEADER_INCLUDED
#define A_UTIL_UTIL_MEMORY_DETAIL_SHARED_PTR_CXX11_HEADER_INCLUDED

#include <memory>

namespace a_util
{
namespace memory
{
namespace detail
{

using std::shared_ptr;

} // namespace detail
} // namespace memory
} // namespace a_util

#endif // A_UTIL_UTIL_MEMORY_DETAIL_SHARED_PTR_CXX11_HEADER_INCLUDED
