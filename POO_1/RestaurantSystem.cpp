#include "RestaurantSystem.h"
#include "Client.h"
#include "Employee.h"
#include <iostream>
#include <algorithm>

RestaurantSystem::RestaurantSystem() {
    initializeTables();
    initializeMenu();
}

void RestaurantSystem::initializeMenu() {
    menu = {
        {"Supa de pui", 15.50},
        {"Salata Caesar", 22.00},
        {"Friptura de vita", 45.00},
        {"Paste Carbonara", 32.50},
        {"Tiramisu", 18.00},
        {"Apa minerala", 7.00},
        {"Suc natural", 12.00}
    };
}

void RestaurantSystem::initializeTables() {
    tables = {
        Table(1, 2),
        Table(2, 4),
        Table(3, 4),
        Table(4, 6),
        Table(5, 8)
    };
}

void RestaurantSystem::displayAvailableTables() const {
    std::cout << "\nMese disponibile:" << std::endl;
    for (const auto& table : tables) {
        if (table.isAvailable()) {
            table.displayInfo();
        }
    }
}

void RestaurantSystem::displayMenu() const {
    std::cout << "\nMeniul restaurantului:" << std::endl;
    int i = 1;
    for (const auto& item : menu) {
        std::cout << i++ << ". " << item.first << " - " << item.second << " RON" << std::endl;
    }
}

void RestaurantSystem::clientMenu() {
    std::string name, phone;
    std::cout << "\nIntroduceti numele dvs: ";
    std::getline(std::cin, name);
    std::cout << "Introduceti numarul de telefon: ";
    std::getline(std::cin, phone);

    Client client(name, phone);
    client.displayRole();

    int option;
    do {
        std::cout << "\n=== MENIU CLIENT ===" << std::endl;
        std::cout << "1. Faceti o rezervare" << std::endl;
        std::cout << "2. Plasati o comanda" << std::endl;
        std::cout << "3. Afisati meniul" << std::endl;
        std::cout << "4. Iesire" << std::endl;
        std::cout << "Alegeti optiunea: ";
        std::cin >> option;
        std::cin.ignore();

        switch (option) {
        case 1: {
            displayAvailableTables();

            int tableId;
            std::cout << "Introduceti numarul mesei dorite: ";
            std::cin >> tableId;
            std::cin.ignore();

            // Find the table
            Table* selectedTable = nullptr;
            for (auto& table : tables) {
                if (table.getId() == tableId && table.isAvailable()) {
                    selectedTable = &table;
                    break;
                }
            }

            if (!selectedTable) {
                std::cout << "Masa selectata nu este disponibila!" << std::endl;
                break;
            }

            std::string dateTime;
            std::cout << "Introduceti data si ora (ex: 15/06/2024 19:00): ";
            std::getline(std::cin, dateTime);

            Reservation reservation(*selectedTable, client, dateTime);
            reservations.push_back(reservation);
            selectedTable->setAvailable(false);

            reservation.displayDetails();
            break;
        }
        case 2: {
            if (reservations.empty()) {
                std::cout << "Trebuie sa faceti mai intai o rezervare!" << std::endl;
                break;
            }

            displayMenu();
            std::vector<std::string> selectedItems;
            double total = 0.0;

            std::cout << "\nSelectati produsele (introduceti numere separate prin spatiu, 0 pentru a termina):" << std::endl;
            while (true) {
                int choice;
                std::cin >> choice;

                if (choice == 0) break;
                if (choice < 1 || choice > menu.size()) {
                    std::cout << "Optiune invalida!" << std::endl;
                    continue;
                }

                auto it = menu.begin();
                std::advance(it, choice - 1);
                selectedItems.push_back(it->first);
                total += it->second;

                std::cout << "Adaugat: " << it->first << std::endl;
            }
            std::cin.ignore();

            if (selectedItems.empty()) {
                std::cout << "Nu ati selectat niciun produs!" << std::endl;
                break;
            }

            Order order(reservations.back(), selectedItems, total);
            orders.push_back(order);
            order.displayDetails();
            break;
        }
        case 3:
            displayMenu();
            break;
        case 4:
            std::cout << "La revedere!" << std::endl;
            break;
        default:
            std::cout << "Optiune invalida!" << std::endl;
        }
    } while (option != 4);
}

