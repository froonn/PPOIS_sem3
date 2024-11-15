//
// Created by froonn on 12/11/24.
//

#ifndef PPOIS_LW2_SEM3_PLUMBER_H
#define PPOIS_LW2_SEM3_PLUMBER_H

#include <string>

#include "technician.h"

class Plumber : public Technician {
public:
    Plumber();
    Plumber(const std::string& name, const std::string& surname, const std::string& position, int salary, const std::string& specialization, int experienceYears);
    Plumber(const Plumber& plumber);
    ~Plumber() override;
    Plumber& operator=(const Plumber& plumber);

    void setExperienceYears(int experienceYears);
    int getExperienceYears() const;

private:
    int experienceYears_;
};

#endif //PPOIS_LW2_SEM3_PLUMBER_H
