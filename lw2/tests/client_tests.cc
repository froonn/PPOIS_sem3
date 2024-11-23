//
// Created by froonn on 18/11/24.
//

#include "client.h"
#include <gtest/gtest.h>

TEST(ClientTests, DefaultConstructor) {
    Client client;
    EXPECT_EQ(client.getName(), "Unknown");
    EXPECT_EQ(client.getContactInfo(), "Unknown");
}

TEST(ClientTests, ParameterizedConstructor) {
    Client client("John", "Doe", "john.doe@example.com");
    EXPECT_EQ(client.getName(), "John");
    EXPECT_EQ(client.getSurname(), "Doe");
    EXPECT_EQ(client.getContactInfo(), "john.doe@example.com");
}

TEST(ClientTests, CopyConstructor) {
    Client original("Jane", "Smith", "jane.smith@example.com");
    Client copy(original);
    EXPECT_EQ(copy.getName(), "Jane");
    EXPECT_EQ(copy.getSurname(), "Smith");
    EXPECT_EQ(copy.getContactInfo(), "jane.smith@example.com");
}

TEST(ClientTests, AssignmentOperator) {
    Client original("Alice", "Johnson", "alice.johnson@example.com");
    Client assigned;
    assigned = original;
    EXPECT_EQ(assigned.getName(), "Alice");
    EXPECT_EQ(assigned.getSurname(), "Johnson");
    EXPECT_EQ(assigned.getContactInfo(), "alice.johnson@example.com");
}

TEST(ClientTests, SetName) {
    Client client;
    client.setName("Bob");
    EXPECT_EQ(client.getName(), "Bob");
}

TEST(ClientTests, SetSurame) {
    Client client;
    client.setSurname("Brown");
    EXPECT_EQ(client.getSurname(), "Brown");
}

TEST(ClientTests, SetContactInfo) {
    Client client;
    client.setContactInfo("bob.brown@example.com");
    EXPECT_EQ(client.getContactInfo(), "bob.brown@example.com");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}