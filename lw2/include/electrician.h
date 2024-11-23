//
// Created by froonn on 12/11/24.
//

#ifndef PPOIS_LW2_SEM3_ELECTRICIAN_H
#define PPOIS_LW2_SEM3_ELECTRICIAN_H

#include <string>

#include "technician.h"

class Electrician : public Technician {
public:
    Electrician(const std::string& name = "Unknown", const std::string& surname = "Unknown",
                const std::string& position = "Unknown", int salary = 0,
                const std::string& specialization = "Default specialization", int certificationLevel = 0);
    Electrician(const Electrician& electrician);
    ~Electrician() override;
    Electrician& operator=(const Electrician& electrician);

    void setCertificationLevel(int certificationLevel);
    [[nodiscard]] int getCertificationLevel() const;

private:
    int certificationLevel_;
};

#endif //PPOIS_LW2_SEM3_ELECTRICIAN_H
