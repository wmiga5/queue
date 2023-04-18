//
// Created by jan on 29.03.23.
//

#ifndef SORTOWANIE_SORTOWANIE_PRZEZ_SCALANIE_H
#define SORTOWANIE_SORTOWANIE_PRZEZ_SCALANIE_H

#include <cmath>
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

int N = 10;
int * original_tab= new int[N];
int * tmp_tab = new int[N];
/*
* Funkcja Scalaj - scala dwa uporządkowane podzbiory w jeden uporządkowany podzbiór
*
* wej:
* int first_index - pierwszy indeks podzbioru wcześniejszego
* int middle_index - pierwszy indeks późniejszego podzbioru
* int last_index - ostatni indeks podzbioru późniejszego
* wyj:
* original_tab - posortowana tablica
* zmienne pom:
* tmp_tab - tablica potrzebna do przepisywania liczb podczas scalania
* a_index - indeks dla liczb w wcześniejszym podzbiorze
* b_index - indeks dla liczb w późniejszym podzbiorze
* index - indeks do iteracji
*/
void Scalaj(int first_index,int middle_index,int last_index)
{
    int a_index = first_index;
    int b_index = middle_index;
    int index = 0;

    for (index = first_index; index <= last_index; index++)
    {
        if (a_index == middle_index) //jesli skończą nam się liczby w pierwszym podzbiorze to liczbę z drugiego przepisujemy do tablicy tymczasowej
        {
            tmp_tab[index] = original_tab[b_index];
            b_index++;
        }
        else if (b_index > last_index) // analogicznie, jeśli w drugim podzbiorze zabraknie już liczb, to przepisujemy z pierwszego
        {
            tmp_tab[index] = original_tab[a_index];
            a_index++;
        }
        else if ( original_tab[a_index] < original_tab[b_index]) // do tmp_tab przepisujemy wieksza wartosc
        {
            tmp_tab[index] = original_tab[b_index];
            b_index++;
        }
        else
        {
            tmp_tab[index] = original_tab[a_index];
            a_index++;
        }
    }

    for (index = first_index; index <= last_index; index++) // przepisujemy uporzadkowane liczby z tmp_tab do oryginalnej tablicy
    {
        original_tab[index] = tmp_tab[index];
    }
}

/* Funkcja sortowania przez scalanie - sortuje tablice na zasadzie dziel i zwyciężaj.
 * Za pomocą rekurencji dzieli tablicę na mniejsze podzbiory, a nastepnie scala idac
 * od najwiekszych podzbiorów do najmniejszych.
 * wej:
 * int first_index - pierwszy indeks podzbioru wcześniejszego
 * int last_index - ostatni indeks podzbioru późniejszego
 * wyj:
 * original_tab - posortowana tablica
 * zmienne pom:
 * int middle_index - pierwszy indeks późniejszego podzbioru
 */
void Sortowanie_przez_scalanie(int first_index, int last_index)
{
    int middle_index = (first_index + last_index + 1)/2;

    if (middle_index - first_index > 1) // dzielimy rekurencyjnie pierwszą połowe tablicy, az do podzbiorów dwuelementowych i potem wywolujemy scalenie, w celu uporządkowania wzorów
    {
        Sortowanie_przez_scalanie(first_index, middle_index - 1); // rekurencyjnie zmniejszamy wielkość zbioru, które na koniec scalimy gdy nie będzie się dało już ich bardziej podzielić
    }
    if (last_index - middle_index > 0) // analogicznie dla drugiej połówki
    {
        Sortowanie_przez_scalanie(middle_index, last_index);
    }
    Scalaj(first_index, middle_index, last_index); // scalamy dwa podzbiory uporządkowując w nich liczby malejąco.
}


#endif //SORTOWANIE_SORTOWANIE_PRZEZ_SCALANIE_H
