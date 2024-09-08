#pragma once
#include <Windows.h>
#include <iostream>

using namespace std;

class Bullet
{
private:
	COORD bulletCoords = { 0, 0 };
	int bulletDamage;
	bool isInvader;
	bool bulletDestroyed;
	void Draw();
	void Erase();
	void Destroy();
public:
	Bullet(COORD entityCoords, bool isInvader);
	void Move();
};

