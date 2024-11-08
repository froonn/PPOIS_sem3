//
// Created by xinardelis on 26/10/24.
//

#ifndef PPOIS_LW2_SEM3_MANAGER_H
#define PPOIS_LW2_SEM3_MANAGER_H

#include "employee.h"

class Manager : public Employee {
public:
    Manager();
    explicit Manager(const std::string& name, const std::string& surname, const std::string& position, int salary, int subordinates);
    Manager(const Manager &manager);
    virtual ~Manager() override;
    Manager& operator=(const Manager &manager);

    void setSubordinates(int subordinates);
    [[nodiscard]] int getSubordinates() const;
private:
    int subordinates_;
};

#endif //PPOIS_LW2_SEM3_MANAGER_H
