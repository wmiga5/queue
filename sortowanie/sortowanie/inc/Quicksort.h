//
// Created by jan on 01.04.23.
//

#ifndef SORTOWANIE_QUICKSORT_H
#define SORTOWANIE_QUICKSORT_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>


/* funkcja quicksort - odpowiedzialna za sortowanie elementów tablicy malejąco
 * dziala na podstawie metody dziel i zwyciężaj oraz rekurencji
 * dane wej:
 * oryginal_tab[] - tablica, do której wpisujemy liczby nieposortowane
 * first_index - indeks do pierwszego elem tablicy
 * last_index - indeks do ostatniego elem tablicy
 * dane wyj:
 * original_tab[] - posortowana tablica wejsciowa
 * zmienne pom:
 * joker - elem, do ktorego wpisujemy element dzieloący zbiór na dwa podzbiory
 * i - indeks pomocniczy, przechodzi po calej tablicy w celu sprawdzenia czy elem jest mniejszy od jokera
 * j - indeks pomocniczy, element pod tym indeksem bedziemy zamieniac z elem o indeksie i
 * tmp - zmienna pomocnicza do zamiany elem tablicy
 */
void quicksort(int first_index,int last_index)
{
    int joker = 0;
    int tmp = 0;
    int j = 0;

    int i = (first_index + last_index)/2;
    joker = original_tab[i];
    original_tab[i] = original_tab[last_index]; // do srodkowego elem wpisujemy ostatni (bo go tez trzeba przesortowac)

    for (i = j = first_index; i < last_index; i++)
    {
        if (original_tab[i] > joker) // jesli elem o indeksie i wiekszy od jokera to zamieniamy z elem j
        {
            tmp = original_tab[i];
            original_tab[i] = original_tab[j];
            original_tab[j] = tmp;
            j++;
        }
    }

    original_tab[last_index] = original_tab[j]; // do ostatniego wpisujemy elem będący pod indeksem dzielącym zbior na dwa podzbiory
    original_tab[j] = joker; // do elem dzielącego dwa podzbiory ponownie przypisujemy usuniety wczesniej elem będący jokerem

    // mamy w tym miejscu tablicę podzieloną na dwa podzbiory (część lewa z elem wiekszymi od jokera,
    // część prawa z elem mniejszymi, bądź równymi jokerowi)

    // za pomocą rekursji sortujemy lewą część podzbioru
    if (first_index < j - 1) // sprawdzamy czy podzbiór ma chociaż jeden element
    {
        quicksort(first_index, j - 1);
    }
    // za pomocą rekursji sortujemy prawą część podzbioru
    if (j + 1 < last_index)
    {
        quicksort(j + 1, last_index);
    }

}

#endif //SORTOWANIE_QUICKSORT_H
