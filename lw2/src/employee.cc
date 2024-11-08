//
// Created by xinardelis on 26/10/24.
//

#include "employee.h"

Employee::Employee() {
    this->name_ = "";
    this->surname_ = "";
    this->position_ = "";
    this->salary_ = 0;
}

Employee::Employee(const std::string &name, const std::string &surname, const std::string &position, int salary) {
    this->name_ = name;
    this->surname_ = surname;
    this->position_ = position;
    this->salary_ = salary;
}

Employee::Employee(const Employee &employee) {
    this->name_ = employee.name_;
    this->surname_ = employee.surname_;
    this->position_ = employee.position_;
    this->salary_ = employee.salary_;
}

Employee::~Employee() = default;

Employee &Employee::operator=(const Employee &employee) {
    if (this != &employee) {
        this->name_ = employee.name_;
        this->surname_ = employee.surname_;
        this->position_ = employee.position_;
        this->salary_ = employee.salary_;
    }
    return *this;
}

void Employee::setName(const std::string &name) {
    this->name_ = name;
}

void Employee::setSurname(const std::string &surname) {
    this->surname_ = surname;
}

void Employee::setPosition(const std::string& position) {
    this->position_ = position;
}

void Employee::setSalary(int salary) {
    this->salary_ = salary;
}

int Employee::getSalary() const {
    return this->salary_;
}

std::string Employee::getName() const {
    return this->name_;
}

std::string Employee::getSurname() const {
    return this->surname_;
}

std::string Employee::getPosition() const {
    return this->position_;
}


