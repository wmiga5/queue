#include "C:\Users\wojte\Desktop\programowanie\checkers\inc\table.h"
#include <iostream>

using namespace std;

void board::draw() {

    cout<<"_________________"<<endl;
    for(int i=0;i<8;i++)
    {    cout<<endl<<"|";
        for(int j=0;j<8;j++)
        {
            if(area[j][i].get_color()==blank){cout<<"-|";}
            else if(area[j][i].get_color()==white){cout<<"W|";}
            else{cout<<"B|";}
        }
    }
}


void board::set_defaul() {
    int help=0;
    int num_w=12;
    int num_b=12;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(help%2==1)
            {
                area[j][i].set_color(black);area[j][i].set_cordinates(j,i);
                area[j][i].get_index()=num_b--;
            }
            else
            {
                area[j][i].set_color(blank);area[j][i].set_cordinates(j,i);
            }
            help++;
        }
        help++;
    }
    for(int i=3;i<5;i++)
    {
        for(int j=0;j<8;j++)
        {
            area[j][i].set_color(blank);area[j][i].set_cordinates(j,i);
            help++;
        }
        help++;
    }
    for(int i=5;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(help%2==1)
            {
                area[j][i].set_color(white);area[j][i].set_cordinates(j,i);
                area[j][i].get_index()=num_w--;
            }
            else
            {
                area[j][i].set_color(blank);area[j][i].set_cordinates(j,i);
            }
            help++;
        }
        help++;
    }
}