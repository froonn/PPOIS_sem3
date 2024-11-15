//
// Created by froonn on 12/11/24.
//

#ifndef PPOIS_LW2_SEM3_INVOICE_H
#define PPOIS_LW2_SEM3_INVOICE_H

#include <string>

class Invoice {
public:
    Invoice();
    Invoice(const std::string& invoiceNumber, double amount);
    Invoice(const Invoice& invoice);
    ~Invoice();
    Invoice& operator=(const Invoice& invoice);

    void setInvoiceNumber(const std::string& invoiceNumber);
    std::string getInvoiceNumber() const;

    void setAmount(double amount);
    double getAmount() const;

private:
    std::string invoiceNumber_;
    double amount_;
};

#endif //PPOIS_LW2_SEM3_INVOICE_H
