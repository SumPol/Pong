#pragma once
#include <SFML\Graphics.hpp> 
class Paddle
{
public:
	Paddle(bool left);
	~Paddle();
	sf::Vector2f pos;
	sf::RectangleShape paddle;
	void drawTo(sf::RenderWindow &window);
	void move(bool left);
	bool left;
};

