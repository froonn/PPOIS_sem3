//
// Created by froonn on 18/11/24.
//

#include "repair_company.h"

RepairCompany::RepairCompany() {
    companyName_ = "Unknown";
}

RepairCompany::RepairCompany(const std::string &companyName) {
    companyName_ = companyName;
}

RepairCompany::RepairCompany(const RepairCompany &repairCompany) = default;

RepairCompany::~RepairCompany() = default;

RepairCompany & RepairCompany::operator=(const RepairCompany &repairCompany) {
    if (this == &repairCompany) return *this;

    companyName_ = repairCompany.companyName_;

    employees_ = repairCompany.employees_;
    technicians_ = repairCompany.technicians_;
    managers_ = repairCompany.managers_;
    electricians_ = repairCompany.electricians_;
    plumbers_ = repairCompany.plumbers_;
    carpenters_ = repairCompany.carpenters_;
    projectManagers_ = repairCompany.projectManagers_;
    financeManagers_ = repairCompany.financeManagers_;
    receptionists_ = repairCompany.receptionists_;
    supervisors_ = repairCompany.supervisors_;
    warehouseManagers_ = repairCompany.warehouseManagers_;

    clients_ = repairCompany.clients_;


    return *this;
}

void RepairCompany::setCompanyName(const std::string &companyName) {
    companyName_ = companyName;
}

std::string RepairCompany::getCompanyName() const {
    return companyName_;
}

void RepairCompany::addEmployee(const Employee& employee) {
    employees_.push_back(employee);
}

void RepairCompany::addTechnician(const Technician& technician) {
    technicians_.push_back(technician);
}

void RepairCompany::addManager(const Manager& manager) {
    managers_.push_back(manager);
}

void RepairCompany::addElectrician(const Electrician& electrician) {
    electricians_.push_back(electrician);
}

void RepairCompany::addPlumber(const Plumber& plumber) {
    plumbers_.push_back(plumber);
}

void RepairCompany::addCarpenter(const Carpenter& carpenter) {
    carpenters_.push_back(carpenter);
}

void RepairCompany::addProjectManager(const ProjectManager& projectManager) {
    projectManagers_.push_back(projectManager);
}

void RepairCompany::addFinanceManager(const FinanceManager& financeManager) {
    financeManagers_.push_back(financeManager);
}

void RepairCompany::addReceptionist(const Receptionist& receptionist) {
    receptionists_.push_back(receptionist);
}

void RepairCompany::addSupervisor(const Supervisor& supervisor) {
    supervisors_.push_back(supervisor);
}

void RepairCompany::addWarehouseManager(const WarehouseManager& warehouseManager) {
    warehouseManagers_.push_back(warehouseManager);
}

void RepairCompany::removeEmployee(const std::string& name, const std::string& surname) {
    employees_.erase(std::remove_if(employees_.begin(), employees_.end(),
        [&name, &surname](const Employee& employee) {
            return employee.getName() == name && employee.getSurname() == surname;
        }), employees_.end());
}

void RepairCompany::removeTechnician(const std::string& name, const std::string& surname) {
    technicians_.erase(std::remove_if(technicians_.begin(), technicians_.end(),
        [&name, &surname](const Technician& technician) {
            return technician.getName() == name && technician.getSurname() == surname;
        }), technicians_.end());
}

void RepairCompany::removeManager(const std::string& name, const std::string& surname) {
    managers_.erase(std::remove_if(managers_.begin(), managers_.end(),
        [&name, &surname](const Manager& manager) {
            return manager.getName() == name && manager.getSurname() == surname;
        }), managers_.end());
}

void RepairCompany::removeElectrician(const std::string& name, const std::string& surname) {
    electricians_.erase(std::remove_if(electricians_.begin(), electricians_.end(),
        [&name, &surname](const Electrician& electrician) {
            return electrician.getName() == name && electrician.getSurname() == surname;
        }), electricians_.end());
}

void RepairCompany::removePlumber(const std::string& name, const std::string& surname) {
    plumbers_.erase(std::remove_if(plumbers_.begin(), plumbers_.end(),
        [&name, &surname](const Plumber& plumber) {
            return plumber.getName() == name && plumber.getSurname() == surname;
        }), plumbers_.end());
}

