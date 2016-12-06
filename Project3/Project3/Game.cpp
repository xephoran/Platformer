#include "Game.h"
#include <SFML/graphics.hpp>
#include "TextureManager.h"
#include "Player.h"
#include "Input.h"
#include <vector>
#include "LevelManager.h"
#include <array>


Game::Game()
{

}

int Game::run()
{
	//starts by initializing classes
	TextureManager textureManager;
	Player player;
	Input input;
	LevelManager levelManager;

	//vectors
	std::vector<int> keysPressed;
	std::vector<int> levelLocations;
	std::vector<sf::IntRect> terrainVector;
	std::array<int, 4> viewArray;

	//other variables needed
	sf::View view1;

	//temporary  int for level number I will eventually change so that you can have load games
	int levelNumber = 1;
	terrainVector = levelManager.loadLevel(1);

	//starts the game by opening a window
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Window Name");
	while (window.isOpen())
	{
		window.clear();
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}
		//clears keypress vector and resetting values
		keysPressed.clear();
		keysPressed = input.keysPressed();

		//lets the player class handle operations first
		player.Main(keysPressed, terrainVector);
		viewArray = player.getCamera();

		view1.reset(sf::FloatRect(viewArray[0], viewArray[1], viewArray[2], viewArray[3]));

		//set camera
		window.setView(view1);
		//drawing everything
		window.draw(levelManager.draw());
		//the level background needs to be drawn first

		//needs to draw the player last
		window.draw(player.draw());
		window.display();
	}


	return 0;
}
