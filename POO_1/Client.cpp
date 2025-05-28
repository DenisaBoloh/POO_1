#include "Client.h"

Client::Client(const std::string& name, const std::string& contact)
    : User(name, contact) {
}

void Client::displayRole() {
    std::cout << "Rol: Client - " << name << " (" << contact << ")" << std::endl;
}