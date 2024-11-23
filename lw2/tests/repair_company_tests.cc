//
// Created by froonn on 18/11/24.
//

#include <gtest/gtest.h>
#include "repair_company.h"

TEST(RepairCompanyTest, AddAndGetEmployee) {
    RepairCompany company;
    Employee employee("John", "Doe");
    company.addEmployee(employee);
    Employee& retrievedEmployee = company.getEmployee("John", "Doe");
    EXPECT_EQ(retrievedEmployee.getName(), "John");
    EXPECT_EQ(retrievedEmployee.getSurname(), "Doe");
}

TEST(RepairCompanyTest, RemoveEmployee) {
    RepairCompany company;
    Employee employee("John", "Doe");
    company.addEmployee(employee);
    company.removeEmployee("John", "Doe");
    EXPECT_THROW(company.getEmployee("John", "Doe"), std::runtime_error);
}

TEST(RepairCompanyTest, AddAndGetClient) {
    RepairCompany company;
    Client client("Jane", "Doe");
    ServiceRequest serviceRequest("Fix sink");
    company.addClient(client, serviceRequest);
    Client& retrievedClient = company.getClient("Jane", "Doe");
    EXPECT_EQ(retrievedClient.getName(), "Jane");
    EXPECT_EQ(retrievedClient.getSurname(), "Doe");
}

TEST(RepairCompanyTest, GetServiceRequest) {
    RepairCompany company;
    Client client("Jane", "Doe");
    ServiceRequest serviceRequest("Fix sink");
    company.addClient(client, serviceRequest);
    ServiceRequest& retrievedServiceRequest = company.getServiceRequest("Jane", "Doe");
    EXPECT_EQ(retrievedServiceRequest.getRequestDetails() , "Fix sink");
}

TEST(RepairCompanyTest, AddAndGetTechnician) {
    RepairCompany company;
    Technician technician("Jane", "Doe");
    company.addTechnician(technician);
    Technician& retrievedTechnician = company.getTechnician("Jane", "Doe");
    EXPECT_EQ(retrievedTechnician.getName(), "Jane");
    EXPECT_EQ(retrievedTechnician.getSurname(), "Doe");
}

TEST(RepairCompanyTest, AddAndGetManager) {
    RepairCompany company;
    Manager manager("Alice", "Smith");
    company.addManager(manager);
    Manager& retrievedManager = company.getManager("Alice", "Smith");
    EXPECT_EQ(retrievedManager.getName(), "Alice");
    EXPECT_EQ(retrievedManager.getSurname(), "Smith");
}

TEST(RepairCompanyTest, AddAndGetElectrician) {
    RepairCompany company;
    Electrician electrician("Bob", "Brown");
    company.addElectrician(electrician);
    Electrician& retrievedElectrician = company.getElectrician("Bob", "Brown");
    EXPECT_EQ(retrievedElectrician.getName(), "Bob");
    EXPECT_EQ(retrievedElectrician.getSurname(), "Brown");
}

TEST(RepairCompanyTest, AddAndGetPlumber) {
    RepairCompany company;
    Plumber plumber("Charlie", "Davis");
    company.addPlumber(plumber);
    Plumber& retrievedPlumber = company.getPlumber("Charlie", "Davis");
    EXPECT_EQ(retrievedPlumber.getName(), "Charlie");
    EXPECT_EQ(retrievedPlumber.getSurname(), "Davis");
}

TEST(RepairCompanyTest, AddAndGetCarpenter) {
    RepairCompany company;
    Carpenter carpenter("David", "Evans");
    company.addCarpenter(carpenter);
    Carpenter& retrievedCarpenter = company.getCarpenter("David", "Evans");
    EXPECT_EQ(retrievedCarpenter.getName(), "David");
    EXPECT_EQ(retrievedCarpenter.getSurname(), "Evans");
}

TEST(RepairCompanyTest, AddAndGetProjectManager) {
    RepairCompany company;
    ProjectManager projectManager("Eve", "Foster");
    company.addProjectManager(projectManager);
    ProjectManager& retrievedProjectManager = company.getProjectManager("Eve", "Foster");
    EXPECT_EQ(retrievedProjectManager.getName(), "Eve");
    EXPECT_EQ(retrievedProjectManager.getSurname(), "Foster");
}

TEST(RepairCompanyTest, AddAndGetFinanceManager) {
    RepairCompany company;
    FinanceManager financeManager("Frank", "Green");
    company.addFinanceManager(financeManager);
    FinanceManager& retrievedFinanceManager = company.getFinanceManager("Frank", "Green");
    EXPECT_EQ(retrievedFinanceManager.getName(), "Frank");
    EXPECT_EQ(retrievedFinanceManager.getSurname(), "Green");
}

