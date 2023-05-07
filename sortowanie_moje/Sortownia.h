//
// Created by wojte on 17.04.2023.
//

#ifndef SORTOWANIE_MOJE_SORTOWNIA_H
#define SORTOWANIE_MOJE_SORTOWNIA_H
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>



struct Data
{
    std:: string Title="Default title";
    int Rating=1;
    bool operator<(Data compared) { return (Rating < compared.Rating); }
    bool operator>(Data compared) { return (Rating > compared.Rating); }
};

std::ostream& operator << (std::ostream& os, const Data& rhs)    //Overloaded operator for '<<'{                                                                                    //for struct output
{
    os<<rhs.Rating<<" "<<rhs.Title<<std::endl;
    return os;

}

template<typename Typ>
class Sorting
        {
        public:
            Sorting(){Table_size=0;Table_with_Data=new Typ[SIZE];}
            ~Sorting(){delete[] Table_with_Data;}
    int cut_table(int first_element,int last_element);
    void quick_sort(int first_element,int last_element);
    void bucket_sort();
    void merge_sort(int first_element,int last_element);
    void Scalaj(int first_element,int middle_element,int last_element);

    void download_data(std::string file_name);
    void write_out();
    int  get_Table_size()const   {return Table_size;}
        private:

    Typ* Table_with_Data;
    int Table_size;


        };

template<typename Typ>
void Sorting<Typ>::Scalaj(int first_element,int middle_element,int last_element) {

    int A_element(first_element),B_element(middle_element+1),index(0);
    Typ *help=new Typ[last_element-first_element+1];

    while(A_element<=middle_element && B_element<=last_element)
    {
        if(Table_with_Data[B_element].Rating>Table_with_Data[A_element].Rating)
        {
            help[index++]=Table_with_Data[B_element++];
        }
        else
        {
            help[index++]=Table_with_Data[A_element++];
        }
    }
    if (A_element <= middle_element)
    {
        while (A_element <= middle_element)
        {
            help[index++] = Table_with_Data[A_element++];
        }

    }
    else
    {
        while (B_element <= last_element)
        {
            help[index++] = Table_with_Data[B_element++];
        }
    }

    // przepisywanie wyniku sortowania z tablicy pomocniczej do oryginalnej
    for (index = 0; index <= last_element - first_element; index++)
    {
        Table_with_Data[first_element + index] = help[index];
    }


    delete [] help;
}

template<typename Typ>
void Sorting<Typ>::write_out() {
    std::cout<<Table_size<<std::endl;
    for(int i=0;i<Table_size;i++)
    {
        std::cout<<Table_with_Data[i]<<std::endl;
    }

}

template<typename Typ>
void Sorting<Typ>::download_data(std::string file_name) {
    Data data;
    std::vector<Data> vector;
    std::fstream file;
    file.open(file_name);
    if (file.good())
    {
        std::string line, number, title1, title2, s_rating, header, trash;
        int i_rating;
        int iterator=0;
        getline(file, header);
        while (getline(file, line)&&iterator<SIZE)
        {

            std::stringstream ss(line);
            getline(ss, number, ',');

            getline(ss, title1, ',');


            if (title1.front() == '\"')
            {
                getline(ss, title2, '\"');
                title1 += ',' + title2;
                title1.erase(title1.begin());
                getline(ss, trash, ',');

            }
            getline(ss, s_rating);
            try {
                if(!s_rating.empty())
                {
                    i_rating = stoi(s_rating);
                    data.Title = title1;
                    data.Rating = i_rating;
                    vector.push_back(data);
                }
            } catch (const std::invalid_argument& e)
            {
                continue;
            }
            iterator++;

        }


    }
    int iterator_table=0;
    while(iterator_table<vector.size())
    {
        Table_with_Data[iterator_table]=vector[iterator_table];
        iterator_table++;
        Table_size++;
    }


std::cout<<Table_size<<std::endl;
}

template<typename Typ>
void Sorting<Typ>::merge_sort(int first_element,int last_element) {
   // std::cout<<"Jestem"<<std::endl;
    if (first_element >= 0 && first_element < last_element) {
        int middle_elemnt = (first_element + last_element) / 2;
        merge_sort( first_element, middle_elemnt);
        merge_sort( middle_elemnt + 1, last_element);
        // scalanie kolejnych 2 podtablic w 1 posortowana az do posortowania oryginalnej
        Scalaj(first_element,middle_elemnt,last_element);
    }
}

template<typename Typ>
void Sorting<Typ>::bucket_sort() {


    struct bucket
    {
        int amount=0;
        Typ *table_rate;
    };
    bucket* buckets_movies=new bucket[10];

    //Alokuje pamięć
    for(int i=0;i<10;i++)
    {
        buckets_movies[i].table_rate=new Typ[Table_size/2];

    }
    //Wkładamy do kubełka
    for(int j=0;j<10;j++)
    {

        for(int i=0;i<Table_size;i++)
        {

           if(Table_with_Data[i].Rating==j+1)
          {
              buckets_movies[j].table_rate[buckets_movies[j].amount]=Table_with_Data[i];

              buckets_movies[j].amount++;

          }

        }

    }


    int j=0,k=9;
    for(int i=0;i<Table_size;)
    {

      //  std::cout<<buckets_movies[k].amount<<std::endl;
        if(buckets_movies[k].amount==0)
        {
          //  std::cout<<"jeste"<<std::endl;
            j=0;

            k=k-1;

        }
        if(buckets_movies[k].amount!=0) {


          //  std::cout << k << buckets_movies[k].amount << std::endl;
            //std::cout<<buckets_movies[k].amount<<std::endl;

            Table_with_Data[i] = buckets_movies[k].table_rate[j];
            // std::cout<<buckets_movies[k].table_rate[j]<<std::endl;

            buckets_movies[k].amount--;
            j++;
            i++;
        }
    }


    //Usuwa pamięć
    for(int i=0;i<10;i++)
    {
        delete[] buckets_movies[i].table_rate;
    }
    delete[] buckets_movies;
}



template<typename Typ>
int Sorting<Typ>::cut_table(int first_element,int last_element)
{
    Typ help;
    Typ pivot=Table_with_Data[(first_element+last_element)/2];
    int iter_A(first_element),iter_B(last_element);
    while(1)
    {
        while(Table_with_Data[iter_A].Rating>pivot.Rating) {iter_A++;}
        while(Table_with_Data[iter_B].Rating<pivot.Rating) {iter_B--;}

        if(iter_A>=iter_B)
        {
            return iter_B;
        }
        help=Table_with_Data[iter_A];
        Table_with_Data[iter_A++]=Table_with_Data[iter_B];
        Table_with_Data[iter_B--]=help;

    }

}


template<typename Typ>
void Sorting<Typ>::quick_sort(int first_element,int last_element) {

    if (first_element >= 0 && first_element < last_element) {
        int pivot = cut_table( first_element, last_element);  // element osiowy
        quick_sort( first_element, pivot);            // lewa podtablica
        quick_sort( pivot + 1, last_element);          // prawa podtablica
    }


}



#endif //SORTOWANIE_MOJE_SORTOWNIA_H
