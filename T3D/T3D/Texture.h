// =========================================================================================
// KXG363 - Advanced Games Programming
// =========================================================================================
//
// Author: Robert Ollington
//
// Texture.h
//
// Class for loading, storing and manipulating textures

#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include "sdl/SDL.h"
#include "SDL_ttf.h"
#include "Colour.h"

namespace T3D
{

	class Texture
	{
	public:
		Texture(int width, int height, bool continuousTone = true, bool mipmap = false);
		Texture(std::string filename, bool continuousTone = true, bool mipmap = false);
		virtual ~Texture(void);

		void createFractal(Colour low, Colour high, float roughness, bool conserveHue = false);
		void writeText(int x, int y, const char *text, Colour c, TTF_Font *font);

		int getWidth(){ return image->w; }
		int getHeight(){ return image->h; }

		Colour getPixel(int x, int y);
		void plotPixel(int x, int y, Colour c);
		void clear(Colour c);

		unsigned int getID(){ return texid; }
		void setID(unsigned int id){ texid = id; }
		
		int getNumberOfColors(){ return image->format->BytesPerPixel; }

		void* getPtr() { return image->pixels; }
		SDL_Surface* getSurface() { return image; }

		bool isRGB(){ return (image->format->Rmask == 0x000000FF); }

		bool getCountinuousTone() { return continuousTone; }
		bool getMipmap() { return mipmap; }

	private:
		SDL_Surface *image;
		unsigned int texid;
		bool continuousTone;			// hint for choosing appropriate texture filtering
		bool mipmap;					// generate automatic mipmaps when loading
	};

}

#endif

