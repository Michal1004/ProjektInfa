#pragma once
#include <vector>
#include <string>
using namespace std;

class Biblioteka {
private:
    vector<ksiazka> ksiazka;

public:
    Biblioteka();
    ~Biblioteka();
    
    void dodajKsiazke(const string& tytul, const string& autor);
    void wyswietlKsiazki() const;
};

