#include "Ball.h"
#include "GlobalVars.h"



Ball::Ball()
{
	ball.setRadius(5);
	ball.setFillColor(sf::Color::White);
	pos = { widht / 2, height / 2 };
	dir = {1,1};
}

void Ball::drawTo(sf::RenderWindow &window)
{
	ball.setPosition(pos);
	window.draw(ball);
}

void Ball::move()
{
	pos.x += dir.x;
	pos.y += dir.y;
	if (pos.y < 5) dir.y *= -1;
	if (pos.y > 295) dir.y *= -1;
}

Ball::~Ball()
{
}
