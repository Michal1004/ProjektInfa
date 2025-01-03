#pragma once
#include <string>
using namespace std;

class User{
private:
    string imie;
    string nazwisko;

protected:
    string haslo;
    int ilosc; //chodzi o to ile ksiazek wypozyczyl

public:
    User();
    ~User();
    
};
