//
// Created by froonn on 12/11/24.
//

#ifndef PPOIS_LW2_SEM3_MANAGER_H
#define PPOIS_LW2_SEM3_MANAGER_H

#include <string>

#include "employee.h"

class Manager : public Employee {
public:
    Manager();
    Manager(const std::string& name, const std::string& surname, const std::string& position, int salary, int teamSize);
    Manager(const Manager& manager);
    ~Manager() override;
    Manager& operator=(const Manager& manager);

    void setTeamSize(int teamSize);
    int getTeamSize() const;

private:
    int teamSize_;
};

#endif //PPOIS_LW2_SEM3_MANAGER_H
