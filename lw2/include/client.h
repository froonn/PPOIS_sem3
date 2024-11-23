//
// Created by froonn on 12/11/24.
//

#ifndef PPOIS_LW2_SEM3_CLIENT_H
#define PPOIS_LW2_SEM3_CLIENT_H

#include <string>

class Client {
public:

    Client(const std::string& name = "Unknown", const std::string& surname = "Unknown",  const std::string& contactInfo = "Unknown");
    Client(const Client& client);
    ~Client();
    Client& operator=(const Client& client);

    void setName(const std::string& name);
    [[nodiscard]] std::string getName() const;

    void setSurname(const std::string& surname);
    [[nodiscard]] std::string getSurname() const;

    void setContactInfo(const std::string& contactInfo);
    [[nodiscard]] std::string getContactInfo() const;

private:
    std::string name_;
    std::string surname_;
    std::string contactInfo_;
};

#endif //PPOIS_LW2_SEM3_CLIENT_H
