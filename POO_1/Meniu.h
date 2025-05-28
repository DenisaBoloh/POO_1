#pragma once
#include "Produs.h"
#include <vector>

class Meniu {
private:
    vector<Produs*> produse;
public:
    ~Meniu();
    void adaugaProdus(Produs* produs);
    void afiseazaMeniu() const;
    Produs* getProdus(int index) const;
    int getNumarProduse() const;
};