#include "Paddle.h"
#include <SFML\Graphics.hpp> 
#include "GlobalVars.h"



Paddle::Paddle(bool left)
{
	paddle.setSize({ 10, 80 });
	paddle.setFillColor(sf::Color::White);
	paddle.setOrigin(5, 40);
	if (left)
	{
		pos = { 10, height / 2 };
	}
	else
	{
		pos = { widht - 20, height / 2 };
	}
}

void Paddle::drawTo(sf::RenderWindow &window)
{
	paddle.setPosition(pos);
	window.draw(paddle);
}

void Paddle::move(bool left)
{
	if (left)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			pos.y--;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
			pos.y++;
	}
	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
			pos.y--;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
			pos.y++;
	}
	if (pos.y <= 40) pos.y++;
	if (pos.y >= 290) pos.y--;
}

Paddle::~Paddle()
{
}
