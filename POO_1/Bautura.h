#pragma once
#include "Produs.h"

class Bautura : public Produs {
private:
    bool alcoolic;
public:
    Bautura(const string& nume, double pret, bool alcoolic);
    string getDescriere() const override;
};
