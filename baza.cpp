#include "baza.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

Biblioteka::Biblioteka(const string& nazwaPliku) {
    wczytajKsiazkiZPliku(nazwaPliku);
}

void Biblioteka::dodajKsiazke(const Ksiazka& nowaKsiazka) {
    string tytul = nowaKsiazka.tytul;
    string autor = nowaKsiazka.autor;

    if (ksiazki.find(tytul) != ksiazki.end()) {
        ksiazki[tytul].second++;
    } else {
        ksiazki[tytul] = {autor, 1};
    }

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
        ksiazki[tytul].second--;
        return true;
    } else {
        cout << "Książka \"" << tytul << "\" jest niedostępna.\n";
        return false;
    }
}

bool Biblioteka::zwracanieKsiazki(const string& tytul, const string& login) {
    if (ksiazki.find(tytul) != ksiazki.end()) {
        ksiazki[tytul].second++;
        return true;
    } else {
        cout << "Nie znaleziono książki o tytule: " << tytul << endl;
        return false;
    }
}

void Biblioteka::wczytajKsiazkiZPliku(const string& ksiazki.txt) {
    ifstream plik(nazwaPliku);
    if (!plik.is_open()) {
        cout << "Nie udało się otworzyć pliku: " << nazwaPliku << endl;
        return;
    }

    string linia;
    while (getline(plik, linia)) {
        stringstream ss(linia);
        string tytul, autor;

        getline(ss, tytul, ',');
        getline(ss, autor);

        Ksiazka ksiazka;
        ksiazka.tytul = tytul;
        ksiazka.autor = autor;

        dodajKsiazke(ksiazka);
    }

    plik.close();
}

void Biblioteka::zapiszKsiazkiDoPliku(const string& ksiazki.txt) const {
    ofstream plik(ksiazki.txt);
    if (!plik.is_open()) {
        cout << "Nie udało się otworzyć pliku do zapisu: " << ksiazki.txt << endl;
        return;
    }

    for (const auto& par : ksiazki) {
        const string& tytul = par.first;
        const string& autor = par.second.first;
        int liczbaEgzemplarzy = par.second.second;

        for (int i = 0; i < liczbaEgzemplarzy; i++) {
            plik << tytul << "," << autor << "\n";
        }
    }

    plik.close();
}


