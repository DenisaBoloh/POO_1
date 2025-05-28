#include "Order.h"
#include <iostream>

Order::Order(const Reservation& reservation, const std::vector<std::string>& items, double total)
    : reservation(reservation), items(items), total(total) {
}

void Order::displayDetails() const {
    std::cout << "\nComanda confirmata:" << std::endl;
    std::cout << "Client: " << reservation.getClient().getName() << std::endl;
    std::cout << "Masa: #" << reservation.getTable().getId() << std::endl;
    std::cout << "Produse comandate:" << std::endl;
    for (const auto& item : items) {
        std::cout << "- " << item << std::endl;
    }
    std::cout << "Total: " << total << " RON" << std::endl;
}

Reservation Order::getReservation() const { return reservation; }
std::vector<std::string> Order::getItems() const { return items; }
double Order::getTotal() const { return total; }