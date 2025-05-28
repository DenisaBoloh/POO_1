#include "Produs.h"
#include <iostream>

Produs::Produs(const string& nume, double pret) : nume(nume), pret(pret) {}

ostream& operator<<(ostream& os, const Produs& produs) {
    os << produs.getDescriere() << " - " << produs.getPret() << " lei";
    return os;
}