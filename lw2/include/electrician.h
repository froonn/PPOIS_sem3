//
// Created by froonn on 12/11/24.
//

#ifndef PPOIS_LW2_SEM3_ELECTRICIAN_H
#define PPOIS_LW2_SEM3_ELECTRICIAN_H

#include <string>

#include "technician.h"

class Electrician : public Technician {
public:
    Electrician();
    Electrician(const std::string& name, const std::string& surname, const std::string& position, int salary, const std::string& specialization, int certificationLevel);
    Electrician(const Electrician& electrician);
    ~Electrician() override;
    Electrician& operator=(const Electrician& electrician);

    void setCertificationLevel(int certificationLevel);
    int getCertificationLevel() const;

private:
    int certificationLevel_;
};

#endif //PPOIS_LW2_SEM3_ELECTRICIAN_H
