/**
 * @file
 * Semaphore common include
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

#ifndef A_UTIL_UTIL_CONCURRENCY_SEMAPHORE_HEADER_INCLUDED
#define A_UTIL_UTIL_CONCURRENCY_SEMAPHORE_HEADER_INCLUDED

#include "a_util/concurrency/condition_variable.h"
#include "a_util/concurrency/mutex.h"
#include "a_util/concurrency/detail/semaphore_decl.h"
#include "a_util/concurrency/detail/semaphore_impl.h"

namespace a_util
{
namespace concurrency
{

typedef detail::basic_semaphore<mutex, condition_variable> semaphore;

} // namespace concurrency
} // namespace a_util

#endif // A_UTIL_UTIL_CONCURRENCY_SEMAPHORE_HEADER_INCLUDED
