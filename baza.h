#pragma once
#include <vector>
#include <string>
#include <unordered_map>
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
     unordered_map<string, pair<string, int>> ksiazki;

public:
    Biblioteka(const string& ksiazki.txt);

    void dodajKsiazke(const Ksiazka& nowaKsiazka);
    void wyswietlKsiazki() const;
    bool wypozyczKsiazke(const string& tytul, const string& login);
    bool zwracanieKsiazki(const string& tytul, const string& login);

    void wczytajKsiazkiZPliku(const string& ksiazki.txt);
    void zapiszKsiazkiDoPliku(const string& ksiazki.txt) const;
};

