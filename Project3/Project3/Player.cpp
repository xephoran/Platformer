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
			if (keyPressed[0] == -1)
			{
				keyPressed[0] = 0;
			}
			else
			{
				keyPressed[0] = 1;
			}
		}
		if (number == 3)
		{
			if (keyPressed[0] == 1)
			{
				keyPressed[0] = 0;
			}
			else
			{
				keyPressed[0] = -1;
			}
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
		if (Player::momentum[0] == 0)
		{
			Player::momentum[0] = 1;
		}
		else if (Player::momentum[0] < 1 && Player::momentum[0] > 0)
		{
			Player::momentum[0] += 0.4;
		}
		else if (Player::momentum[0] >= 1 && Player::momentum[0] < 10)
		{
			Player::momentum[0] += 0.2;
		}
		else if (Player::momentum[0] < 0)
		{
			Player::momentum[0] += 0.4;
		}
		used[0] = 1;
	}
	if (actions[0] == -1)
	{
		//moving left
		//TODO: put check for ability to move here:

		//
		Player::direction[1] = 1;
		Player::playerLocation[0] += momentum[0];
		std::cout << Player::momentum[0];
		if (Player::momentum[0] == 0)
		{
			Player::momentum[0] = -1;
		}
		else if (Player::momentum[0] > -1 && Player::momentum[0] < 0)
		{
			Player::momentum[0] += -0.4;
		}
		else if (Player::momentum[0] <= -1 && Player::momentum[0] > -10)
		{
			std::cout << "ENTERED MOMENTUM >= 1 thing \n\n\n";
			Player::momentum[0] += -0.2;
		}
		else if (Player::momentum[0] > 0)
		{
			Player::momentum[0] += -0.4;
		}
		//this is the used for left/right
		used[0] = 1;
	}

	//does stuff to remove momentum and use remaining momentum (horizontal)
	for (int i = 0; i < used.size(); i++)
	{
		if (used[i] == 1)
		{
			//this means nothing needs to be messed with
		}
		else if (used[i] == 0)
		{
			//this means we werent actively going this way an uh oh, incompatible now!
			Player::direction[i] = 0;
			Player::playerLocation[0] += Player::momentum[i];
			if (Player::momentum[i] > 0)
			{
				{Player::momentum[i] += -0.4;}
			}
			if (Player::momentum[i] < 0)
			{
				Player::momentum[i] += 0.4;
			}
			if (Player::momentum[i] < 0.5 && Player::momentum[i] > -0.5)
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

int Player::Main(std::vector<int> keyPressed, std::vector<int> courseLocation)
{
	std::array<int, 2> actions = actionCheck(keyPressed);
	//setting action number for texture. This needs to be updated to allow for multi button presses (ex. down and right) in future
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
	if (actionNumber == -1)
	{
		//action -1 is moving left(for now)
		if (!Player::playerTexture.loadFromFile("images/Player.jpg", sf::IntRect(125, 9, 55, 48)))
		{
			std::cout << "COULDNT LOAD FROM TEXTURE OH NO!!!";
		}
	}

			//updating sprite location
			Player::playerSprite.setPosition(Player::playerLocation[0], Player::playerLocation[1]);

		//assiging the texture to sprite and returning it to be drawn

		Player::playerSprite.setTexture(Player::playerTexture);
		sf::Sprite returnSprite = Player::playerSprite;
		
		
		return returnSprite;
}