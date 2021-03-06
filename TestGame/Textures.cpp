#include "Textures.h"

#include <iostream>
Textures::Textures()
{
}


Textures::~Textures()
{
}

void Textures::SetupTexture(GLuint texture, string filePath, bool allowWrap){
	SDL_Surface * surface = IMG_Load(filePath.c_str());
	if (!surface) {
		printf("IMG_Load: %s\n", IMG_GetError());
		// handle error
		exit(1);
	}
	GLenum textureFormat;
		switch (surface->format->BytesPerPixel) {
		case 4:
			if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
				textureFormat = GL_BGRA;
			else
				textureFormat = GL_RGBA;
			break;

		case 3:
			if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
				textureFormat = GL_BGR;
			else
				textureFormat = GL_RGB;
			break;
	}

		//SDL_SaveBMP(surface, "test.bmp");


	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	if (!allowWrap){
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	}
	glTexImage2D(GL_TEXTURE_2D, 0, surface->format->BytesPerPixel, surface->w,
		surface->h, 0, textureFormat, GL_UNSIGNED_BYTE, surface->pixels);
	glBindTexture(GL_TEXTURE_2D, 0);


	SDL_FreeSurface(surface);
}
