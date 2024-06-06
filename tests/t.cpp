
#include "../DynamicVector.h"
#include "../StaticVector.h"
#include <gtest/gtest.h>

TEST(DynamicVectorTest, ConstructorTest) {
    DynamicVector<int> v = {1, 2, 3};
    ASSERT_EQ(v.size(), 3);
    ASSERT_EQ(v[0], 1);
    ASSERT_EQ(v[1], 2);
    ASSERT_EQ(v[2], 3);
}

TEST(DynamicVectorTest, AssignmentTest) {
    DynamicVector<int> v = {1, 2, 3};
    DynamicVector<int> w = v;
    ASSERT_EQ(w.size(), 3);
    ASSERT_EQ(w[0], 1);
    ASSERT_EQ(w[1], 2);
    ASSERT_EQ(w[2], 3);
}

TEST(StaticVectorTest, ConstructorTest) {
    StaticVector<int, 4> v = {4, 5, 6, 7};
    ASSERT_EQ(v.size(), 4);
    ASSERT_EQ(v[0], 4);
    ASSERT_EQ(v[1], 5);
    ASSERT_EQ(v[2], 6);
    ASSERT_EQ(v[3], 7);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}