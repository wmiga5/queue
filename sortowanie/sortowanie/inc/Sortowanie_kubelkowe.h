//
// Created by jan on 04.04.23.
//

#ifndef SORTOWANIE_SORTOWANIE_KUBELKOWE_H
#define SORTOWANIE_SORTOWANIE_KUBELKOWE_H

#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>

using namespace std;

/* funkcja szukaj_max() - znajduje max wartość w zadanym zbiorze
 * wej:
 * original_tab[] - zbiór do przeszukania
 * wyj:
 * max_val - najwieksza wartosc znajdujaca sie w tablicy
 * zmienne pom:
 * tmp_val - przechowuje aktualna wartość tablicy
 * i - zmienna licznikowa
 */
int szukaj_max()
{
    int max_val = 0;
    int tmp_val;

    for (int i = 0; i < N; i++)
    {
        tmp_val = original_tab[i];
        if (max_val < tmp_val)
        {
            max_val = tmp_val;
        }
    }
    return max_val;
}
/* funkcja szukaj_min() - znajduje min wartość w zadanym zbiorze
 * wej:
 * original_tab[] - zbiór do przeszukania
 * wyj:
 * min_val - najmniejsza wartosc znajdujaca sie w tablicy
 * zmienne pom:
 * tmp_val - przechowuje aktualna wartość tablicy
 * i - zmienna licznikowa
 */
int szukaj_min()
{
    int min_val = 10;
    int tmp_val;

    for (int i = 0; i < N; i++)
    {
        tmp_val = original_tab[i];
        if (min_val > tmp_val)
        {
            min_val = tmp_val;
        }
    }
    return min_val;
}

/* funkcja sortowanie_kubelkowe() zajmuje się sortowaniem liczb całkowitych rosnąco, odbywa się to za pomocą
 * 4 pętli. Określa wartości max i min zbioru. Dla każdej możliwej wartości występującej w zbiorze tworzy się
 * "kubełek", zliczający ilość wystąpień tej liczby (liczba kubełków = max - min + 1). Przeglądamy elem zbioru
 * i zapisujemy ilość wystąpień danych wartości w kubełkach. Wyniki przepisujemy sortując do zbioru wynikowego.
 * wej:
 * original_tab[] - zbiór liczb całkowitych
 * N - liczba elem w zbiorze
 * max_val - max wartość elem zbioru
 * min_val - min wartość elem zbioru
 * wyj:
 * original_tab[] - posortowany zbiór liczb całkowitych
 * zmienne pom:
 * tmp_tab[] - tablica przechowująca ilość wystąpień danych wartości o indeksach min_val do max_val
 * i,j - zmienne licznikowe
 */
void sortowanie_kubelkowe(int max_val, int min_val) {
    // tablica liczników o indeksach od min_val do max_val - wypełniona zerami
    // indeks wynosi (i - min_val), bo w nieszczesnym c++ iterujemy tablice od zera
    for (int i = min_val; i <= max_val; i++) {
        tmp_tab[i - min_val] = 0;
    }
    // przechodzac po wartościach oryginalnej tablicy szukamy liczb równych indeksowi licznika w tmp_tab, pomniejszonemu o min_val, jak znajdziemy zwiększamy licznik o 1
    for (int i = 0; i < N; i++) {
        tmp_tab[original_tab[i] - min_val]++;
    }
    int j = 0;
    // zapis do oryginalnej tablicy numerów niezerowych liczników, wykonujemy tyle razy ile wynosi wartość licznika
    for (int i = max_val; i >= min_val; i--) {
        while (tmp_tab[i - min_val] > 0) {
            original_tab[j] = i;
            tmp_tab[i - min_val]--;
            j++;
        }
    }
}

#endif //SORTOWANIE_SORTOWANIE_KUBELKOWE_H
