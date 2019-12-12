/**
 * @file
 * Semapore declaration
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

#ifndef A_UTIL_UTIL_CONCURRENCY_DETAIL_SEMAPHORE_DECL_HEADER_INCLUDED
#define A_UTIL_UTIL_CONCURRENCY_DETAIL_SEMAPHORE_DECL_HEADER_INCLUDED

#include "a_util/concurrency/chrono.h"

namespace a_util
{
namespace concurrency
{
namespace detail
{

/// simple semaphore implementation, combining a mutex and a condvar to manage a counter
template <typename Mutex, typename CondVar>
class basic_semaphore
{
    basic_semaphore(const basic_semaphore&);            // = delete;
    basic_semaphore& operator=(const basic_semaphore&); // = delete;

public:
    /// creates a semaphore initializing its count
    explicit basic_semaphore(int count = 0);

    /// increments the counter and notifies any waiters
    void notify();

    /// decrements the counter, blocking until the count becomes non-zero (if neccessary)
    void wait();

    /// decrements the counter and returns true if the counter is greater than zero else returns
    /// false
    bool try_wait();

    template <typename Rep, typename Period>
    bool wait_for(const a_util::chrono::duration<Rep, Period>& timeout);

    /// resets the counter to 0
    void reset();

    /// returns true if the counter is non-zero
    bool is_set();

protected:
    Mutex _mutex;
    CondVar _cv;
    int _lock_count;
};

} // namespace detail
} // namespace concurrency
} // namespace a_util

#endif // A_UTIL_UTIL_CONCURRENCY_DETAIL_SEMAPHORE_DECL_HEADER_INCLUDED
