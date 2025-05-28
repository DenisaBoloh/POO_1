#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "User.h"
#include <string>

class Employee : public User {
    std::string position;
    std::string username;
    std::string password;
public:
    Employee(const std::string& name, const std::string& contact, const std::string& position);
    void setCredentials(const std::string& user, const std::string& pass);
    bool authenticate(const std::string& user, const std::string& pass) const;
    void displayRole() override;
};

#endif // EMPLOYEE_H