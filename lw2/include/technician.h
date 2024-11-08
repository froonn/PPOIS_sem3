//
// Created by xinardelis on 26/10/24.
//

#ifndef PPOIS_LW2_SEM3_TECHNICIAN_H
#define PPOIS_LW2_SEM3_TECHNICIAN_H

#include "employee.h"

class Technician : public Employee {
public:
    Technician();

    explicit Technician(const std::string &name,
                        const std::string &surname,
                        const std::string &position,
                        int salary,
                        int experience);

    Technician(const Technician &technician);

    virtual ~Technician() override;

    Technician &operator=(const Technician &technician);

    void setExperience(int experience);

    [[nodiscard]] int getExperience() const;

private:
    int experience_;
};

#endif //PPOIS_LW2_SEM3_TECHNICIAN_H
