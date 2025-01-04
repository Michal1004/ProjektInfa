#include "user.h"
#include <iostream>
#include <string>
using namespace std;

User :: User(string Imie, string Nazwisko, string Login, string Haslo):
imie(Imie), nazwisko(Nazwisko), login(Login), haslo(Haslo){}

void User::pokazHistorie() const {

}
void User::setHaslo() {

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
