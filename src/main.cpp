#include <iostream>

#include <SDL.h>
#include "headers/player.h"
#include "headers/point.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Starts up SDL and creates window
bool init();

//Player Information

const int MOVEMENT_SPEED = 5;
const int PLAYER_WIDTH = 10;
const int PLAYER_HEIGHT = 10;

Player player;

//Loads media
bool loadMedia();

//Loads individual image
SDL_Surface* loadStretchedSurface( std::string path );

//Frees media and shuts down SDL
void close();

void mainGameLoop();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;
    
//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;

//Current displayed image
SDL_Surface* gStretchedSurface = NULL;

SDL_Surface* gPlayerSurface = NULL;


int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{			
            // do the main game loop.
			mainGameLoop();
		}
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

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Get window surface
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }
    }

    return success;
}


bool loadMedia()
{
    //Loading success flag
    bool success = true;

    //Load stretching surface
	gStretchedSurface = loadStretchedSurface( "res/owlHead.bmp" );
    gPlayerSurface = loadStretchedSurface("res/player.bmp");

    if( gStretchedSurface == NULL )
	{
		printf( "Failed to load stretching image!\n" );
		success = false;
	}

    return success;
}


SDL_Surface* loadStretchedSurface( std::string path )
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
    SDL_FreeSurface( gHelloWorld );
    gHelloWorld = NULL;

    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}

void mainGameLoop()
{
    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;
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
        
        //Apply the image stretched
        SDL_Rect stretchRect;
        stretchRect.x = 0;
        stretchRect.y = 0;
        stretchRect.w = SCREEN_WIDTH / 4;
        stretchRect.h = SCREEN_HEIGHT / 4;


        SDL_Rect playerRect;
        playerRect.x = player.pos.x;
        playerRect.y = player.pos.y;
        playerRect.w = PLAYER_WIDTH;
        playerRect.h = PLAYER_HEIGHT;

        


        //SDL_BlitScaled( gStretchedSurface, NULL, gScreenSurface, &stretchRect );
        SDL_BlitScaled( gPlayerSurface, NULL, gScreenSurface, &playerRect );
    
        //Update the surface
        SDL_UpdateWindowSurface( gWindow );
    }
}

