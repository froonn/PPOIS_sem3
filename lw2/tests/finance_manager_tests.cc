//
// Created by froonn on 18/11/24.
//

#include "finance_manager.h"
#include <gtest/gtest.h>

TEST(FinanceManagerTests, DefaultConstructor) {
    FinanceManager financeManager;
    EXPECT_EQ(financeManager.getName(), "Unknown");
    EXPECT_EQ(financeManager.getSurname(), "Unknown");
    EXPECT_EQ(financeManager.getPosition(), "Unknown");
    EXPECT_EQ(financeManager.getSalary(), 0);
    EXPECT_EQ(financeManager.getTeamSize(), 0);
    EXPECT_EQ(financeManager.getBudget(), 0.0);
}

TEST(FinanceManagerTests, ParameterizedConstructor) {
    FinanceManager financeManager("John", "Doe", "Finance Manager", 6000, 15, 100000.0);
    EXPECT_EQ(financeManager.getName(), "John");
    EXPECT_EQ(financeManager.getSurname(), "Doe");
    EXPECT_EQ(financeManager.getPosition(), "Finance Manager");
    EXPECT_EQ(financeManager.getSalary(), 6000);
    EXPECT_EQ(financeManager.getTeamSize(), 15);
    EXPECT_EQ(financeManager.getBudget(), 100000.0);
}

TEST(FinanceManagerTests, CopyConstructor) {
    FinanceManager original("Jane", "Smith", "Finance Manager", 6500, 10, 200000.0);
    FinanceManager copy(original);
    EXPECT_EQ(copy.getName(), "Jane");
    EXPECT_EQ(copy.getSurname(), "Smith");
    EXPECT_EQ(copy.getPosition(), "Finance Manager");
    EXPECT_EQ(copy.getSalary(), 6500);
    EXPECT_EQ(copy.getTeamSize(), 10);
    EXPECT_EQ(copy.getBudget(), 200000.0);
}

TEST(FinanceManagerTests, AssignmentOperator) {
    FinanceManager original("Alice", "Johnson", "Finance Manager", 6200, 20, 150000.0);
    FinanceManager assigned;
    assigned = original;
    EXPECT_EQ(assigned.getName(), "Alice");
    EXPECT_EQ(assigned.getSurname(), "Johnson");
    EXPECT_EQ(assigned.getPosition(), "Finance Manager");
    EXPECT_EQ(assigned.getSalary(), 6200);
    EXPECT_EQ(assigned.getTeamSize(), 20);
    EXPECT_EQ(assigned.getBudget(), 150000.0);
}

TEST(FinanceManagerTests, SetBudget) {
    FinanceManager financeManager;
    financeManager.setBudget(300000.0);
    EXPECT_EQ(financeManager.getBudget(), 300000.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
