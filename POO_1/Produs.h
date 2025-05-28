#pragma once
#include <string>
using namespace std;

class Produs {
protected:
    string nume;
    double pret;
public:
    Produs(const string& nume, double pret);
    virtual string getDescriere() const = 0;
    virtual ~Produs() {}
    double getPret() const { return pret; }
};