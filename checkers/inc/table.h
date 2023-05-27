#ifndef TABLE_H
#define TABLE_H
#include <vector>
#include "piece.h"

class board{
public:
    board(){num_black=12;num_white=12;set_defaul();}
    void draw();
    void set_defaul();


private:
    piece area[8][8];
    int num_black,num_white;
};


#endif