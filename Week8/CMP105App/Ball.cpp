#include "Ball.h"

Ball::Ball()
{


};

Ball::~Ball()
{



};

void Ball::update(float dt,int maxX,int maxY)
{
	move(velocity * dt);

	if (getPosition().x < 0)
	{
		setPosition(0, getPosition().y);
		setPosition(maxX / 2, maxY / 2);
	}
	if (getPosition().x > maxX)
	{
		setPosition(maxX, getPosition().y);
		setPosition(maxX / 2, maxY / 2);
	}
	if (getPosition().y < 0)
	{
		setPosition(getPosition().x,0);
		velocity.y = -velocity.y;
	}
	if (getPosition().y > maxY)
	{
		setPosition(getPosition().x, maxY);
		velocity.y = -velocity.y;
	}


};

void Ball::collisionResponse(GameObject* collider)
{

	velocity.x = -velocity.x;

};
