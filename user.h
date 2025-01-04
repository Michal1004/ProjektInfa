#pragma once
#include <string>
using namespace std;

class User{
private:
    string imie;
    string nazwisko;
    string haslo;
    string login;

protected:
    int ilosc; //chodzi o to ile ksiazek wypozyczyl

public:
    User(string Imie, string Nazwisko, string Login, string Haslo);
    void setHaslo(string Haslo);
    void setLogin(string Login);
    void setNazwisko(string Nazwisko);
    void setImie(string Imie);
    void pokazHistorie() const;
    void wypozyczKsiazki()const;
    bool sprawdzDane(string wpisanyLogin, string wpisaneHaslo) const;
    void pokazDane() const;
};
