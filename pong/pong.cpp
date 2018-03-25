#include <SFML\Graphics.hpp> 
#include "GlobalVars.h"
#include "Paddle.h"
#include "Ball.h"

Paddle left(1);
Paddle right(0);
Ball ball;
int scoreRight = 0;
int scoreLeft = 0;
int scoreRight1 = 0;
int scoreLeft1 = 0;

void Collision()
{
	if ((ball.pos.y < left.pos.y + 40) && (ball.pos.y > left.pos.y - 40) && (ball.pos.x < 10))
		ball.dir.x *= -1;
	if ((ball.pos.y < right.pos.y + 40) && (ball.pos.y > right.pos.y - 40) && (ball.pos.x > 570))
		ball.dir.x *= -1;
	if (ball.pos.x < 0) {
		ball.pos = { widht / 2, height / 2 };
		scoreRight1++;
	}
	if (ball.pos.x > 580) {
		ball.pos = { widht / 2, height / 2 };
		scoreLeft1++;
	}
}


void main()
{
	sf::RenderWindow window(sf::VideoMode(widht, height), "Pong!");
	sf::Text scoreLeft;
	sf::Text scoreRight;
	sf::Font arial;
	arial.loadFromFile("arial.ttf");
	scoreLeft.setCharacterSize(20);
	scoreLeft.setFillColor(sf::Color::White);
	scoreLeft.setFont(arial);
	scoreLeft.setPosition(widht / 2 - 20, 0);
	scoreRight.setCharacterSize(20);
	scoreRight.setFillColor(sf::Color::White);
	scoreRight.setFont(arial);
	scoreRight.setPosition(widht / 2 + 20, 0);
	window.setFramerateLimit(300);
	while (window.isOpen())
	{
		window.clear();
		left.move(1);
		left.drawTo(window);
		right.move(0);
		right.drawTo(window);
		ball.move();
		Collision();
		ball.drawTo(window);
		scoreLeft.setString(std::to_string(scoreLeft1));
		window.draw(scoreLeft);
		scoreRight.setString(std::to_string(scoreRight1));
		window.draw(scoreRight);
		window.display();
	}
}