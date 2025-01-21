#pragma once
#include <string>
#include <vector>
#include "bcrypt/BCrypt.hpp"
using namespace std;

class User {
private:
    string imie;
    string nazwisko;
    string haslo;
    string login;
    string rola;
    vector<string> historiaWypozyczen;

public:
    User(string Imie, string Nazwisko, string Login, string Haslo, string Rola);
    void setHaslo(string Haslo);
    void setLogin(string Login);
    void setNazwisko(string Nazwisko);
    void setImie(string Imie);
    void setRola(string Rola);

    bool sprawdzDane(string wpisanyLogin, string wpisaneHaslo) const;
    void pokazDane() const;
    void dodajDoHistorii(const string& tytul);
    void pokazHistorie() const;

    string getRola() const;

    static void wczytajUzytkownikowZPliku(vector<User>& uzytkownicy, const string& nazwaPliku);
    static void zapiszUzytkownikowDoPliku(const vector<User>& uzytkownicy, const string& nazwaPliku);
};
