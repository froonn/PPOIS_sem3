//
// Created by froonn on 18/11/24.
//

#include "project_manager.h"
#include <gtest/gtest.h>

TEST(ProjectManagerTests, DefaultConstructor) {
    ProjectManager projectManager;
    EXPECT_EQ(projectManager.getName(), "Unknown");
    EXPECT_EQ(projectManager.getSurname(), "Unknown");
    EXPECT_EQ(projectManager.getPosition(), "Unknown");
    EXPECT_EQ(projectManager.getSalary(), 0);
    EXPECT_EQ(projectManager.getTeamSize(), 0);
    EXPECT_EQ(projectManager.getProjectCount(), 0);
}

TEST(ProjectManagerTests, ParameterizedConstructor) {
    ProjectManager projectManager("John", "Doe", "Project Manager", 5000, 10, 3);
    EXPECT_EQ(projectManager.getName(), "John");
    EXPECT_EQ(projectManager.getSurname(), "Doe");
    EXPECT_EQ(projectManager.getPosition(), "Project Manager");
    EXPECT_EQ(projectManager.getSalary(), 5000);
    EXPECT_EQ(projectManager.getTeamSize(), 10);
    EXPECT_EQ(projectManager.getProjectCount(), 3);
}

TEST(ProjectManagerTests, CopyConstructor) {
    ProjectManager original("Jane", "Smith", "Project Manager", 5500, 8, 5);
    ProjectManager copy(original);
    EXPECT_EQ(copy.getName(), "Jane");
    EXPECT_EQ(copy.getSurname(), "Smith");
    EXPECT_EQ(copy.getPosition(), "Project Manager");
    EXPECT_EQ(copy.getSalary(), 5500);
    EXPECT_EQ(copy.getTeamSize(), 8);
    EXPECT_EQ(copy.getProjectCount(), 5);
}

TEST(ProjectManagerTests, AssignmentOperator) {
    ProjectManager original("Alice", "Johnson", "Project Manager", 5200, 12, 4);
    ProjectManager assigned;
    assigned = original;
    EXPECT_EQ(assigned.getName(), "Alice");
    EXPECT_EQ(assigned.getSurname(), "Johnson");
    EXPECT_EQ(assigned.getPosition(), "Project Manager");
    EXPECT_EQ(assigned.getSalary(), 5200);
    EXPECT_EQ(assigned.getTeamSize(), 12);
    EXPECT_EQ(assigned.getProjectCount(), 4);
}

TEST(ProjectManagerTests, SetProjectCount) {
    ProjectManager projectManager;
    projectManager.setProjectCount(7);
    EXPECT_EQ(projectManager.getProjectCount(), 7);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}