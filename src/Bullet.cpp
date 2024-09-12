#include "../libraries/Bullet.h"

using namespace std;

const char bulletTrue = char(42);
const char bulletFalse = char(00);
const char bulletMovement = char(32);

Bullet::Bullet(COORD entityCoords, bool typeInvader) {
	isInvader = typeInvader;
	bulletDamage = 50;
	bulletDestroyed = false;

	Spawn(entityCoords, typeInvader);
}

void Bullet::Move() {
	if (!bulletDestroyed) {
		if (isInvader && bulletCoords.Y < 36) {
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
	Erase();
	Canva::GoToXY(0, 0, bulletCoords);
	cout << bulletFalse;
}

void Bullet::Spawn(COORD entityCoords, bool isNewInvader) {
	int x = entityCoords.X + 3, y;
	isInvader = isNewInvader;
	isInvader ? y = entityCoords.Y + 4 : y = entityCoords.Y - 1;

	Canva::GoToXY(x, y, bulletCoords);
	Draw();
}

void Bullet::Impact(Entity &entity) {
	COORD entityCoords = entity.GetCoords();
	int newEntityHealth = entity.GetHealth() - bulletDamage;
	if (CheckCoords(entityCoords) && !entity.isDestroyed) {
		entity.SetHealth(newEntityHealth);
		if (newEntityHealth == 0) {
			entity.isDestroyed = true;
			entity.Death(entityCoords.X, entityCoords.Y);
		}

		COORD coords = { 0, 0 };
		Canva::GoToXY(1, 2, coords);
		bulletDestroyed = true;
		Reset();
	}
}



bool Bullet::CheckCoords(COORD entityCoords) {
	if ((bulletCoords.X >= entityCoords.X && bulletCoords.Y >= entityCoords.Y) && 
		(bulletCoords.X <= entityCoords.X+6 && bulletCoords.Y <= entityCoords.Y+3))
	{
		return true;
	}

	return false;
}

