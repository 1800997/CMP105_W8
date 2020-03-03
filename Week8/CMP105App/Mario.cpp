#include "Mario.h"

Mario::Mario()
{
	walk.addFrame(sf::IntRect(0, 0, 15, 20)); 
	walk.addFrame(sf::IntRect(15, 0, 15, 20)); 
	walk.addFrame(sf::IntRect(30, 0, 15, 20)); 
	walk.addFrame(sf::IntRect(45, 0, 15, 20)); 
	walk.setFrameSpeed(1.f / 10.f);

};

Mario::~Mario()
{



};

void Mario::update(float dt, int maxX)
{
	walk.animate(dt); 
	setTextureRect(walk.getCurrentFrame());
	move(velocity * dt);

	if (getPosition().x < 0)
	{
		setPosition(0, getPosition().y);
		velocity.x = -velocity.x;
		walk.setFlipped(false);
	}
	if (getPosition().x > maxX)
	{
		setPosition(maxX, getPosition().y);
		velocity.x = -velocity.x;
		walk.setFlipped(true);
	}


};

void Mario::collisionResponse(GameObject* collider)
{

	velocity.x = -velocity.x;
	walk.setFlipped(true);

};
