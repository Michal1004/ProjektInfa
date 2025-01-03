#include "baza.h"
#include <iostream>
#include <ctime>
using namespace std;

 void dodajKsiazke(const Ksiazka& nowaKsiazka) {
    ksiazka.push_back(nowaKsiazka);
    cout << "Dodano książkę: " << tytul << " autora: " << autor << "\n";
}

void wyswietlKsiazki() const {
    cout << "Dostępne książki w bibliotece:\n";
    for (const auto& ksiazka : ksiazki) {
        ksiazka.display();
    }
}

