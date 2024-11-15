//
// Created by froonn on 12/11/24.
//

#ifndef CARPENTER_H
#define CARPENTER_H

#include <string>

#include "technician.h"

class Carpenter : public Technician {
public:
    Carpenter();
    Carpenter(const std::string& name, const std::string& surname, const std::string& position, int salary, const std::string& specialization, const std::string& toolset);
    Carpenter(const Carpenter& carpenter);
    ~Carpenter();
    Carpenter& operator=(const Carpenter& carpenter);

    void setToolset(const std::string& toolset);
    [[nodiscard]] std::string getToolset() const;

private:
    std::string toolset_;
};

#endif //CARPENTER_H
