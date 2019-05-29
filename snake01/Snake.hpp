#ifndef Snake_hpp
#define Snake_hpp

#include <stdlib.h>
#include <SFML/Graphics.hpp>

const int extern N,M,size;

struct coordonates{
    int x,y;
};

class Snake{
    
public:
    
    int len;
    coordonates snake[100];
    
public:
    
    Snake();
    void move(int dir,coordonates& food);
};

#endif
