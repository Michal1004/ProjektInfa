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
    vector<Ksiazka> ksiazka;

public:
    Biblioteka();
    ~Biblioteka();
    
    void dodajKsiazke(const string& tytul, const string& autor);
    void wyswietlKsiazki() const;
};

