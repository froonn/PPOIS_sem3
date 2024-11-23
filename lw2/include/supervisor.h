//
// Created by froonn on 12/11/24.
//

#ifndef PPOIS_LW2_SEM3_SUPERVISOR_H
#define PPOIS_LW2_SEM3_SUPERVISOR_H

#include <string>

#include "manager.h"

class Supervisor : public Manager {
public:
    Supervisor(const std::string& name = "Unknown", const std::string& surname = "Unknown",
               const std::string& position = "Unknown", int salary = 0, int teamSize = 0, const std::string& department = "Unknown");
    Supervisor(const Supervisor& supervisor);
    ~Supervisor() override;
    Supervisor& operator=(const Supervisor& supervisor);

    void setDepartment(const std::string& department);
    [[nodiscard]] std::string getDepartment() const;

private:
    std::string department_;
};

#endif //PPOIS_LW2_SEM3_SUPERVISOR_H
