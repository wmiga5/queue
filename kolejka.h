//
// Created by wojte on 30.03.2023.
//

#ifndef PROGRAMOWANIE_KOLEJKA_H
#define PROGRAMOWANIE_KOLEJKA_H

#include <string>

template < typename Typ >
struct elem_listy {
    elem_listy < Typ > (int k = 100, Typ x = 0) {
        priorytet = k;
        element = x;
        nastepny = NULL;
    }
    elem_listy < Typ > * nastepny;
    int priorytet;
    Typ element;

};

template < typename Typ >
class Kolejka {
public:

    Kolejka() {
        head = NULL;
        tail = NULL;
    }

    int size() const;

    void insert(int numer, Typ dane);

    elem_listy < Typ > * removeMin();

    Typ min() const;

    bool isEmpty() const;

    void wypisz();
private:
    //Struktura przechwująca elementy kolejki

    elem_listy < Typ > * head;
    elem_listy < Typ > * tail;

};

template < typename Typ >
void Kolejka < Typ > ::wypisz() {

    if (isEmpty()) {
        std::cout << "pusto" << std::endl;
    }

    elem_listy < Typ > * pomoc = head;

    while (pomoc != NULL) { //std::cout<<"test "<<pomoc->nastepny->element<<std::endl;
        // std::cout<<pomoc->priorytet<<std::endl;
        std::cout << pomoc -> element;
        pomoc = pomoc -> nastepny;
    }

}

template < typename Typ >
bool Kolejka < Typ > ::isEmpty() const {
    if (head == NULL) {
        return true;
    } else {
        return false;
    }

}

template < typename Typ >
Typ Kolejka < Typ > ::min() const {
    return head -> element;
}

template < typename Typ >
elem_listy < Typ > * Kolejka < Typ > ::removeMin() {
    //sprawdz to
    elem_listy < Typ > * pomoc;
    pomoc = head;

    head = head -> nastepny;
    elem_listy < Typ > * zwraca = pomoc;

    return zwraca;
}

template < typename Typ >
void Kolejka < Typ > ::insert(int numer, Typ dane) {
    elem_listy < Typ > * dodany = new elem_listy < Typ > (numer, dane);
    //lista jest pusta
    if (isEmpty()) {
        head = dodany;
        tail = dodany;

    } else {
        elem_listy < Typ > * licznik = head;

        elem_listy < Typ > * poprzedni = NULL;
        while (licznik != NULL) {
            //Sprawdzamy czy priorytet dodanego jest mniejszy niż kolejnych elementów, jeśli tak to przeskakujemy dalej
            if (dodany -> priorytet >= licznik -> priorytet) {
                poprzedni = licznik;
                licznik = licznik -> nastepny;
                //Jeśli dodany element ma najwyższy priorytet to poprzedni wskazuje na niego, a dodany wskazuje na null
                if (licznik == NULL) {
                    poprzedni -> nastepny = dodany;
                    tail = dodany;
                }
            } else {
                if (licznik == head) {
                    head = dodany;

                } else {
                    poprzedni -> nastepny = dodany;
                }

                dodany -> nastepny = licznik;

                return;
            }
        }

    }
}

template < typename Typ >
int Kolejka < Typ > ::size() const {
    int rozmiar = 0;
    elem_listy < Typ > * pomoc = head;
    while (pomoc != NULL) {
        pomoc = pomoc -> nastepny;
        rozmiar++;
    }

    return rozmiar;
}

#endif //PROGRAMOWANIE_KOLEJKA_H