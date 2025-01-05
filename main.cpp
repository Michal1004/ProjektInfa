#include <iostream>
#include "baza.h"
#include "user.h"
using namespace std;

int main()
{
    Biblioteka biblioteka;
    User admin("Michał", "Bibliotekarz", "admin", "admin123");
    User Michal("Michał", "Bagiński", "Michal1004", "Nauka2025");
    User Jakub("Jakub", "Klyszczyński", "Asnd123", "Studia#2024");
    User Maks("Maks", "Szwejkowski", "eloMaks", "Wiedza2023!");
    User nowy("", "", "", "");
    int zadanie;
    char akcja;
    string login, haslo, imie, nazwisko;
    string tytul, autor;

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
            if(admin.sprawdzDane(login, haslo)) {
                cout << "Zalogowano pomyślnie!" << endl;
                break;
            }
        }
        else if (akcja == 'R' || akcja == 'r') {
            cout << "Imię: ";
            cin >> imie;
            nowy.setImie(imie);
            cout << "Nazwisko: ";
            cin >> nazwisko;
            nowy.setNazwisko(nazwisko);
            cout << "Nazwa użytkownika/login: ";
            cin >> login;
            nowy.setLogin(login);
            cout << "Podaj hasło do konta: ";
            cin >> haslo;
            nowy.setHaslo(haslo);
            cout << "Konto zostało utworzone!" << endl;
            nowy.pokazDane();
            break;
        }
        else {
            cout << "Nieprawidłowe żądanie, wprowadź jeszcze raz.\n";
        }
    } while (true);
    if(login == "admin") {
        do {
            cout<<"1. Wyświetl dostępne książki"<<endl;
            cout<<"2. Dodaj książkę"<<endl;
            cout<<"3. Historia wypożyczeń użytkowników"<<endl;
            cout<<"4. Wyloguj"<<endl;
            cout<<"Wybierz czynności: ";
            cin>>zadanie;

            cin.ignore();
            if (zadanie ==1) {
                biblioteka.wyswietlKsiazki();
            }
            else if(zadanie ==2) {
                Ksiazka nowaKsiazka;
                cout<<"Podaj autora: ";
                getline(cin,autor);
                cout<<"Podaj tytuł: ";
                getline(cin, tytul);
                nowaKsiazka.autor = autor;
                nowaKsiazka.tytul = tytul;
                biblioteka.dodajKsiazke(nowaKsiazka);

            }
            else if(zadanie ==3) {

            }
            else if(zadanie ==4) {
                cout<<"Wylogowano pomyślnie";
                break;
            }
            else {
                cout<<"Nieobsługiwane żądanie. Spróbuj ponownie"<<endl;
            }
        } while (true);
    }
    else {
        do {
            cout<<"1. Wyświetl dostępne książki"<<endl;
            cout<<"2. Wypożycz książkę"<<endl;
            cout<<"3. Zwróć książkę"<<endl;
            cout<<"4. Historia wypożyczeń"<<endl;
            cout<<"5. Wyloguj"<<endl;
            cout<<"Wybierz czynności: ";
            cin>>zadanie;
            if (zadanie ==1) {
                biblioteka.wyswietlKsiazki();
            }
            else if(zadanie ==2) {

            }
            else if(zadanie ==3) {}
            else if(zadanie ==4) {}
            else if(zadanie ==5) {
                cout<<"Wylogowano pomyślnie";
                break;
            }
            else {
                cout<<"Nieobsługiwane żądanie. Spróbuj ponownie"<<endl;
            }
        } while (true);

    }
    return 0;
}
