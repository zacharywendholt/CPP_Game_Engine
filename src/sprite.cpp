#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "headers/sprite.h"
#include "headers/globals.h"

//Texture wrapper class
SpriteTexture::SpriteTexture()
{
	printf("this could also probably work by taking in the string of the path for the image. \n then load the image, and make the texture. \n");
	printf("default constructor could just use some default image then. ");
	//Initialize
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
    numberOfFrames = 4;
	currentFrame = 0;
}


SpriteTexture::~SpriteTexture()
{
	//Deallocate
	free();
}

void SpriteTexture::initSpriteTexture() {
	SDL_Surface* testSurface = IMG_Load("res/foo.png");
    mTexture = SDL_CreateTextureFromSurface(gameRenderer, testSurface);
	loadSpriteAnimationFrames();
	
}


void SpriteTexture::free()
{
	//Free texture if it exists
	if( mTexture != NULL )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}


void SpriteTexture::render( int x, int y)
{

	if (mTexture == NULL) {
		printf("please only be once");
		initSpriteTexture();
	}
	// Start checking the actual render values for this.
	
	// Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	// Choose the actual sprite frame from the animation sheet.
	SDL_Rect* currentClip = &animationFrames[ currentFrame / 4 ];

	//Set clip rendering dimensions
	if( currentClip != NULL )
	{
		renderQuad.w = currentClip->w;
		renderQuad.h = currentClip->h;
	}
	else {
		printf(  SDL_GetError() );
	}

    SDL_RenderCopy(gameRenderer, mTexture, currentClip, &renderQuad);

	currentFrame++;

	if( currentFrame / 4 >= 4 )
	{
		currentFrame = 0;
	}
}

int SpriteTexture::getWidth()
{
	return mWidth;
}

int SpriteTexture::getHeight()
{
	return mHeight;
}

bool SpriteTexture::loadSpriteAnimationFrames()
{
	//Loading success flag
	bool success = true;

	//Load sprite sheet texture
	if( false )
	{
		printf( "Failed to load walking animation texture!\n" );
		success = false;
	}
	else
	{
		//Set sprite clips
		animationFrames[ 0 ].x =   0;
		animationFrames[ 0 ].y =   0;
		animationFrames[ 0 ].w =  64;
		animationFrames[ 0 ].h = 205;

		animationFrames[ 1 ].x =  64;
		animationFrames[ 1 ].y =   0;
		animationFrames[ 1 ].w =  64;
		animationFrames[ 1 ].h = 205;
		
		animationFrames[ 2 ].x = 128;
		animationFrames[ 2 ].y =   0;
		animationFrames[ 2 ].w =  64;
		animationFrames[ 2 ].h = 205;

		animationFrames[ 3 ].x = 192;
		animationFrames[ 3 ].y =   0;
		animationFrames[ 3 ].w =  64;
		animationFrames[ 3 ].h = 205;
	}
	
	return success;
}

