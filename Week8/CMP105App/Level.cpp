#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	player1.playStyle = true;
	player2.playStyle = false;
	
	player1.setInput(in);
	player2.setInput(in);

	maxX = window->getSize().x;
	maxY = window->getSize().y;

	player1.setSize(sf::Vector2f(20,150));
	player1.setCollisionBox(sf::FloatRect(0, 0, 20, 150));
	player1.setPosition(100, maxY/2);
	player1.setVelocity(0, 500);
	player1.setFillColor(sf::Color::Red);

	player2.setSize(sf::Vector2f(20, 150));
	player2.setCollisionBox(sf::FloatRect(0, 0, 20, 150));
	player2.setPosition(maxX - 100, maxY / 2);
	player2.setVelocity(0, 500);
	player2.setFillColor(sf::Color::Red);

	ballTexture.loadFromFile("gfx/Beach_Ball.png");
	ball1.setTexture(&ballTexture);
	ball1.setSize(sf::Vector2f(75, 75));
	ball1.setCollisionBox(sf::FloatRect(0, 0, 75, 75));
	ball1.setPosition(maxX / 2, maxY / 2);
	ball1.setVelocity(500,500);

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	player1.handleInput(dt);
	player2.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	maxX = window->getSize().x;
	maxY = window->getSize().y;

	player1.update(dt, maxY-150);
	player2.update(dt, maxY-150);
	ball1.update(dt, maxX-75,maxY-75);

	if (Collision::checkBoundingBox(&ball1,&player1))
	{
		ball1.collisionResponse(NULL);
	}

	if (Collision::checkBoundingBox(&ball1, &player2))
	{
		ball1.collisionResponse(NULL);
	}
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(player1);
	window->draw(player2);
	window->draw(ball1);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color::Black);
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}