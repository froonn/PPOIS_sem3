#include <iostream>
#include <UnitTest++/UnitTest++.h>
#include "../include/Real_matrix.h"

SUITE(Real_matrix) {
    TEST(save_load) {
        Real_matrix a(2, 2);
        a[0][0] = 1;
        a[0][1] = 2;
        a[1][0] = 3;
        a[1][1] = 4;
        a.save_to_file("test.txt");
        Real_matrix b;
        b.load_from_file("test.txt");
        CHECK_EQUAL(a[0][0], b[0][0]);
        CHECK_EQUAL(a[0][1], b[0][1]);
        CHECK_EQUAL(a[1][0], b[1][0]);
        CHECK_EQUAL(a[1][1], b[1][1]);
    }

    TEST(resize_submatrix) {
        Real_matrix a;
        a.load_from_file("test.txt");
        a.resize(1, 1);
        Real_matrix b = a.submatrix(1, 1);
        CHECK_EQUAL(a, b);
    }

    TEST(transpose) {
        Real_matrix a;
        a.load_from_file("test.txt");
        a.T();
        CHECK_EQUAL(a[0][0], 1);
        CHECK_EQUAL(a[0][1], 3);
        CHECK_EQUAL(a[1][0], 2);
        CHECK_EQUAL(a[1][1], 4);
    }

    TEST(determinant_1x1) {
        Real_matrix a(1, 1);
        a[0][0] = 1;
        CHECK_EQUAL(a.det(), 1);
    }

    TEST(determinant_1x2) {
        Real_matrix a(1, 2);
        CHECK_THROW(a.det(), std::logic_error);
    }

    TEST(determinant_2x2) {
        Real_matrix a;
        a.load_from_file("test.txt");
        CHECK_EQUAL(a.det(), -2);

    }

    TEST(determinant_3x3) {
        Real_matrix a(3, 3);
        for (int i = 0; i < 3; i += 1) {
            for (int j = 0; j < 3; j += 1) {
                a[i][j] = i + j;
            }
        }
        CHECK_EQUAL(a.det(), 0);
    }

    TEST(norm) {
        Real_matrix a;
        a.load_from_file("test.txt");
        CHECK_EQUAL(a.norm(), 7);
    }

    TEST(prefix_increment) {
        Real_matrix a;
        a.load_from_file("test.txt");
        ++a;
        CHECK_EQUAL(a[0][0], 2);
        CHECK_EQUAL(a[0][1], 3);
        CHECK_EQUAL(a[1][0], 4);
        CHECK_EQUAL(a[1][1], 5);
    }

    TEST(postfix_increment) {
        Real_matrix a;
        a.load_from_file("test.txt");
        a++;
        CHECK_EQUAL(a[0][0], 2);
        CHECK_EQUAL(a[0][1], 3);
        CHECK_EQUAL(a[1][0], 4);
        CHECK_EQUAL(a[1][1], 5);
    }

    TEST(prefix_decrement) {
        Real_matrix a;
        a.load_from_file("test.txt");
        --a;
        CHECK_EQUAL(a[0][0], 0);
        CHECK_EQUAL(a[0][1], 1);
        CHECK_EQUAL(a[1][0], 2);
        CHECK_EQUAL(a[1][1], 3);
    }

    TEST(postfix_decrement) {
        Real_matrix a;
        a.load_from_file("test.txt");
        a--;
        CHECK_EQUAL(a[0][0], 0);
        CHECK_EQUAL(a[0][1], 1);
        CHECK_EQUAL(a[1][0], 2);
        CHECK_EQUAL(a[1][1], 3);
    }

    TEST(plus_equal_matrix) {
        Real_matrix a;
        a.load_from_file("test.txt");
        Real_matrix b;
        b.load_from_file("test.txt");
        a += b;
        CHECK_EQUAL(a[0][0], 2);
        CHECK_EQUAL(a[0][1], 4);
        CHECK_EQUAL(a[1][0], 6);
        CHECK_EQUAL(a[1][1], 8);
    }

    TEST(plus_matrix) {
        Real_matrix a;
        a.load_from_file("test.txt");
        Real_matrix b;
        b.load_from_file("test.txt");
        Real_matrix c = a + b;
        CHECK_EQUAL(c[0][0], 2);
        CHECK_EQUAL(c[0][1], 4);
        CHECK_EQUAL(c[1][0], 6);
        CHECK_EQUAL(c[1][1], 8);
    }

    TEST(plus_equal_double) {
        Real_matrix a;
        a.load_from_file("test.txt");
        a += 1;
        CHECK_EQUAL(a[0][0], 2);
        CHECK_EQUAL(a[0][1], 3);
        CHECK_EQUAL(a[1][0], 4);
        CHECK_EQUAL(a[1][1], 5);
    }

    TEST(plus_double) {
        Real_matrix a;
        a.load_from_file("test.txt");
        Real_matrix b = a + 1;
        CHECK_EQUAL(b[0][0], 2);
        CHECK_EQUAL(b[0][1], 3);
        CHECK_EQUAL(b[1][0], 4);
        CHECK_EQUAL(b[1][1], 5);
    }

    TEST(minus_equal_matrix) {
        Real_matrix a;
        a.load_from_file("test.txt");
        Real_matrix b;
        b.load_from_file("test.txt");
        a -= b;
        CHECK_EQUAL(a[0][0], 0);
        CHECK_EQUAL(a[0][1], 0);
        CHECK_EQUAL(a[1][0], 0);
        CHECK_EQUAL(a[1][1], 0);
    }

    TEST(minus_matrix) {
        Real_matrix a;
        a.load_from_file("test.txt");
        Real_matrix b;
        b.load_from_file("test.txt");
        Real_matrix c = a - b;
        CHECK_EQUAL(c[0][0], 0);
        CHECK_EQUAL(c[0][1], 0);
        CHECK_EQUAL(c[1][0], 0);
        CHECK_EQUAL(c[1][1], 0);
    }

    TEST(minus_equal_double) {
        Real_matrix a;
        a.load_from_file("test.txt");
        a -= 1;
        CHECK_EQUAL(a[0][0], 0);
        CHECK_EQUAL(a[0][1], 1);
        CHECK_EQUAL(a[1][0], 2);
        CHECK_EQUAL(a[1][1], 3);
    }

    TEST(minus_double) {
        Real_matrix a;
        a.load_from_file("test.txt");
        Real_matrix b = a - 1;
        CHECK_EQUAL(b[0][0], 0);
        CHECK_EQUAL(b[0][1], 1);
        CHECK_EQUAL(b[1][0], 2);
        CHECK_EQUAL(b[1][1], 3);
    }

    TEST(multiply_equal_matrix) {
        Real_matrix a;
        a.load_from_file("test.txt");
        Real_matrix b;
        b.load_from_file("test.txt");
        a *= b;
        CHECK_EQUAL(a[0][0], 7);
        CHECK_EQUAL(a[0][1], 10);
        CHECK_EQUAL(a[1][0], 15);
        CHECK_EQUAL(a[1][1], 22);
    }

    TEST(multiply_matrix) {
        Real_matrix a;
        a.load_from_file("test.txt");
        Real_matrix b;
        b.load_from_file("test.txt");
        Real_matrix c = a * b;
        CHECK_EQUAL(c[0][0], 7);
        CHECK_EQUAL(c[0][1], 10);
        CHECK_EQUAL(c[1][0], 15);
        CHECK_EQUAL(c[1][1], 22);
    }

    TEST(multiply_equal_double) {
        Real_matrix a;
        a.load_from_file("test.txt");
        a *= 2;
        CHECK_EQUAL(a[0][0], 2);
        CHECK_EQUAL(a[0][1], 4);
        CHECK_EQUAL(a[1][0], 6);
        CHECK_EQUAL(a[1][1], 8);
    }

    TEST(multiply_double) {
        Real_matrix a;
        a.load_from_file("test.txt");
        Real_matrix b = a * 2;
        CHECK_EQUAL(b[0][0], 2);
        CHECK_EQUAL(b[0][1], 4);
        CHECK_EQUAL(b[1][0], 6);
        CHECK_EQUAL(b[1][1], 8);
    }

    TEST(divide_equal_double) {
        Real_matrix a;
        a.load_from_file("test.txt");
        a /= 2;
        CHECK_EQUAL(a[0][0], 0.5);
        CHECK_EQUAL(a[0][1], 1);
        CHECK_EQUAL(a[1][0], 1.5);
        CHECK_EQUAL(a[1][1], 2);
    }

    TEST(divide_double) {
        Real_matrix a;
        a.load_from_file("test.txt");
        Real_matrix b = a / 2;
        CHECK_EQUAL(b[0][0], 0.5);
        CHECK_EQUAL(b[0][1], 1);
        CHECK_EQUAL(b[1][0], 1.5);
        CHECK_EQUAL(b[1][1], 2);
    }

    TEST(power_equal_double) {
        Real_matrix a;
        a.load_from_file("test.txt");
        a ^= 2;
        CHECK_EQUAL(a[0][0], 7);
        CHECK_EQUAL(a[0][1], 10);
        CHECK_EQUAL(a[1][0], 15);
        CHECK_EQUAL(a[1][1], 22);
    }

    TEST(power_equal_double_0) {
        Real_matrix a;
        a.load_from_file("test.txt");
        a ^= 0;
        CHECK_EQUAL(a[0][0], 1);
        CHECK_EQUAL(a[0][1], 0);
        CHECK_EQUAL(a[1][0], 0);
        CHECK_EQUAL(a[1][1], 1);
    }

    TEST(power_equal_not_square) {
        Real_matrix a(2, 3);
        CHECK_THROW(a ^= 2, std::logic_error);
    }

    TEST(power_double) {
        Real_matrix a;
        a.load_from_file("test.txt");
        Real_matrix b = a ^ 2;
        CHECK_EQUAL(b[0][0], 7);
        CHECK_EQUAL(b[0][1], 10);
        CHECK_EQUAL(b[1][0], 15);
        CHECK_EQUAL(b[1][1], 22);
    }

    TEST(plus_equal_matrix_exception) {
        Real_matrix a(2, 2);
        Real_matrix b(3, 3);
        CHECK_THROW(a += b, std::logic_error);
    }

    TEST(plus_matrix_exception) {
        Real_matrix a(2, 2);
        Real_matrix b(3, 3);
        CHECK_THROW(a + b, std::logic_error);
    }

    TEST(minus_equal_matrix_exception) {
        Real_matrix a(2, 2);
        Real_matrix b(3, 3);
        CHECK_THROW(a -= b, std::logic_error);
    }

    TEST(minus_matrix_exception) {
        Real_matrix a(2, 2);
        Real_matrix b(3, 3);
        CHECK_THROW(a - b, std::logic_error);
    }

    TEST(multiply_equal_matrix_exception) {
        Real_matrix a(2, 2);
        Real_matrix b(3, 3);
        CHECK_THROW(a *= b, std::logic_error);
    }

    TEST(multiply_matrix_exception) {
        Real_matrix a(2, 2);
        Real_matrix b(3, 3);
        CHECK_THROW(a * b, std::logic_error);
    }

    TEST(power_equal_double_exception_negative) {
        Real_matrix a(2, 2);
        CHECK_THROW(a ^= -1, std::logic_error);
    }

    TEST(power_double_exception_negative) {
        Real_matrix a(2, 2);
        CHECK_THROW(a ^ -1, std::logic_error);
    }

    TEST(power_equal_double_exception_non_square) {
        Real_matrix a(2, 3);
        CHECK_THROW(a ^= 2, std::logic_error);
    }

    TEST(power_double_exception_non_square) {
        Real_matrix a(2, 3);
        CHECK_THROW(a ^ 2, std::logic_error);
    }

    TEST(equal) {
        Real_matrix a(2, 2);
        Real_matrix b(2, 3);
        CHECK(!(a == b));
    }

    TEST(not_equal) {
        Real_matrix a(2, 2);
        Real_matrix b(2, 3);
        CHECK(a != b);
    }

    TEST(is_square) {
        Real_matrix a(2, 2);
        CHECK(a.is_square());
    }

    TEST(is_not_square) {
        Real_matrix a(2, 3);
        CHECK(!a.is_square());
    }

    TEST(is_diagonal) {
        Real_matrix a(2, 2);
        a[0][0] = 1;
        a[1][1] = 2;
        CHECK(a.is_diagonal());
    }

    TEST(is_not_diagonal) {
        Real_matrix a(2, 2);
        a[0][0] = 1;
        a[0][1] = 2;
        a[1][0] = 3;
        a[1][1] = 4;
        CHECK(!a.is_diagonal());
    }

    TEST(is_zero) {
        Real_matrix a(2, 2);
        CHECK(a.is_zero());
    }

    TEST(is_not_zero) {
        Real_matrix a(2, 2);
        a[0][0] = 1;
        CHECK(!a.is_zero());
    }

    TEST(is_identity) {
        Real_matrix a(2, 2);
        a[0][0] = 1;
        a[1][1] = 1;
        CHECK(a.is_identity());
    }

    TEST(is_not_identity) {
        Real_matrix a(2, 2);
        a[0][0] = 1;
        a[0][1] = 2;
        a[1][0] = 3;
        a[1][1] = 4;
        CHECK(!a.is_identity());
    }

    TEST(is_symmetric) {
        Real_matrix a(2, 2);
        a[0][0] = 1;
        a[0][1] = 2;
        a[1][0] = 2;
        a[1][1] = 3;
        CHECK(a.is_symmetric());
    }

    TEST(is_not_symmetric) {
        Real_matrix a(2, 2);
        a[0][0] = 1;
        a[0][1] = 2;
        a[1][0] = 3;
        a[1][1] = 4;
        CHECK(!a.is_symmetric());
    }

    TEST(is_upper_triangular) {
        Real_matrix a(2, 2);
        a[0][0] = 1;
        a[0][1] = 2;
        a[1][1] = 3;
        CHECK(a.is_upper_triangular());
    }

    TEST(is_not_upper_triangular) {
        Real_matrix a(2, 2);
        a[0][0] = 1;
        a[0][1] = 2;
        a[1][0] = 3;
        a[1][1] = 4;
        CHECK(!a.is_upper_triangular());
    }

    TEST(is_lower_triangular) {
        Real_matrix a(2, 2);
        a[0][0] = 1;
        a[1][0] = 2;
        a[1][1] = 3;
        CHECK(a.is_lower_triangular());
    }

    TEST(is_not_lower_triangular) {
        Real_matrix a(2, 2);
        a[0][0] = 1;
        a[0][1] = 2;
        a[1][1] = 3;
        CHECK(!a.is_lower_triangular());
    }

    TEST(ostream) {
        Real_matrix a(2, 2);
        a[0][0] = 1;
        a[0][1] = 2;
        a[1][0] = 3;
        a[1][1] = 4;
        std::ostringstream out;
        out << a;
        CHECK_EQUAL("1 2 \n3 4 \n", out.str());
    }

    TEST(index_operator_out_of_range) {
        Real_matrix a(2, 2);
        CHECK_THROW(a[2][0], std::out_of_range);
    }

    TEST(index_operator_negative) {
        Real_matrix a(2, 2);
        CHECK_THROW(a[-1][0], std::out_of_range);
    }
}

int main() {
    return UnitTest::RunAllTests();
}
