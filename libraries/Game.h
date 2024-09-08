#pragma once
#include "InputManager.h"
#include "InvaderManager.h"
#include "Canva.h"
#include "Player.h"

class Game
{
private:
	InputManager inputManager;
	InvaderManager invaderManager;
	Canva canva;
	Player player;
public:
	Game();
	void Run();
	void End();
};

