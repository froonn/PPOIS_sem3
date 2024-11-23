//
// Created by froonn on 12/11/24.
//

#ifndef PPOIS_LW2_SEM3_WAREHOUSE_MANAGER_H
#define PPOIS_LW2_SEM3_WAREHOUSE_MANAGER_H

#include <string>

#include "manager.h"

class WarehouseManager : public Manager {
public:
    WarehouseManager(const std::string& name = "Unknown", const std::string& surname = "Unknown",
                     const std::string& position = "Unknown", int salary = 0, int teamSize = 0, int warehouseSize = 0);
    WarehouseManager(const WarehouseManager& warehouseManager);
    ~WarehouseManager() override;
    WarehouseManager& operator=(const WarehouseManager& warehouseManager);

    void setWarehouseSize(int warehouseSize);
    [[nodiscard]] int getWarehouseSize() const;

private:
    int warehouseSize_;
};

#endif //PPOIS_LW2_SEM3_WAREHOUSE_MANAGER_H
