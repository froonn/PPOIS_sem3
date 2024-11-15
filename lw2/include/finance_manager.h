//
// Created by froonn on 12/11/24.
//

#ifndef PPOIS_LW2_SEM3_FINANCE_MANAGER_H
#define PPOIS_LW2_SEM3_FINANCE_MANAGER_H

#include <string>

#include "manager.h"

class FinanceManager : public Manager {
public:
    FinanceManager();
    FinanceManager(const std::string& name, const std::string& surname, const std::string& position, int salary, int teamSize, double budget);
    FinanceManager(const FinanceManager& financeManager);
    ~FinanceManager() override;
    FinanceManager& operator=(const FinanceManager& financeManager);

    void setBudget(double budget);
    double getBudget() const;

private:
    double budget_;
};

#endif //PPOIS_LW2_SEM3_FINANCE_MANAGER_H
