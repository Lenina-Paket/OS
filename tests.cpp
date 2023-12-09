#include <gtest/gtest.h>
#include "closest_pair_tonum.h"

TEST(test_01, basic_test_set)
{
    ASSERT_TRUE(closest_pair_tonum(50).first == 45);
    ASSERT_TRUE(closest_pair_tonum(50).second == 36);
}

TEST(test_02, basic_test_set)
{
    ASSERT_TRUE(closest_pair_tonum(10).first == 5);
    ASSERT_TRUE(closest_pair_tonum(10).second == 4);
}

TEST(test_03, basic_test_set)
{
    ASSERT_TRUE(closest_pair_tonum(30).first == 29);
    ASSERT_TRUE(closest_pair_tonum(30).second == 20);
}

TEST(test_04, basic_test_set)
{
    ASSERT_TRUE(closest_pair_tonum(103).first == 101);
    ASSERT_TRUE(closest_pair_tonum(103).second == 20);
}

TEST(test_05, basic_test_set)
{
    ASSERT_TRUE(closest_pair_tonum(1034).first == 1033);
    ASSERT_TRUE(closest_pair_tonum(1034).second == 192);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}