#include "../libraries/Game.h"
#include <thread>

using namespace std;

Game::Game(): invaderManager(&bulletManager), inputManager(&bulletManager, &player) {
	thread invadersManagerThread(&InvaderManager::UpdateInvaders, &invaderManager);
	invadersManagerThread.detach();
}
void Game::Run() {
	while (!player.isDestroyed) {
		inputManager.HandleInput();
		bulletManager.MoveBullets(invaderManager.GetInvaders(), player);
		Sleep(30);
	}
	End();
}

void Game::End() {
	invaderManager.threadStopped = true;
}



