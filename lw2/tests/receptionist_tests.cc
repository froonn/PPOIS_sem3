//
// Created by froonn on 18/11/24.
//

#include "receptionist.h"
#include <gtest/gtest.h>

TEST(ReceptionistTests, DefaultConstructor) {
    Receptionist receptionist;
    EXPECT_EQ(receptionist.getName(), "Unknown");
    EXPECT_EQ(receptionist.getSurname(), "Unknown");
    EXPECT_EQ(receptionist.getPosition(), "Unknown");
    EXPECT_EQ(receptionist.getSalary(), 0);
    EXPECT_EQ(receptionist.getShift(), "Default shift");
}

TEST(ReceptionistTests, ParameterizedConstructor) {
    Receptionist receptionist("John", "Doe", "Receptionist", 3000, "Morning");
    EXPECT_EQ(receptionist.getName(), "John");
    EXPECT_EQ(receptionist.getSurname(), "Doe");
    EXPECT_EQ(receptionist.getPosition(), "Receptionist");
    EXPECT_EQ(receptionist.getSalary(), 3000);
    EXPECT_EQ(receptionist.getShift(), "Morning");
}

TEST(ReceptionistTests, CopyConstructor) {
    Receptionist original("Jane", "Smith", "Receptionist", 3500, "Evening");
    Receptionist copy(original);
    EXPECT_EQ(copy.getName(), "Jane");
    EXPECT_EQ(copy.getSurname(), "Smith");
    EXPECT_EQ(copy.getPosition(), "Receptionist");
    EXPECT_EQ(copy.getSalary(), 3500);
    EXPECT_EQ(copy.getShift(), "Evening");
}

TEST(ReceptionistTests, AssignmentOperator) {
    Receptionist original("Alice", "Johnson", "Receptionist", 3200, "Night");
    Receptionist assigned;
    assigned = original;
    EXPECT_EQ(assigned.getName(), "Alice");
    EXPECT_EQ(assigned.getSurname(), "Johnson");
    EXPECT_EQ(assigned.getPosition(), "Receptionist");
    EXPECT_EQ(assigned.getSalary(), 3200);
    EXPECT_EQ(assigned.getShift(), "Night");
}

TEST(ReceptionistTests, SetShift) {
    Receptionist receptionist;
    receptionist.setShift("Afternoon");
    EXPECT_EQ(receptionist.getShift(), "Afternoon");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}