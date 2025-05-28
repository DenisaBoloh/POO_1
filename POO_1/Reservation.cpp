#include "Reservation.h"
#include <iostream>

Reservation::Reservation(const Table& table, const Client& client, const std::string& dateTime)
    : table(table), client(client), dateTime(dateTime) {
}

void Reservation::displayDetails() const {
    std::cout << "\nRezervare confirmata:" << std::endl;
    std::cout << "Client: " << client.getName() << std::endl;
    std::cout << "Contact: " << client.getContact() << std::endl;
    std::cout << "Masa: #" << table.getId() << " (" << table.getSeats() << " locuri)" << std::endl;
    std::cout << "Data si ora: " << dateTime << std::endl;
}

Table Reservation::getTable() const { return table; }
Client Reservation::getClient() const { return client; }
std::string Reservation::getDateTime() const { return dateTime; }