#include "Employee.h"
#include <iostream>

Employee::Employee(const std::string& name, const std::string& contact, const std::string& position)
    : User(name, contact), position(position) {
}

void Employee::setCredentials(const std::string& user, const std::string& pass) {
    username = user;
    password = pass;
}

bool Employee::authenticate(const std::string& user, const std::string& pass) const {
    return (user == username && pass == password);
}

void Employee::displayRole() {
    std::cout << "Rol: Angajat - " << name << " (" << position << ")" << std::endl;
}