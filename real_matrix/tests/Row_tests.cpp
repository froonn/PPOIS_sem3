#include <iostream>
#include <UnitTest++/UnitTest++.h>
#include "../include/Row.h"

SUITE(Row) {
    TEST(constructor) {
        Row r;
        CHECK_EQUAL(0, r.size());
    }

    TEST(constructor_with_size) {
        Row r(3);
        CHECK_EQUAL(3, r.size());
        CHECK_EQUAL(0, r[0]);
        CHECK_EQUAL(0, r[1]);
        CHECK_EQUAL(0, r[2]);
    }

    TEST(copy_constructor) {
        Row r(3);
        r[0] = 1;
        r[1] = 2;
        r[2] = 3;

        Row r2(r);
        CHECK_EQUAL(3, r2.size());
        CHECK_EQUAL(1, r2[0]);
        CHECK_EQUAL(2, r2[1]);
        CHECK_EQUAL(3, r2[2]);
    }

    TEST(assignment_operator) {
        Row r(3);
        r[0] = 1;
        r[1] = 2;
        r[2] = 3;

        Row r2;
        r2 = r;
        CHECK_EQUAL(3, r2.size());
        CHECK_EQUAL(1, r2[0]);
        CHECK_EQUAL(2, r2[1]);
        CHECK_EQUAL(3, r2[2]);
    }

    TEST(index_operator) {
        Row r(3);
        r[0] = 1;
        r[1] = 2;
        r[2] = 3;

        CHECK_EQUAL(1, r[0]);
        CHECK_EQUAL(2, r[1]);
        CHECK_EQUAL(3, r[2]);
    }

    TEST(index_operator_out_of_range) {
        Row r(3);
        CHECK_THROW(r[3], std::out_of_range);
    }

    TEST(index_operator_negative) {
        Row r(3);
        CHECK_THROW(r[-1], std::out_of_range);
    }



    TEST(resize) {
        Row r(3);
        r[0] = 1;
        r[1] = 2;
        r[2] = 3;

        r.resize(4);
        CHECK_EQUAL(4, r.size());
        CHECK_EQUAL(1, r[0]);
        CHECK_EQUAL(2, r[1]);
        CHECK_EQUAL(3, r[2]);
        CHECK_EQUAL(0, r[3]);
    }
}

int main() {
    return UnitTest::RunAllTests();
}


