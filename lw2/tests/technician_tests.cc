//
// Created by froonn on 18/11/24.
//

#include <gtest/gtest.h>
#include "technician.h"

TEST(Technician, DefaultConstructor) {
    Technician technician;
    EXPECT_EQ(technician.getSpecialization(), "Default specialization");
}

TEST(Technician, ParameterizedConstructor) {
    Technician technician("John", "Doe", "Technician", 50000, "Electrical");
    EXPECT_EQ(technician.getName(), "John");
    EXPECT_EQ(technician.getSurname(), "Doe");
    EXPECT_EQ(technician.getPosition(), "Technician");
    EXPECT_EQ(technician.getSalary(), 50000);
    EXPECT_EQ(technician.getSpecialization(), "Electrical");
}

TEST(Technician, CopyConstructor) {
    Technician technician1("John", "Doe", "Technician", 50000, "Electrical");
    Technician technician2(technician1);
    EXPECT_EQ(technician2.getName(), "John");
    EXPECT_EQ(technician2.getSurname(), "Doe");
    EXPECT_EQ(technician2.getPosition(), "Technician");
    EXPECT_EQ(technician2.getSalary(), 50000);
    EXPECT_EQ(technician2.getSpecialization(), "Electrical");
}

TEST(Technician, AssignmentOperator) {
    Technician technician1("John", "Doe", "Technician", 50000, "Electrical");
    Technician technician2;
    technician2 = technician1;
    EXPECT_EQ(technician2.getName(), "John");
    EXPECT_EQ(technician2.getSurname(), "Doe");
    EXPECT_EQ(technician2.getPosition(), "Technician");
    EXPECT_EQ(technician2.getSalary(), 50000);
    EXPECT_EQ(technician2.getSpecialization(), "Electrical");
}

TEST(Technician, SetSpecialization) {
    Technician technician;
    technician.setSpecialization("Mechanical");
    EXPECT_EQ(technician.getSpecialization(), "Mechanical");
}

TEST(Technician, GetSpecialization) {
    Technician technician("John", "Doe", "Technician", 50000, "Electrical");
    EXPECT_EQ(technician.getSpecialization(), "Electrical");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}