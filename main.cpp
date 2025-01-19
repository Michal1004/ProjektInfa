#include <iostream>
#include "user.h"
#include "baza.h"
#include <vector>

using namespace std;

int main() {
    vector<User> uzytkownicy;
    string nazwaPlikuUzytkownikow = "uzytkownicy.txt";

    User::wczytajUzytkownikowZPliku(uzytkownicy, nazwaPlikuUzytkownicy);

    string login, haslo, imie, nazwisko, tytul, autor;
    int zadanie;
    char akcja;

    cout << "Witaj w Bibliotece!" << endl;

    while (true) {
        cout << "Masz konto? Zaloguj się po kliknięciu Z" << endl;
        cout << "Nie masz konta? Zarejestruj się po kliknięciu R" << endl;
        cout << "Naciśnij Q, żeby zakończyć program" << endl;
        cin >> akcja;

        if (akcja == 'Q' || akcja == 'q') {
            cout << "Dziękujemy za wybranie naszej biblioteki.\nDo widzenia!" << endl;
            break;
        }

        if (akcja == 'Z' || akcja == 'z') {
            cout << "Login: ";
            cin >> login;
            cout << "Hasło: ";
            cin >> haslo;

            bool logowanie = false;
            for (const auto& uzytkownik : uzytkownicy) {
                if (uzytkownik.sprawdzDane(login, haslo)) {
                    logowanie = true;
                    cout << "Zalogowano pomyślnie!" << endl;
                   
                    if (uzytkownik.getRola() == "admin") {
                        cout << "Masz uprawnienia administratora." << endl;
                    }
                    break;
                }
            }

            if (!logowanie) {
                cout << "Niepoprawny login lub hasło." << endl;
            }
        } else if (akcja == 'R' || akcja == 'r') {
            cout << "Imię: ";
            cin >> imie;
            cout << "Nazwisko: ";
            cin >> nazwisko;
            cout << "Login: ";
            cin >> login;
            cout << "Hasło: ";
            cin >> haslo;
            cout << "Czy ma zostać adminem? (T/N): ";
            char admin;
            cin >> admin;

            string rola = (admin == 'T' || admin == 't') ? "admin" : "user";
            uzytkownicy.push_back(User(imie, nazwisko, login, haslo, rola));

            User::zapiszUzytkownikowDoPliku(uzytkownicy, nazwaPlikuUzytkownicy);
            cout << "Konto zostało utworzone!" << endl;
        } else {
            cout << "Nieprawidłowa opcja!" << endl;
        }
    }

    return 0;
}
