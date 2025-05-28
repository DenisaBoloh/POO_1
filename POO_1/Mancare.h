#pragma once
#include "Produs.h"

class Mancare : public Produs {
protected:
    string categorie;
public:
    Mancare(const string& nume, double pret, const string& categorie);
    string getDescriere() const override;
};