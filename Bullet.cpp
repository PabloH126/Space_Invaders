#include "Bullet.h"
#include "Canva.h"
#include <iostream>
#include <thread>

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
	thread MoveBulletThread(&Bullet::Move, this);
	MoveBulletThread.detach();
}

void Bullet::Move() {
	while (isInvader && bulletCoords.Y < 37) { 
		Erase();
		bulletCoords.Y++;
		Draw();
		Sleep(1000 / 60);
	}

	while (!isInvader && bulletCoords.Y > 4) { 
		Erase();
		bulletCoords.Y--; 
		Draw();
		Sleep(1000 / 2);
	}

	Destroy();
}

void Bullet::Draw() {
	Canva::GoToXY(bulletCoords.X, bulletCoords.Y, bulletCoords);
	cout << "*";
}

void Bullet::Erase() {
	Canva::GoToXY(bulletCoords.X, bulletCoords.Y, bulletCoords);
	cout << " ";
}

void Bullet::Destroy() {
	Erase();
	bulletDestroyed = true;
}

Bullet::~Bullet() {
	cout << "Bala destruida";
}
