#include <gtest/gtest.h>
#include "../include/real_matrix.h"

TEST(RealMatrixTest, SaveLoad) {
    RealMatrix a(2, 2);
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 3;
    a[1][1] = 4;
    a.save_to_file("test.txt");
    RealMatrix b;
    b.load_from_file("test.txt");
    EXPECT_EQ(a[0][0], b[0][0]);
    EXPECT_EQ(a[0][1], b[0][1]);
    EXPECT_EQ(a[1][0], b[1][0]);
    EXPECT_EQ(a[1][1], b[1][1]);
}

TEST(RealMatrixTest, LoadException) {
    RealMatrix a;
    EXPECT_THROW(a.load_from_file("nonexistent.txt"), std::runtime_error);
}

TEST(RealMatrixTest, ResizeSubmatrix) {
    RealMatrix a;
    a.load_from_file("test.txt");
    a.resize(1, 1);
    RealMatrix b = a.submatrix(1, 1);
    EXPECT_EQ(a, b);
}

TEST(RealMatrixTest, Transpose) {
    RealMatrix a;
    a.load_from_file("test.txt");
    a.T();
    EXPECT_EQ(a[0][0], 1);
    EXPECT_EQ(a[0][1], 3);
    EXPECT_EQ(a[1][0], 2);
    EXPECT_EQ(a[1][1], 4);
}

TEST(RealMatrixTest, Determinant1x1) {
    RealMatrix a(1, 1);
    a[0][0] = 1;
    EXPECT_EQ(a.det(), 1);
}

TEST(RealMatrixTest, Determinant1x2) {
    RealMatrix a(1, 2);
    double result;
    EXPECT_THROW(result = a.det(), std::logic_error);
    result += 1;
}

TEST(RealMatrixTest, Determinant2x2) {
    RealMatrix a;
    a.load_from_file("test.txt");
    EXPECT_EQ(a.det(), -2);
}

TEST(RealMatrixTest, Determinant3x3) {
    RealMatrix a(3, 3);
    for (int i = 0; i < 3; i += 1) {
        for (int j = 0; j < 3; j += 1) {
            a[i][j] = i + j;
        }
    }
    EXPECT_EQ(a.det(), 0);
}

TEST(RealMatrixTest, Norm) {
    RealMatrix a;
    a.load_from_file("test.txt");
    EXPECT_EQ(a.norm(), 7);
}

TEST(RealMatrixTest, PrefixIncrement) {
    RealMatrix a;
    a.load_from_file("test.txt");
    ++a;
    EXPECT_EQ(a[0][0], 2);
    EXPECT_EQ(a[0][1], 3);
    EXPECT_EQ(a[1][0], 4);
    EXPECT_EQ(a[1][1], 5);
}

TEST(RealMatrixTest, PostfixIncrement) {
    RealMatrix a;
    a.load_from_file("test.txt");
    a++;
    EXPECT_EQ(a[0][0], 2);
    EXPECT_EQ(a[0][1], 3);
    EXPECT_EQ(a[1][0], 4);
    EXPECT_EQ(a[1][1], 5);
}

TEST(RealMatrixTest, PrefixDecrement) {
    RealMatrix a;
    a.load_from_file("test.txt");
    --a;
    EXPECT_EQ(a[0][0], 0);
    EXPECT_EQ(a[0][1], 1);
    EXPECT_EQ(a[1][0], 2);
    EXPECT_EQ(a[1][1], 3);
}

TEST(RealMatrixTest, PostfixDecrement) {
    RealMatrix a;
    a.load_from_file("test.txt");
    a--;
    EXPECT_EQ(a[0][0], 0);
    EXPECT_EQ(a[0][1], 1);
    EXPECT_EQ(a[1][0], 2);
    EXPECT_EQ(a[1][1], 3);
}

TEST(RealMatrixTest, PlusEqualMatrix) {
    RealMatrix a;
    a.load_from_file("test.txt");
    RealMatrix b;
    b.load_from_file("test.txt");
    a += b;
    EXPECT_EQ(a[0][0], 2);
    EXPECT_EQ(a[0][1], 4);
    EXPECT_EQ(a[1][0], 6);
    EXPECT_EQ(a[1][1], 8);
}

