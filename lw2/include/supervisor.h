//
// Created by froonn on 12/11/24.
//

#ifndef PPOIS_LW2_SEM3_SUPERVISOR_H
#define PPOIS_LW2_SEM3_SUPERVISOR_H

#include <string>

#include "manager.h"

class Supervisor : public Manager {
public:
    Supervisor();
    Supervisor(const std::string& name, const std::string& surname, const std::string& position, int salary, int teamSize, const std::string& department);
    Supervisor(const Supervisor& supervisor);
    ~Supervisor() override;
    Supervisor& operator=(const Supervisor& supervisor);

    void setDepartment(const std::string& department);
    std::string getDepartment() const;

private:
    std::string department_;
};

#endif //PPOIS_LW2_SEM3_SUPERVISOR_H
