//
// Created by froonn on 12/11/24.
//

#ifndef PPOIS_LW2_SEM3_MANAGER_H
#define PPOIS_LW2_SEM3_MANAGER_H

#include <string>

#include "employee.h"

class Manager : public Employee {
public:
    Manager(const std::string& name = "Unknown", const std::string& surname = "Unknown",
            const std::string& position = "Unknown", int salary = 0, int teamSize = 0);
    Manager(const Manager& manager);
    ~Manager() override;
    Manager& operator=(const Manager& manager);

    void setTeamSize(int teamSize);
    [[nodiscard]] int getTeamSize() const;

private:
    int teamSize_;
};

#endif //PPOIS_LW2_SEM3_MANAGER_H
