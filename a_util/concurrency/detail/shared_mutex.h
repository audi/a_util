/**
 * @file
 * Shared mutex fallback implementation header for platforms not supporting @c std::shared_mutex
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

#ifndef A_UTIL_UTIL_CONCURRENCY_DETAIL_SHARED_MUTEX_FALLBACK_HEADER_INCLUDED
#define A_UTIL_UTIL_CONCURRENCY_DETAIL_SHARED_MUTEX_FALLBACK_HEADER_INCLUDED

#include "a_util/memory/unique_ptr.h"

namespace a_util
{
namespace concurrency
{
namespace detail
{

/// shared_mutex class
class shared_mutex
{
    shared_mutex(const shared_mutex&);            // = delete;
    shared_mutex& operator=(const shared_mutex&); // = delete;

    struct impl;
    a_util::memory::unique_ptr<impl> p;

public:
    /// CTOR - creates the mutex in an unlocked state
    shared_mutex();

    /// DTOR - does not call unlock!
    ~shared_mutex();

    /// locks the mutex, blocks if the mutex is not available
    void lock();

    /// tries to lock the mutex, returns if the mutex is not available
    bool try_lock();

    /// unlocks the mutex
    void unlock();

    /// locks the mutex for shared ownership, blocks if the mutex is not available
    void lock_shared();

    /// tries to lock the mutex for shared ownership, returns if the mutex is not available
    bool try_lock_shared();

    /// unlocks the mutex (shared ownership)
    void unlock_shared();
};

} // namespace detail
} // namespace concurrency
} // namespace a_util

#endif // A_UTIL_UTIL_CONCURRENCY_DETAIL_SHARED_MUTEX_FALLBACK_HEADER_INCLUDED
