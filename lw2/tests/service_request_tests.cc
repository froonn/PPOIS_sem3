//
// Created by froonn on 18/11/24.
//

#include "service_request.h"
#include <gtest/gtest.h>

TEST(ServiceRequestTests, DefaultConstructor) {
    ServiceRequest serviceRequest;
    EXPECT_EQ(serviceRequest.getRequestDetails(), "Unknown");
    EXPECT_EQ(serviceRequest.getStatus(), "Pending");
}

TEST(ServiceRequestTests, ParameterizedConstructor) {
    ServiceRequest serviceRequest("Fix server issue", "In Progress");
    EXPECT_EQ(serviceRequest.getRequestDetails(), "Fix server issue");
    EXPECT_EQ(serviceRequest.getStatus(), "In Progress");
}

TEST(ServiceRequestTests, CopyConstructor) {
    ServiceRequest original("Update software", "Completed");
    ServiceRequest copy(original);
    EXPECT_EQ(copy.getRequestDetails(), "Update software");
    EXPECT_EQ(copy.getStatus(), "Completed");
}

TEST(ServiceRequestTests, AssignmentOperator) {
    ServiceRequest original("Install new hardware", "Pending");
    ServiceRequest assigned;
    assigned = original;
    EXPECT_EQ(assigned.getRequestDetails(), "Install new hardware");
    EXPECT_EQ(assigned.getStatus(), "Pending");
}

TEST(ServiceRequestTests, SetRequestDetails) {
    ServiceRequest serviceRequest;
    serviceRequest.setRequestDetails("Replace faulty cable");
    EXPECT_EQ(serviceRequest.getRequestDetails(), "Replace faulty cable");
}

TEST(ServiceRequestTests, SetStatus) {
    ServiceRequest serviceRequest;
    serviceRequest.setStatus("Resolved");
    EXPECT_EQ(serviceRequest.getStatus(), "Resolved");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}