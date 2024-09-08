#include "../libraries/Game.h"
#include "../libraries/InputManager.h"
#include "../libraries/InvaderManager.h"
#include "../libraries/Canva.h"
#include "../libraries/Player.h"
#include <thread>

using namespace std;

Game::Game() {
	canva.DrawCanva();
	invaderManager.DrawInvaders();
	thread invadersManagerThread(&InvaderManager::UpdateInvaders, &invaderManager);
	invadersManagerThread.detach();
}
void Game::Run() {
	while (player.GetHealth() != 0) {
		inputManager.HandleInput(player);
		player.MoveBullets();
		Sleep(30);
	}
	End();
}

void Game::End() {
	invaderManager.threadStopped = true;
}