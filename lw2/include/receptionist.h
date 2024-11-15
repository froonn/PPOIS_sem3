//
// Created by froonn on 12/11/24.
//

#ifndef PPOIS_LW2_SEM3_RECEPTIONIST_H
#define PPOIS_LW2_SEM3_RECEPTIONIST_H

#include <string>

#include "employee.h"

class Receptionist : public Employee {
public:
    Receptionist();
    Receptionist(const std::string& name, const std::string& surname, const std::string& position, int salary, const std::string& shift);
    Receptionist(const Receptionist& receptionist);
    ~Receptionist() override;
    Receptionist& operator=(const Receptionist& receptionist);

    void setShift(const std::string& shift);
    std::string getShift() const;

private:
    std::string shift_;
};

#endif //PPOIS_LW2_SEM3_RECEPTIONIST_H
