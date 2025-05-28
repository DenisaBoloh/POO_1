#ifndef RESTAURANTSYSTEM_H
#define RESTAURANTSYSTEM_H

#include "Table.h"
#include "Reservation.h"
#include "Order.h"
#include <vector>
#include <map>
#include <string>
#include <algorithm>

class RestaurantSystem {
    std::vector<Table> tables;
    std::vector<Reservation> reservations;
    std::vector<Order> orders;
    std::map<std::string, double> menu;

    void initializeMenu();
    void initializeTables();
    void displayAvailableTables() const;
    void displayMenu() const;

public:
    RestaurantSystem();
    void clientMenu();
    void employeeMenu();
};

#endif // RESTAURANTSYSTEM_H