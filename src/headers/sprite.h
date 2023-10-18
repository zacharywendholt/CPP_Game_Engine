#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

#ifndef SpriteTexture_H
#define SpriteTexture_H

class SpriteTexture
{
	public:
		
		SpriteTexture(const char * spritePath);

        // Initializes variables
        SpriteTexture();

		//Deallocates memory
		~SpriteTexture();

		void initSpriteTexture();

		//Deallocates texture
		void free();

        bool loadSpriteAnimationFrames();
		
		//Renders texture at given point
		void render( int x, int y);

		//Gets image dimensions
		int getWidth();
		int getHeight();

	private:
		//The actual hardware texture
		SDL_Texture* mTexture;

		SDL_Rect animationFrames[ 4 ];

		//Image dimensions
		int mWidth;
		int mHeight;

        int numberOfFrames;
		int currentFrame;

		const char * spritePath;
        
};

#endif