//
// Created by froonn on 18/11/24.
//

#include "finance_manager.h"

FinanceManager::FinanceManager(const std::string &name, const std::string &surname, const std::string &position, int salary, int teamSize, double budget)
    : Manager(name, surname, position, salary, teamSize), budget_(budget) {}

FinanceManager::FinanceManager(const FinanceManager &financeManager)
    : Manager(financeManager), budget_(financeManager.budget_) {}

FinanceManager::~FinanceManager() = default;

FinanceManager & FinanceManager::operator=(const FinanceManager &financeManager) {
    if (this != &financeManager) {
        Manager::operator=(financeManager);
        budget_ = financeManager.budget_;
    }
    return *this;
}

void FinanceManager::setBudget(double budget) {
    budget_ = budget;
}

double FinanceManager::getBudget() const {
    return budget_;
}
