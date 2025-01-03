#include "baza.h"
#include <iostream>
#include<string>
#include <vector>
using namespace std;

void Biblioteka::dodajKsiazke(const Ksiazka& nowaKsiazka) {
    ksiazka.push_back(nowaKsiazka);
    cout << "Dodano ksiazke: " << nowaKsiazka.tytul << " autora: " << nowaKsiazka.autor << "\n";
}
void Biblioteka::wyswietlKsiazki() const {
    for (const auto& k : ksiazka) {
        cout << "Tytul: " << k.tytul << ", Autor: " << k.autor << endl;
    }
}
