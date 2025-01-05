#include "baza.h"
#include <iostream>
#include<string>
#include <vector>
using namespace std;

void Biblioteka::dodajKsiazke(const Ksiazka& nowaKsiazka) {
    ksiazki.push_back(nowaKsiazka);
    cout << "Dodano ksiazke: " << nowaKsiazka.tytul << " autora: " << nowaKsiazka.autor << "\n";
}
void Biblioteka::wyswietlKsiazki() const {
    if (ksiazki.empty()) {
        cout << "Brak dostępnych książek\n";
        return;
    }
    cout<<"Dostępne książki"<<endl;
    for (const Ksiazka& k : ksiazki) {
        cout << "Tytuł: " << k.tytul << " Autor: " << k.autor << endl;
    }

}
Biblioteka::Biblioteka() {
    ksiazki.push_back({"Władca Pierścieni", "J.R.R. Tolkien"});
    ksiazki.push_back({"1984", "George Orwell"});
    ksiazki.push_back({"Gdzie śpiewają raki?", "Delia Owens"});
    ksiazki.push_back({"Doktor Żywago", "Borys Pasternak"});
    ksiazki.push_back({"W pustyni i w puszczy", "Henryk Sienkiewicz"});
    ksiazki.push_back({"Romeo i Julia", "William Shakespeare"});
    ksiazki.push_back({"Zbrodnia i kara", "Fiodor Dostojewski"});
    ksiazki.push_back({"Bracia Karamazow", "Fiodor Dostojewski"});
    ksiazki.push_back({"Anna Karenina", "Lew Tołstoj"});
    ksiazki.push_back({"Wojna i pokój", "Lew Tołstoj"});
    ksiazki.push_back({"Folwark Zwierzęcy", "George Orwell"});
    ksiazki.push_back({"Droga na molo w Wigan", "George Orwell"});
    ksiazki.push_back({"Przeminęło z wiatrem", "Margaret Mitchell"});
    ksiazki.push_back({"Duma i uprzedzenie", "Jane Austen"});
    ksiazki.push_back({"Pan Tadeusz", "Adam Mickiewicz"});
    ksiazki.push_back({"Sklepy cynamonowe", "Bruno Schulz"});
    ksiazki.push_back({"Kordian", "Juliusz Słowacki"});
    ksiazki.push_back({"Boska komedia", "Dante Alighieri"});
    ksiazki.push_back({"Lalka", "Bolesław Prus"});
    ksiazki.push_back({"Emancypantki", "Bolesław Prus"});

}
