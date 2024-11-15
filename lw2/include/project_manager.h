//
// Created by froonn on 12/11/24.
//

#ifndef PPOIS_LW2_SEM3_PROJECT_MANAGER_H
#define PPOIS_LW2_SEM3_PROJECT_MANAGER_H

#include <string>

#include "manager.h"

class ProjectManager : public Manager {
public:
    ProjectManager();
    ProjectManager(const std::string& name, const std::string& surname, const std::string& position, int salary, int teamSize, int projectCount);
    ProjectManager(const ProjectManager& projectManager);
    ~ProjectManager() override;
    ProjectManager& operator=(const ProjectManager& projectManager);

    void setProjectCount(int projectCount);
    int getProjectCount() const;

private:
    int projectCount_;
};

#endif //PPOIS_LW2_SEM3_PROJECT_MANAGER_H
