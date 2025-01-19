#include "baza.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

Biblioteka::Biblioteka(const string& nazwaPliku) {
    wczytajKsiazkiZPliku(nazwaPliku);  // Wczytanie książek z pliku przy tworzeniu obiektu
}

void Biblioteka::dodajKsiazke(const Ksiazka& nowaKsiazka) {
    string tytul = nowaKsiazka.tytul;
    string autor = nowaKsiazka.autor;

    // Jeśli książka o danym tytule już istnieje, zwiększamy liczbę egzemplarzy
    if (ksiazki.find(tytul) != ksiazki.end()) {
        ksiazki[tytul].second++;  // Zwiększamy liczbę egzemplarzy
    } else {
        ksiazki[tytul] = {autor, 1};  // Dodajemy nową książkę do mapy
    }

    // Zapisz książki do pliku po każdej dodanej książce
    zapiszKsiazkiDoPliku("ksiazki.txt");
}

void Biblioteka::wyswietlKsiazki() const {
    if (ksiazki.empty()) {
        cout << "Brak dostępnych książek.\n";
        return;
    }

    cout << "Dostępne książki:\n";
    for (const auto& par : ksiazki) {
        const string& tytul = par.first;
        const string& autor = par.second.first;
        int liczbaEgzemplarzy = par.second.second;

        cout << liczbaEgzemplarzy << "x \"" << tytul << "\", " << autor << endl;
    }
}

bool Biblioteka::wypozyczKsiazke(const string& tytul, const string& login) {
    if (ksiazki.find(tytul) != ksiazki.end() && ksiazki.at(tytul).second > 0) {
        // Zmniejszamy liczbę egzemplarzy książki
        ksiazki[tytul].second--;
        return true;
    } else {
        cout << "Książka \"" << tytul << "\" jest niedostępna.\n";
        return false;
    }
}

bool Biblioteka::zwracanieKsiazki(const string& tytul, const string& login) {
    if (ksiazki.find(tytul) != ksiazki.end()) {
        // Zwiększamy liczbę egzemplarzy książki
        ksiazki[tytul].second++;
        return true;
    } else {
        cout << "Nie znaleziono książki o tytule: " << tytul << endl;
        return false;
    }
}

void Biblioteka::wczytajKsiazkiZPliku(const string& nazwaPliku) {
    ifstream plik(nazwaPliku);
    if (!plik.is_open()) {
        cout << "Nie udało się otworzyć pliku: " << nazwaPliku << endl;
        return;
    }

    string linia;
    while (getline(plik, linia)) {
        stringstream ss(linia);
        string tytul, autor;

        // Zakładamy, że tytuł i autor są rozdzieleni przecinkiem
        getline(ss, tytul, ',');
        getline(ss, autor);

        Ksiazka ksiazka;
        ksiazka.tytul = tytul;
        ksiazka.autor = autor;

        dodajKsiazke(ksiazka);  // Dodajemy książkę do biblioteki
    }

    plik.close();
}

void Biblioteka::zapiszKsiazkiDoPliku(const string& nazwaPliku) const {
    ofstream plik(nazwaPliku);
    if (!plik.is_open()) {
        cout << "Nie udało się otworzyć pliku do zapisu: " << nazwaPliku << endl;
        return;
    }

    // Zapisujemy książki do pliku w formacie: "tytuł,autor"
    for (const auto& par : ksiazki) {
        const string& tytul = par.first;
        const string& autor = par.second.first;
        int liczbaEgzemplarzy = par.second.second;

        // Zapisujemy każdą książkę tyle razy, ile jej egzemplarzy
        for (int i = 0; i < liczbaEgzemplarzy; i++) {
            plik << tytul << "," << autor << "\n";
        }
    }

    plik.close();
}


