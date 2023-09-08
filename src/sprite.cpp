#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "headers/sprite.h"

//Texture wrapper class



SpriteTexture::SpriteTexture()
{
	//Initialize
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
    numberOfFrames = 4;
}

SpriteTexture::~SpriteTexture()
{
	//Deallocate
	free();
}

bool SpriteTexture::loadFromFile( std::string path, SDL_Renderer& gRenderer)
{
	//Get rid of preexisting texture
	free();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Color key image
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( &gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	//Return success
	mTexture = newTexture;
	return mTexture != NULL;
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

void SpriteTexture::setColor( Uint8 red, Uint8 green, Uint8 blue )
{
	//Modulate texture rgb
	SDL_SetTextureColorMod( mTexture, red, green, blue );
}

void SpriteTexture::setBlendMode( SDL_BlendMode blending )
{
	//Set blending function
	SDL_SetTextureBlendMode( mTexture, blending );
}
		
void SpriteTexture::setAlpha( Uint8 alpha )
{
	//Modulate texture alpha
	SDL_SetTextureAlphaMod( mTexture, alpha );
}

void SpriteTexture::render( int x, int y, SDL_Rect* clip, SDL_Renderer& gRenderer)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopy( &gRenderer, mTexture, clip, &renderQuad );
}

int SpriteTexture::getWidth()
{
	return mWidth;
}

int SpriteTexture::getHeight()
{
	return mHeight;
}

bool SpriteTexture::loadSpriteAnimationFrames(SDL_Renderer& gRenderer)
{
	//Loading success flag
	bool success = true;

	//Load sprite sheet texture
	if( !loadFromFile( "res/foo.png", gRenderer) )
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

