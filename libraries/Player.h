#pragma once
#include "Entity.h"
#include "Bullet.h"
#include <list>
#include <iostream>

using namespace std;

class Player : public Entity
{
private:
	list<Bullet*> bulletsFired;
	list<Bullet*>::iterator it;
public:
	
	Player();
	void Move(char input) override;
	void Draw() override;
	void Move();
	void Shoot();
	void MoveBullets();
};