TEST(RealMatrixTest, PlusMatrix) {
    RealMatrix a;
    a.load_from_file("test.txt");
    RealMatrix b;
    b.load_from_file("test.txt");
    RealMatrix c = a + b;
    EXPECT_EQ(c[0][0], 2);
    EXPECT_EQ(c[0][1], 4);
    EXPECT_EQ(c[1][0], 6);
    EXPECT_EQ(c[1][1], 8);
}

TEST(RealMatrixTest, PlusEqualDouble) {
    RealMatrix a;
    a.load_from_file("test.txt");
    a += 1;
    EXPECT_EQ(a[0][0], 2);
    EXPECT_EQ(a[0][1], 3);
    EXPECT_EQ(a[1][0], 4);
    EXPECT_EQ(a[1][1], 5);
}

TEST(RealMatrixTest, PlusDouble) {
    RealMatrix a;
    a.load_from_file("test.txt");
    RealMatrix b = a + 1;
    EXPECT_EQ(b[0][0], 2);
    EXPECT_EQ(b[0][1], 3);
    EXPECT_EQ(b[1][0], 4);
    EXPECT_EQ(b[1][1], 5);
}

TEST(RealMatrixTest, MinusEqualMatrix) {
    RealMatrix a;
    a.load_from_file("test.txt");
    RealMatrix b;
    b.load_from_file("test.txt");
    a -= b;
    EXPECT_EQ(a[0][0], 0);
    EXPECT_EQ(a[0][1], 0);
    EXPECT_EQ(a[1][0], 0);
    EXPECT_EQ(a[1][1], 0);
}

TEST(RealMatrixTest, MinusMatrix) {
    RealMatrix a;
    a.load_from_file("test.txt");
    RealMatrix b;
    b.load_from_file("test.txt");
    RealMatrix c = a - b;
    EXPECT_EQ(c[0][0], 0);
    EXPECT_EQ(c[0][1], 0);
    EXPECT_EQ(c[1][0], 0);
    EXPECT_EQ(c[1][1], 0);
}

TEST(RealMatrixTest, MinusEqualDouble) {
    RealMatrix a;
    a.load_from_file("test.txt");
    a -= 1;
    EXPECT_EQ(a[0][0], 0);
    EXPECT_EQ(a[0][1], 1);
    EXPECT_EQ(a[1][0], 2);
    EXPECT_EQ(a[1][1], 3);
}

TEST(RealMatrixTest, MinusDouble) {
    RealMatrix a;
    a.load_from_file("test.txt");
    RealMatrix b = a - 1;
    EXPECT_EQ(b[0][0], 0);
    EXPECT_EQ(b[0][1], 1);
    EXPECT_EQ(b[1][0], 2);
    EXPECT_EQ(b[1][1], 3);
}

TEST(RealMatrixTest, MultiplyEqualMatrix) {
    RealMatrix a;
    a.load_from_file("test.txt");
    RealMatrix b;
    b.load_from_file("test.txt");
    a *= b;
    EXPECT_EQ(a[0][0], 7);
    EXPECT_EQ(a[0][1], 10);
    EXPECT_EQ(a[1][0], 15);
    EXPECT_EQ(a[1][1], 22);
}

TEST(RealMatrixTest, MultiplyMatrix) {
    RealMatrix a;
    a.load_from_file("test.txt");
    RealMatrix b;
    b.load_from_file("test.txt");
    RealMatrix c = a * b;
    EXPECT_EQ(c[0][0], 7);
    EXPECT_EQ(c[0][1], 10);
    EXPECT_EQ(c[1][0], 15);
    EXPECT_EQ(c[1][1], 22);
}

TEST(RealMatrixTest, MultiplyEqualDouble) {
    RealMatrix a;
    a.load_from_file("test.txt");
    a *= 2;
    EXPECT_EQ(a[0][0], 2);
    EXPECT_EQ(a[0][1], 4);
    EXPECT_EQ(a[1][0], 6);
    EXPECT_EQ(a[1][1], 8);
}

