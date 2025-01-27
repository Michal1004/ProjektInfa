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
        historiaWypozyczen[login].push_back(tytul);
        zapiszKsiazkiDoPliku("ksiazki.txt");
        return true;
    } else {
        cout << "Książka \"" << tytul << "\" jest niedostępna.\n";
        return false;
    }
}

bool Biblioteka::zwracanieKsiazki(const string& tytul, const string& login) {
    if (ksiazki.find(tytul) != ksiazki.end()) {
        ksiazki[tytul].second++;
        zapiszKsiazkiDoPliku("ksiazki.txt");
        return true;
    } 
    else {
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
        int ilosc;
        stringstream ss(linia);
        string tytul, autor;

        getline(ss, tytul, ',');
        getline(ss, autor);


        if (ksiazki.find(tytul) != ksiazki.end()) {
            ksiazki[tytul].second++;
        } else {
            ksiazki[tytul] = {autor, 1};
        }
    }

    plik.close();
}

void Biblioteka::zapiszKsiazkiDoPliku(const string& nazwaPliku) const {
    ofstream plik(nazwaPliku);
    if (!plik.is_open()) {
        cout << "Nie udało się otworzyć pliku: " << nazwaPliku << endl;
        return;
    }

    for (const auto& par : ksiazki) {
        plik << par.first << "," << par.second.first << "," << par.second.second << "\n";
    }

    plik.close();
}



void Biblioteka::wyswietlHistorieWypozyczen(const string& login) const {
    auto it = historiaWypozyczen.find(login);
    if (it != historiaWypozyczen.end()) {
        cout << "Historia wypożyczeń dla " << login << ":\n";
        for (const auto& tytul : it->second) {
            cout << "- " << tytul << "\n";
        }
    } else {
        cout << "Brak historii wypożyczeń dla " << login << ".\n";
    }
}
