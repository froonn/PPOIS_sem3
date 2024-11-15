//
// Created by froonn on 12/11/24.
//

#ifndef PPOIS_LW2_SEM3_WAREHOUSE_MANAGER_H
#define PPOIS_LW2_SEM3_WAREHOUSE_MANAGER_H

#include <string>

#include "manager.h"

class WarehouseManager : public Manager {
public:
    WarehouseManager();
    WarehouseManager(const std::string& name, const std::string& surname, const std::string& position, int salary, int teamSize, int warehouseSize);
    WarehouseManager(const WarehouseManager& warehouseManager);
    ~WarehouseManager() override;
    WarehouseManager& operator=(const WarehouseManager& warehouseManager);

    void setWarehouseSize(int warehouseSize);
    int getWarehouseSize() const;

private:
    int warehouseSize_;
};

#endif //PPOIS_LW2_SEM3_WAREHOUSE_MANAGER_H