TEST(RealMatrixTest, MultiplyDouble) {
    RealMatrix a;
    a.load_from_file("test.txt");
    RealMatrix b = a * 2;
    EXPECT_EQ(b[0][0], 2);
    EXPECT_EQ(b[0][1], 4);
    EXPECT_EQ(b[1][0], 6);
    EXPECT_EQ(b[1][1], 8);
}

TEST(RealMatrixTest, DivideEqualDouble) {
    RealMatrix a;
    a.load_from_file("test.txt");
    a /= 2;
    EXPECT_EQ(a[0][0], 0.5);
    EXPECT_EQ(a[0][1], 1);
    EXPECT_EQ(a[1][0], 1.5);
    EXPECT_EQ(a[1][1], 2);
}

TEST(RealMatrixTest, DivideDouble) {
    RealMatrix a;
    a.load_from_file("test.txt");
    RealMatrix b = a / 2;
    EXPECT_EQ(b[0][0], 0.5);
    EXPECT_EQ(b[0][1], 1);
    EXPECT_EQ(b[1][0], 1.5);
    EXPECT_EQ(b[1][1], 2);
}

TEST(RealMatrixTest, PowerEqualDouble) {
    RealMatrix a;
    a.load_from_file("test.txt");
    a ^= 2;
    EXPECT_EQ(a[0][0], 7);
    EXPECT_EQ(a[0][1], 10);
    EXPECT_EQ(a[1][0], 15);
    EXPECT_EQ(a[1][1], 22);
}

TEST(RealMatrixTest, PowerEqualDouble0) {
    RealMatrix a;
    a.load_from_file("test.txt");
    a ^= 0;
    EXPECT_EQ(a[0][0], 1);
    EXPECT_EQ(a[0][1], 0);
    EXPECT_EQ(a[1][0], 0);
    EXPECT_EQ(a[1][1], 1);
}

TEST(RealMatrixTest, PowerEqualNotSquare) {
    RealMatrix a(2, 3);
    EXPECT_THROW(a ^= 2, std::logic_error);
}

TEST(RealMatrixTest, PowerEqual0NotSquare) {
    RealMatrix a(2, 3);
    EXPECT_THROW(a ^= 0, std::logic_error);
}

TEST(RealMatrixTest, PowerDouble) {
    RealMatrix a;
    a.load_from_file("test.txt");
    RealMatrix b = a ^ 2;
    EXPECT_EQ(b[0][0], 7);
    EXPECT_EQ(b[0][1], 10);
    EXPECT_EQ(b[1][0], 15);
    EXPECT_EQ(b[1][1], 22);
}

TEST(RealMatrixTest, PlusEqualMatrixException) {
    RealMatrix a(2, 2);
    RealMatrix b(3, 3);
    EXPECT_THROW(a += b, std::logic_error);
}

TEST(RealMatrixTest, PlusMatrixException) {
    RealMatrix a(2, 2);
    RealMatrix b(3, 3);
    EXPECT_THROW(a + b, std::logic_error);
}

TEST(RealMatrixTest, MinusEqualMatrixException) {
    RealMatrix a(2, 2);
    RealMatrix b(3, 3);
    EXPECT_THROW(a -= b, std::logic_error);
}

TEST(RealMatrixTest, MinusMatrixException) {
    RealMatrix a(2, 2);
    RealMatrix b(3, 3);
    EXPECT_THROW(a - b, std::logic_error);
}

TEST(RealMatrixTest, MultiplyEqualMatrixException) {
    RealMatrix a(2, 2);
    RealMatrix b(3, 3);
    EXPECT_THROW(a *= b, std::logic_error);
}

TEST(RealMatrixTest, MultiplyMatrixException) {
    RealMatrix a(2, 2);
    RealMatrix b(3, 3);
    EXPECT_THROW(a * b, std::logic_error);
}

TEST(RealMatrixTest, PowerEqualDoubleExceptionNegative) {
    RealMatrix a(2, 2);
    EXPECT_THROW(a ^= -1, std::logic_error);
}

TEST(RealMatrixTest, PowerDoubleExceptionNegative) {
    RealMatrix a(2, 2);
    EXPECT_THROW(a ^ -1, std::logic_error);
}

