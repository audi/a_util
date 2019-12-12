/**
 * @file
 * Condition variable test implementation
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

#include "gtest/gtest.h"
#include "a_util/concurrency.h"
#include "a_util/system.h"
using namespace a_util;

struct CondVarTestStruct
{
    concurrency::condition_variable& cond;
    concurrency::mutex& mtx;
    volatile bool& signal;
    CondVarTestStruct(concurrency::condition_variable& cond_,
                      concurrency::mutex& mtx_,
                      bool& signal_)
        : cond(cond_), mtx(mtx_), signal(signal_)
    {
    }

    void Work()
    {
        concurrency::unique_lock<concurrency::mutex> guard(mtx);
        ASSERT_FALSE(signal);
        while (!signal)
        {
            cond.wait_for(guard, a_util::chrono::minutes(1));
            concurrency::memoryBarrier();
        }
    }
};

TEST(condvar_test, TestCondVar)
{
    concurrency::condition_variable cond;
    concurrency::mutex mtx;
    bool signal = false;

    CondVarTestStruct test(cond, mtx, signal);
    concurrency::thread th(&CondVarTestStruct::Work, &test);
    system::sleepMilliseconds(500);

    {
        concurrency::unique_lock<concurrency::mutex> guard(mtx);
        signal = true;
        cond.notify_one();
    }

    th.join();
}
