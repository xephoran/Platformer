#include "Player.h"


//THINGS ONLY NEEDED FOR DEBUGGING
#include <iostream>

//private undeclared functions


std::array<int, 2> actionCheck(std::vector<int> vector)
{
	//creates the return array (0 = move right, 1 = move left, etc...)
	std::array<int, 2> keyPressed = { 0,0 };

	for (int i = 0; i < vector.size(); i++)
	{
		//this for loop checks if numbers in the vector of keypresses are useful to the player class
		int number = vector[i];
		if (number == 2)
		{
			keyPressed[0] = 1;
		}
	}
	return keyPressed;
}

void Player::move(std::array<int,2> actions)
{
	std::array<int, 4> used = { 0,0,0,0 };
	if (actions[0] == 1)
	{
		//moving right
		//TODO: put check for ability to move here:

		//
		Player::direction[0] = 1;
		Player::playerLocation[0] += momentum[0];
		std::cout << Player::momentum[0];
		if (Player::momentum[0] < 1)
		{
			Player::momentum[0] = 1;
		}
		else if (Player::momentum[0] >= 1 && Player::momentum[0] < 10)
		{
			Player::momentum[0] += 0.2;
		}
		used[0] = 1;
	}


	//does stuff to remove momentum and use remaining momentum
	for (int i = 0; i < used.size(); i++)
	{
		if (used[i] == 1)
		{

		}
		else if (used[i] == 0)
		{
			Player::direction[i] = 0;
			Player::playerLocation[0] += Player::momentum[i];
			if (Player::momentum[i] > 0)
			{
				{Player::momentum[i] += -0.4;}
			}
			if (Player::momentum[i] < 0)
			{
				momentum[i] = 0;
			}
		}
	}
	return;
}

Player::Player()
{
}

int Player::Main(std::vector<int> keyPressed)
{
	std::array<int, 2> actions = actionCheck(keyPressed);
	//setting action number for texture. This needs to be updated to include multi button presses in future
	Player::actionNumber = actions[0];
	move(actions);

	return 0;
}

sf::Sprite Player::draw()
{
	//TODO begins by loading the correct texture for the action being taken by the player
	if (actionNumber == 0)
	{
		//0 = static
		if (!Player::playerTexture.loadFromFile("images/Player.jpg", sf::IntRect(13,9,55,48)))
		{
			std::cout << "COULDNT LOAD TEXURE OH NO!!!";
		}
	}
	if (actionNumber == 1)
	{
		//action 1 = moving right(for now)?
		if (!Player::playerTexture.loadFromFile("images/Player.jpg", sf::IntRect(69, 9, 55, 48)))
		{
			std::cout << "COULDNT LOAD TEXURE OH NO!!!";
		}
	}

			//updating sprite location
			Player::playerSprite.setPosition(Player::playerLocation[0], Player::playerLocation[1]);

		//assiging the texture to sprite and returning it to be drawn

		Player::playerSprite.setTexture(Player::playerTexture);
		sf::Sprite returnSprite = Player::playerSprite;
		
		
		return returnSprite;
}