//
// Created by froonn on 12/11/24.
//

#ifndef PPOIS_LW2_SEM3_EMPLOYEE_H
#define PPOIS_LW2_SEM3_EMPLOYEE_H

#include <string>

class Employee {
public:
    Employee();
    Employee(const std::string& name, const std::string& surname, const std::string& position = "Unknown", int salary = 0);
    Employee(const Employee& employee);
    virtual ~Employee();
    Employee& operator=(const Employee& employee);

    void setName(const std::string& name);
    void setSurname(const std::string& surname);
    void setPosition(const std::string& position);
    void setSalary(int salary);

    [[nodiscard]] std::string getName() const;
    [[nodiscard]] std::string getSurname() const;
    [[nodiscard]] std::string getPosition() const;
    [[nodiscard]] int getSalary() const;

private:
    std::string name_;
    std::string surname_;
    std::string position_;
    int salary_;
};

#endif //PPOIS_LW2_SEM3_EMPLOYEE_H
