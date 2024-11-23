//
// Created by froonn on 18/11/24.
//

#include "invoice.h"

Invoice::Invoice() : invoiceNumber_("Unknown"), amount_(0.0) {}

Invoice::Invoice(const std::string &invoiceNumber, double amount)
    : invoiceNumber_(invoiceNumber), amount_(amount) {}

Invoice::Invoice(const Invoice &invoice)
    : invoiceNumber_(invoice.invoiceNumber_), amount_(invoice.amount_) {}

Invoice::~Invoice() = default;

Invoice & Invoice::operator=(const Invoice &invoice) {
    if (this != &invoice) {
        invoiceNumber_ = invoice.invoiceNumber_;
        amount_ = invoice.amount_;
    }
    return *this;
}

void Invoice::setInvoiceNumber(const std::string &invoiceNumber) {
    invoiceNumber_ = invoiceNumber;
}

std::string Invoice::getInvoiceNumber() const {
    return invoiceNumber_;
}

void Invoice::setAmount(double amount) {
    amount_ = amount;
}

double Invoice::getAmount() const {
    return amount_;
}

Invoice generateInvoice(ServiceRequest serviceRequest) {
    static int lastInvoiceNumber = 0; // Static variable to keep track of the last invoice number
    lastInvoiceNumber++; // Increment the invoice number

    std::string invoiceNumber = "INV" + std::to_string(lastInvoiceNumber); // Generate a unique invoice number
    double amount = 100.0 + (std::rand() % 101); // Generate a random amount between 100 and 200

    return Invoice(invoiceNumber, amount);
}
