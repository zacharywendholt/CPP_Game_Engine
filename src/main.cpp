#include <iostream>

#include <SDL.h>
#include "headers/player.h"
#include "headers/point.h"
#include "headers/window.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Player Information

const int MOVEMENT_SPEED = 5;
const int PLAYER_WIDTH = 10;
const int PLAYER_HEIGHT = 10;

Player player;

Window gameWindow;

//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

void mainGameLoop();

//Loads individual image
SDL_Surface* loadStretchedSurface( std::string path , SDL_Surface* gRenderer);

//The image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;

int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
        // do the main game loop.
        mainGameLoop();
	}

	//Free resources and close SDL
	close();

	return 0;
}


bool init()
{
    //Initialization flag
    bool success = true; 

    player = Player(MOVEMENT_SPEED, 
                    PLAYER_WIDTH, 
                    PLAYER_HEIGHT, 
                    Point(50, 50));
    return success;
}


SDL_Surface* loadStretchedSurface( std::string path, SDL_Surface* gScreenSurface )
{
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;
	//Load image at specified path
	SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface( loadedSurface, gScreenSurface->format, 0 );
		if( optimizedSurface == NULL )
		{
			printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}
	return optimizedSurface;
}


void close()
{
    //Deallocate surface
    player.close();

    //Destroy window
    gameWindow.close();

    //Quit SDL subsystems
    SDL_Quit();
}

void mainGameLoop()
{
    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    //Current animation frame.
    //int frame = 0;

    while( !quit )
    {
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }
            else if (e.type == SDL_KEYDOWN) {
                if(e.key.keysym.sym == SDLK_a){
                    player.move(-player.speed, 0);
                } else if(e.key.keysym.sym == SDLK_d){
                    player.move(player.speed, 0);
                } else if(e.key.keysym.sym == SDLK_w){
                    player.move(0, -player.speed);
                } else if(e.key.keysym.sym == SDLK_s){
                    player.pos.y += player.speed;
                }
                
                else if (e.key.keysym.sym == SDLK_ESCAPE) {
                    quit = true;
                }
            }
        }

        SDL_SetRenderDrawColor (gameWindow.gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( gameWindow.gRenderer);

        player.animationUpdate(gameWindow.gRenderer);

        SDL_RenderPresent( gameWindow.gRenderer);
    
    }
}

