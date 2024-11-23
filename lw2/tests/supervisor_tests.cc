//
// Created by froonn on 18/11/24.
//

#include "supervisor.h"
#include <gtest/gtest.h>

TEST(SupervisorTests, DefaultConstructor) {
    Supervisor supervisor;
    EXPECT_EQ(supervisor.getName(), "Unknown");
    EXPECT_EQ(supervisor.getSurname(), "Unknown");
    EXPECT_EQ(supervisor.getPosition(), "Unknown");
    EXPECT_EQ(supervisor.getSalary(), 0);
    EXPECT_EQ(supervisor.getTeamSize(), 0);
    EXPECT_EQ(supervisor.getDepartment(), "Unknown");
}

TEST(SupervisorTests, ParameterizedConstructor) {
    Supervisor supervisor("John", "Doe", "Supervisor", 7000, 5, "Engineering");
    EXPECT_EQ(supervisor.getName(), "John");
    EXPECT_EQ(supervisor.getSurname(), "Doe");
    EXPECT_EQ(supervisor.getPosition(), "Supervisor");
    EXPECT_EQ(supervisor.getSalary(), 7000);
    EXPECT_EQ(supervisor.getTeamSize(), 5);
    EXPECT_EQ(supervisor.getDepartment(), "Engineering");
}

TEST(SupervisorTests, CopyConstructor) {
    Supervisor original("Jane", "Smith", "Supervisor", 7500, 6, "HR");
    Supervisor copy(original);
    EXPECT_EQ(copy.getName(), "Jane");
    EXPECT_EQ(copy.getSurname(), "Smith");
    EXPECT_EQ(copy.getPosition(), "Supervisor");
    EXPECT_EQ(copy.getSalary(), 7500);
    EXPECT_EQ(copy.getTeamSize(), 6);
    EXPECT_EQ(copy.getDepartment(), "HR");
}

TEST(SupervisorTests, AssignmentOperator) {
    Supervisor original("Alice", "Johnson", "Supervisor", 7200, 7, "Finance");
    Supervisor assigned;
    assigned = original;
    EXPECT_EQ(assigned.getName(), "Alice");
    EXPECT_EQ(assigned.getSurname(), "Johnson");
    EXPECT_EQ(assigned.getPosition(), "Supervisor");
    EXPECT_EQ(assigned.getSalary(), 7200);
    EXPECT_EQ(assigned.getTeamSize(), 7);
    EXPECT_EQ(assigned.getDepartment(), "Finance");
}

TEST(SupervisorTests, SetDepartment) {
    Supervisor supervisor;
    supervisor.setDepartment("Marketing");
    EXPECT_EQ(supervisor.getDepartment(), "Marketing");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}