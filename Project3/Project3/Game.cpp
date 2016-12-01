#include "Game.h"
#include <SFML/graphics.hpp>
#include "TextureManager.h"
#include "Player.h"
#include "Input.h"
#include <vector>



Game::Game()
{

}

int Game::run()
{
	//starts by initializing classes
	TextureManager textureManager;
	Player player;
	Input input;

	//vector for key codes
	std::vector<int> keysPressed;

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
		player.Main(keysPressed);


		//drawing everything
		
		//needs to draw the player last
		window.draw(player.draw());
		window.display();
	}

	
	return 0;
}
