/**
 * @file
 * Memory test implementation
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
#include "a_util/memory.h"

using namespace a_util;
using namespace a_util::memory;

// Test a_util::memory::copy
TEST(memory_test, TestMemcopy)
{
    uint8_t buf_dst[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    uint8_t buf_src[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    EXPECT_FALSE(a_util::memory::copy(nullptr, 10, buf_src, 10));
    EXPECT_FALSE(a_util::memory::copy(buf_dst, 10, nullptr, 10));
    EXPECT_FALSE(a_util::memory::copy(nullptr, 10, nullptr, 10));
    EXPECT_FALSE(a_util::memory::copy(buf_dst, 10, buf_src, 11));

    EXPECT_TRUE(a_util::memory::copy(buf_dst, 0, buf_src, 0));
    EXPECT_EQ(buf_dst[0], 0);

    EXPECT_TRUE(a_util::memory::copy(buf_dst, 10, buf_src, 1));
    EXPECT_EQ(buf_dst[0], 1);
    EXPECT_EQ(buf_dst[1], 0);

    EXPECT_TRUE(a_util::memory::copy(buf_dst, 10, buf_src, 10));
    for (int i = 0; i < 10; ++i)
    {
        EXPECT_EQ(buf_dst[i], 1);
    }

    a_util::memory::MemoryBuffer buffer;
    EXPECT_TRUE(a_util::memory::copy(buffer, buf_src, 10));

    a_util::memory::MemoryBuffer buffer2(buf_src, 10);
    EXPECT_TRUE(buffer == buffer2);
}

// Test a_util::memory::set
TEST(memory_test, TestMemset)
{
    uint8_t buf_dst[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    EXPECT_FALSE(a_util::memory::set(nullptr, 10, 42, 10));
    EXPECT_FALSE(a_util::memory::set(buf_dst, 10, 42, 11));

    EXPECT_TRUE(a_util::memory::set(buf_dst, 10, 42, 5));
    for (int i = 0; i < 5; ++i)
    {
        EXPECT_EQ(buf_dst[i], 42);
    }
    EXPECT_EQ(buf_dst[5], 5);

    EXPECT_TRUE(a_util::memory::set(buf_dst, 10, 0, 10));
    for (int i = 0; i < 10; ++i)
    {
        EXPECT_EQ(buf_dst[i], 0);
    }

    a_util::memory::MemoryBuffer buffer;
    EXPECT_TRUE(a_util::memory::set(buffer, 0, 10));

    a_util::memory::MemoryBuffer buffer2(buf_dst, 10);
    EXPECT_TRUE(buffer == buffer2);
}

// Test a_util::memory::zero
TEST(memory_test, TestMemzero)
{
    uint8_t buf_dst[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    EXPECT_FALSE(a_util::memory::zero(nullptr, 10, 10));
    EXPECT_FALSE(a_util::memory::zero(buf_dst, 10, 11));

    EXPECT_TRUE(a_util::memory::zero(buf_dst, 10, 5));
    for (int i = 0; i < 5; ++i)
    {
        EXPECT_EQ(buf_dst[i], 0);
    }
    EXPECT_EQ(buf_dst[5], 5);

    EXPECT_TRUE(a_util::memory::zero(buf_dst, 10, 10));
    for (int i = 0; i < 10; ++i)
    {
        EXPECT_EQ(buf_dst[i], 0);
    }

    a_util::memory::MemoryBuffer buffer;
    EXPECT_TRUE(a_util::memory::zero(buffer, 10));

    a_util::memory::MemoryBuffer buffer2(buf_dst, 10);
    EXPECT_TRUE(buffer == buffer2);
}

// Test a_util::memory::memcmp
TEST(memory_test, TestMemcmp)
{
    uint8_t buf_1[4] = {0, 0, 0, 0};
    uint8_t buf_2[4] = {0, 0, 1, 1};

    EXPECT_THROW(a_util::memory::compare(nullptr, 10, buf_2, 10), std::invalid_argument);
    EXPECT_THROW(a_util::memory::compare(buf_1, 10, nullptr, 10), std::invalid_argument);
    EXPECT_THROW(a_util::memory::compare(nullptr, 10, nullptr, 10), std::invalid_argument);
    EXPECT_THROW(a_util::memory::compare(buf_1, 10, buf_2, 11), std::invalid_argument);
    EXPECT_NO_THROW(a_util::memory::compare(buf_1, 0, buf_2, 0));

    EXPECT_EQ(a_util::memory::compare(buf_1, 0, buf_2, 0), 0);
    EXPECT_EQ(a_util::memory::compare(buf_1, 2, buf_2, 2), 0);
    EXPECT_EQ(a_util::memory::compare(buf_1, 4, buf_1, 4), 0);
    EXPECT_TRUE(a_util::memory::compare(buf_1, 4, buf_2, 4) < 0);
    EXPECT_TRUE(a_util::memory::compare(buf_2, 4, buf_1, 4) > 0);
}

// Test a_util::memory::isZero
TEST(memory_test, TestIsZero)
{
    char test_array[42] = {};
    EXPECT_TRUE(a_util::memory::isZero(test_array, sizeof(test_array)));
    test_array[0] = 0x01;
    EXPECT_FALSE(a_util::memory::isZero(test_array, sizeof(test_array)));
    test_array[0] = 0x00;
    test_array[41] = 0x01;
    EXPECT_FALSE(a_util::memory::isZero(test_array, sizeof(test_array)));
    test_array[41] = 0x00;
    test_array[13] = 0x0A;
    EXPECT_FALSE(a_util::memory::isZero(test_array, sizeof(test_array)));
    test_array[13] = 0x00;
    EXPECT_TRUE(a_util::memory::isZero(test_array, sizeof(test_array)));
}

// Test a_util::memory::swap_endianess
TEST(memory_test, TestEndianess)
{
    bool b = false;
    int8_t i8 = 0x77;
    uint8_t u8 = 0xAA;
    EXPECT_TRUE(a_util::memory::swapEndianess(b) == b);
    EXPECT_TRUE(a_util::memory::swapEndianess(i8) == i8);
    EXPECT_TRUE(a_util::memory::swapEndianess(u8) == u8);

    int16_t i16 = 0x7788;
    EXPECT_EQ(a_util::memory::swapEndianess(i16), (int16_t) 0x8877);

    uint16_t u16 = 0xAABB;
    EXPECT_EQ(a_util::memory::swapEndianess(u16), 0xBBAA);

    int32_t i32 = 0x778899AA;
    EXPECT_EQ(a_util::memory::swapEndianess(i32), (int32_t) 0xAA998877);

    uint32_t u32 = 0xAABBCCDD;
    EXPECT_EQ(a_util::memory::swapEndianess(u32), 0xDDCCBBAA);

    int64_t i64 = 0x778899AABBCCDDEE;
    EXPECT_EQ(a_util::memory::swapEndianess(i64), (int64_t) 0xEEDDCCBBAA998877LL);

    uint64_t u64 = 0xBBAAFFEEDDCCBBAA;
    EXPECT_EQ(a_util::memory::swapEndianess(u64), 0xAABBCCDDEEFFAABBULL);
}
