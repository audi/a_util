/**
 * @file
 * Thread API induction into namespace for platforms supporting @c std::thread
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

#ifndef A_UTIL_UTIL_CONCURRENCY_DETAIL_THREAD_CXX11_HEADER_INCLUDED
#define A_UTIL_UTIL_CONCURRENCY_DETAIL_THREAD_CXX11_HEADER_INCLUDED

#if (defined(__GNUC__) && (__GNUC__ < 5) && (__GNUC_MINOR__ < 7) && (__GXX_EXPERIMENTAL_CXX0X__))
#ifndef _GLIBCXX_USE_SCHED_YIELD
#define _GLIBCXX_USE_SCHED_YIELD
#endif
#endif

#include <thread>

namespace a_util
{
namespace concurrency
{
namespace detail
{

using std::thread;

namespace this_thread
{

using std::this_thread::get_id;
using std::this_thread::yield;

} // namespace this_thread
} // namespace detail
} // namespace concurrency
} // namespace a_util

#endif // A_UTIL_UTIL_CONCURRENCY_DETAIL_THREAD_CXX11_HEADER_INCLUDED
