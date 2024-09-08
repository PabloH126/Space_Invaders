#pragma once
#include <Windows.h>
#include <iostream>
#include "../libraries/Invader.h"
#include <vector>

using namespace std;

class Bullet
{
private:
	COORD bulletCoords = { 0, 0 };
	COORD initCoords = { 0, 0 };
	int bulletDamage;
	bool isInvader;
	void Draw();
	void Erase();
	void Reset();
	bool CheckCoords(COORD invaderCoords);
public:
	Bullet(COORD entityCoords, bool isInvader);

	bool bulletDestroyed;
	void Move();
	void Spawn(COORD entityCoord);
	void Impact(vector<Invader*> invaders);
};

