#include "Player.h"

Player::Player()
{




};

Player::~Player()
{



};

void Player::update(float dt, int maxY)
{
	if (getPosition().y < 0)
	{
		setPosition(getPosition().x, 0);
	}
	if (getPosition().y > maxY)
	{
		setPosition(getPosition().x,maxY);
	}
};


void Player::handleInput(float dt)
{
	if (playStyle)
	{
		if (input->isKeyDown(sf::Keyboard::Up))
		{
			move(sf::Vector2f(0,-velocity.y * dt));
		}
		else if (input->isKeyDown(sf::Keyboard::Down))
		{
			move(sf::Vector2f(0,velocity.y * dt));
		}
	}
	else
	{
		if (input->isKeyDown(sf::Keyboard::W))
		{
			move(sf::Vector2f(0, -velocity.y * dt));
		}
		else if (input->isKeyDown(sf::Keyboard::S))
		{
			move(sf::Vector2f(0, velocity.y * dt));
		}
	}


};