#include "Bullet.h"
#include "Canva.h"
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

Bullet::Bullet(COORD entityCoords, bool typeInvader) {
	isInvader = typeInvader;
	bulletDamage = 50;
	bulletDestroyed = false;

	int x = entityCoords.X + 3, y;
	isInvader ? y = entityCoords.Y + 4 : y = entityCoords.Y - 1;
	COORD initCoords = { x, y };

	Canva::GoToXY(x, y, bulletCoords);
	cout << "*";
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
}

void Bullet::Draw() {
	Canva::GoToXY(bulletCoords.X, bulletCoords.Y, bulletCoords);
	cout << "*";
}

void Bullet::Erase() {
	Canva::GoToXY(bulletCoords.X, bulletCoords.Y, bulletCoords);
	cout << " ";
}