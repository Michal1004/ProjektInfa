#pragma once
#include <vector>
#include <string>
using namespace std;

class Ksiazka {
public:
    string tytul;
    string autor;
};

class Biblioteka {
private:
    vector<Ksiazka> ksiazki;

public:
    Biblioteka();

    void dodajKsiazke(const Ksiazka& nowaKsiazka);
    void wyswietlKsiazki() const;

};
