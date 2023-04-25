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
    void quick_sort(int first_element,int last_element);
    void bucket_sort();
    void merge_sort();
    void download_data(std::string file_name);
    void write_out();
    int  get_Table_size()const   {return Table_size;}
        private:

    Typ* Table_with_Data;
    int Table_size;


        };

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
void Sorting<Typ>::merge_sort() {

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
void Sorting<Typ>::quick_sort(int first_element,int last_element) {

    Typ pivot;
    Typ swap_help;



    int j=0;

    int i=(first_element+last_element)/2;
    pivot=Table_with_Data[i];
    Table_with_Data[i]=Table_with_Data[last_element];
   // std::cout<<pivot.Rating<<std::endl;
    for(i=j=first_element;i<last_element;i++)
    {
        if(Table_with_Data[i].Rating>pivot.Rating)
        {
            swap_help=Table_with_Data[i];
            Table_with_Data[i]=Table_with_Data[j];
            Table_with_Data[j]=swap_help;
            j++;


        }
    }
    Table_with_Data[last_element]=Table_with_Data[j];
    Table_with_Data[j]=pivot;


    if(first_element<j-1)
    {
        this->quick_sort(first_element,j-1);
    }

    if(j+1<last_element)
    {
        this->quick_sort(j+1,last_element);
    }

}



#endif //SORTOWANIE_MOJE_SORTOWNIA_H
