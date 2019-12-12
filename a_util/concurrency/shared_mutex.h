/**
 * @file
 * Shared mutex
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

#ifndef A_UTIL_UTIL_CONCURRENCY_SHARED_MUTEX_HEADER_INCLUDED
#define A_UTIL_UTIL_CONCURRENCY_SHARED_MUTEX_HEADER_INCLUDED

// before suggesting std::shared_mutex read this: https://stackoverflow.com/a/42302130
#include "a_util/concurrency/detail/shared_mutex.h"

namespace a_util
{
namespace concurrency
{

using detail::shared_mutex;

} // namespace concurrency
} // namespace a_util

#endif // A_UTIL_UTIL_CONCURRENCY_SHARED_MUTEX_HEADER_INCLUDED
