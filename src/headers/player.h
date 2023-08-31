#include "point.h"

#ifndef Player_H
#define Player_H



class Player {
      
    public:
        Player(int speed, int width, int height, Point pos);
        Player(int speed, int width, int height);
        Player();
        int speed;
        int width;
        int height;
        Point pos;
        void move(int x, int y);
        
};


#endif  