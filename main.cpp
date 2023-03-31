#include <iostream>
#include "kolejka.h"
#include "zdanie.h"
#include <cstdlib>
#include <ctime>
using namespace std;



int main() {

    srand(time(NULL));
    Kolejka<string> kolej;


    Zdanie wpis;

    wpis.wpisz();

    wpis.podziel();

    for(int i=1;i<= wpis.get_rozmiar();i++)
    {
        kolej.insert(i,(wpis.get_tablica()[i-1]));
    }

    string losowa_tablica[kolej.size()];
    int losowa_przydzial[kolej.size()];
    int licznik=0;
    while(licznik<kolej.size())
    {
        int wylosowania;
        wylosowania=rand()%(kolej.size());

        bool czy_jest=false;
        //sprawdzam czy jest już ta pozycja
        for(int i=0;i<kolej.size();i++)
        {
            if(wylosowania==losowa_przydzial[i])
            {
                czy_jest= true;
            }
        }
        if(czy_jest==false)
        {
            losowa_przydzial[licznik]=wylosowania;


            licznik++;
        }

    }
    //Przypisuję losowo do tablicy
    int rozmiar=kolej.size();
    for(int i=0;i<kolej.size();i++)
    {
        losowa_tablica[losowa_przydzial[i]]=kolej.removeMin();

    }

    for(int i=0;i<rozmiar;i++)
    {
        cout<<losowa_tablica[i]<<endl;
    }


    kolej.wypisz();
    return 0;
}
