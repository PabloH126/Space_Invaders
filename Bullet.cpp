#include "Bullet.h"
#include "Canva.h"
#include <iostream>

using namespace std;

Bullet::Bullet(COORD entityCoords, bool isInvader) {
	bulletDamage = 50;
	int x = entityCoords.X + 3, y;
	isInvader ? y = entityCoords.Y + 4 : y = entityCoords.Y - 1;
	COORD initCoords = { x, y };
	Canva::GoToXY(x, y, bulletCoords);
	cout << "*";
}

void Bullet::Move() {
	Canva::GoToXY(bulletCoords.X, bulletCoords.Y, bulletCoords);
	cout << " ";
	isInvader ? bulletCoords.Y++ : bulletCoords.Y--;
	Canva::GoToXY(bulletCoords.X, bulletCoords.Y, bulletCoords);
	cout << "*";
}
