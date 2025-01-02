#ifndef baza_H
#define baza_H

#include <vector>
#include <string>
#include "baza.h"
using namespace std;

class Biblioteka {
private:
    vector<ksiazka> ksiazka;

public:
    void dodajKsiazke(const string& tytul, const string& autor);
    void wyswietlKsiazki() const;

};

#endif