TEST(RepairCompanyTest, AddAndGetReceptionist) {
    RepairCompany company;
    Receptionist receptionist("Grace", "Harris");
    company.addReceptionist(receptionist);
    Receptionist& retrievedReceptionist = company.getReceptionist("Grace", "Harris");
    EXPECT_EQ(retrievedReceptionist.getName(), "Grace");
    EXPECT_EQ(retrievedReceptionist.getSurname(), "Harris");
}

TEST(RepairCompanyTest, AddAndGetSupervisor) {
    RepairCompany company;
    Supervisor supervisor("Hank", "Ivy");
    company.addSupervisor(supervisor);
    Supervisor& retrievedSupervisor = company.getSupervisor("Hank", "Ivy");
    EXPECT_EQ(retrievedSupervisor.getName(), "Hank");
    EXPECT_EQ(retrievedSupervisor.getSurname(), "Ivy");
}

TEST(RepairCompanyTest, AddAndGetWarehouseManager) {
    RepairCompany company;
    WarehouseManager warehouseManager("Ivy", "Jones");
    company.addWarehouseManager(warehouseManager);
    WarehouseManager& retrievedWarehouseManager = company.getWarehouseManager("Ivy", "Jones");
    EXPECT_EQ(retrievedWarehouseManager.getName(), "Ivy");
    EXPECT_EQ(retrievedWarehouseManager.getSurname(), "Jones");
}

TEST(RepairCompanyTest, RemoveTechnician) {
    RepairCompany company;
    Technician technician("Jane", "Doe");
    company.addTechnician(technician);
    company.removeTechnician("Jane", "Doe");
    EXPECT_THROW(company.getTechnician("Jane", "Doe"), std::runtime_error);
}

TEST(RepairCompanyTest, RemoveManager) {
    RepairCompany company;
    Manager manager("Alice", "Smith");
    company.addManager(manager);
    company.removeManager("Alice", "Smith");
    EXPECT_THROW(company.getManager("Alice", "Smith"), std::runtime_error);
}

TEST(RepairCompanyTest, RemoveElectrician) {
    RepairCompany company;
    Electrician electrician("Bob", "Brown");
    company.addElectrician(electrician);
    company.removeElectrician("Bob", "Brown");
    EXPECT_THROW(company.getElectrician("Bob", "Brown"), std::runtime_error);
}

TEST(RepairCompanyTest, RemovePlumber) {
    RepairCompany company;
    Plumber plumber("Charlie", "Davis");
    company.addPlumber(plumber);
    company.removePlumber("Charlie", "Davis");
    EXPECT_THROW(company.getPlumber("Charlie", "Davis"), std::runtime_error);
}

TEST(RepairCompanyTest, RemoveCarpenter) {
    RepairCompany company;
    Carpenter carpenter("David", "Evans");
    company.addCarpenter(carpenter);
    company.removeCarpenter("David", "Evans");
    EXPECT_THROW(company.getCarpenter("David", "Evans"), std::runtime_error);
}

TEST(RepairCompanyTest, RemoveProjectManager) {
    RepairCompany company;
    ProjectManager projectManager("Eve", "Foster");
    company.addProjectManager(projectManager);
    company.removeProjectManager("Eve", "Foster");
    EXPECT_THROW(company.getProjectManager("Eve", "Foster"), std::runtime_error);
}

TEST(RepairCompanyTest, RemoveFinanceManager) {
    RepairCompany company;
    FinanceManager financeManager("Frank", "Green");
    company.addFinanceManager(financeManager);
    company.removeFinanceManager("Frank", "Green");
    EXPECT_THROW(company.getFinanceManager("Frank", "Green"), std::runtime_error);
}

TEST(RepairCompanyTest, RemoveReceptionist) {
    RepairCompany company;
    Receptionist receptionist("Grace", "Harris");
    company.addReceptionist(receptionist);
    company.removeReceptionist("Grace", "Harris");
    EXPECT_THROW(company.getReceptionist("Grace", "Harris"), std::runtime_error);
}

TEST(RepairCompanyTest, RemoveSupervisor) {
    RepairCompany company;
    Supervisor supervisor("Hank", "Ivy");
    company.addSupervisor(supervisor);
    company.removeSupervisor("Hank", "Ivy");
    EXPECT_THROW(company.getSupervisor("Hank", "Ivy"), std::runtime_error);
}

TEST(RepairCompanyTest, RemoveWarehouseManager) {
    RepairCompany company;
    WarehouseManager warehouseManager("Ivy", "Jones");
    company.addWarehouseManager(warehouseManager);
    company.removeWarehouseManager("Ivy", "Jones");
    EXPECT_THROW(company.getWarehouseManager("Ivy", "Jones"), std::runtime_error);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}