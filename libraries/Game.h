#pragma once
#include "InputManager.h"
#include "InvaderManager.h"
#include "BulletManager.h"
#include "Canva.h"
#include "Player.h"

class Game
{
private:
	InputManager inputManager;
	InvaderManager invaderManager;
	BulletManager bulletManager;
	Canva canva;
	Player player;
public:
	Game();
	int Run();
	void End();
};

