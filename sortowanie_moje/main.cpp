#include <iostream>

#include <iomanip>
#include <chrono>
long int const SIZE=2100;

#include "Sortownia.h"
using namespace std;
int main() {




    Sorting<Data> movies_bucket,movies_quick,movies_merge;
    movies_bucket.download_data("../projekt2_dane.CngRDs-i.csv");
    movies_quick.download_data("../projekt2_dane.CngRDs-i.csv");
    movies_merge.download_data("../projekt2_dane.CngRDs-i.csv");

    auto start_count = std::chrono::high_resolution_clock::now();
    movies_bucket.bucket_sort();
    auto end_count = std::chrono::high_resolution_clock::now(); // kończymy zliczać czas
    std::chrono::duration<double, std::milli> sort_duration = (end_count - start_count);
    cout<<"Czas sortowania kubelkowego: "<<sort_duration.count()<<"ms"<<endl;


    start_count = std::chrono::high_resolution_clock::now();
    movies_merge.merge_sort(0,movies_merge.get_Table_size()-1);
    end_count = std::chrono::high_resolution_clock::now(); // kończymy zliczać czas
    sort_duration = (end_count - start_count);
    cout<<"Czas sortowania przez scalanie: "<<sort_duration.count()<<"ms"<<endl;

    start_count = std::chrono::high_resolution_clock::now();
    movies_quick.quick_sort(0,movies_quick.get_Table_size()-1);

     end_count = std::chrono::high_resolution_clock::now(); // kończymy zliczać czas
    sort_duration = (end_count - start_count);
    cout<<"Czas sortowania szybkiego: "<<sort_duration.count()<<"ms"<<endl;

  //  movies_bucket.write_out();

        movies_bucket.Check();
        movies_quick.Check();
        movies_merge.Check();


        cout<<"Srednia: "<<movies_bucket.average()<<endl;
         cout<<"Srednia: "<<movies_merge.average()<<endl;
        cout<<"Srednia: "<<movies_quick.average()<<endl;

    cout<<"Mediana: "<<movies_bucket.median()<<endl;
    cout<<"Mediana: "<<movies_merge.median()<<endl;
    cout<<"Mediana: "<<movies_quick.median()<<endl;


    return 0;
}
