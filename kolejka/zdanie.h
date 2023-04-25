//
// Created by wojte on 31.03.2023.
//

#ifndef PROGRAMOWANIE_ZDANIE_H
#define PROGRAMOWANIE_ZDANIE_H#include <string>

class Zdanie {

public: Zdanie() {
        wyrazenie = "Basic";
        tablica = NULL;
        rozmiar = 0;
    }

    void wpisz();

    void wypisz();

    void podziel();

    int get_rozmiar() const {
        return rozmiar;
    }

    std::string * get_tablica() {
        return tablica;
    }

private:

    std::string wyrazenie;

    std::string * tablica;

    int rozmiar;

};

void Zdanie::wypisz() {
    std::cout << wyrazenie << std::endl;
}

void Zdanie::wpisz() {

    std::cout << "Podaj swoje zdanie" << std::endl;
    std::getline(std::cin, wyrazenie);

}

void Zdanie::podziel() {
    if (wyrazenie.length() % 5 != 0) {
        tablica = new std::string[(wyrazenie.length() / 5) + 1];
        rozmiar = (wyrazenie.length() / 5) + 1;
    } else {
        tablica = new std::string[(wyrazenie.length() / 5)];
        rozmiar = (wyrazenie.length() / 5);
    }

    for (int i = 0; i < rozmiar; i++) {

        for (int j = 0; j < 5; j++) {
            if (j + (5 * i) <= wyrazenie.length()) {
                tablica[i] = tablica[i] + wyrazenie[j + (5 * i)];
            }

        }

    }
    std::cout << "Stworzono " << rozmiar << " pakietow" << std::endl;

}
#endif //PROGRAMOWANIE_ZDANIE_H