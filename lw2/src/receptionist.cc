//
// Created by froonn on 18/11/24.
//

#include "receptionist.h"

Receptionist::Receptionist(const std::string &name, const std::string &surname, const std::string &position, int salary, const std::string &shift)
    : Employee(name, surname, position, salary), shift_(shift) {}

Receptionist::Receptionist(const Receptionist &receptionist)
    : Employee(receptionist), shift_(receptionist.shift_) {}

Receptionist::~Receptionist() = default;

Receptionist & Receptionist::operator=(const Receptionist &receptionist) {
    if (this != &receptionist) {
        Employee::operator=(receptionist);
        shift_ = receptionist.shift_;
    }
    return *this;
}

void Receptionist::setShift(const std::string &shift) {
    shift_ = shift;
}

std::string Receptionist::getShift() const {
    return shift_;
}
