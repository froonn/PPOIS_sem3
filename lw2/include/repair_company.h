//
// Created by froonn on 12/11/24.
//

#ifndef PPOIS_LW2_SEM3_REPAIR_COMPANY_H
#define PPOIS_LW2_SEM3_REPAIR_COMPANY_H

#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>


#include "employee.h"
#include "technician.h"
#include "manager.h"
#include "electrician.h"
#include "plumber.h"
#include "carpenter.h"
#include "project_manager.h"
#include "finance_manager.h"
#include "receptionist.h"
#include "supervisor.h"
#include "warehouse_manager.h"
#include "client.h"
#include "service_request.h"
#include "invoice.h"

class RepairCompany {
public:
    RepairCompany();
    explicit RepairCompany(const std::string &companyName);
    RepairCompany(const RepairCompany& repairCompany);
    ~RepairCompany();
    RepairCompany& operator=(const RepairCompany& repairCompany);

    void setCompanyName(const std::string& companyName);
    [[nodiscard]] std::string getCompanyName() const;

    void addEmployee(const Employee& employee);
    void addTechnician(const Technician& technician);
    void addManager(const Manager& manager);
    void addElectrician(const Electrician& electrician);
    void addPlumber(const Plumber& plumber);
    void addCarpenter(const Carpenter& carpenter);
    void addProjectManager(const ProjectManager& projectManager);
    void addFinanceManager(const FinanceManager& financeManager);
    void addReceptionist(const Receptionist& receptionist);
    void addSupervisor(const Supervisor& supervisor);
    void addWarehouseManager(const WarehouseManager& warehouseManager);
    
    void removeEmployee(const std::string& name, const std::string& surname);
    void removeTechnician(const std::string& name, const std::string& surname);
    void removeManager(const std::string& name, const std::string& surname);
    void removeElectrician(const std::string& name, const std::string& surname);
    void removePlumber(const std::string& name, const std::string& surname);
    void removeCarpenter(const std::string& name, const std::string& surname);
    void removeProjectManager(const std::string& name, const std::string& surname);
    void removeFinanceManager(const std::string& name, const std::string& surname);
    void removeReceptionist(const std::string& name, const std::string& surname);
    void removeSupervisor(const std::string& name, const std::string& surname);
    void removeWarehouseManager(const std::string& name, const std::string& surname);

    [[nodiscard]] Employee& getEmployee(const std::string& name, const std::string& surname);
    [[nodiscard]] Technician& getTechnician(const std::string& name, const std::string& surname);
    [[nodiscard]] Manager& getManager(const std::string& name, const std::string& surname);
    [[nodiscard]] Electrician& getElectrician(const std::string& name, const std::string& surname);
    [[nodiscard]] Plumber& getPlumber(const std::string& name, const std::string& surname);
    [[nodiscard]] Carpenter& getCarpenter(const std::string& name, const std::string& surname);
    [[nodiscard]] ProjectManager& getProjectManager(const std::string& name, const std::string& surname);
    [[nodiscard]] FinanceManager& getFinanceManager(const std::string& name, const std::string& surname);
    [[nodiscard]] Receptionist& getReceptionist(const std::string& name, const std::string& surname);
    [[nodiscard]] Supervisor& getSupervisor(const std::string& name, const std::string& surname);
    [[nodiscard]] WarehouseManager& getWarehouseManager(const std::string& name, const std::string& surname);


    void addClient(const Client& client, const ServiceRequest& serviceRequest);
    Client& getClient(const std::string& name, const std::string& surname);
    ServiceRequest& getServiceRequest(const std::string& name, const std::string& surname);
    Invoice& removeClient(const std::string& name, const std::string& surname);

private:

    std::vector<Employee> employees_;
    std::vector<Technician> technicians_;
    std::vector<Manager> managers_;
    std::vector<Electrician> electricians_;
    std::vector<Plumber> plumbers_;
    std::vector<Carpenter> carpenters_;
    std::vector<ProjectManager> projectManagers_;
    std::vector<FinanceManager> financeManagers_;
    std::vector<Receptionist> receptionists_;
    std::vector<Supervisor> supervisors_;
    std::vector<WarehouseManager> warehouseManagers_;

    std::vector<std::pair<Client, ServiceRequest>> clients_;



    std::string companyName_;
};

#endif //PPOIS_LW2_SEM3_REPAIR_COMPANY_H
