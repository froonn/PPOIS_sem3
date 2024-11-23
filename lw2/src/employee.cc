//
// Created by froonn on 18/11/24.
//

#include "employee.h"

Employee::Employee() {
    name_ = "Unknown";
    surname_ = "Unknown";
    position_ = "Unknown";
    salary_ = 0;
}

Employee::Employee(const std::string &name, const std::string &surname, const std::string &position, int salary) {
    name_ = name;
    surname_ = surname;
    position_ = position;
    salary_ = salary;
}

Employee::Employee(const Employee &employee) {
    name_ = employee.name_;
    surname_ = employee.surname_;
    position_ = employee.position_;
    salary_ = employee.salary_;
}

Employee::~Employee() = default;

Employee & Employee::operator=(const Employee &employee) {
    if (this != &employee) {
        name_ = employee.name_;
        surname_ = employee.surname_;
        position_ = employee.position_;
        salary_ = employee.salary_;
    }
    return *this;
}

void Employee::setName(const std::string &name) {
    name_ = name;
}

void Employee::setSurname(const std::string &surname) {
    surname_ = surname;
}

void Employee::setPosition(const std::string &position) {
    position_ = position;
}

void Employee::setSalary(int salary) {
    salary_ = salary;
}

std::string Employee::getName() const {
    return name_;
}

std::string Employee::getSurname() const {
    return surname_;
}

std::string Employee::getPosition() const {
    return position_;
}

int Employee::getSalary() const {
    return salary_;
}