void RepairCompany::removeCarpenter(const std::string& name, const std::string& surname) {
    carpenters_.erase(std::remove_if(carpenters_.begin(), carpenters_.end(),
        [&name, &surname](const Carpenter& carpenter) {
            return carpenter.getName() == name && carpenter.getSurname() == surname;
        }), carpenters_.end());
}

void RepairCompany::removeProjectManager(const std::string& name, const std::string& surname) {
    projectManagers_.erase(std::remove_if(projectManagers_.begin(), projectManagers_.end(),
        [&name, &surname](const ProjectManager& projectManager) {
            return projectManager.getName() == name && projectManager.getSurname() == surname;
        }), projectManagers_.end());
}

void RepairCompany::removeFinanceManager(const std::string& name, const std::string& surname) {
    financeManagers_.erase(std::remove_if(financeManagers_.begin(), financeManagers_.end(),
        [&name, &surname](const FinanceManager& financeManager) {
            return financeManager.getName() == name && financeManager.getSurname() == surname;
        }), financeManagers_.end());
}

void RepairCompany::removeReceptionist(const std::string& name, const std::string& surname) {
    receptionists_.erase(std::remove_if(receptionists_.begin(), receptionists_.end(),
        [&name, &surname](const Receptionist& receptionist) {
            return receptionist.getName() == name && receptionist.getSurname() == surname;
        }), receptionists_.end());
}

void RepairCompany::removeSupervisor(const std::string& name, const std::string& surname) {
    supervisors_.erase(std::remove_if(supervisors_.begin(), supervisors_.end(),
        [&name, &surname](const Supervisor& supervisor) {
            return supervisor.getName() == name && supervisor.getSurname() == surname;
        }), supervisors_.end());
}

void RepairCompany::removeWarehouseManager(const std::string& name, const std::string& surname) {
    warehouseManagers_.erase(std::remove_if(warehouseManagers_.begin(), warehouseManagers_.end(),
        [&name, &surname](const WarehouseManager& warehouseManager) {
            return warehouseManager.getName() == name && warehouseManager.getSurname() == surname;
        }), warehouseManagers_.end());
}



Employee& RepairCompany::getEmployee(const std::string& name, const std::string& surname) {
    auto it = std::find_if(employees_.begin(), employees_.end(),
        [&name, &surname](const Employee& employee) {
            return employee.getName() == name && employee.getSurname() == surname;
        });
    if (it != employees_.end()) {
        return *it;
    } else {
        throw std::runtime_error("Employee not found");
    }
}

Technician& RepairCompany::getTechnician(const std::string& name, const std::string& surname) {
    auto it = std::find_if(technicians_.begin(), technicians_.end(),
        [&name, &surname](const Technician& technician) {
            return technician.getName() == name && technician.getSurname() == surname;
        });
    if (it != technicians_.end()) {
        return *it;
    } else {
        throw std::runtime_error("Technician not found");
    }
}

Manager& RepairCompany::getManager(const std::string& name, const std::string& surname) {
    auto it = std::find_if(managers_.begin(), managers_.end(),
        [&name, &surname](const Manager& manager) {
            return manager.getName() == name && manager.getSurname() == surname;
        });
    if (it != managers_.end()) {
        return *it;
    } else {
        throw std::runtime_error("Manager not found");
    }
}

Electrician& RepairCompany::getElectrician(const std::string& name, const std::string& surname) {
    auto it = std::find_if(electricians_.begin(), electricians_.end(),
        [&name, &surname](const Electrician& electrician) {
            return electrician.getName() == name && electrician.getSurname() == surname;
        });
    if (it != electricians_.end()) {
        return *it;
    } else {
        throw std::runtime_error("Electrician not found");
    }
}

Plumber& RepairCompany::getPlumber(const std::string& name, const std::string& surname) {
    auto it = std::find_if(plumbers_.begin(), plumbers_.end(),
        [&name, &surname](const Plumber& plumber) {
            return plumber.getName() == name && plumber.getSurname() == surname;
        });
    if (it != plumbers_.end()) {
        return *it;
    } else {
        throw std::runtime_error("Plumber not found");
    }
}

