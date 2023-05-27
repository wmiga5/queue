//
// Created by wojte on 27.05.2023.
//

#ifndef UNTITLED_PIECE_H
#define UNTITLED_PIECE_H
enum color_piece{black,white,blank};

class piece{
public:

    piece(){ set_color(blank);}
    //piece(color_piece b_w,int x,int y){color=b_w;cordinates_x=x;cordinates_y=y;index=amount;amount++;}
    void set_color(color_piece black_or_white){color=black_or_white;}
    void set_cordinates(int x,int y){cordinates_x=x;cordinates_y=y;}
    color_piece get_color()const {return color;}
    int & get_index(){ return index;}
    int  get_index()const{return index;}
private:

    color_piece color;
    int cordinates_x,cordinates_y;
    int index;
};



#endif //UNTITLED_PIECE_H
