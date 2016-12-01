#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <string>

class TextureManager
{
public:
	TextureManager();
	int loadLocationArray(std::string location);
	int loadFVector(std::vector<std::string> stringVector);
	int loadFTexture(int textureNumber);
private:
	std::vector<sf::Texture> textureVector;
	std::vector<std::string> textureLocations;
	std::string location;
};

