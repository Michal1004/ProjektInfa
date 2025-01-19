#include "user.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

User::User(string Imie, string Nazwisko, string Login, string Haslo, string Rola)
    : imie(Imie), nazwisko(Nazwisko), login(Login), haslo(Haslo), rola(Rola) {}

void User::setLogin(string Login) {
    login = Login;
}

void User::setHaslo(string Haslo) {
    haslo = Haslo;
}

void User::setNazwisko(string Nazwisko) {
    nazwisko = Nazwisko;
}

void User::setImie(string Imie) {
    imie = Imie;
}

void User::setRola(string Rola) {
    rola = Rola;
}

bool User::sprawdzDane(string wpisanyLogin, string wpisaneHaslo) const {
    return wpisanyLogin == login && wpisaneHaslo == haslo;
}

void User::pokazDane() const {
    cout << "Imię: " << imie << endl;
    cout << "Nazwisko: " << nazwisko << endl;
    cout << "Login: " << login << endl;
    cout << "Rola: " << rola << endl;  // Pokazujemy rolę użytkownika
}

void User::dodajDoHistorii(const string& tytul) {
    historiaWypozyczen.push_back(tytul);
}

void User::pokazHistorie() const {
    if (historiaWypozyczen.empty()) {
        cout << "Brak wypożyczonych książek w historii." << endl;
        return;
    }
    cout << "Historia wypożyczeń:" << endl;
    for (const auto& tytul : historiaWypozyczen) {
        cout << "- " << tytul << endl;
    }
}

string User::getRola() const {
    return rola;
}

// Metoda wczytująca użytkowników z pliku
void User::wczytajUzytkownikowZPliku(vector<User>& uzytkownicy, const string& nazwaPliku) {
    ifstream plik(nazwaPliku);
    if (!plik.is_open()) {
        cout << "Nie udało się otworzyć pliku z użytkownikami." << endl;
        return;
    }

    string linia;
    while (getline(plik, linia)) {
        stringstream ss(linia);
        string imie, nazwisko, login, haslo, rola;

        getline(ss, imie, ',');
        getline(ss, nazwisko, ',');
        getline(ss, login, ',');
        getline(ss, haslo, ',');
        getline(ss, rola);  // Odczytujemy rolę z pliku

        uzytkownicy.push_back(User(imie, nazwisko, login, haslo, rola));
    }

    plik.close();
}

// Metoda zapisująca użytkowników do pliku
void User::zapiszUzytkownikowDoPliku(const vector<User>& uzytkownicy, const string& nazwaPliku) {
    ofstream plik(nazwaPliku, ios::app); // Otwieramy plik w trybie dopisywania
    if (!plik.is_open()) {
        cout << "Nie udało się otworzyć pliku do zapisu." << endl;
        return;
    }

    for (const auto& uzytkownik : uzytkownicy) {
        plik << uzytkownik.imie << "," << uzytkownik.nazwisko << ","
             << uzytkownik.login << "," << uzytkownik.haslo << ","
             << uzytkownik.rola << "\n";  // Zapisujemy rolę do pliku
    }

    plik.close();
}
