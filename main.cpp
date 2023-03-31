#include <iostream>
#include "kolejka.h"
#include "zdanie.h"
using namespace std;

int main() {


    Kolejka<string> kolej;
    Zdanie wpis;

    wpis.wpisz();

    wpis.podziel();



    return 0;
}
