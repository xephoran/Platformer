#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <vector>

class LevelManager
{
public:
	LevelManager();
	std::vector<sf::IntRect> loadLevel(int levelNumber);
	sf::Sprite draw();
private:
	std::string location;
	sf::Texture levelTexture;
	sf::Sprite levelSprite;
};

