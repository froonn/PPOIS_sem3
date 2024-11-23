//
// Created by froonn on 18/11/24.
//

#include <gtest/gtest.h>
#include "manager.h"

TEST(Manager, DefaultConstructor) {
    Manager manager;
    EXPECT_EQ(manager.getTeamSize(), 0);
}

TEST(Manager, ParameterizedConstructor) {
    Manager manager("Alice", "Smith", "Manager", 90000, 10);
    EXPECT_EQ(manager.getName(), "Alice");
    EXPECT_EQ(manager.getSurname(), "Smith");
    EXPECT_EQ(manager.getPosition(), "Manager");
    EXPECT_EQ(manager.getSalary(), 90000);
    EXPECT_EQ(manager.getTeamSize(), 10);
}

TEST(Manager, CopyConstructor) {
    Manager manager1("Alice", "Smith", "Manager", 90000, 10);
    Manager manager2(manager1);
    EXPECT_EQ(manager2.getName(), "Alice");
    EXPECT_EQ(manager2.getSurname(), "Smith");
    EXPECT_EQ(manager2.getPosition(), "Manager");
    EXPECT_EQ(manager2.getSalary(), 90000);
    EXPECT_EQ(manager2.getTeamSize(), 10);
}

TEST(Manager, AssignmentOperator) {
    Manager manager1("Alice", "Smith", "Manager", 90000, 10);
    Manager manager2;
    manager2 = manager1;
    EXPECT_EQ(manager2.getName(), "Alice");
    EXPECT_EQ(manager2.getSurname(), "Smith");
    EXPECT_EQ(manager2.getPosition(), "Manager");
    EXPECT_EQ(manager2.getSalary(), 90000);
    EXPECT_EQ(manager2.getTeamSize(), 10);
}

TEST(Manager, SetTeamSize) {
    Manager manager;
    manager.setTeamSize(5);
    EXPECT_EQ(manager.getTeamSize(), 5);
}

TEST(Manager, GetTeamSize) {
    Manager manager("Alice", "Smith", "Manager", 90000, 10);
    EXPECT_EQ(manager.getTeamSize(), 10);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}