#include <iostream>
#include "kolejka.h"

using namespace std;

int main() {


    Kolejka<string> kolej;
    kolej.insert(1,"kloc1");

    kolej.insert(3,"kloc2");
    kolej.insert(2,"kloc3");

    kolej.insert(5,"kloc4");
    kolej.wypisz();
    cout<<kolej.size();
    kolej.removeMin();
    cout<<endl;
    kolej.wypisz();
    cout<<kolej.size();
    cout<<kolej.min()<<endl;
    return 0;
}
