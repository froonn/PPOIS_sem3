//
// Created by froonn on 12/11/24.
//

#ifndef PPOIS_LW2_SEM3_RECEPTIONIST_H
#define PPOIS_LW2_SEM3_RECEPTIONIST_H

#include <string>

#include "employee.h"

class Receptionist : public Employee {
public:
    Receptionist(const std::string& name = "Unknown", const std::string& surname = "Unknown",
                 const std::string& position = "Unknown", int salary = 0, const std::string& shift = "Default shift");
    Receptionist(const Receptionist& receptionist);
    ~Receptionist() override;
    Receptionist& operator=(const Receptionist& receptionist);

    void setShift(const std::string& shift);
    [[nodiscard]] std::string getShift() const;

private:
    std::string shift_;
};

#endif //PPOIS_LW2_SEM3_RECEPTIONIST_H
