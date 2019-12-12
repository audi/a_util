/**
 * @file
 * Test implementation for Result type return values from library code
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
#include "a_util/result/result_type.h"
#include "a_util/result/result_util.h"
#include "lib/result_tester_lib.h"

TEST(result_type_from_lib_test, TestStackResultFromLibrary)
{
    using a_util::result::Result;
    Result noerror = test::GetResult();
    ASSERT_EQ(noerror, Result());

    Result error_out_of_memory = test::GetResultOutOfMemory();
    ASSERT_EQ(error_out_of_memory.getErrorCode(), ERR_OUT_OF_MEMORY.getCode());
    ASSERT_STREQ(error_out_of_memory.getErrorLabel(), "(unknown)");

    Result detailed_error_out_of_memory = test::GetDetailedResultOutOfMemory();
    ASSERT_EQ(detailed_error_out_of_memory.getErrorCode(), ERR_OUT_OF_MEMORY.getCode());
    EXPECT_STREQ(detailed_error_out_of_memory.getErrorLabel(), "ERR_OUT_OF_MEMORY");
    EXPECT_STREQ(detailed_error_out_of_memory.getDescription(), "Out of memory");
    EXPECT_EQ(detailed_error_out_of_memory.getLine(), 22);

    Result error_out_of_internal_memory = test::GetResultOutOfInternalMemory();
    ASSERT_EQ(error_out_of_internal_memory.getErrorCode(), -1001);
    ASSERT_STREQ(error_out_of_memory.getErrorLabel(), "(unknown)");

    Result detailed_error_out_of_internal_memory = test::GetDetailedResultOutOfInternalMemory();
    ASSERT_EQ(detailed_error_out_of_internal_memory.getErrorCode(), -1001);
    EXPECT_STREQ(detailed_error_out_of_internal_memory.getErrorLabel(),
                 "ERR_OUT_OF_INTERNAL_MEMORY");
    EXPECT_STREQ(detailed_error_out_of_internal_memory.getDescription(), "Out of internal memory");
    EXPECT_EQ(detailed_error_out_of_internal_memory.getLine(), 34);
}
