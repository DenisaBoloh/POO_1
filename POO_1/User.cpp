#include "User.h"

User::User(const std::string& name, const std::string& contact)
    : name(name), contact(contact) {
}

std::string User::getName() const { return name; }
std::string User::getContact() const { return contact; }