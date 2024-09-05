#pragma once
#include <Windows.h>
#include <iostream>

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
	~Bullet();
	void Move();
};

