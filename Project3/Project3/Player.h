#pragma once
#include <array>
#include <vector>
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player();
	int Main(std::vector<int> keyPressed);
	sf::Sprite draw();
private:
	std::array<int, 2> playerLocation = { 0,1000 };
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
	int actionNumber = 0; //0 = rest, 1-? move right,
	void move(std::array<int, 2> actions);
	std::array<double, 4> momentum = { 0,0,0,0 };
	std::array<int, 4> direction = { 0,0,0,0 }; //0 = no, 1 = right, 2 = left, 3 = up, 4 = down
};

