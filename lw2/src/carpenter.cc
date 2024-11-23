//
// Created by froonn on 12/11/24.
//

#include "carpenter.h"

Carpenter::Carpenter(const std::string &name, const std::string &surname, const std::string &position, int salary,
    const std::string &specialization, const std::string &toolset)
    : Technician(name, surname, position, salary, specialization), toolset_(toolset) {}

Carpenter::Carpenter(const Carpenter &carpenter)
    : Technician(carpenter), toolset_(carpenter.toolset_) {}

Carpenter::~Carpenter() = default;

Carpenter & Carpenter::operator=(const Carpenter &carpenter) {
    if (this == &carpenter) {
        return *this;
    }
    Technician::operator=(carpenter);
    toolset_ = carpenter.toolset_;
    return *this;
}

void Carpenter::setToolset(const std::string &toolset) {
    toolset_ = toolset;
}

std::string Carpenter::getToolset() const {
    return toolset_;
}
