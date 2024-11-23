//
// Created by froonn on 18/11/24.
//

#include <gtest/gtest.h>
#include "plumber.h"

TEST(Plumber, DefaultConstructor) {
    Plumber plumber;
    EXPECT_EQ(plumber.getSpecialization(), "Default specialization");
    EXPECT_EQ(plumber.getExperienceYears(), 0);
}

TEST(Plumber, ParameterizedConstructor) {
    Plumber plumber("John", "Doe", "Plumber", 60000, "Plumbing", 8);
    EXPECT_EQ(plumber.getName(), "John");
    EXPECT_EQ(plumber.getSurname(), "Doe");
    EXPECT_EQ(plumber.getPosition(), "Plumber");
    EXPECT_EQ(plumber.getSalary(), 60000);
    EXPECT_EQ(plumber.getSpecialization(), "Plumbing");
    EXPECT_EQ(plumber.getExperienceYears(), 8);
}

TEST(Plumber, CopyConstructor) {
    Plumber plumber1("John", "Doe", "Plumber", 60000, "Plumbing", 8);
    Plumber plumber2(plumber1);
    EXPECT_EQ(plumber2.getName(), "John");
    EXPECT_EQ(plumber2.getSurname(), "Doe");
    EXPECT_EQ(plumber2.getPosition(), "Plumber");
    EXPECT_EQ(plumber2.getSalary(), 60000);
    EXPECT_EQ(plumber2.getSpecialization(), "Plumbing");
    EXPECT_EQ(plumber2.getExperienceYears(), 8);
}

TEST(Plumber, AssignmentOperator) {
    Plumber plumber1("John", "Doe", "Plumber", 60000, "Plumbing", 8);
    Plumber plumber2;
    plumber2 = plumber1;
    EXPECT_EQ(plumber2.getName(), "John");
    EXPECT_EQ(plumber2.getSurname(), "Doe");
    EXPECT_EQ(plumber2.getPosition(), "Plumber");
    EXPECT_EQ(plumber2.getSalary(), 60000);
    EXPECT_EQ(plumber2.getSpecialization(), "Plumbing");
    EXPECT_EQ(plumber2.getExperienceYears(), 8);
}

TEST(Plumber, SetExperienceYears) {
    Plumber plumber;
    plumber.setExperienceYears(5);
    EXPECT_EQ(plumber.getExperienceYears(), 5);
}

TEST(Plumber, GetExperienceYears) {
    Plumber plumber("John", "Doe", "Plumber", 60000, "Plumbing", 8);
    EXPECT_EQ(plumber.getExperienceYears(), 8);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}