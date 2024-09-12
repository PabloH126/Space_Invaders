#pragma once
#include <vector>
#include "Bullet.h"
#include "Player.h"
#include "Entity.h"
#include "Canva.h"

using namespace std;

class BulletManager
{
private:
	vector<Bullet*> bulletsFired;
	vector<Bullet*>::iterator it;
public:
	void MoveBullets(vector<Invader*> invaders, Player& player);
	void Shoot(bool isInvader, Entity &entity);
};

