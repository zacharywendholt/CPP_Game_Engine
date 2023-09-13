#include "point.h"
#include "sprite.h"
#include <SDL.h>
#include <SDL_image.h>

#ifndef Player_H
#define Player_H



class Player {
      
    public:
        Player(int speed, int width, int height, Point pos, SpriteTexture playerTexture);
        Player();
        int speed;
        int width;
        int height;
        Point pos;
        SDL_Surface* playerSurface;
        SpriteTexture playerTexture;
        void move(int x, int y);
        void animationUpdate(SDL_Renderer* gRenderer);
        void close();
        
};


#endif  