#pragma once
#include "Entity.h"
#include "Bullet.h"
#include "Invader.h"
#include <vector>
#include <iostream>

using namespace std;

class Player : public Entity
{
public:	
	Player();
	void Move(char input) override;
	void Draw() override;
	void Move();
};

