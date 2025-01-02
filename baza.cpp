#include "baza.h"
#include <iostream>
#include <ctime>
using namespace std;

void dodajKsiazke(const string& tytul, const string& autor) {
    ksiazka.push_back(Book(tytul, autor));
    cout << "Dodano książkę: " << tytul << " przez autora: " << autor << "\n";
}

void wyswietlKsiazki() const {
    cout << "Dostępne książki w bibliotece:\n";
    for (const auto& ksiazka : ksiazki) {
        ksiazka.display();
    }
}

