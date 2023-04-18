#define SIZE 10000
#include "../inc/Sortowanie_przez_scalanie.h"
#include "../inc/Quicksort.h"
#include "../inc/Sortowanie_kubelkowe.h"
#include <fstream>
#include <string>
#include <vector>

int main()
{
    // odczyt z pliku
    struct Data {
        string Title;
        int Rating = 0;
    };

    Data data;
    vector<Data> vec;

    fstream file;
    file.open("../projekt2_dane.CngRDs-i.csv");

    if (file.good())
    {
        string line, number, title1, title2, s_rating, header, trash;
        int i_rating;

        getline(file, header);
        while (getline(file, line))
        {

            stringstream ss(line);
            getline(ss, number, ',');

            getline(ss, title1, ',');


            if (title1.front() == '\"')
            {
                getline(ss, title2, '\"');
                title1 += ',' + title2;
                title1.erase(title1.begin());
                getline(ss, trash, ',');
                
            }
            getline(ss, s_rating, ',');
            try {
                if(!s_rating.empty())
                {
                    i_rating = stoi(s_rating);
                    data.Title = title1;
                    data.Rating = i_rating;
                    vec.push_back(data);
                }
            } catch (const invalid_argument& e)
            {
                continue;
            }
        }
    }
    cout << vec[0].Title << endl;
    cout << vec[0].Rating << endl;

    srand((unsigned)time(NULL));
    int max_value, min_value;
    int nr;
    cout << "Wybierz typ sortowania: (podaj numer): " << endl;
    cout << "1. Quicksort" << endl;
    cout << "2. Sortowanie przez scalanie" << endl;
    cout << "3. Kubełkowe" << endl;
    cout << "numer: ";
    cin >> nr;
    cout << endl;


    switch(nr)
    {
        case 1: {
            cout << "Quicksort: "<< endl;
            cout << "tablica do posortowania: " << endl;
            for (int i = 0; i < N; i++)
            {
                original_tab[i] = rand() % 10;
            }
            for (int i = 0; i < N; i++)
            {
                cout << setw(4) << original_tab[i];
            }
            cout << endl << "tablica posortowana: " << endl;
            auto start_count = std::chrono::high_resolution_clock::now(); // zaczynamy zliczać czas
            quicksort(0, N - 1);
            auto end_count = std::chrono::high_resolution_clock::now(); // kończymy zliczać czas
            std::chrono::duration<double, std::milli> sort_duration = (end_count - start_count);
            for (int i = 0; i < N; i++)
            {
                cout << setw(4) << original_tab[i];
            }
            cout << endl << "Czas sortowania: " << sort_duration.count() << "ms" << endl;
            break;
        }
        case 2: {
            cout << "Sortowanie przez scalanie: " << endl;
            cout << "tablica do posortowania: " << endl;
            for (int i = 0; i < N; i++) {
                original_tab[i] = rand() % 10;
            }
            for (int i = 0; i < N; i++) {
                cout << setw(4) << original_tab[i];
            }
            cout << endl << "tablica posortowana: " << endl;
            auto start_count = std::chrono::high_resolution_clock::now();
            Sortowanie_przez_scalanie(0, N - 1);
            auto end_count = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> sort_duration = (end_count - start_count);
            for (int i = 0; i < N; i++) {
                cout << setw(4) << original_tab[i];
            }
            cout << endl << "Czas sortowania: " << sort_duration.count() << "ms" << endl;
            break;
        }
        case 3: {
            cout << "Sortowanie kubełkowe: " << endl;
            cout << "tablica do posortowania: " << endl;
            for (int i = 0; i < N; i++) {
                original_tab[i] = rand() % 10;
            }
            for (int i = 0; i < N; i++) {
                cout << setw(4) << original_tab[i];
            }
            min_value = szukaj_min();
            max_value = szukaj_max();
            cout << endl << "tablica posortowana: " << endl;
            auto start_count = std::chrono::high_resolution_clock::now();
            sortowanie_kubelkowe(max_value, min_value);
            auto end_count = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> sort_duration = (end_count - start_count);
            for (int i = 0; i < N; i++) {
                cout << setw(4) << original_tab[i];
            }
            cout << endl << "Czas sortowania: " << sort_duration.count() << "ms" << endl;
            break;
        }
        default:
            break;
    }


    return 0;
}
