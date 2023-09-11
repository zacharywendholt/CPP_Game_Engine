#include "headers/window.h"


//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


Window::Window(/* args */)
{
    
    initWindow();
    initRenderer();
}

Window::~Window()
{
    close();
}

bool Window::initWindow() {
    //Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!\n" );
		}

		//Create window
		this->gameWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( this->gameWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			this->gScreenSurface = SDL_GetWindowSurface( this->gameWindow );
			if (this->gScreenSurface == NULL) {
				printf("The main window screen could not be created");
				success = false;
			}
		}
	}

	return success;
}

bool Window::initRenderer() {
    bool success = true;
    //Create vsynced renderer for window
    this->gRenderer = SDL_CreateRenderer( gameWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
    if( gRenderer == NULL )
    {
        printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Initialize renderer color
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

        //Initialize PNG loading
        int imgFlags = IMG_INIT_PNG;
        if( !( IMG_Init( imgFlags ) & imgFlags ) )
        {
            printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
            success = false;
        }
    }
    return success;
}

//Frees media and shuts down SDL
void Window::close()
{
	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gameWindow );
    SDL_FreeSurface( gScreenSurface);
	gameWindow = NULL;
	gRenderer = NULL;
    gScreenSurface = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}
