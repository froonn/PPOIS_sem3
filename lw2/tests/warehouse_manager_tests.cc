//
// Created by froonn on 18/11/24.
//

#include "warehouse_manager.h"
#include <gtest/gtest.h>

TEST(WarehouseManagerTests, DefaultConstructor) {
    WarehouseManager warehouseManager;
    EXPECT_EQ(warehouseManager.getName(), "Unknown");
    EXPECT_EQ(warehouseManager.getSurname(), "Unknown");
    EXPECT_EQ(warehouseManager.getPosition(), "Unknown");
    EXPECT_EQ(warehouseManager.getSalary(), 0);
    EXPECT_EQ(warehouseManager.getTeamSize(), 0);
    EXPECT_EQ(warehouseManager.getWarehouseSize(), 0);
}

TEST(WarehouseManagerTests, ParameterizedConstructor) {
    WarehouseManager warehouseManager("John", "Doe", "Warehouse Manager", 5000, 10, 2000);
    EXPECT_EQ(warehouseManager.getName(), "John");
    EXPECT_EQ(warehouseManager.getSurname(), "Doe");
    EXPECT_EQ(warehouseManager.getPosition(), "Warehouse Manager");
    EXPECT_EQ(warehouseManager.getSalary(), 5000);
    EXPECT_EQ(warehouseManager.getTeamSize(), 10);
    EXPECT_EQ(warehouseManager.getWarehouseSize(), 2000);
}

TEST(WarehouseManagerTests, CopyConstructor) {
    WarehouseManager original("Jane", "Smith", "Warehouse Manager", 5500, 8, 2500);
    WarehouseManager copy(original);
    EXPECT_EQ(copy.getName(), "Jane");
    EXPECT_EQ(copy.getSurname(), "Smith");
    EXPECT_EQ(copy.getPosition(), "Warehouse Manager");
    EXPECT_EQ(copy.getSalary(), 5500);
    EXPECT_EQ(copy.getTeamSize(), 8);
    EXPECT_EQ(copy.getWarehouseSize(), 2500);
}

TEST(WarehouseManagerTests, AssignmentOperator) {
    WarehouseManager original("Alice", "Johnson", "Warehouse Manager", 5200, 12, 3000);
    WarehouseManager assigned;
    assigned = original;
    EXPECT_EQ(assigned.getName(), "Alice");
    EXPECT_EQ(assigned.getSurname(), "Johnson");
    EXPECT_EQ(assigned.getPosition(), "Warehouse Manager");
    EXPECT_EQ(assigned.getSalary(), 5200);
    EXPECT_EQ(assigned.getTeamSize(), 12);
    EXPECT_EQ(assigned.getWarehouseSize(), 3000);
}

TEST(WarehouseManagerTests, SetWarehouseSize) {
    WarehouseManager warehouseManager;
    warehouseManager.setWarehouseSize(4000);
    EXPECT_EQ(warehouseManager.getWarehouseSize(), 4000);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}