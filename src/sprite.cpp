#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "headers/sprite.h"
#include "headers/globals.h"


SpriteTexture::SpriteTexture(const char *spritePath) 
{
	this->spritePath = spritePath;
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
    numberOfFrames = 4;
	currentFrame = 0;
}

SpriteTexture::SpriteTexture()
{
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
	SDL_Surface* spriteSurface;
	if (spritePath) {
		spriteSurface = IMG_Load(spritePath);
	}
	
	if (!spriteSurface) {
		spriteSurface = IMG_Load("res/foo.png");
	}
    mTexture = SDL_CreateTextureFromSurface(gameRenderer, spriteSurface);
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

