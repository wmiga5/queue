#include <iostream>
long int const SIZE=90000;

#include "Sortownia.h"
using namespace std;
int main() {




    Sorting<Data> movies;
    movies.download_data("../projekt2_dane.CngRDs-i.csv");
    //movies.write_out();
    //movies.bucket_sort();

    movies.quick_sort(0,movies.get_Table_size()-1);
    movies.write_out();

    return 0;
}