void RestaurantSystem::employeeMenu() {
    std::string name, phone, position;
    std::cout << "\nIntroduceti numele angajatului: ";
    std::getline(std::cin, name);
    std::cout << "Introduceti numarul de telefon: ";
    std::getline(std::cin, phone);
    std::cout << "Introduceti functia: ";
    std::getline(std::cin, position);

    Employee employee(name, phone, position);
    employee.displayRole();

    std::string username, password;
    std::cout << "Username: ";
    std::getline(std::cin, username);
    std::cout << "Parola: ";
    std::getline(std::cin, password);

    employee.setCredentials("admin", "password123");
    if (!employee.authenticate(username, password)) {
        std::cout << "Autentificare esuata!" << std::endl;
        return;
    }

    int option;
    do {
        std::cout << "\n=== MENIU ANGAJAT ===" << std::endl;
        std::cout << "1. Vizualizare rezervari" << std::endl;
        std::cout << "2. Eliberare masa" << std::endl;
        std::cout << "3. Vizualizare comenzi" << std::endl;
        std::cout << "4. Finalizare comanda" << std::endl;
        std::cout << "5. Raport comenzi" << std::endl;
        std::cout << "6. Iesire" << std::endl;
        std::cout << "Alegeti optiunea: ";
        std::cin >> option;
        std::cin.ignore();

        switch (option) {
        case 1: {
            if (reservations.empty()) {
                std::cout << "Nu exista rezervari!" << std::endl;
                break;
            }

            std::cout << "\nRezervari active:" << std::endl;
            for (const auto& res : reservations) {
                res.displayDetails();
                std::cout << "-------------------" << std::endl;
            }
            break;
        }
        case 2: {
            if (tables.empty()) {
                std::cout << "Nu exista mese!" << std::endl;
                break;
            }

            std::cout << "\nStare curenta mese:" << std::endl;
            for (const auto& table : tables) {
                table.displayInfo();
            }

            int tableId;
            std::cout << "Introduceti numarul mesei de eliberat: ";
            std::cin >> tableId;
            std::cin.ignore();

            bool found = false;
            for (auto& table : tables) {
                if (table.getId() == tableId) {
                    table.setAvailable(true);
                    std::cout << "Masa #" << tableId << " a fost eliberata." << std::endl;
                    found = true;

                    // Remove reservations for this table
                    reservations.erase(
                        std::remove_if(reservations.begin(), reservations.end(),
                            [tableId](const Reservation& r) {
                                return r.getTable().getId() == tableId;
                            }),
                        reservations.end());
                    break;
                }
            }

            if (!found) {
                std::cout << "Masa #" << tableId << " nu a fost gasita!" << std::endl;
            }
            break;
        }
        case 3: {
            if (orders.empty()) {
                std::cout << "Nu exista comenzi!" << std::endl;
                break;
            }

            std::cout << "\nComenzi active:" << std::endl;
            for (const auto& order : orders) {
                order.displayDetails();
                std::cout << "-------------------" << std::endl;
            }
            break;
        }
        case 4: {
            if (orders.empty()) {
                std::cout << "Nu exista comenzi!" << std::endl;
                break;
            }

            std::cout << "\nSelectati comanda de finalizat (introduceti numarul mesei): ";
            int tableId;
            std::cin >> tableId;
            std::cin.ignore();

            bool found = false;
            for (auto it = orders.begin(); it != orders.end(); ) {
                if (it->getReservation().getTable().getId() == tableId) {
                    std::cout << "Comanda finalizata pentru masa #" << tableId << std::endl;
                    it = orders.erase(it);
                    found = true;
                }
                else {
                    ++it;
                }
            }

            if (!found) {
                std::cout << "Nu s-a gasit comanda pentru masa #" << tableId << std::endl;
            }
            break;
        }
        case 5: {
            if (orders.empty()) {
                std::cout << "Nu exista comenzi!" << std::endl;
                break;
            }

            double totalDay = 0.0;
            std::cout << "\nRaport comenzi:" << std::endl;
            for (const auto& order : orders) {
                order.displayDetails();
                totalDay += order.getTotal();
                std::cout << "-------------------" << std::endl;
            }
            std::cout << "TOTAL ZI: " << totalDay << " RON" << std::endl;
            break;
        }
        case 6:
            std::cout << "La revedere!" << std::endl;
            break;
        default:
            std::cout << "Optiune invalida!" << std::endl;
        }
    } while (option != 6);
}