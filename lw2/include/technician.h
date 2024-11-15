//
// Created by froonn on 12/11/24.
//

#ifndef PPOIS_LW2_SEM3_TECHNICIAN_H
#define PPOIS_LW2_SEM3_TECHNICIAN_H

#include <string>

#include "employee.h"

class Technician : public Employee {
public:
    Technician();
    Technician(const std::string& name, const std::string& surname, const std::string& position, int salary, const std::string& specialization);
    Technician(const Technician& technician);
    // ~Technician() override;
    Technician& operator=(const Technician& technician);

    void setSpecialization(const std::string& specialization);
    std::string getSpecialization() const;

private:
    std::string specialization_;
};

#endif //PPOIS_LW2_SEM3_TECHNICIAN_H
