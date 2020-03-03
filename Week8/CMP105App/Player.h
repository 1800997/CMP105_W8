#pragma once
#include "Framework/GameObject.h"

class Player: public GameObject
{
public:
	Player();
	~Player();
	bool playStyle;
	void update(float, int);
	void handleInput(float);
};

