#include "Player.h"


//THINGS ONLY NEEDED FOR DEBUGGING
#include <iostream>

//private undeclared functions

std::array<int,4> Player::moveCheck(std::vector<sf::IntRect> rectVect)
{
	std::array<int, 4> canMove = { 0,0,0,0 };
	sf::IntRect playerBounds = (sf::IntRect)Player::playerSprite.getGlobalBounds();
	sf::IntRect xCheckRight((playerBounds.left + Player::momentum[0] + 1), (playerBounds.top - 1), playerBounds.width, (playerBounds.height - 2));
	sf::IntRect xCheckLeft((playerBounds.left - Player::momentum[0] - 1), (playerBounds.top- 1), playerBounds.width, (playerBounds.height - 2));
	sf::IntRect yCheckDown((playerBounds.left), playerBounds.top, (playerBounds.width), (playerBounds.height + Player::momentum[1] + 1));
	sf::IntRect yCheckUp((playerBounds.left + 1), ((int)playerBounds.top + (int)Player::momentum[1] - 1), (playerBounds.width - 2), playerBounds.height);
	for (int i = 0; i < rectVect.size(); i++)
	{

		if (xCheckRight.intersects(rectVect[i]))
		{
			if (momentum[0] > 0)
			{
				Player::momentum[0] = (rectVect[i].left - (playerBounds.left + playerBounds.width) - 1);
				Player::playerLocation[0] += momentum[0];
				//std::cout << momentum[0];
			}
			canMove[0] = 1;
		}
		if (xCheckLeft.intersects(rectVect[i]))
		{
			//this may not actually be the thing causing the problem????
			if (momentum[0] < 0)
			{
				Player::momentum[0] = (playerBounds.left - (rectVect[i].left + rectVect[i].width) + 2);
				Player::playerLocation[0] += -momentum[0];
				std::cout << (playerBounds.left - (rectVect[i].left + rectVect[i].width) + 1);
				std::cout << "\n";
			}
			canMove[1] = 1;
		}
		if (yCheckUp.intersects(rectVect[i]))
		{
			//Player::momentum[]
		}
		if (yCheckDown.intersects(rectVect[i]))
		{

			
			//std::cout << "\n";
				Player::momentum[1] = (rectVect[i].top - (playerBounds.top + playerBounds.height));
				Player::playerLocation[1] += momentum[1];
				std::cout << Player::momentum[1];
			canMove[3] = 1;
		}
	}

	return canMove;
}

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
		else if (number == 3)
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
		else if (number == 4)
		{
			if (keyPressed[1] == -1)
			{
				keyPressed[1] = 0;
			}
			else
			{
				keyPressed[1] = 1;
			}
		}
	}
	return keyPressed;
}

void Player::move(std::array<int,2> actions, std::vector<sf::IntRect> vectRect)
{
	static int upCheck = 0;



	std::array<int, 4> used = { 0,0,0,0 };
	std::array<int,4> moveCheckArray = Player::moveCheck(vectRect);

	if (moveCheckArray[3] == 1)
	{
		Player::airCount = 0;
	}

	//moving right
	if (actions[0] == 1)
	{
		//TODO: put check for ability to move here:

		//
		used[0] = 1;
		Player::direction[0] = 1;
		if (moveCheckArray[0] == 0)
		{
			Player::playerLocation[0] += momentum[0];
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
			
		}
	}

	//moving left
	if (actions[0] == -1)
	{
		used[0] = 1;
		Player::direction[0] = 1;

		if (moveCheckArray[1] == 0)
		{
			Player::playerLocation[0] += momentum[0];
			if (Player::momentum[0] == 0 )
			{
				Player::momentum[0] = -1;
			}
			else if (Player::momentum[0] > -1 && Player::momentum[0] < 0)
			{
				Player::momentum[0] += -0.4;
			}
			else if (Player::momentum[0] <= -1 && Player::momentum[0] > -10)
			{
				Player::momentum[0] += -0.2;
			}
			else if (Player::momentum[0] > 0)
			{
				Player::momentum[0] += -0.4;
			}
			//this is the used for left/right
			
		}
	}

	//jumping
	if (actions[1] == 1)
	{
		//Player::direction[1] = 1;
		
		if (!(moveCheckArray[1] == 1))
		{
			Player::playerLocation[1] += momentum[1];
			if (Player::momentum[1] == 0)
			{
				if (upCheck == 0)
				{
					upCheck = 1;
				}
				else if (upCheck == 1)
				{
					upCheck = 0;
					used[1] = 1;
					Player::momentum[1] = -15;
				}
			}
		}

	}
	
	//does stuff to remove momentum and use remaining momentum
	if (used[0] == 0)
	{
		//this means we werent actively going this way
		//Player::direction[i] = 0;
		
		if ((moveCheckArray[0] != 1) && (moveCheckArray[1] != 1))
		{
			Player::playerLocation[0] += Player::momentum[0];
			//handling horizontal
				if (Player::momentum[0] > 0)
				{
					{Player::momentum[0] += -0.4;}
				}
				if (Player::momentum[0] < 0)
				{
					Player::momentum[0] += 0.4;
				}
				if (Player::momentum[0] < 0.5 && Player::momentum[0] > -0.5)
				{
					Player::momentum[0] = 0;
				}
			}
		
		}	
	if (used[1] == 0)
	{
		if (moveCheckArray[3] != 1)
		{
			Player::airCount++;
			Player::momentum[1] += ((0.2)*(Player::airCount));
			Player::playerLocation[1] += Player::momentum[1];
		}
	}
	return;
}

Player::Player()
{
}

int Player::Main(std::vector<int> keyPressed, std::vector<sf::IntRect> terrain)
{
	std::array<int, 2> actions = actionCheck(keyPressed);
	//setting action number for texture. This needs to be updated to allow for multi button presses (ex. down and right) in future
	Player::actionNumber = actions[0];
	move(actions, terrain);

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

std::array<int, 4> Player::getCamera()
{
	std::array<int, 4> returnArray = { 0,0,0,0 };
	returnArray[0] = (Player::playerLocation[0] - 960);
	returnArray[1] = (Player::playerLocation[1] - 900);
	returnArray[2] = 1920;
	returnArray[3] = 1080;
	if ((returnArray[0] ) <= 0)
	{
		returnArray[0] = 0;
	}
	return returnArray;
}