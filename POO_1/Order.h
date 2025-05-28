#ifndef ORDER_H
#define ORDER_H

#include "Reservation.h"
#include <vector>
#include <string>

class Order {
    Reservation reservation;
    std::vector<std::string> items;
    double total;
public:
    Order(const Reservation& reservation, const std::vector<std::string>& items, double total);
    void displayDetails() const;
    Reservation getReservation() const;
    std::vector<std::string> getItems() const;
    double getTotal() const;
};

#endif // ORDER_H