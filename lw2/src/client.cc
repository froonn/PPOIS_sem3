//
// Created by froonn on 18/11/24.
//

#include "client.h"

Client::Client(const std::string &name, const std::string &surname, const std::string &contactInfo)
    : name_(name), surname_(surname), contactInfo_(contactInfo) {}

Client::Client(const Client &client)
    : name_(client.name_), surname_(client.surname_),  contactInfo_(client.contactInfo_) {}

Client::~Client() = default;

Client & Client::operator=(const Client &client) {
    if (this != &client) {
        name_ = client.name_;
        surname_ = client.surname_;
        contactInfo_ = client.contactInfo_;
    }
    return *this;
}

void Client::setName(const std::string &name) {
    name_ = name;
}

std::string Client::getName() const {
    return name_;
}

void Client::setSurname(const std::string &surname) {
    surname_ = surname;
}

std::string Client::getSurname() const {
    return surname_;
}

void Client::setContactInfo(const std::string &contactInfo) {
    contactInfo_ = contactInfo;
}

std::string Client::getContactInfo() const {
    return contactInfo_;
}
