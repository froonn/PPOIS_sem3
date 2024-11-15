//
// Created by froonn on 12/11/24.
//

#include "carpenter.h"

Carpenter::Carpenter() {
    toolset_ = "Default toolset";
}

Carpenter::Carpenter(const std::string &name, const std::string &surname, const std::string &position, int salary,
    const std::string &specialization, const std::string &toolset) {
}

Carpenter::~Carpenter() {
    toolset_ = "";
}
