#pragma once
#include<iostream>
#include<string>
#include<vector>
#include "lodepng.h"


class Texture
{
public:
	/**
	*	Returns the address of array of bytes, the texture in raw form
	*	@return texture as byte array address
	*/
	std::vector<unsigned char> & GetTexture();

	/**
	*	Returns the position of the Actor
	*	@param filePath the file path to the texture
	*	@param w width of texture
	*	@param h height of texture
	*/
	void LoadTexture(std::string filePath, unsigned w, unsigned h);

	/**
	*	Returns the width of the texture
	*	@return width of texture
	*/
	unsigned GetWidth(){ return texW; };

	/**
	*	Returns the height of the texture
	*	@return height of texture
	*/
	unsigned GetHeight() { return texH; };

private:
	unsigned texW;/*<! Texture width*/
	unsigned texH;/*<! Texture height*/
	std::vector<unsigned char> data; /*<! Texture as array of bytes*/
};


void Texture::LoadTexture(std::string filePath, unsigned w, unsigned h)
{
	texW = w;
	texH = h;

	unsigned error = lodepng::decode(data, texW, texH, filePath);

	if (error != 0)
	{
		std::cout << "error " << error << ": " << lodepng_error_text(error) << std::endl;
		exit(1);
	}
}

std::vector<unsigned char> & Texture::GetTexture()
{
	return data;
}

