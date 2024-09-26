#include <iostream>
#include <UnitTest++/UnitTest++.h>
#include "../include/real_matrix.h"

SUITE(real_matrix) {
    TEST(save_load) {
        real_matrix a(2, 2);
        a[0][0] = 1;
        a[0][1] = 2;
        a[1][0] = 3;
        a[1][1] = 4;
        a.save_to_file("test.txt");
        real_matrix b;
        b.load_from_file("test.txt");
        CHECK_EQUAL(a[0][0], b[0][0]);
        CHECK_EQUAL(a[0][1], b[0][1]);
        CHECK_EQUAL(a[1][0], b[1][0]);
        CHECK_EQUAL(a[1][1], b[1][1]);
    }

    TEST(transpose) {
        real_matrix a;
        a.load_from_file("test.txt");
        a.T();
        CHECK_EQUAL(a[0][0], 1);
        CHECK_EQUAL(a[0][1], 3);
        CHECK_EQUAL(a[1][0], 2);
        CHECK_EQUAL(a[1][1], 4);

    }

    TEST(determinant) {
        real_matrix a;
        a.load_from_file("test.txt");
        CHECK_EQUAL(a.det(), -2);

    }

    TEST(norm) {
        real_matrix a;
        a.load_from_file("test.txt");
        CHECK_EQUAL(a.norm(), 7);
    }

    TEST(prefix_increment) {
        real_matrix a;
        a.load_from_file("test.txt");
        ++a;
        CHECK_EQUAL(a[0][0], 2);
        CHECK_EQUAL(a[0][1], 3);
        CHECK_EQUAL(a[1][0], 4);
        CHECK_EQUAL(a[1][1], 5);
    }

    TEST(postfix_increment) {
        real_matrix a;
        a.load_from_file("test.txt");
        a++;
        CHECK_EQUAL(a[0][0], 2);
        CHECK_EQUAL(a[0][1], 3);
        CHECK_EQUAL(a[1][0], 4);
        CHECK_EQUAL(a[1][1], 5);
    }

    TEST(prefix_decrement) {
        real_matrix a;
        a.load_from_file("test.txt");
        --a;
        CHECK_EQUAL(a[0][0], 0);
        CHECK_EQUAL(a[0][1], 1);
        CHECK_EQUAL(a[1][0], 2);
        CHECK_EQUAL(a[1][1], 3);
    }

    TEST(postfix_decrement) {
        real_matrix a;
        a.load_from_file("test.txt");
        a--;
        CHECK_EQUAL(a[0][0], 0);
        CHECK_EQUAL(a[0][1], 1);
        CHECK_EQUAL(a[1][0], 2);
        CHECK_EQUAL(a[1][1], 3);
    }

    TEST(plus_equal_matrix) {
        real_matrix a;
        a.load_from_file("test.txt");
        real_matrix b;
        b.load_from_file("test.txt");
        a += b;
        CHECK_EQUAL(a[0][0], 2);
        CHECK_EQUAL(a[0][1], 4);
        CHECK_EQUAL(a[1][0], 6);
        CHECK_EQUAL(a[1][1], 8);
    }

    TEST(plus_matrix) {
        real_matrix a;
        a.load_from_file("test.txt");
        real_matrix b;
        b.load_from_file("test.txt");
        real_matrix c = a + b;
        CHECK_EQUAL(c[0][0], 2);
        CHECK_EQUAL(c[0][1], 4);
        CHECK_EQUAL(c[1][0], 6);
        CHECK_EQUAL(c[1][1], 8);
    }

    TEST(plus_equal_double) {
        real_matrix a;
        a.load_from_file("test.txt");
        a += 1;
        CHECK_EQUAL(a[0][0], 2);
        CHECK_EQUAL(a[0][1], 3);
        CHECK_EQUAL(a[1][0], 4);
        CHECK_EQUAL(a[1][1], 5);
    }

    TEST(plus_double) {
        real_matrix a;
        a.load_from_file("test.txt");
        real_matrix b = a + 1;
        CHECK_EQUAL(b[0][0], 2);
        CHECK_EQUAL(b[0][1], 3);
        CHECK_EQUAL(b[1][0], 4);
        CHECK_EQUAL(b[1][1], 5);
    }

    TEST(minus_equal_matrix) {
        real_matrix a;
        a.load_from_file("test.txt");
        real_matrix b;
        b.load_from_file("test.txt");
        a -= b;
        CHECK_EQUAL(a[0][0], 0);
        CHECK_EQUAL(a[0][1], 0);
        CHECK_EQUAL(a[1][0], 0);
        CHECK_EQUAL(a[1][1], 0);
    }

    TEST(minus_matrix) {
        real_matrix a;
        a.load_from_file("test.txt");
        real_matrix b;
        b.load_from_file("test.txt");
        real_matrix c = a - b;
        CHECK_EQUAL(c[0][0], 0);
        CHECK_EQUAL(c[0][1], 0);
        CHECK_EQUAL(c[1][0], 0);
        CHECK_EQUAL(c[1][1], 0);
    }

    TEST(minus_equal_double) {
        real_matrix a;
        a.load_from_file("test.txt");
        a -= 1;
        CHECK_EQUAL(a[0][0], 0);
        CHECK_EQUAL(a[0][1], 1);
        CHECK_EQUAL(a[1][0], 2);
        CHECK_EQUAL(a[1][1], 3);
    }

    TEST(minus_double) {
        real_matrix a;
        a.load_from_file("test.txt");
        real_matrix b = a - 1;
        CHECK_EQUAL(b[0][0], 0);
        CHECK_EQUAL(b[0][1], 1);
        CHECK_EQUAL(b[1][0], 2);
        CHECK_EQUAL(b[1][1], 3);
    }

    TEST(multiply_equal_matrix) {
        real_matrix a;
        a.load_from_file("test.txt");
        real_matrix b;
        b.load_from_file("test.txt");
        a *= b;
        CHECK_EQUAL(a[0][0], 7);
        CHECK_EQUAL(a[0][1], 10);
        CHECK_EQUAL(a[1][0], 15);
        CHECK_EQUAL(a[1][1], 22);
    }

    TEST(multiply_matrix) {
        real_matrix a;
        a.load_from_file("test.txt");
        real_matrix b;
        b.load_from_file("test.txt");
        real_matrix c = a * b;
        CHECK_EQUAL(c[0][0], 7);
        CHECK_EQUAL(c[0][1], 10);
        CHECK_EQUAL(c[1][0], 15);
        CHECK_EQUAL(c[1][1], 22);
    }

    TEST(multiply_equal_double) {
        real_matrix a;
        a.load_from_file("test.txt");
        a *= 2;
        CHECK_EQUAL(a[0][0], 2);
        CHECK_EQUAL(a[0][1], 4);
        CHECK_EQUAL(a[1][0], 6);
        CHECK_EQUAL(a[1][1], 8);
    }

    TEST(multiply_double) {
        real_matrix a;
        a.load_from_file("test.txt");
        real_matrix b = a * 2;
        CHECK_EQUAL(b[0][0], 2);
        CHECK_EQUAL(b[0][1], 4);
        CHECK_EQUAL(b[1][0], 6);
        CHECK_EQUAL(b[1][1], 8);
    }

    TEST(divide_equal_double) {
        real_matrix a;
        a.load_from_file("test.txt");
        a /= 2;
        CHECK_EQUAL(a[0][0], 0.5);
        CHECK_EQUAL(a[0][1], 1);
        CHECK_EQUAL(a[1][0], 1.5);
        CHECK_EQUAL(a[1][1], 2);
    }

    TEST(divide_double) {
        real_matrix a;
        a.load_from_file("test.txt");
        real_matrix b = a / 2;
        CHECK_EQUAL(b[0][0], 0.5);
        CHECK_EQUAL(b[0][1], 1);
        CHECK_EQUAL(b[1][0], 1.5);
        CHECK_EQUAL(b[1][1], 2);
    }

    TEST(power_equal_double) {
        real_matrix a;
        a.load_from_file("test.txt");
        a ^= 2;
        CHECK_EQUAL(a[0][0], 7);
        CHECK_EQUAL(a[0][1], 10);
        CHECK_EQUAL(a[1][0], 15);
        CHECK_EQUAL(a[1][1], 22);
    }

    TEST(power_double) {
        real_matrix a;
        a.load_from_file("test.txt");
        real_matrix b = a ^ 2;
        CHECK_EQUAL(b[0][0], 7);
        CHECK_EQUAL(b[0][1], 10);
        CHECK_EQUAL(b[1][0], 15);
        CHECK_EQUAL(b[1][1], 22);
    }

    TEST(plus_equal_matrix_exception) {
        real_matrix a(2, 2);
        real_matrix b(3, 3);
        CHECK_THROW(a += b, std::logic_error);
    }

    TEST(plus_matrix_exception) {
        real_matrix a(2, 2);
        real_matrix b(3, 3);
        CHECK_THROW(a + b, std::logic_error);
    }

    TEST(minus_equal_matrix_exception) {
        real_matrix a(2, 2);
        real_matrix b(3, 3);
        CHECK_THROW(a -= b, std::logic_error);
    }

    TEST(minus_matrix_exception) {
        real_matrix a(2, 2);
        real_matrix b(3, 3);
        CHECK_THROW(a - b, std::logic_error);
    }

    TEST(multiply_equal_matrix_exception) {
        real_matrix a(2, 2);
        real_matrix b(3, 3);
        CHECK_THROW(a *= b, std::logic_error);
    }

    TEST(multiply_matrix_exception) {
        real_matrix a(2, 2);
        real_matrix b(3, 3);
        CHECK_THROW(a * b, std::logic_error);
    }

    TEST(power_equal_double_exception_negative) {
        real_matrix a(2, 2);
        CHECK_THROW(a ^= -1, std::logic_error);
    }

    TEST(power_double_exception_negative) {
        real_matrix a(2, 2);
        CHECK_THROW(a ^ -1, std::logic_error);
    }

    TEST(power_equal_double_exception_non_square) {
        real_matrix a(2, 3);
        CHECK_THROW(a ^= 2, std::logic_error);
    }

    TEST(power_double_exception_non_square) {
        real_matrix a(2, 3);
        CHECK_THROW(a ^ 2, std::logic_error);
    }

    TEST(equal) {
        real_matrix a(2, 2);
        real_matrix b(2, 3);
        CHECK(!(a == b));
    }

    TEST(not_equal) {
        real_matrix a(2, 2);
        real_matrix b(2, 3);
        CHECK(a != b);
    }

    TEST(is_square) {
        real_matrix a(2, 2);
        CHECK(a.is_square());
    }

    TEST(is_not_square) {
        real_matrix a(2, 3);
        CHECK(!a.is_square());
    }

    TEST(is_diagonal) {
        real_matrix a(2, 2);
        a[0][0] = 1;
        a[1][1] = 2;
        CHECK(a.is_diagonal());
    }

    TEST(is_not_diagonal) {
        real_matrix a(2, 2);
        a[0][0] = 1;
        a[0][1] = 2;
        a[1][0] = 3;
        a[1][1] = 4;
        CHECK(!a.is_diagonal());
    }

    TEST(is_zero) {
        real_matrix a(2, 2);
        CHECK(a.is_zero());
    }

    TEST(is_not_zero) {
        real_matrix a(2, 2);
        a[0][0] = 1;
        CHECK(!a.is_zero());
    }

    TEST(is_identity) {
        real_matrix a(2, 2);
        a[0][0] = 1;
        a[1][1] = 1;
        CHECK(a.is_identity());
    }

    TEST(is_not_identity) {
        real_matrix a(2, 2);
        a[0][0] = 1;
        a[0][1] = 2;
        a[1][0] = 3;
        a[1][1] = 4;
        CHECK(!a.is_identity());
    }

    TEST(is_symmetric) {
        real_matrix a(2, 2);
        a[0][0] = 1;
        a[0][1] = 2;
        a[1][0] = 2;
        a[1][1] = 3;
        CHECK(a.is_symmetric());
    }

    TEST(is_not_symmetric) {
        real_matrix a(2, 2);
        a[0][0] = 1;
        a[0][1] = 2;
        a[1][0] = 3;
        a[1][1] = 4;
        CHECK(!a.is_symmetric());
    }

    TEST(is_upper_triangular) {
        real_matrix a(2, 2);
        a[0][0] = 1;
        a[0][1] = 2;
        a[1][1] = 3;
        CHECK(a.is_upper_triangular());
    }

    TEST(is_not_upper_triangular) {
        real_matrix a(2, 2);
        a[0][0] = 1;
        a[0][1] = 2;
        a[1][0] = 3;
        a[1][1] = 4;
        CHECK(!a.is_upper_triangular());
    }

    TEST(is_lower_triangular) {
        real_matrix a(2, 2);
        a[0][0] = 1;
        a[1][0] = 2;
        a[1][1] = 3;
        CHECK(a.is_lower_triangular());
    }

    TEST(is_not_lower_triangular) {
        real_matrix a(2, 2);
        a[0][0] = 1;
        a[0][1] = 2;
        a[1][1] = 3;
        CHECK(!a.is_lower_triangular());
    }
}

int main() {

    return UnitTest::RunAllTests();

}
