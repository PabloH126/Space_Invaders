#pragma once
#include "Entity.h"
#include "Bullet.h"
#include <vector>
#include <iostream>

using namespace std;

class Player : public Entity
{
private:
	vector<Bullet> bulletsFired;
public:
	Player();
	void Move(char input) override;
	void Draw() override;
	void Move();
	void Shoot();
};

