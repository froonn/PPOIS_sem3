//
// Created by froonn on 18/11/24.
//

#include "electrician.h"

Electrician::Electrician(const std::string &name, const std::string &surname, const std::string &position, int salary, const std::string &specialization, int certificationLevel)
    : Technician(name, surname, position, salary, specialization), certificationLevel_(certificationLevel) {}

Electrician::Electrician(const Electrician &electrician)
    : Technician(electrician), certificationLevel_(electrician.certificationLevel_) {}

Electrician::~Electrician() = default;

Electrician & Electrician::operator=(const Electrician &electrician) {
    if (this != &electrician) {
        Technician::operator=(electrician);
        certificationLevel_ = electrician.certificationLevel_;
    }
    return *this;
}

void Electrician::setCertificationLevel(int certificationLevel) {
    certificationLevel_ = certificationLevel;
}

int Electrician::getCertificationLevel() const {
    return certificationLevel_;
}
