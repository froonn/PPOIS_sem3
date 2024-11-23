//
// Created by froonn on 12/11/24.
//

#ifndef CARPENTER_H
#define CARPENTER_H

#include <string>

#include "technician.h"

class Carpenter : public Technician {
public:
    Carpenter(const std::string& name = "Unknown", const std::string& surname = "Unknown",
              const std::string& position = "Unknown", int salary = 0,
              const std::string& specialization = "Default specialization", const std::string& toolset = "Default toolset");
    Carpenter(const Carpenter& carpenter);
    ~Carpenter() override;
    Carpenter& operator=(const Carpenter& carpenter);

    void setToolset(const std::string& toolset);
    [[nodiscard]] std::string getToolset() const;

private:
    std::string toolset_;
};

#endif //CARPENTER_H
