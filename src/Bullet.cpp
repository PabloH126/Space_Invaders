#include "../libraries/Bullet.h"
#include "../libraries/Canva.h"
#include "../libraries/Invader.h"
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

const char bulletTrue = char(42);
const char bulletFalse = char(00);
const char bulletMovement = char(32);

Bullet::Bullet(COORD entityCoords, bool typeInvader) {
	isInvader = typeInvader;
	bulletDamage = 50;
	bulletDestroyed = false;

	Spawn(entityCoords);
}

void Bullet::Move() {
	if (isInvader && bulletCoords.Y < 37) { 
		Erase();
		bulletCoords.Y++;
		Draw();
	}
	else if (!isInvader && bulletCoords.Y > 4) { 
		Erase();
		bulletCoords.Y--; 
		Draw();
	}
	else {
		bulletDestroyed = true;
		Erase();
	}
}

void Bullet::Draw() {
	Canva::GoToXY(bulletCoords.X, bulletCoords.Y, bulletCoords);
	cout << bulletTrue;
}

void Bullet::Erase() {
	Canva::GoToXY(bulletCoords.X, bulletCoords.Y, bulletCoords);
	cout << bulletMovement;
}

void Bullet::Reset() {
	Canva::GoToXY(initCoords.X, initCoords.Y, bulletCoords);
	cout << bulletFalse;
}

void Bullet::Spawn(COORD entityCoords) {
	int x = entityCoords.X + 3, y;
	isInvader ? y = entityCoords.Y + 4 : y = entityCoords.Y - 1;
	initCoords = { (short)x, (short)y };

	Canva::GoToXY(x, y, bulletCoords);
	Draw();
}

void Bullet::Impact(vector<Invader*> invaders) {
	for (Invader* invader : invaders) {
		COORD invaderCoords = invader->GetCoords();
		if (CheckCoords(invaderCoords) && !invader->isDestroyed) {
			invader->isDestroyed = true;
			invader->Death(invaderCoords.X, invaderCoords.Y);
			Reset();
		}
	}
}

bool Bullet::CheckCoords(COORD invaderCoords) {
	if ((bulletCoords.X >= invaderCoords.X && bulletCoords.Y >= invaderCoords.Y) && 
		(bulletCoords.X <= invaderCoords.X+6 && bulletCoords.Y <= invaderCoords.Y+3))
	{
		return true;
	}

	return false;
}

