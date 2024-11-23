//
// Created by froonn on 18/11/24.
//

#include "plumber.h"

Plumber::Plumber(const std::string &name, const std::string &surname, const std::string &position, int salary, const std::string &specialization, int experienceYears)
    : Technician(name, surname, position, salary, specialization), experienceYears_(experienceYears) {}

Plumber::Plumber(const Plumber &plumber)
    : Technician(plumber), experienceYears_(plumber.experienceYears_) {}

Plumber::~Plumber() = default;

Plumber & Plumber::operator=(const Plumber &plumber) {
    if (this != &plumber) {
        Technician::operator=(plumber);
        experienceYears_ = plumber.experienceYears_;
    }
    return *this;
}

void Plumber::setExperienceYears(int experienceYears) {
    experienceYears_ = experienceYears;
}

int Plumber::getExperienceYears() const {
    return experienceYears_;
}
