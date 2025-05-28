#ifndef CLIENT_H
#define CLIENT_H

#include "User.h"
#include <iostream>

class Client : public User {
public:
    Client(const std::string& name, const std::string& contact);
    void displayRole() override;
};

#endif // CLIENT_H