#include "point.h"
#include <SDL.h>
#include <SDL_image.h>

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
        SDL_Surface* playerSurface;
        void move(int x, int y);
        void close();
        
};


#endif  