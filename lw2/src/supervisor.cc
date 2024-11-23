//
// Created by froonn on 18/11/24.
//

#include "supervisor.h"

Supervisor::Supervisor(const std::string &name, const std::string &surname, const std::string &position, int salary, int teamSize, const std::string &department)
    : Manager(name, surname, position, salary, teamSize), department_(department) {}

Supervisor::Supervisor(const Supervisor &supervisor)
    : Manager(supervisor), department_(supervisor.department_) {}

Supervisor::~Supervisor() = default;

Supervisor & Supervisor::operator=(const Supervisor &supervisor) {
    if (this != &supervisor) {
        Manager::operator=(supervisor);
        department_ = supervisor.department_;
    }
    return *this;
}

void Supervisor::setDepartment(const std::string &department) {
    department_ = department;
}

std::string Supervisor::getDepartment() const {
    return department_;
}

