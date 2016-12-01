#include "TextureManager.h"



TextureManager::TextureManager()
{
}

int TextureManager::loadLocationArray(std::string location)
{
	//this gets the string variable for where the texture files are I just named the class weird
	TextureManager::location = location;


	return 0;
}

int TextureManager::loadFVector(std::vector<std::string> stringVector)
{
	//this class is used to load textures from a vector, which im not sure why i'd do

	return 0;
}

int TextureManager::loadFTexture(int textureNumber)
{
	//gets the number of the texture file and changes the number to a string
	std::string textureString = std::to_string(textureNumber);
	//push back the texture location + # which equals the file name
	TextureManager::textureLocations.push_back((TextureManager::location + textureString));

	return 0;
}