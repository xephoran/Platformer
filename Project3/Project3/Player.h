#pragma once
#include <array>
#include <vector>
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player();
	int Main(std::vector<int> keyPressed, std::vector<sf::IntRect> courseLocation);
	sf::Sprite draw();
	std::array<int, 4> getCamera();
private:
	int airCount = 0;
	std::array<int,2> playerLocation = { 0,1380 };
	std::array<int,4> moveCheck(std::vector<sf::IntRect> rectVect);
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
	int actionNumber = 0; //0 = rest, 1-? move right,
	void move(std::array<int, 2> actions, std::vector<sf::IntRect> vectRect);
	std::array<double, 4> momentum = { 0,0,0,0 };
	std::array<int, 4> direction = { 0,0,0,0 }; //0 = no, 1 = right, 2 = left, 3 = up, 4 = down
};

