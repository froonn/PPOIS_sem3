//
// Created by froonn on 18/11/24.
//

#include "service_request.h"

#include <pthread.h>

ServiceRequest::ServiceRequest() : requestDetails_("Unknown"), status_("Pending") {}

ServiceRequest::ServiceRequest(const std::string &requestDetails, const std::string &status)
    : requestDetails_(requestDetails), status_(status) {}

ServiceRequest::ServiceRequest(const ServiceRequest &serviceRequest)
    : requestDetails_(serviceRequest.requestDetails_), status_(serviceRequest.status_) {}

ServiceRequest::~ServiceRequest() = default;

ServiceRequest & ServiceRequest::operator=(const ServiceRequest &serviceRequest) {
    if (this != &serviceRequest) {
        requestDetails_ = serviceRequest.requestDetails_;
        status_ = serviceRequest.status_;
    }
    return *this;
}

void ServiceRequest::setRequestDetails(const std::string &requestDetails) {
    requestDetails_ = requestDetails;
}

std::string ServiceRequest::getRequestDetails() const {
    return requestDetails_;
}

void ServiceRequest::setStatus(const std::string &status) {
    status_ = status;
}

std::string ServiceRequest::getStatus() const {
    return status_;
}

