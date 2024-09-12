#pragma once
#include "Player.h"
#include "BulletManager.h"

class InputManager
{
public:
	void HandleInput(Player &player, BulletManager &bulletManager);
};

