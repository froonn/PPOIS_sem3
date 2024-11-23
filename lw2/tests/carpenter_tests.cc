//
// Created by froonn on 12/11/24.
//

#include <gtest/gtest.h>
#include "carpenter.h"

TEST(Carpenter, DefaultConstructor) {
    Carpenter carpenter;
    EXPECT_EQ(carpenter.getSpecialization(), "Default specialization");
    EXPECT_EQ(carpenter.getToolset(), "Default toolset");
}

TEST(Carpenter, ParameterizedConstructor) {
    Carpenter carpenter("John", "Doe", "Carpenter", 60000, "Woodworking", "Hammer");
    EXPECT_EQ(carpenter.getName(), "John");
    EXPECT_EQ(carpenter.getSurname(), "Doe");
    EXPECT_EQ(carpenter.getPosition(), "Carpenter");
    EXPECT_EQ(carpenter.getSalary(), 60000);
    EXPECT_EQ(carpenter.getSpecialization(), "Woodworking");
    EXPECT_EQ(carpenter.getToolset(), "Hammer");
}

TEST(Carpenter, CopyConstructor) {
    Carpenter carpenter1("John", "Doe", "Carpenter", 60000, "Woodworking", "Hammer");
    Carpenter carpenter2(carpenter1);
    EXPECT_EQ(carpenter2.getName(), "John");
    EXPECT_EQ(carpenter2.getSurname(), "Doe");
    EXPECT_EQ(carpenter2.getPosition(), "Carpenter");
    EXPECT_EQ(carpenter2.getSalary(), 60000);
    EXPECT_EQ(carpenter2.getSpecialization(), "Woodworking");
    EXPECT_EQ(carpenter2.getToolset(), "Hammer");
}

TEST(Carpenter, AssignmentOperator) {
    Carpenter carpenter1("John", "Doe", "Carpenter", 60000, "Woodworking", "Hammer");
    Carpenter carpenter2;
    carpenter2 = carpenter1;
    EXPECT_EQ(carpenter2.getName(), "John");
    EXPECT_EQ(carpenter2.getSurname(), "Doe");
    EXPECT_EQ(carpenter2.getPosition(), "Carpenter");
    EXPECT_EQ(carpenter2.getSalary(), 60000);
    EXPECT_EQ(carpenter2.getSpecialization(), "Woodworking");
    EXPECT_EQ(carpenter2.getToolset(), "Hammer");
}

TEST(Carpenter, SetToolset) {
    Carpenter carpenter;
    carpenter.setToolset("Saw");
    EXPECT_EQ(carpenter.getToolset(), "Saw");
}

TEST(Carpenter, GetToolset) {
    Carpenter carpenter("John", "Doe", "Carpenter", 60000, "Woodworking", "Hammer");
    EXPECT_EQ(carpenter.getToolset(), "Hammer");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
