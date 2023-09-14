#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "headers/sprite.h"

//Texture wrapper class
SpriteTexture::SpriteTexture(SDL_Renderer* spriteRenderer)
{
	printf("good texture\n check parameters \n");
	//Initialize
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
    numberOfFrames = 4;
	currentFrame = 0;
	this->spriteRenderer = spriteRenderer;
	initSpriteTexture();
}

SpriteTexture::SpriteTexture() 
{
	printf("bad texture\n");
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
	numberOfFrames = 0;
	currentFrame = 0;
	this->spriteRenderer = NULL;

	printf("this is where render issue starts I believe. if I dont initialize it, then there is no image, if i do, then there is no renderer.");
	initSpriteTexture();
}

SpriteTexture::~SpriteTexture()
{
	//Deallocate
	free();
	spriteRenderer = NULL;
}

void SpriteTexture::initSpriteTexture() {
	if (this->spriteRenderer == NULL) {
		printf("\nSprite Renderer is Null in the sprite init\n");
	} else {
		loadSpriteAnimationFrames();
	}
}

bool SpriteTexture::loadFromFile( std::string path)
{
	//Get rid of preexisting texture

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
        newTexture = SDL_CreateTextureFromSurface( this->spriteRenderer, loadedSurface );
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

void SpriteTexture::render( int x, int y)
{
	// Start checking the actual render values for this.
	
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	SDL_Rect* currentClip = &animationFrames[ currentFrame / 4 ];

	// 50, 50   mWidth: 256mHeight: 205
	// 50, 50  mWidth: 256mHeight: 205

	//Set clip rendering dimensions
	if( currentClip != NULL )
	{
		renderQuad.w = currentClip->w;
		renderQuad.h = currentClip->h;
	}
	else {
		printf(  SDL_GetError() );
	}

	if (mTexture == NULL) {
		printf("there is no texture");
	}

	if (currentClip == NULL) {
		printf("no current clip");
	}

	//Render to screen
	SDL_RenderCopy( this->spriteRenderer, mTexture, currentClip, &renderQuad);

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
	free();

	//Load sprite sheet texture
	if( !loadFromFile( "res/foo.png") )
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

