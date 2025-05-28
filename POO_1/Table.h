#ifndef TABLE_H
#define TABLE_H

#include <iostream>

class Table {
    int id;
    int seats;
    bool available;
public:
    Table(int id, int seats);
    int getId() const;
    int getSeats() const;
    bool isAvailable() const;
    void setAvailable(bool status);
    void displayInfo() const;
};

#endif // TABLE_H