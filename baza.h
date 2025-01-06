#pragma once
#include <vector>
#include <string>
using namespace std;

class Ksiazka {
public:
    string tytul;
    string autor;
    bool wypozyczona = false;
    string wypozyczajacy = "";
};

class Biblioteka {
private:
    vector<Ksiazka> ksiazki;

public:
    Biblioteka();

    void dodajKsiazke(const Ksiazka& nowaKsiazka);
    void wyswietlKsiazki() const;
    bool wypozyczKsiazke(const string& tytul, const string& login);
    bool zwracanieKsiazki(const string& tytul, const string& login);

};

