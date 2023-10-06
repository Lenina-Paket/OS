#include <gtest/gtest.h>
#include "thirteen.h"

TEST(equal, test01) {
    Thirteen num1("0"), num2("0");
    ASSERT_TRUE(num1 == num2);
}

TEST(equal, test02) {
    Thirteen num1("00000000000000"), num2("0");
    std::cout << num1 << ' ' << num2 << std::endl;
    ASSERT_TRUE(num1 == num2);
}

TEST(equal, test03) {
    Thirteen num1("1a2"), num2("1a1");
    ASSERT_FALSE(num1 == num2);
}

TEST(equal, test04) {
    Thirteen num1("31a");
    ASSERT_TRUE(num1 == Thirteen("31a"));
}

TEST(equal, test05) {
    Thirteen num1("aaa");
    ASSERT_FALSE(num1 == Thirteen("aab"));
}

TEST(equal, test06) {
    Thirteen num1("00000000000000aaa"), num2("aaa");
    ASSERT_TRUE(num1 == num2);
}



TEST(not_equal, test01) {
    Thirteen num1("10abc"), num2("10abc");
    ASSERT_FALSE(num1 != num2);
}

TEST(not_equal, test02) {
    Thirteen num1("abc"), num2("1000");
    ASSERT_TRUE(num1 != num2);
}

TEST(not_eq, test03) {
    Thirteen num1("322");
    ASSERT_TRUE(num1 != Thirteen());
}

TEST (greater, test01) {
    Thirteen num1("10abc"), num2("22c");
    ASSERT_TRUE(num1 > num2);
}

TEST(greater, test02) {
    Thirteen num1("10abc");
    ASSERT_FALSE(num1 > num1);
}

TEST(greater, test03) {
    Thirteen num1("1010b"), num2("10010");
    ASSERT_TRUE(num1 > num2);
}

TEST(greater, test04) {
    Thirteen num1("10b"), num2("22c");
    ASSERT_FALSE(num1 > num2);
}


TEST(greater_or_eq, test01) {
    Thirteen num1("10abc"), num2("22c");
    ASSERT_TRUE(num1 >= num2);
}

TEST(greater_or_eq, test02) {
    Thirteen num1("10abc");
    ASSERT_TRUE(num1 >= num1);
}


TEST(greater_or_eq, test03) {
    Thirteen num1("0"), num2("1220");
    ASSERT_FALSE(num1 >= num2);
}



TEST(less, test01) {
    Thirteen num1("10abc"), num2("22c");
    ASSERT_FALSE(num1 < num2);
}

TEST(less, test02) {
    Thirteen num1("145c");
    ASSERT_FALSE(num1 < num1);
}

TEST(less, test03) {
    Thirteen num1("10100"), num2("10010");
    ASSERT_FALSE(num1 < num2);
}

TEST(less, test04) {
    Thirteen num1("10"), num2("1220");
    ASSERT_TRUE(num1 < num2);
}



TEST(less_or_eq, test01) {
    Thirteen num1("3a4"), num2("1b");
    ASSERT_FALSE(num1 <= num2);
}

TEST(less_or_eq, test02) {
    Thirteen num1("145");
    ASSERT_TRUE(num1 <= num1);
}

TEST(less_or_eq, test03) {
    Thirteen num1("22a"), num2("12");
    ASSERT_FALSE(num1 <= num2);
}

TEST(less_or_eq, test04) {
    Thirteen num1("10"), num2("1220");
    ASSERT_TRUE(num1 <= num2);
}


TEST(add, test01) {
    Thirteen num1("0"), num2("10abc");
    ASSERT_TRUE(num1 + num2 == Thirteen("10abc"));
}

TEST(add, test02) {
    Thirteen num1("10c"), num2("0");
    ASSERT_TRUE(num1 + num2 == Thirteen("10c"));
}

TEST(add, test03) {
    Thirteen num1("4ac"), num2("1");
    ASSERT_TRUE(num1 + num2 == Thirteen("4b0"));
}

TEST(add, test04) {
    Thirteen num1("4acb"), num2("10890");
    ASSERT_TRUE(num1 + num2 == Thirteen("1568b"));
}

TEST(add, test05) {
    Thirteen num1("54b"), num2("22c");
    ASSERT_TRUE(num1 + num2 == Thirteen("77a"));
}

TEST(add, test06) {
    Thirteen num1("4"), num2("1abc2222");
    ASSERT_TRUE(num1 + num2 == Thirteen("1abc2226"));
}

TEST(add, test07) {
    Thirteen num1("00000000000004"), num2("1abc2222");
    std::cout<< num1 << std::endl;
    ASSERT_TRUE(num1 + num2 == Thirteen("1abc2226"));
}

TEST(add_n_ravno, test01) {
    Thirteen num1("0"), num2("4acb");
    num1 += num2;
    ASSERT_TRUE (num1 == num2);
}

TEST(add_n_ravno, test02) {
    Thirteen num1("4acb"), num2("0");
    num1 += num2;
    ASSERT_TRUE (num1 == Thirteen("4acb"));
}

TEST(add_n_ravno, test03) {
    Thirteen num1("4acb"), num2("4acb");
    num1 += num2;
    ASSERT_TRUE (num1 == Thirteen("98c9"));
}

TEST(add_n_ravno, test04) {
    Thirteen num1("4acb"), num2("10890a");
    num1 += num2;
    ASSERT_TRUE (num1 == Thirteen("110708"));
}

TEST(sub, test01) {
    Thirteen num1("10abc104032bc"), num2("22c");
    Thirteen res(num1 - num2);
    ASSERT_TRUE(num1 - num2 == res);
}

TEST(sub, test02) {
    Thirteen num1("4acb10101"), num2("4acb10100");
    Thirteen res = num1 - num2;
    ASSERT_TRUE(num1 - num2 == Thirteen("1"));
}

TEST(sub, test03) {
    Thirteen num1("4acb10101"), num2("4acb10100");
    Thirteen res = num1 - num2;
    ASSERT_TRUE(num1 - num2 == Thirteen("0001"));
}

TEST(sub, test04) {
    Thirteen num1("10abc"), num2("0");
    Thirteen res(num1 - num2);
    ASSERT_TRUE(num1 - num2 == num1);
}

TEST(sub, test05) {
    Thirteen num1("22c"), num2("10abc");
    ASSERT_ANY_THROW(num1 - num2);
}

TEST(sub_n_ravno, test01) {
    Thirteen num1("0"), num2("4acb");
    ASSERT_ANY_THROW(num1 -= num2;);
}

TEST(sub_n_ravno, test02) {
    Thirteen num1("4acb"), num2("0");
    num1 -= num2;
    ASSERT_TRUE (num1 == Thirteen("4acb"));
}

TEST(sub_n_ravno, test03) {
    Thirteen num1("4acb"), num2("4acb");
    num1 -= num2;
    ASSERT_TRUE (num1 == Thirteen("0"));
}

TEST(sub_n_ravno, test04) {
    Thirteen num1("4acb"), num2("1089");
    num1 -= num2;
    ASSERT_TRUE (num1 == Thirteen("3a42"));
}

TEST(sub_n_ravno, test05) {
    Thirteen num1("4acb10101"), num2("4acb10100");
    num1 -= num2;
    ASSERT_TRUE(num1 == Thirteen("1"));
}

TEST(sub_n_ravno, test06) {
    Thirteen num1("4acb"), num2("4acb10100");
    ASSERT_ANY_THROW(num1 -= num2);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}