#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

#ifndef SpriteTexture_H
#define SpriteTexture_H

class SpriteTexture
{
	public:
        // Initializes variables
        SpriteTexture(SDL_Renderer* spriteRenderer);
		SpriteTexture();

		//Deallocates memory
		~SpriteTexture();

		void initSpriteTexture();

		//Loads image at specified path
		bool loadFromFile( std::string path);

		//Deallocates texture
		void free();

        bool loadSpriteAnimationFrames();

		//Set color modulation
		void setColor( Uint8 red, Uint8 green, Uint8 blue );

		//Set blending
		void setBlendMode( SDL_BlendMode blending );

		//Set alpha modulation
		void setAlpha( Uint8 alpha );
		
		//Renders texture at given point
		void render( int x, int y);

		//Gets image dimensions
		int getWidth();
		int getHeight();

	private:
		//The actual hardware texture
		SDL_Texture* mTexture;
		SDL_Renderer * spriteRenderer;

		SDL_Rect animationFrames[ 4 ];

		//Image dimensions
		int mWidth;
		int mHeight;

        int numberOfFrames;
		int currentFrame;
        
};

#endif