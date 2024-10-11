#include <gtest/gtest.h>
#include "../include/row.h"

TEST(RowTest, Constructor) {
    Row r;
    EXPECT_EQ(r.size(), 0);
}

TEST(RowTest, ConstructorWithSize) {
    Row r(3);
    EXPECT_EQ(r.size(), 3);
    EXPECT_EQ(r[0], 0);
    EXPECT_EQ(r[1], 0);
    EXPECT_EQ(r[2], 0);
}

TEST(RowTest, CopyConstructor) {
    Row r(3);
    r[0] = 1;
    r[1] = 2;
    r[2] = 3;

    Row r2(r);
    EXPECT_EQ(r2.size(), 3);
    EXPECT_EQ(r2[0], 1);
    EXPECT_EQ(r2[1], 2);
    EXPECT_EQ(r2[2], 3);
}

TEST(RowTest, AssignmentOperator) {
    Row r(3);
    r[0] = 1;
    r[1] = 2;
    r[2] = 3;

    Row r2;
    r2 = r;
    EXPECT_EQ(r2.size(), 3);
    EXPECT_EQ(r2[0], 1);
    EXPECT_EQ(r2[1], 2);
    EXPECT_EQ(r2[2], 3);
}

TEST(RowTest, IndexOperator) {
    Row r(3);
    r[0] = 1;
    r[1] = 2;
    r[2] = 3;

    EXPECT_EQ(r[0], 1);
    EXPECT_EQ(r[1], 2);
    EXPECT_EQ(r[2], 3);
}

TEST(RowTest, IndexOperatorOutOfRange) {
    Row r(3);
    EXPECT_THROW(r[3], std::out_of_range);
}

TEST(RowTest, IndexOperatorNegative) {
    Row r(3);
    EXPECT_THROW(r[-1], std::out_of_range);
}

TEST(RowTest, Resize) {
    Row r(3);
    r[0] = 1;
    r[1] = 2;
    r[2] = 3;
    r.resize(4);

    EXPECT_EQ(r.size(), 4);
    EXPECT_EQ(r[0], 1);
    EXPECT_EQ(r[1], 2);
    EXPECT_EQ(r[2], 3);
    EXPECT_EQ(r[3], 0);
}

TEST(RowTest, InequalityOperator) {
    Row r(3);
    Row r2(3);
    r2[0] = 1;
    r2[1] = 2;
    r2[2] = 3;

    EXPECT_TRUE(r != r2);
}

TEST(RowTest, EqualityOperator) {
    Row r(3);
    Row r2(3);
    r[0] = 1;
    r[1] = 2;
    r[2] = 3;
    r2[0] = 1;
    r2[1] = 2;
    r2[2] = 3;

    EXPECT_TRUE(r == r2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}