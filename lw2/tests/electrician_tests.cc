//
// Created by froonn on 18/11/24.
//

#include <gtest/gtest.h>
#include "electrician.h"

TEST(Electrician, DefaultConstructor) {
    Electrician electrician;
    EXPECT_EQ(electrician.getSpecialization(), "Default specialization");
    EXPECT_EQ(electrician.getCertificationLevel(), 0);
}

TEST(Electrician, ParameterizedConstructor) {
    Electrician electrician("John", "Doe", "Electrician", 70000, "Electrical", 5);
    EXPECT_EQ(electrician.getName(), "John");
    EXPECT_EQ(electrician.getSurname(), "Doe");
    EXPECT_EQ(electrician.getPosition(), "Electrician");
    EXPECT_EQ(electrician.getSalary(), 70000);
    EXPECT_EQ(electrician.getSpecialization(), "Electrical");
    EXPECT_EQ(electrician.getCertificationLevel(), 5);
}

TEST(Electrician, CopyConstructor) {
    Electrician electrician1("John", "Doe", "Electrician", 70000, "Electrical", 5);
    Electrician electrician2(electrician1);
    EXPECT_EQ(electrician2.getName(), "John");
    EXPECT_EQ(electrician2.getSurname(), "Doe");
    EXPECT_EQ(electrician2.getPosition(), "Electrician");
    EXPECT_EQ(electrician2.getSalary(), 70000);
    EXPECT_EQ(electrician2.getSpecialization(), "Electrical");
    EXPECT_EQ(electrician2.getCertificationLevel(), 5);
}

TEST(Electrician, AssignmentOperator) {
    Electrician electrician1("John", "Doe", "Electrician", 70000, "Electrical", 5);
    Electrician electrician2;
    electrician2 = electrician1;
    EXPECT_EQ(electrician2.getName(), "John");
    EXPECT_EQ(electrician2.getSurname(), "Doe");
    EXPECT_EQ(electrician2.getPosition(), "Electrician");
    EXPECT_EQ(electrician2.getSalary(), 70000);
    EXPECT_EQ(electrician2.getSpecialization(), "Electrical");
    EXPECT_EQ(electrician2.getCertificationLevel(), 5);
}

TEST(Electrician, SetCertificationLevel) {
    Electrician electrician;
    electrician.setCertificationLevel(3);
    EXPECT_EQ(electrician.getCertificationLevel(), 3);
}

TEST(Electrician, GetCertificationLevel) {
    Electrician electrician("John", "Doe", "Electrician", 70000, "Electrical", 5);
    EXPECT_EQ(electrician.getCertificationLevel(), 5);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}