#include "LevelManager.h"
#include <iostream>
#include <fstream>
#include <array>


LevelManager::LevelManager()
{
}

std::vector<sf::IntRect> LevelManager::loadLevel(int levelNumber)
{
	//gets the number of the level texture file and changes the number to a string
	std::string textureString = std::to_string(levelNumber);
	//change the level file location to correct one if needed
	LevelManager::location = "levels/l" + textureString + ".jpg";

	if (!LevelManager::levelTexture.loadFromFile(location))
	{
		std::cout << "COULDNT LOAD TEXURE OH NO!!!";
	}

	LevelManager::levelSprite.setTexture(LevelManager::levelTexture);

	//opening the txt file for the terrain sprite bounds
	std::array<int, 4> spriteBounds = { 0,0,0,0 };
	std::ifstream infile;
	infile.open("levels/" + textureString + ".txt");
	if (infile.fail())
	{
		std::cout << "\n COULDNT OPEN FILE!!!";
	}
	int lineCount = 0;
	int item = 0;
	
	std::vector<sf::IntRect> rectVect;

	for (int i = 0; !infile.eof(); i++)
	{
		//WORK HERE!!! PLZ ME DO IT!!!!
		infile >> item;
		if (i % 4 == 0)
		{
			spriteBounds[0] = item;
		}
		if (i % 4 == 1)
		{
			spriteBounds[1] = item;
		}
		if (i % 4 == 2)
		{
			spriteBounds[2] = item;
		}
		if (i % 4 == 3)
		{
			spriteBounds[3] = item;
			sf::IntRect terrain(spriteBounds[0], spriteBounds[1], spriteBounds[2], spriteBounds[3]);
			rectVect.push_back(terrain);
		}
	}


	//need to load the 1.txt into an array for the sprite return
	return rectVect;
}

sf::Sprite LevelManager::draw()
{
	return LevelManager::levelSprite;
}


