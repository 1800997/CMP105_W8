#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"

class Mario: public GameObject
{
public:
	Mario();
	~Mario();
	void update(float, int);
	void collisionResponse(GameObject*);
protected:
	Animation walk;
};

