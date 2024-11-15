//
// Created by froonn on 12/11/24.
//

#ifndef PPOIS_LW2_SEM3_REPAIR_COMPANY_H
#define PPOIS_LW2_SEM3_REPAIR_COMPANY_H

#include <string>

class RepairCompany : /*TODO*/ {
public:
    RepairCompany();
    RepairCompany(const std::string& name, const std::string& surname, const std::string& position, int salary, int teamSize, int projectCount, double budget);
    RepairCompany(const RepairCompany& repairCompany);
    ~RepairCompany() override;
    RepairCompany& operator=(const RepairCompany& repairCompany);

    void setCompanyName(const std::string& companyName);
    std::string getCompanyName() const;

private:
    std::string companyName_;
};

#endif //PPOIS_LW2_SEM3_REPAIR_COMPANY_H
