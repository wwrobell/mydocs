#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "pow.h"

using namespace testing;

TEST(pow2Test, HandlesZeroInput)
{
    EXPECT_EQ(pow2(0), 1);
}

TEST(pow2Test, HandlesOneInput)
{
    EXPECT_EQ(pow2(1), 2);
}

TEST(pow2Test, HandlesPositiveInput)
{
    EXPECT_EQ(pow2(2), 4);
    EXPECT_EQ(pow2(3), 8);
    EXPECT_EQ(pow2(4), 16);
}
