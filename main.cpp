#include <iostream>
using namespace std;

int main()
{
    char akcja;
    string login, haslo, imie, nazwisko;

    cout << "Witaj w Bibliotece!" << endl;


    do {
        cout << "Masz konto? Zaloguj sie po kliknieciu Z" << endl;
        cout << "Nie masz konta? Zarejestruj sie po kliknieciu R" << endl;
        cin >> akcja;
        if (akcja == 'Z' || akcja == 'z') {
            cout << "Login: ";
            cin >> login;
            cout << "Haslo: ";
            cin >> haslo;
            cout << "Zalogowano pomyslnie!" << endl;
            break;
        }
        else if (akcja == 'R' || akcja == 'r') {
            cout << "Imie: ";
            cin >> imie;
            cout << "Nazwisko: ";
            cin >> nazwisko;
            cout << "Nazwa uzytkownika/login: ";
            cin >> login;
            cout << "Podaj haslo do konta: ";
            cin >> haslo;
            cout << "Konto zostało utworzone!" << endl;
            break;
        }
        else {
            cout << "Nieprawidlowe zapytanie, wprowadz jeszcze raz.\n";
        }
    } while (true);

    return 0;
}
