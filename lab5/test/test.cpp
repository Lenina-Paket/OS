#include <gtest/gtest.h>
#include "../include/allocator.hpp"
#include "../include/vector.hpp" 

std::size_t BLOCK_SIZE = 50000;
TEST(custom_vector_methods, test_01) {
    Vector<int, Allocator<int>> vec;

    for (int i = 0; i < 5; i++) {
        vec.pushBack(i*i);
    }
    ASSERT_EQ(vec.size(), 5);
    vec.pop_back();
    ASSERT_EQ(vec.size(), 4);
    vec.clear();
    ASSERT_EQ(vec.size(), 0);
    ASSERT_EQ(vec.empty(), true);
}

TEST(custom_vector_methods, test_02) {
    Vector<double, Allocator<double>> vec;
    for (int i = 0; i < 5; i++) {
        vec.pushBack(i*i);
    }
    Vector<double, Allocator<double>> other(vec);

    ASSERT_EQ(vec.size(), other.size());
    for (int i = 0; i < vec.size(); i++) {
        ASSERT_EQ(vec[i], other[i]);
    }

    Vector<double, Allocator<double>> moved(std::move(vec));
    ASSERT_EQ(moved.size(), other.size());
    for (int i = 0; i < moved.size(); i++) {
        ASSERT_EQ(moved[i], other[i]);
    }
}

TEST(custom_vector_iter, test_01) {
    Vector<int, Allocator<int>> vec;
    for (int i = 0; i < 5; ++i) {
        vec.pushBack(i);
    }
    auto iter = vec.cbegin();
    for (int i = 0; i < vec.size(); i++) {
        ASSERT_EQ(*iter, i);
        ++iter;
    }
    ASSERT_EQ(iter, vec.cend());
}

TEST(custom_vector_iter, test_02) {
    Vector<int, Allocator<int>> vec;
    for (int i = 0; i < 5; ++i) {
        vec.pushBack(i);
    }
    auto iter = vec.begin();
    for (int i = 0; i < vec.size(); i++) {
        ASSERT_EQ(*iter, i);
        ++iter;
    }
    ASSERT_EQ(iter, vec.end());
}

TEST(allocator, test_01) {
    Allocator<int> alloc;
    ASSERT_ANY_THROW(int* data = alloc.allocate(78000000000));
}

TEST(allocator, test_02) {
    Allocator<int> alloc;
    int* data = alloc.allocate(1000);
    ASSERT_ANY_THROW(alloc.deallocate(data, 1001));
}

TEST(allocator, test_03) {
    Allocator<int> alloc;
    int* data = alloc.allocate(1000);
    alloc.deallocate(data, 999);
    ASSERT_EQ(BLOCK_SIZE - alloc.free_count(), 1);
}

TEST(iterator, test_01) {
    Vector<int, Allocator<int>> vec;
    vec.pushBack(1);
    vec.pushBack(2);
    auto iter = vec.begin();
    auto iter2 = vec.end();

    ASSERT_EQ(*iter, 1);
    ASSERT_FALSE(iter == iter2);
    ASSERT_TRUE(iter != iter2);
}

TEST(Iterator, test_02) {
    Vector<int, Allocator<int>> vec;
    vec.pushBack(1);
    vec.pushBack(2);
    vec.pushBack(3);
    Vector<int, Allocator<int>>::Iterator iter(vec, 0);
    ASSERT_EQ(*iter, 1);
    ++iter;
    ASSERT_EQ(*iter, 2);
    ++iter;
    ASSERT_EQ(*iter, 3);
    ++iter;
    ASSERT_EQ(iter, vec.end());
    ASSERT_ANY_THROW(++iter);
}

TEST(const_iterator, test_01) {
    Vector<int, Allocator<int>> vec;
    vec.pushBack(1);
    vec.pushBack(2);
    auto iter = vec.cbegin();
    auto iter2 = vec.cend();

    ASSERT_EQ(*iter, 1);
    ASSERT_FALSE(iter == iter2);
    ASSERT_TRUE(iter != iter2);
}

TEST(Const_iterator, test_02) {
    Vector<int, Allocator<int>> vec;
    vec.pushBack(1);
    vec.pushBack(2);
    vec.pushBack(3);
    Vector<int, Allocator<int>>::ConstIterator iter(vec, 0);
    ASSERT_EQ(*iter, 1);
    ++iter;
    ASSERT_EQ(*iter, 2);
    ++iter;
    ASSERT_EQ(*iter, 3);
    ++iter;
    ASSERT_EQ(iter, vec.cend());
    ASSERT_ANY_THROW(++iter);
}
