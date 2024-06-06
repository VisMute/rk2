#include <gtest/gtest.h>
#include "../DenseVector.h"
#include "../DynamicVector.h"
#include "../StaticVector.h"

// Tests para DenseVector
TEST(DenseVectorTest, SizeTest) {
    class MyVector : public DenseVector<MyVector> {
    public:
        using value_type = double;
        constexpr size_t size() const noexcept { return 5; }
        constexpr value_type& operator[](size_t index) noexcept { return data_[index]; }
        constexpr value_type const& operator[](size_t index) const noexcept { return data_[index]; }
        constexpr auto begin() noexcept { return std::begin(data_); }
        constexpr auto begin() const noexcept { return std::begin(data_); }
        constexpr auto end() noexcept { return std::end(data_); }
        constexpr auto end() const noexcept { return std::end(data_); }
    private:
        value_type data_[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    };

    MyVector v;
    ASSERT_EQ(v.size(), 5);
}

TEST(DenseVectorTest, IndexingTest) {
    class MyVector : public DenseVector<MyVector> {
    public:
        using value_type = double;
        constexpr size_t size() const noexcept { return 5; }
        constexpr value_type& operator[](size_t index) noexcept { return data_[index]; }
        constexpr value_type const& operator[](size_t index) const noexcept { return data_[index]; }
        constexpr auto begin() noexcept { return std::begin(data_); }
        constexpr auto begin() const noexcept { return std::begin(data_); }
        constexpr auto end() noexcept { return std::end(data_); }
        constexpr auto end() const noexcept { return std::end(data_); }
    private:
        value_type data_[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    };

    MyVector v;
    ASSERT_EQ(v[0], 1.0);
    ASSERT_EQ(v[1], 2.0);
    ASSERT_EQ(v[2], 3.0);
    ASSERT_EQ(v[3], 4.0);
    ASSERT_EQ(v[4], 5.0);
}

TEST(DenseVectorTest, L2NormTest) {
    class MyVector : public DenseVector<MyVector> {
    public:
        using value_type = double;
        constexpr size_t size() const noexcept { return 5; }
        constexpr value_type& operator[](size_t index) noexcept { return data_[index]; }
        constexpr value_type const& operator[](size_t index) const noexcept { return data_[index]; }
        constexpr auto begin() noexcept { return std::begin(data_); }
        constexpr auto begin() const noexcept { return std::begin(data_); }
        constexpr auto end() noexcept { return std::end(data_); }
        constexpr auto end() const noexcept { return std::end(data_); }
    private:
        value_type data_[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    };

    MyVector v;
    double expected_norm = std::sqrt(1.0 * 1.0 + 2.0 * 2.0 + 3.0 * 3.0 + 4.0 * 4.0 + 5.0 * 5.0);
    ASSERT_NEAR(l2norm(v), expected_norm, 1e-10);
}

// Tests para DynamicVector
TEST(DynamicVectorTest, InitializerListConstructor) {
    DynamicVector<double> v = {1.0, 2.0, 3.0, 4.0, 5.0};
    ASSERT_EQ(v.size(), 5);
    ASSERT_EQ(v[0], 1.0);
    ASSERT_EQ(v[1], 2.0);
    ASSERT_EQ(v[2], 3.0);
    ASSERT_EQ(v[3], 4.0);
    ASSERT_EQ(v[4], 5.0);
}

TEST(DynamicVectorTest, Indexing) {
    DynamicVector<int> v = {1, 2, 3, 4, 5};
    ASSERT_EQ(v[0], 1);
    ASSERT_EQ(v[1], 2);
    ASSERT_EQ(v[2], 3);
    ASSERT_EQ(v[3], 4);
    ASSERT_EQ(v[4], 5);
}

TEST(DynamicVectorTest, Iteration) {
    DynamicVector<std::string> v = {"one", "two", "three", "four", "five"};
    int i = 0;
    for (const auto& elem : v) {
        ASSERT_EQ(elem, std::to_string(i + 1));
        i++;
    }
    ASSERT_EQ(i, 5);
}

// Tests para StaticVector
TEST(StaticVectorTest, InitializerListConstructor) {

    StaticVector<double, 5> v = {1.0, 2.0, 3.0, 4.0, 5.0};
    ASSERT_EQ(v.size(), 5);
    ASSERT_EQ(v[0], 1.0);
    ASSERT_EQ(v[1], 2.0);
    ASSERT_EQ(v[2], 3.0);
    ASSERT_EQ(v[3], 4.0);
    ASSERT_EQ(v[4], 5.0);
}

TEST(StaticVectorTest, Indexing) {
    StaticVector<int, 5> v = {1, 2, 3, 4, 5};
    ASSERT_EQ(v[0], 1);
    ASSERT_EQ(v[1], 2);
    ASSERT_EQ(v[2], 3);
    ASSERT_EQ(v[3], 4);
    ASSERT_EQ(v[4], 5);
}

TEST(StaticVectorTest, Iteration) {
    StaticVector<std::string, 5> v = {"one", "two", "three", "four", "five"};
    int i = 0;
    for (const auto& elem : v) {
        ASSERT_EQ(elem, std::to_string(i + 1));
        i++;
    }
    ASSERT_EQ(i, 5);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
