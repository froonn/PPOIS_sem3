//
// Created by froonn on 12/11/24.
//

#ifndef PPOIS_LW2_SEM3_PROJECT_MANAGER_H
#define PPOIS_LW2_SEM3_PROJECT_MANAGER_H

#include <string>

#include "manager.h"

class ProjectManager : public Manager {
public:
    ProjectManager(const std::string& name = "Unknown", const std::string& surname = "Unknown",
                   const std::string& position = "Unknown", int salary = 0, int teamSize = 0, int projectCount = 0);
    ProjectManager(const ProjectManager& projectManager);
    ~ProjectManager() override;
    ProjectManager& operator=(const ProjectManager& projectManager);

    void setProjectCount(int projectCount);
    [[nodiscard]] int getProjectCount() const;

private:
    int projectCount_;
};

#endif //PPOIS_LW2_SEM3_PROJECT_MANAGER_H
