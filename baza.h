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
    unordered_map<string, vector<string>> historiaWypozyczen;

public:
    Biblioteka(const string& nazwaPliku);
    Biblioteka();

    void dodajKsiazke(const Ksiazka& nowaKsiazka);
    void wyswietlKsiazki() const;
    bool wypozyczKsiazke(const string& tytul, const string& login);
    bool zwracanieKsiazki(const string& tytul, const string& login);
    void wyswietlHistorieWypozyczen(const string& login) const;

    void wczytajKsiazkiZPliku(const string& nazwaPliku);
    void zapiszKsiazkiDoPliku(const string& nazwaPliku) const;
};
