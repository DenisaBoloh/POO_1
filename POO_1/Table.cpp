#include "Table.h"
#include <iostream>

Table::Table(int id, int seats) : id(id), seats(seats), available(true) {}

int Table::getId() const { return id; }
int Table::getSeats() const { return seats; }
bool Table::isAvailable() const { return available; }
void Table::setAvailable(bool status) { available = status; }

void Table::displayInfo() const {
    std::cout << "Masa #" << id << " (" << seats << " locuri) - "
        << (available ? "Disponibila" : "Ocupata") << std::endl;
}