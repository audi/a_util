/**
 * @file
 * Variant test implementation
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

#include <stdexcept>
#include "gtest/gtest.h"
#include "a_util/variant.h"

using namespace a_util;
using namespace a_util::variant;

TEST(variant_test, TestVariantCTORS)
{
    // CTORS, getType, isEmpty, CCTOR
    Variant var;
    ASSERT_TRUE(var.isEmpty());
    ASSERT_EQ(var.getType(), VT_Empty);

    Variant var2 = true;
    ASSERT_FALSE(var2.isEmpty());
    ASSERT_EQ(var2.getType(), VT_Bool);

    Variant var3 = (int8_t) 1;
    ASSERT_FALSE(var3.isEmpty());
    ASSERT_EQ(var3.getType(), VT_Int8);

    Variant var4 = (uint8_t) 1;
    ASSERT_FALSE(var4.isEmpty());
    ASSERT_EQ(var4.getType(), VT_UInt8);

    Variant var5 = (int16_t) 1;
    ASSERT_FALSE(var5.isEmpty());
    ASSERT_EQ(var5.getType(), VT_Int16);

    Variant var6 = (uint16_t) 1;
    ASSERT_FALSE(var6.isEmpty());
    ASSERT_EQ(var6.getType(), VT_UInt16);

    Variant var7 = (int32_t) 1;
    ASSERT_FALSE(var7.isEmpty());
    ASSERT_EQ(var7.getType(), VT_Int32);

    Variant var8 = (uint32_t) 1;
    ASSERT_FALSE(var8.isEmpty());
    ASSERT_EQ(var8.getType(), VT_UInt32);

    Variant var9 = (int64_t) 1;
    ASSERT_FALSE(var9.isEmpty());
    ASSERT_EQ(var9.getType(), VT_Int64);

    Variant var10 = (uint64_t) 1;
    ASSERT_FALSE(var10.isEmpty());
    ASSERT_EQ(var10.getType(), VT_UInt64);

    Variant var11 = 1.0f;
    ASSERT_FALSE(var11.isEmpty());
    ASSERT_EQ(var11.getType(), VT_Float);

    Variant var12 = 1.0;
    ASSERT_FALSE(var12.isEmpty());
    ASSERT_EQ(var12.getType(), VT_Double);

    Variant var13 = "abc";
    ASSERT_FALSE(var13.isEmpty());
    ASSERT_EQ(var13.getType(), VT_String);

    // CCTOR
    Variant var14 = var13;
    ASSERT_EQ(var14.getType(), VT_String);
    ASSERT_TRUE(a_util::strings::isEqual(var14.getString(), "abc"));

    Variant var15 = var12;
    ASSERT_EQ(var15.getType(), VT_Double);
    ASSERT_EQ(var15.asDouble(), 1.0);

    bool arr[] = {true, true, false};
    ASSERT_NO_THROW(var15.reset(arr, 3));

    Variant var16 = var15;
    ASSERT_EQ(var16.getArraySize(), 3);
    ASSERT_TRUE(var16.isArray());
    ASSERT_EQ(var16.getBool(0), true);
    ASSERT_EQ(var16.getBool(1), true);
    ASSERT_EQ(var16.getBool(2), false);
}

TEST(variant_test, TestVariantReset)
{
    // reset overloads, Get overloads, assignment operators
    Variant var;
    EXPECT_NO_THROW(var.reset(true));
    EXPECT_EQ(var.getType(), VT_Bool);
    EXPECT_EQ(var.getBool(), true);

    EXPECT_NO_THROW(var.reset((int8_t) -42));
    EXPECT_EQ(var.getType(), VT_Int8);
    EXPECT_EQ(var.getInt8(), -42);

    EXPECT_NO_THROW(var.reset((uint8_t) 42));
    EXPECT_EQ(var.getType(), VT_UInt8);
    EXPECT_EQ(var.getUInt8(), 42);

    EXPECT_NO_THROW(var.reset((int16_t) -42));
    EXPECT_EQ(var.getType(), VT_Int16);
    EXPECT_EQ(var.getInt16(), -42);

    EXPECT_NO_THROW(var.reset((uint16_t) 42));
    EXPECT_EQ(var.getType(), VT_UInt16);
    EXPECT_EQ(var.getUInt16(), 42);

    EXPECT_NO_THROW(var.reset((int32_t) -42));
    EXPECT_EQ(var.getType(), VT_Int32);
    EXPECT_EQ(var.getInt32(), -42);

    EXPECT_NO_THROW(var.reset((uint32_t) 42));
    EXPECT_EQ(var.getType(), VT_UInt32);
    EXPECT_EQ(var.getUInt32(), 42);

    EXPECT_NO_THROW(var.reset((int64_t) -42));
    EXPECT_EQ(var.getType(), VT_Int64);
    EXPECT_EQ(var.getInt64(), -42);

    EXPECT_NO_THROW(var.reset((uint64_t) 42));
    EXPECT_EQ(var.getType(), VT_UInt64);
    EXPECT_EQ(var.getUInt64(), 42);

    EXPECT_NO_THROW(var.reset(42.0f));
    EXPECT_EQ(var.getType(), VT_Float);
    EXPECT_EQ(var.getFloat(), 42.0f);

    EXPECT_NO_THROW(var.reset(42.0));
    EXPECT_EQ(var.getType(), VT_Double);
    EXPECT_EQ(var.getDouble(), 42.0);

    EXPECT_NO_THROW(var.reset("Hallo"));
    EXPECT_EQ(var.getType(), VT_String);
    EXPECT_EQ(std::string(var.getString()), "Hallo");

    EXPECT_NO_THROW(var.reset());
    EXPECT_EQ(var.getType(), VT_Empty);

    // assignment operators
    var = true;
    EXPECT_EQ(var.getType(), VT_Bool);
    EXPECT_EQ(var.getBool(), true);

    var = (int8_t) -42;
    EXPECT_EQ(var.getType(), VT_Int8);
    EXPECT_EQ(var.getInt8(), -42);

    var = (uint8_t) 42;
    EXPECT_EQ(var.getType(), VT_UInt8);
    EXPECT_EQ(var.getUInt8(), 42);

    var = (int16_t) -42;
    EXPECT_EQ(var.getType(), VT_Int16);
    EXPECT_EQ(var.getInt16(), -42);

    var = (uint16_t) 42;
    EXPECT_EQ(var.getType(), VT_UInt16);
    EXPECT_EQ(var.getUInt16(), 42);

    var = (int32_t) -42;
    EXPECT_EQ(var.getType(), VT_Int32);
    EXPECT_EQ(var.getInt32(), -42);

    var = (uint32_t) 42;
    EXPECT_EQ(var.getType(), VT_UInt32);
    EXPECT_EQ(var.getUInt32(), 42);

    var = (int64_t) -42;
    EXPECT_EQ(var.getType(), VT_Int64);
    EXPECT_EQ(var.getInt64(), -42);

    var = (uint64_t) 42;
    EXPECT_EQ(var.getType(), VT_UInt64);
    EXPECT_EQ(var.getUInt64(), 42);

    var = 42.0f;
    EXPECT_EQ(var.getType(), VT_Float);
    EXPECT_EQ(var.getFloat(), 42.0f);

    var = 42.0;
    EXPECT_EQ(var.getType(), VT_Double);
    EXPECT_EQ(var.getDouble(), 42.0);

    var = "Blubb";
    EXPECT_EQ(var.getType(), VT_String);
    EXPECT_EQ(std::string(var.getString()), "Blubb");
    var = "Bla";
    EXPECT_EQ(std::string(var.getString()), "Bla");
    var = "Blabber";
    EXPECT_EQ(std::string(var.getString()), "Blabber");

    Variant var2 = false;
    var = var2;
    EXPECT_EQ(var2.getType(), VT_Bool);
    EXPECT_EQ(var2.getBool(), false);
    EXPECT_EQ(var.getType(), VT_Bool);
    EXPECT_EQ(var.getBool(), false);
}

void TestConversion(Variant& var,
                    bool b,
                    int8_t i8,
                    uint8_t u8,
                    int16_t i16,
                    uint16_t u16,
                    int32_t i32,
                    uint32_t u32,
                    int64_t i64,
                    uint64_t u64,
                    float f,
                    double d,
                    const char* s)
{
    EXPECT_EQ(var.asBool(), b);
    EXPECT_EQ(var.asInt8(), i8);
    EXPECT_EQ(var.asUInt8(), u8);
    EXPECT_EQ(var.asInt16(), i16);
    EXPECT_EQ(var.asUInt16(), u16);
    EXPECT_EQ(var.asInt32(), i32);
    EXPECT_EQ(var.asUInt32(), u32);
    EXPECT_EQ(var.asInt64(), i64);
    EXPECT_EQ(var.asUInt64(), u64);
    EXPECT_EQ(var.asFloat(), f);
    EXPECT_EQ(var.asDouble(), f);
    EXPECT_EQ(var.asString(), s);
    EXPECT_EQ((bool) var, b);
    EXPECT_EQ((int8_t) var, i8);
    EXPECT_EQ((uint8_t) var, u8);
    EXPECT_EQ((int16_t) var, i16);
    EXPECT_EQ((uint16_t) var, u16);
    EXPECT_EQ((int32_t) var, i32);
    EXPECT_EQ((uint32_t) var, u32);
    EXPECT_EQ((int64_t) var, i64);
    EXPECT_EQ((uint64_t) var, u64);
    EXPECT_EQ((float) var, f);
    EXPECT_EQ((double) var, d);
    EXPECT_EQ((std::string) var, s);
}

TEST(variant_test, TestVariantConversion)
{
    // As, conversion operators
    Variant var;
    var = true;
    TestConversion(var, true, 1, 1, 1, 1, 1, 1, 1, 1, 1.0f, 1.0, "true");

    var = (int8_t) 0;
    TestConversion(var, false, 0, 0, 0, 0, 0, 0, 0, 0, 0.0f, 0.0, "0");

    var = (uint8_t) 1;
    TestConversion(var, true, 1, 1, 1, 1, 1, 1, 1, 1, 1.0f, 1.0, "1");

    var = (int16_t) -1;
    TestConversion(var,
                   true,
                   -1,
                   (uint8_t) -1,
                   -1,
                   (uint16_t) -1,
                   -1,
                   (uint32_t) -1,
                   -1,
                   (uint64_t) -1,
                   -1.0f,
                   -1.0,
                   "-1");

    var = (uint16_t) 1;
    TestConversion(var, true, 1, 1, 1, 1, 1, 1, 1, 1, 1.0f, 1.0, "1");

    var = (int32_t) 1;
    TestConversion(var, true, 1, 1, 1, 1, 1, 1, 1, 1, 1.0f, 1.0, "1");

    var = (uint32_t) 0;
    TestConversion(var, false, 0, 0, 0, 0, 0, 0, 0, 0, 0.0f, 0.0, "0");

    var = (int64_t) 1;
    TestConversion(var, true, 1, 1, 1, 1, 1, 1, 1, 1, 1.0f, 1.0, "1");

    var = (uint64_t) 1;
    TestConversion(var, true, 1, 1, 1, 1, 1, 1, 1, 1, 1.0f, 1.0, "1");

    var = 1.0f;
    TestConversion(var, true, 1, 1, 1, 1, 1, 1, 1, 1, 1.0f, 1.0, "1.000000");

    var = 1.0;
    TestConversion(var, true, 1, 1, 1, 1, 1, 1, 1, 1, 1.0f, 1.0, "1.000000");

    var = "1";
    TestConversion(var, true, 1, 1, 1, 1, 1, 1, 1, 1, 1.0f, 1.0, "1");

    var = "true";
    TestConversion(var, true, 0, 0, 0, 0, 0, 0, 0, 0, 0.0f, 0.0, "true");

    var = "false";
    TestConversion(var, false, 0, 0, 0, 0, 0, 0, 0, 0, 0.0f, 0.0, "false");
}

TEST(variant_test, TestVariantArrays)
{
    // getArraySize, isArray, reset overloads, Get overloads
    Variant var;
    ASSERT_EQ(var.getArraySize(), 0);
    ASSERT_FALSE(var.isArray());
    var = true;
    ASSERT_FALSE(var.isArray());

    bool arr[] = {true, true, false};
    ASSERT_NO_THROW(var.reset(arr, 3));
    ASSERT_EQ(var.getArraySize(), 3);
    ASSERT_TRUE(var.isArray());
    ASSERT_EQ(var.getBool(0), true);
    ASSERT_EQ(var.getBool(1), true);
    ASSERT_EQ(var.getBool(2), false);

    ASSERT_THROW(var.reset((uint8_t*) nullptr, 0), std::invalid_argument);
    ASSERT_THROW(var.getBool(4), std::out_of_range);

    int8_t arr2[] = {1, 2, 3};
    ASSERT_NO_THROW(var.reset(arr2, 3));
    ASSERT_EQ(var.getArraySize(), 3);
    ASSERT_TRUE(var.isArray());
    ASSERT_EQ(var.getInt8(0), 1);
    ASSERT_EQ(var.getInt8(1), 2);
    ASSERT_EQ(var.getInt8(2), 3);

    double arr3[] = {1.0, 2.0, 3.0};
    ASSERT_NO_THROW(var.reset(arr3, 3));
    ASSERT_EQ(var.getArraySize(), 3);
    ASSERT_TRUE(var.isArray());
    ASSERT_EQ(var.getDouble(0), 1.0);
    ASSERT_EQ(var.getDouble(1), 2.0);
    ASSERT_EQ(var.getDouble(2), 3.0);
}

TEST(variant_test, TestVariantComparison)
{
    // Comparison operators
    EXPECT_TRUE(Variant(true) == Variant(true));
    EXPECT_TRUE(Variant(true) != Variant(false));
    EXPECT_TRUE(Variant((int8_t) -42) == Variant((int8_t) -42));
    EXPECT_TRUE(Variant((int8_t) -42) != Variant((int8_t) -21));
    EXPECT_TRUE(Variant((uint8_t) 42) == Variant((uint8_t) 42));
    EXPECT_TRUE(Variant((uint8_t) 42) != Variant((uint8_t) 21));
    EXPECT_TRUE(Variant((int16_t) -42) == Variant((int16_t) -42));
    EXPECT_TRUE(Variant((int16_t) -42) != Variant((int16_t) -21));
    EXPECT_TRUE(Variant((uint16_t) 42) == Variant((uint16_t) 42));
    EXPECT_TRUE(Variant((uint16_t) 42) != Variant((uint16_t) 21));
    EXPECT_TRUE(Variant((int32_t) -42) == Variant((int32_t) -42));
    EXPECT_TRUE(Variant((int32_t) -42) != Variant((int32_t) -21));
    EXPECT_TRUE(Variant((uint32_t) 42) == Variant((uint32_t) 42));
    EXPECT_TRUE(Variant((uint32_t) 42) != Variant((uint32_t) 21));
    EXPECT_TRUE(Variant((int64_t) -42) == Variant((int64_t) -42));
    EXPECT_TRUE(Variant((int64_t) -42) != Variant((int64_t) -21));
    EXPECT_TRUE(Variant((uint64_t) 42) == Variant((uint64_t) 42));
    EXPECT_TRUE(Variant((uint64_t) 42) != Variant((uint64_t) 21));
    EXPECT_TRUE(Variant((float) 42.0f) == Variant((float) 42.0f));
    EXPECT_TRUE(Variant((float) 42.0f) != Variant((float) 21.0f));
    EXPECT_TRUE(Variant((double) 42.0) == Variant((double) 42.0));
    EXPECT_TRUE(Variant((double) 42.0) != Variant((double) 21.0));
    EXPECT_TRUE(Variant("Hello") == Variant("Hello"));
    EXPECT_TRUE(Variant("Hi") != Variant("Hello"));

    EXPECT_TRUE(Variant(false) != Variant((int8_t) 1));
    EXPECT_TRUE(Variant((int8_t) 1) != Variant((uint8_t) 1));
    EXPECT_TRUE(Variant((uint8_t) 1) != Variant((int16_t) 1));
    EXPECT_TRUE(Variant((int16_t) 1) != Variant((uint16_t) 1));
    EXPECT_TRUE(Variant((uint16_t) 1) != Variant((int32_t) 1));
    EXPECT_TRUE(Variant((int32_t) 1) != Variant((uint32_t) 1));
    EXPECT_TRUE(Variant((uint32_t) 1) != Variant((int64_t) 1));
    EXPECT_TRUE(Variant((int64_t) 1) != Variant((uint64_t) 1));
    EXPECT_TRUE(Variant((uint64_t) 1) != Variant(1.0f));
    EXPECT_TRUE(Variant(1.0f) != Variant(1.0));
    EXPECT_TRUE(Variant(1.0) != Variant(""));

    Variant var1, var2;
    double arr1[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double arr2[] = {1.0, 2.0, 3.0, 4.0, 5.0};

    ASSERT_NO_THROW(var1.reset(arr1, 5));
    ASSERT_NO_THROW(var2.reset(arr2, 5));
    EXPECT_TRUE(var1 == var2);

    ASSERT_NO_THROW(var1.reset(arr1, 4));
    EXPECT_FALSE(var1 == var2);

    double arr3[] = {1.0, 2.0, 3.0, 3.0, 3.0};
    ASSERT_NO_THROW(var1.reset(arr3, 5));
    EXPECT_FALSE(var1 == var2);
}
