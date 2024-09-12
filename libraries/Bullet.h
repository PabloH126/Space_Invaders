#pragma once
#include <Windows.h>
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

#include "Invader.h"
#include "Player.h"
#include "Canva.h"
#include "Entity.h"

using namespace std;

class Bullet
{
private:
	COORD bulletCoords = { 0, 0 };
	COORD initCoords = { 0, 0 };
	int bulletDamage;
	void Draw();
	void Erase();
	void Reset();
	bool CheckCoords(COORD invaderCoords);
public:
	Bullet(COORD entityCoords, bool isInvader);

	bool isInvader;
	bool bulletDestroyed;

	void Move();
	void Spawn(COORD entityCoord, bool isNewInvader);
	void Impact(Entity& entity);
};

