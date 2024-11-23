//
// Created by froonn on 18/11/24.
//

#include "technician.h"


Technician::Technician(const std::string &name, const std::string &surname, const std::string &position, int salary, const std::string &specialization)
    : Employee(name, surname, position, salary), specialization_(specialization) {
}

Technician::Technician(const Technician &technician) : Employee(technician) {
    specialization_ = technician.specialization_;
}

Technician::~Technician() = default;

Technician & Technician::operator=(const Technician &technician) {
    if (this != &technician) {
        Employee::operator=(technician);
        specialization_ = technician.specialization_;
    }
    return *this;
}

void Technician::setSpecialization(const std::string &specialization) {
    specialization_ = specialization;
}

std::string Technician::getSpecialization() const {
    return specialization_;
}
