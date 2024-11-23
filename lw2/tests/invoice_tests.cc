//
// Created by froonn on 18/11/24.
//

#include "invoice.h"
#include <gtest/gtest.h>

TEST(InvoiceTests, DefaultConstructor) {
    Invoice invoice;
    EXPECT_EQ(invoice.getInvoiceNumber(), "Unknown");
    EXPECT_EQ(invoice.getAmount(), 0.0);
}

TEST(InvoiceTests, ParameterizedConstructor) {
    Invoice invoice("INV12345", 1500.75);
    EXPECT_EQ(invoice.getInvoiceNumber(), "INV12345");
    EXPECT_EQ(invoice.getAmount(), 1500.75);
}

TEST(InvoiceTests, CopyConstructor) {
    Invoice original("INV67890", 2500.50);
    Invoice copy(original);
    EXPECT_EQ(copy.getInvoiceNumber(), "INV67890");
    EXPECT_EQ(copy.getAmount(), 2500.50);
}

TEST(InvoiceTests, AssignmentOperator) {
    Invoice original("INV54321", 3000.00);
    Invoice assigned;
    assigned = original;
    EXPECT_EQ(assigned.getInvoiceNumber(), "INV54321");
    EXPECT_EQ(assigned.getAmount(), 3000.00);
}

TEST(InvoiceTests, SetInvoiceNumber) {
    Invoice invoice;
    invoice.setInvoiceNumber("INV98765");
    EXPECT_EQ(invoice.getInvoiceNumber(), "INV98765");
}

TEST(InvoiceTests, SetAmount) {
    Invoice invoice;
    invoice.setAmount(4500.25);
    EXPECT_EQ(invoice.getAmount(), 4500.25);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}