#ifndef RESERVATION_H
#define RESERVATION_H

#include "Table.h"
#include "Client.h"
#include <string>

class Reservation {
    Table table;
    Client client;
    std::string dateTime;
public:
    Reservation(const Table& table, const Client& client, const std::string& dateTime);
    void displayDetails() const;
    Table getTable() const;
    Client getClient() const;
    std::string getDateTime() const;
};

#endif // RESERVATION_H