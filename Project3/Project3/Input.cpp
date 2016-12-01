#include "Input.h"

//DUEBBING
#include <iostream>



Input::Input()
{
}

std::vector<int> Input::keysPressed()
{
	std::vector<int> keysPressed;
	//this is a huge set of if statements for testing if various keys are pressed and if so adding them to a vector
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		keysPressed.push_back(1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		keysPressed.push_back(2);
	}


	//final return of the vector
	return keysPressed;
}