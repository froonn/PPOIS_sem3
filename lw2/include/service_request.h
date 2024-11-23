//
// Created by froonn on 12/11/24.
//

#ifndef PPOIS_LW2_SEM3_SERVICE_REQUEST_H
#define PPOIS_LW2_SEM3_SERVICE_REQUEST_H

#include <string>

class ServiceRequest {
public:
    ServiceRequest();
    explicit ServiceRequest(const std::string& requestDetails, const std::string& status = "Unknown");
    ServiceRequest(const ServiceRequest& serviceRequest);
    ~ServiceRequest();
    ServiceRequest& operator=(const ServiceRequest& serviceRequest);

    void setRequestDetails(const std::string& requestDetails);
    [[nodiscard]] std::string getRequestDetails() const;

    void setStatus(const std::string& status);
    [[nodiscard]] std::string getStatus() const;

private:
    std::string requestDetails_;
    std::string status_;
};
#endif //PPOIS_LW2_SEM3_SERVICE_REQUEST_H
