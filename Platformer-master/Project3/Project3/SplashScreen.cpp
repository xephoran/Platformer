#include "SplashScreen.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


SplashScreen::SplashScreen()
{
}

int SplashScreen::displaySplash()
{
	sf::RenderWindow splashWindow(sf::VideoMode(800, 600), "", sf::Style::None);
	sf::Clock clock;
	sf::Time endTime = sf::milliseconds(5000);
	sf::Time timer = clock.getElapsedTime();
	bool displayingTitle = true;
	sf::Texture texture;
	texture.loadFromFile("images/logo.png");
	sf::Sprite sprite;
	sprite.setTexture(texture);
	splashWindow.draw(sprite);
	splashWindow.display();
	
	while (displayingTitle)
	{
		timer = clock.getElapsedTime();
		if (endTime <= timer)
		{
			displayingTitle = false;
		}
	}
	
	return 1;
}