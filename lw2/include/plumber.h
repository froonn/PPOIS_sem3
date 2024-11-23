//
// Created by froonn on 12/11/24.
//

#ifndef PPOIS_LW2_SEM3_PLUMBER_H
#define PPOIS_LW2_SEM3_PLUMBER_H

#include <string>

#include "technician.h"

class Plumber : public Technician {
public:
    Plumber(const std::string& name = "Unknown", const std::string& surname = "Unknown",
            const std::string& position = "Unknown", int salary = 0,
            const std::string& specialization = "Default specialization", int experienceYears = 0);
    Plumber(const Plumber& plumber);
    ~Plumber() override;
    Plumber& operator=(const Plumber& plumber);

    void setExperienceYears(int experienceYears);
    [[nodiscard]] int getExperienceYears() const;

private:
    int experienceYears_;
};

#endif //PPOIS_LW2_SEM3_PLUMBER_H
