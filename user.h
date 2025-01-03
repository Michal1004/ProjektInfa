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
    void setHaslo();
    void setLogin();
    void setNazwisko();
    void setImie();
    void pokazHistorie() const;
    void wypozyczKsiazki()const;
};
