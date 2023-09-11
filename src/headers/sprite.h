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
        SpriteTexture();

		//Deallocates memory
		~SpriteTexture();

		//Loads image at specified path
		bool loadFromFile( std::string path, SDL_Renderer* gRenderer);

		//Deallocates texture
		void free();

        bool loadSpriteAnimationFrames(SDL_Renderer* gRenderer);

		//Set color modulation
		void setColor( Uint8 red, Uint8 green, Uint8 blue );

		//Set blending
		void setBlendMode( SDL_BlendMode blending );

		//Set alpha modulation
		void setAlpha( Uint8 alpha );
		
		//Renders texture at given point
		void render( int x, int y, SDL_Renderer* gRenderer, SDL_Rect* clip = NULL );

		//Gets image dimensions
		int getWidth();
		int getHeight();

	private:
		//The actual hardware texture
		SDL_Texture* mTexture;
        SDL_Rect* animationFrames;

		//Image dimensions
		int mWidth;
		int mHeight;

        int numberOfFrames;
        
};

#endif