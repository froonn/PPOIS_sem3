//
// Created by froonn on 12/11/24.
//

#ifndef PPOIS_LW2_SEM3_CLIENT_H
#define PPOIS_LW2_SEM3_CLIENT_H

#include <string>

class Client {
public:
    Client();
    Client(const std::string& name, const std::string& contactInfo);
    Client(const Client& client);
    ~Client();
    Client& operator=(const Client& client);

    void setName(const std::string& name);
    std::string getName() const;

    void setContactInfo(const std::string& contactInfo);
    std::string getContactInfo() const;

private:
    std::string name_;
    std::string contactInfo_;
};

#endif //PPOIS_LW2_SEM3_CLIENT_H
