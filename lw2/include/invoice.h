//
// Created by froonn on 12/11/24.
//

#ifndef PPOIS_LW2_SEM3_INVOICE_H
#define PPOIS_LW2_SEM3_INVOICE_H

#include <string>
#include <random>

#include "service_request.h"

class Invoice {
public:
    Invoice();
    Invoice(const std::string& invoiceNumber, double amount);
    Invoice(const Invoice& invoice);
    ~Invoice();
    Invoice& operator=(const Invoice& invoice);

    void setInvoiceNumber(const std::string& invoiceNumber);
    [[nodiscard]] std::string getInvoiceNumber() const;

    void setAmount(double amount);
    [[nodiscard]] double getAmount() const;

    friend Invoice generateInvoice(ServiceRequest serviceRequest);

private:
    std::string invoiceNumber_;
    double amount_;
};

Invoice generateInvoice(ServiceRequest serviceRequest);

#endif //PPOIS_LW2_SEM3_INVOICE_H
