//
// Created by froonn on 18/11/24.
//

#include "warehouse_manager.h"

WarehouseManager::WarehouseManager(const std::string &name, const std::string &surname, const std::string &position, int salary, int teamSize, int warehouseSize)
    : Manager(name, surname, position, salary, teamSize), warehouseSize_(warehouseSize) {}

WarehouseManager::WarehouseManager(const WarehouseManager &warehouseManager)
    : Manager(warehouseManager), warehouseSize_(warehouseManager.warehouseSize_) {}

WarehouseManager::~WarehouseManager() = default;

WarehouseManager & WarehouseManager::operator=(const WarehouseManager &warehouseManager) {
    if (this != &warehouseManager) {
        Manager::operator=(warehouseManager);
        warehouseSize_ = warehouseManager.warehouseSize_;
    }
    return *this;
}

void WarehouseManager::setWarehouseSize(int warehouseSize) {
    warehouseSize_ = warehouseSize;
}

int WarehouseManager::getWarehouseSize() const {
    return warehouseSize_;
}
