#include <iostream>
#include "user.h"
#include "baza.h"
#include <vector>

using namespace std;


int main() {
    Biblioteka biblioteka;
    vector<User> uzytkownicy;
    string nazwaPlikuUzytkownikow = "uzytkownicy.txt";

    User::wczytajUzytkownikowZPliku(uzytkownicy, nazwaPlikuUzytkownikow);

    string login, haslo, imie, nazwisko, rola;
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
                        int zadanie;
                       string autor, tytul;
                      do {
                        cout << "\n1. Wyświetl dostępne książki" << endl;
                        cout << "2. Dodaj książkę" << endl;
                        cout << "3. Historia wypożyczeń użytkowników" << endl;
                        cout << "4. Wyloguj" << endl;
                        cout << "Wybierz czynności: ";
                        cin >> zadanie;
                        cin.ignore();

                        if (zadanie == 1) {
                            biblioteka.wyswietlKsiazki();
                        } else if (zadanie == 2) {
                            Ksiazka nowaKsiazka;
                            cout << "Podaj autora: ";
                            getline(cin, autor);
                            cout << "Podaj tytuł: ";
                            getline(cin, tytul);
                            nowaKsiazka.autor = autor;
                            nowaKsiazka.tytul = tytul;
                            biblioteka.dodajKsiazke(nowaKsiazka);
                        } else if (zadanie == 3) {

                        } else if (zadanie == 4) {
                            cout << "Wylogowano pomyślnie" << endl;
                            break;
                        } else {
                            cout << "Nieobsługiwane żądanie. Spróbuj ponownie" << endl;
                        }
                    } while (true);
                    } else {
                        int zadanie;
                        do {
                        cout << "\n1. Wyświetl dostępne książki" << endl;
                        cout << "2. Wypożycz książkę" << endl;
                        cout << "3. Zwróć książkę" << endl;
                        cout << "4. Historia wypożyczeń" << endl;
                        cout << "5. Wyloguj" << endl;
                        cout << "Wybierz czynności: ";
                        cin >> zadanie;

                        if (zadanie == 1) {
                            biblioteka.wyswietlKsiazki();
                        } else if (zadanie == 2) {
                            biblioteka.wyswietlKsiazki();
                            cout << "Którą książkę chcesz wypożyczyć?" << endl;

                        } else if (zadanie == 3) {

                        } else if (zadanie == 4) {

                        } else if (zadanie == 5) {
                            cout << "Wylogowano pomyślnie" << endl;
                            break;
                        } else {
                            cout << "Nieobsługiwane żądanie. Spróbuj ponownie" << endl;
                        }
                    } while (true);
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

            User::zapiszUzytkownikowDoPliku(uzytkownicy, nazwaPlikuUzytkownikow);
            cout << "Konto zostało utworzone!" << endl;
        } else {
            cout << "Nieprawidłowa opcja!" << endl;
        }
    }

    return 0;
}
