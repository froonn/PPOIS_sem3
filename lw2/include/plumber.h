//
// Created by xinardelis on 26/10/24.
//

#ifndef PPOIS_LW2_SEM3_PLUMBER_H
#define PPOIS_LW2_SEM3_PLUMBER_H

#include "technician.h"

class Plumber : public Technician {
public:
    Plumber();
    explicit Plumber(const std::string& name, const std::string& surname, const std::string& position, int salary, int experience);
    Plumber(const Plumber &plumber);
    virtual ~Plumber() override;
    Plumber& operator=(const Plumber &plumber);

    void setExperience(int experience);
    [[nodiscard]] int getExperience() const;

private:
    int experience_;
};


#endif //PPOIS_LW2_SEM3_PLUMBER_H
