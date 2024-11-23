//
// Created by froonn on 18/11/24.
//

#include "manager.h"

Manager::Manager(const std::string &name, const std::string &surname, const std::string &position, int salary, int teamSize)
    : Employee(name, surname, position, salary), teamSize_(teamSize) {}

Manager::Manager(const Manager &manager)
    : Employee(manager), teamSize_(manager.teamSize_) {}

Manager::~Manager() = default;

Manager & Manager::operator=(const Manager &manager) {
    if (this != &manager) {
        Employee::operator=(manager);
        teamSize_ = manager.teamSize_;
    }
    return *this;
}

void Manager::setTeamSize(int teamSize) {
    teamSize_ = teamSize;
}

int Manager::getTeamSize() const {
    return teamSize_;
}
