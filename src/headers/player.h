#include "point.h"

#ifndef Player_H
#define Player_H



class Player {
      
    public:
        Player(int speed, Point pos);
        Player(int speed);
        Player();
        int speed;
        Point pos;
        
};


#endif  