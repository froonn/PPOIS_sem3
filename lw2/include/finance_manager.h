//
// Created by froonn on 12/11/24.
//

#ifndef PPOIS_LW2_SEM3_FINANCE_MANAGER_H
#define PPOIS_LW2_SEM3_FINANCE_MANAGER_H

#include <string>

#include "manager.h"

class FinanceManager : public Manager {
public:
    FinanceManager(const std::string& name = "Unknown", const std::string& surname = "Unknown",
                   const std::string& position = "Unknown", int salary = 0, int teamSize = 0, double budget = 0);
    FinanceManager(const FinanceManager& financeManager);
    ~FinanceManager() override;
    FinanceManager& operator=(const FinanceManager& financeManager);

    void setBudget(double budget);
    [[nodiscard]] double getBudget() const;

private:
    double budget_;
};

#endif //PPOIS_LW2_SEM3_FINANCE_MANAGER_H
