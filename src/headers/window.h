#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

#ifndef Window_H
#define Window_H

class Window
{
private:
    
public:
    SDL_Window* gameWindow;
    //The window renderer
    SDL_Renderer* gRenderer;

    // ok, so i have this stuff, but i think i need to actually make the objects that these pointers are going to. 
    SDL_Surface* gScreenSurface;
    Window();
    ~Window();
    bool initWindow();
    bool initRenderer();
    void close();
};


#endif