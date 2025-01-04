#include "user.h"
#include <iostream>
#include <string>
using namespace std;

User :: User(string Imie, string Nazwisko, string Login, string Haslo):
imie(Imie), nazwisko(Nazwisko), login(Login), haslo(Haslo){}

void User::pokazHistorie() const {

}
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

bool User::sprawdzDane(string wpisanyLogin, string wpisaneHaslo) const {
    if(wpisanyLogin == login && wpisaneHaslo == haslo) {
        return true;
    }
    else {
        cout<<"Niepoprawne hasło i/lub login"<<endl;
        return false;
    }
}
void User::pokazDane() const {
    cout << "Imię: " << imie << endl;
    cout << "Nazwisko: " << nazwisko << endl;
    cout << "Login: " << login << endl;
}
