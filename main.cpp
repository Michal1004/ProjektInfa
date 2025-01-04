#include <iostream>
#include "baza.h"
using namespace std;

int main()
{
    Biblioteka biblioteka;

    char akcja;
    string login, haslo, imie, nazwisko;

    cout << "Witaj w Bibliotece!" << endl;


    do {
        cout << "Masz konto? Zaloguj sie po kliknięciu Z" << endl;
        cout << "Nie masz konta? Zarejestruj sie po kliknięciu R" << endl;
        cin >> akcja;
        if (akcja == 'Z' || akcja == 'z') {
            cout << "Login: ";
            cin >> login;
            cout << "Hasło: ";
            cin >> haslo;
            cout << "Zalogowano pomyślnie!" << endl;
            break;
        }
        else if (akcja == 'R' || akcja == 'r') {
            cout << "Imię: ";
            cin >> imie;
            cout << "Nazwisko: ";
            cin >> nazwisko;
            cout << "Nazwa użytkownika/login: ";
            cin >> login;
            cout << "Podaj hasło do konta: ";
            cin >> haslo;
            cout << "Konto zostało utworzone!" << endl;
            break;
        }
        else {
            cout << "Nieprawidłowe żądanie, wprowadź jeszcze raz.\n";
        }
    } while (true);
    biblioteka.wyswietlKsiazki();
    return 0;
}
