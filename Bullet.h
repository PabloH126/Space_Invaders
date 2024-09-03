#pragma once
#include <Windows.h>
#include <iostream>

class Bullet
{
private:
	COORD bulletCoords = { 0, 0 };
	int bulletDamage;
	bool isInvader;
public:
	Bullet(COORD entityCoords, bool isInvader);
	void Move();
};

