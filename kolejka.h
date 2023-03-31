//
// Created by wojte on 30.03.2023.
//

#ifndef PROGRAMOWANIE_KOLEJKA_H
#define PROGRAMOWANIE_KOLEJKA_H

#include <string>




template <typename Typ>
class Kolejka
{
public:

    Kolejka(){head=NULL;tail=NULL;}

int size() const ;

void insert(int numer,Typ dane);

Typ removeMin();

Typ min() const;

bool isEmpty() const ;

void wypisz();
private:
    //Struktura przechwująca elementy kolejki
    struct elem_listy
    {
        elem_listy(int k=100,Typ x=0){priorytet=k;element=x; nastepny=NULL;}
        elem_listy *nastepny;
        int priorytet;
        Typ element;


    };

    elem_listy *head;
    elem_listy *tail;


};

template<typename Typ>
void Kolejka<Typ>::wypisz() {

    if(isEmpty())
    {std::cout<<"pusto"<<std::endl;}


    elem_listy *pomoc=head;

    while (pomoc!=NULL)
    {
        std::cout<<pomoc->element;
        pomoc=pomoc->nastepny;
    }

}

template<typename Typ>
bool Kolejka<Typ>::isEmpty() const {
    if(head==NULL)
    {return true;}
    else
    {return false;}

}

template<typename Typ>
Typ Kolejka<Typ>::min() const {
    return head->element;
}

template<typename Typ>
Typ Kolejka<Typ>::removeMin() {
    //sprawdz to
    elem_listy* pomoc;
    pomoc=head;

    head= head->nastepny;
    Typ zwraca=pomoc->element;
    delete pomoc;
    return zwraca;
}

template<typename Typ>
void Kolejka<Typ>::insert(int numer, Typ dane) {
    elem_listy * dodany=new elem_listy(numer,dane);
    //lista jest pusta
    if(isEmpty())
    {
        head=dodany;
        tail=dodany;

    }
    else
    {
        elem_listy * licznik=head;

        elem_listy * poprzedni=NULL;
        while (licznik!=NULL) {
            //Sprawdzamy czy priorytet dodanego jest mniejszy niż kolejnych elementów, jeśli tak to przeskakujemy dalej
            if ( dodany->priorytet >= licznik->priorytet)
            {
                poprzedni=licznik;
                licznik=licznik->nastepny;
                //Jeśli dodany element ma najwyższy priorytet to poprzedni wskazuje na niego, a dodany wskazuje na null
                if(licznik==NULL)
                {

                    poprzedni->nastepny=dodany;
                    tail=dodany;
                }
            }

            else
            {
                if(licznik==head)
                {
                    head=dodany;

                }
                else
                {
                    poprzedni->nastepny=dodany;
                }

                dodany->nastepny=licznik;

                return;
            }
        }

    }
}

template<typename Typ>
int Kolejka<Typ>::size() const {
        int rozmiar=0;
        elem_listy* pomoc=head;
        while(pomoc!=NULL)
        {
            pomoc=pomoc->nastepny;
            rozmiar++;
        }

    return rozmiar;
}



#endif //PROGRAMOWANIE_KOLEJKA_H