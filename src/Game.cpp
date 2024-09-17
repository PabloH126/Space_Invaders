#include "../libraries/Game.h"
#include <thread>
#include <algorithm>

using namespace std;

Game::Game(): invaderManager(&bulletManager), inputManager(&bulletManager, &player) {
	thread invadersManagerThread(&InvaderManager::UpdateInvaders, &invaderManager);
	invadersManagerThread.detach();
}
int Game::Run() {
	bool allInvadersDestroyed = true;
	do {
		inputManager.HandleInput();
		bulletManager.MoveBullets(invaderManager.GetInvaders(), player);
		vector<Invader> invaders = invaderManager.GetInvaders();
		allInvadersDestroyed = all_of(invaders.begin(), invaders.end(), [](const Invader& invader) { return invader.isDestroyed; });
		Sleep(30);
	} while (!player.isDestroyed && !allInvadersDestroyed);
	End();
	return (player.isDestroyed) ? 0 : 2; //Si el jugador perdió, devuelve 0, si ganó, devuelve 2
}

void Game::End() {
	invaderManager.threadStopped = true;
}