Carpenter& RepairCompany::getCarpenter(const std::string& name, const std::string& surname) {
    auto it = std::find_if(carpenters_.begin(), carpenters_.end(),
        [&name, &surname](const Carpenter& carpenter) {
            return carpenter.getName() == name && carpenter.getSurname() == surname;
        });
    if (it != carpenters_.end()) {
        return *it;
    } else {
        throw std::runtime_error("Carpenter not found");
    }
}

ProjectManager& RepairCompany::getProjectManager(const std::string& name, const std::string& surname) {
    auto it = std::find_if(projectManagers_.begin(), projectManagers_.end(),
        [&name, &surname](const ProjectManager& projectManager) {
            return projectManager.getName() == name && projectManager.getSurname() == surname;
        });
    if (it != projectManagers_.end()) {
        return *it;
    } else {
        throw std::runtime_error("Project Manager not found");
    }
}

FinanceManager& RepairCompany::getFinanceManager(const std::string& name, const std::string& surname) {
    auto it = std::find_if(financeManagers_.begin(), financeManagers_.end(),
        [&name, &surname](const FinanceManager& financeManager) {
            return financeManager.getName() == name && financeManager.getSurname() == surname;
        });
    if (it != financeManagers_.end()) {
        return *it;
    } else {
        throw std::runtime_error("Finance Manager not found");
    }
}

Receptionist& RepairCompany::getReceptionist(const std::string& name, const std::string& surname) {
    auto it = std::find_if(receptionists_.begin(), receptionists_.end(),
        [&name, &surname](const Receptionist& receptionist) {
            return receptionist.getName() == name && receptionist.getSurname() == surname;
        });
    if (it != receptionists_.end()) {
        return *it;
    } else {
        throw std::runtime_error("Receptionist not found");
    }
}

Supervisor& RepairCompany::getSupervisor(const std::string& name, const std::string& surname) {
    auto it = std::find_if(supervisors_.begin(), supervisors_.end(),
        [&name, &surname](const Supervisor& supervisor) {
            return supervisor.getName() == name && supervisor.getSurname() == surname;
        });
    if (it != supervisors_.end()) {
        return *it;
    } else {
        throw std::runtime_error("Supervisor not found");
    }
}

WarehouseManager& RepairCompany::getWarehouseManager(const std::string& name, const std::string& surname) {
    auto it = std::find_if(warehouseManagers_.begin(), warehouseManagers_.end(),
        [&name, &surname](const WarehouseManager& warehouseManager) {
            return warehouseManager.getName() == name && warehouseManager.getSurname() == surname;
        });
    if (it != warehouseManagers_.end()) {
        return *it;
    } else {
        throw std::runtime_error("Warehouse Manager not found");
    }
}

void RepairCompany::addClient(const Client& client, const ServiceRequest& serviceRequest) {
    clients_.push_back(std::pair(client, serviceRequest));
}

Client& RepairCompany::getClient(const std::string& name, const std::string& surname) {
    auto it = std::find_if(clients_.begin(), clients_.end(),
        [&name, &surname](const std::pair<Client, ServiceRequest>& clientPair) {
            return clientPair.first.getName() == name && clientPair.first.getSurname() == surname;
        });
    if (it != clients_.end()) {
        return it->first;
    } else {
        throw std::runtime_error("Client not found");
    }
}

ServiceRequest& RepairCompany::getServiceRequest(const std::string& name, const std::string& surname) {
    auto it = std::find_if(clients_.begin(), clients_.end(),
        [&name, &surname](const std::pair<Client, ServiceRequest>& clientPair) {
            return clientPair.first.getName() == name && clientPair.first.getSurname() == surname;
        });
    if (it != clients_.end()) {
        return it->second;
    } else {
        throw std::runtime_error("Service request not found");
    }
}

Invoice& RepairCompany::removeClient(const std::string& name, const std::string& surname) {
    auto it = std::find_if(clients_.begin(), clients_.end(),
        [&name, &surname](const std::pair<Client, ServiceRequest>& clientPair) {
            return clientPair.first.getName() == name && clientPair.first.getSurname() == surname;
        });
    if (it != clients_.end()) {
        Invoice invoice = generateInvoice(it->second); // Assuming generateInvoice is a method that creates an invoice from a service request
        clients_.erase(it);
        return invoice;
    } else {
        throw std::runtime_error("Client not found");
    }
}