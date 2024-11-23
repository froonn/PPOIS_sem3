//
// Created by froonn on 18/11/24.
//

#include "project_manager.h"

ProjectManager::ProjectManager(const std::string &name, const std::string &surname, const std::string &position, int salary, int teamSize, int projectCount)
    : Manager(name, surname, position, salary, teamSize), projectCount_(projectCount) {}

ProjectManager::ProjectManager(const ProjectManager &projectManager)
    : Manager(projectManager), projectCount_(projectManager.projectCount_) {}

ProjectManager::~ProjectManager() = default;

ProjectManager & ProjectManager::operator=(const ProjectManager &projectManager) {
    if (this != &projectManager) {
        Manager::operator=(projectManager);
        projectCount_ = projectManager.projectCount_;
    }
    return *this;
}

void ProjectManager::setProjectCount(int projectCount) {
    projectCount_ = projectCount;
}

int ProjectManager::getProjectCount() const {
    return projectCount_;
}