TEST(RealMatrixTest, PowerEqualDoubleExceptionNonSquare) {
    RealMatrix a(2, 3);
    EXPECT_THROW(a ^= 2, std::logic_error);
}

TEST(RealMatrixTest, PowerDoubleExceptionNonSquare) {
    RealMatrix a(2, 3);
    EXPECT_THROW(a ^ 2, std::logic_error);
}

TEST(RealMatrixTest, Equal) {
    RealMatrix a(2, 2);
    RealMatrix b(2, 3);
    EXPECT_FALSE(a == b);
}

TEST(RealMatrixTest, NotEqual) {
    RealMatrix a(2, 2);
    RealMatrix b(2, 3);
    EXPECT_TRUE(a != b);
}

TEST(RealMatrixTest, IsSquare) {
    RealMatrix a(2, 2);
    EXPECT_TRUE(a.is_square());
}

TEST(RealMatrixTest, IsNotSquare) {
    RealMatrix a(2, 3);
    EXPECT_FALSE(a.is_square());
}

TEST(RealMatrixTest, IsDiagonal) {
    RealMatrix a(2, 2);
    a[0][0] = 1;
    a[1][1] = 2;
    EXPECT_TRUE(a.is_diagonal());
}

TEST(RealMatrixTest, IsNotDiagonal) {
    RealMatrix a(2, 2);
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 3;
    a[1][1] = 4;
    EXPECT_FALSE(a.is_diagonal());
}

TEST(RealMatrixTest, IsZero) {
    RealMatrix a(2, 2);
    EXPECT_TRUE(a.is_zero());
}

TEST(RealMatrixTest, IsNotZero) {
    RealMatrix a(2, 2);
    a[0][0] = 1;
    EXPECT_FALSE(a.is_zero());
}

TEST(RealMatrixTest, IsIdentity) {
    RealMatrix a(2, 2);
    a[0][0] = 1;
    a[1][1] = 1;
    EXPECT_TRUE(a.is_identity());
}

TEST(RealMatrixTest, IsNotIdentity) {
    RealMatrix a(2, 2);
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 3;
    a[1][1] = 4;
    EXPECT_FALSE(a.is_identity());
}

TEST(RealMatrixTest, IsSymmetric) {
    RealMatrix a(2, 2);
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 2;
    a[1][1] = 3;
    EXPECT_TRUE(a.is_symmetric());
}

TEST(RealMatrixTest, IsNotSymmetric) {
    RealMatrix a(2, 2);
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 3;
    a[1][1] = 4;
    EXPECT_FALSE(a.is_symmetric());
}

TEST(RealMatrixTest, IsUpperTriangular) {
    RealMatrix a(2, 2);
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][1] = 3;
    EXPECT_TRUE(a.is_upper_triangular());
}

TEST(RealMatrixTest, IsNotUpperTriangular) {
    RealMatrix a(2, 2);
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 3;
    a[1][1] = 4;
    EXPECT_FALSE(a.is_upper_triangular());
}

TEST(RealMatrixTest, IsLowerTriangular) {
    RealMatrix a(2, 2);
    a[0][0] = 1;
    a[1][0] = 2;
    a[1][1] = 3;
    EXPECT_TRUE(a.is_lower_triangular());
}

TEST(RealMatrixTest, IsNotLowerTriangular) {
    RealMatrix a(2, 2);
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][1] = 3;
    EXPECT_FALSE(a.is_lower_triangular());
}

TEST(RealMatrixTest, Ostream) {
    RealMatrix a(2, 2);
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 3;
    a[1][1] = 4;
    std::ostringstream out;
    out << a;
    EXPECT_EQ("1 2 \n3 4 \n", out.str());
}

TEST(RealMatrixTest, IndexOperatorOutOfRange) {
    RealMatrix a(2, 2);
    EXPECT_THROW(a[2][0], std::out_of_range);
}

TEST(RealMatrixTest, IndexOperatorNegative) {
    RealMatrix a(2, 2);
    EXPECT_THROW(a[-1][0], std::out_of_range);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}