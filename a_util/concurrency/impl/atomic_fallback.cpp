/**
 * @file
 * Atomics
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

#include <atomic>
#include <cstdint>
#include "a_util/concurrency/atomic.h"

#ifdef _MSC_VER
#include <intrin.h>

namespace a_util
{
namespace concurrency
{

void memoryBarrier()
{
    ::_ReadWriteBarrier();
}

#else // gcc

namespace a_util
{
namespace concurrency
{

void memoryBarrier()
{
    __sync_synchronize();
}

#endif //_MSC_VER

} // ns concurrency
} // ns a_util
