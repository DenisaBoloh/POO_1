#include "RestaurantSystem.h"
#include <iostream>

int main() {
    RestaurantSystem system;

    int userType;
    std::cout << "Bun venit la Sistemul de Administrare a Restaurantului!" << std::endl;
    std::cout << "Selectati tipul de utilizator:" << std::endl;
    std::cout << "1. Client" << std::endl;
    std::cout << "2. Angajat" << std::endl;
    std::cout << "Alegeti optiunea: ";
    std::cin >> userType;
    std::cin.ignore();

    switch (userType) {
    case 1:
        system.clientMenu();
        break;
    case 2:
        system.employeeMenu();
        break;
    default:
        std::cout << "Optiune invalida!" << std::endl;
    }

    return 0;
}