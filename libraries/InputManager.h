#pragma once
#include "Player.h"
#include "BulletManager.h"

class InputManager
{
private:
	BulletManager* bulletManager;
	Player* player;
public:
	InputManager(BulletManager* gameBulletManager, Player* gamePlayer);
	void HandleInput();
};

