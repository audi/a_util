/**
 * @file
 * Test a_util::maybe_unused function template
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
#include "a_util/base/types.h"

class MaybeUnused : public ::testing::Test
{
protected:
    bool faultyCompareWithUnreferencedFormalParameter(int left, int right) noexcept
    {
        using a_util::maybe_unused;
        maybe_unused(right);
        return left == left;
    }

    bool faultyCompareWithLocalVariableIsInitializedButNotReferenced(int left, int right) noexcept
    {
        using a_util::maybe_unused;
        bool val = (left == right);
        maybe_unused(val);
        return true;
    }
};

TEST_F(MaybeUnused, silencesCompilerWarnings)
{
    EXPECT_TRUE(faultyCompareWithUnreferencedFormalParameter(42, 43));
    EXPECT_TRUE(faultyCompareWithLocalVariableIsInitializedButNotReferenced(42, 43));
}