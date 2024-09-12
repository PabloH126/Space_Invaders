#include "../libraries/InputManager.h"
#include <iostream>
#include <conio.h>

using namespace std;

InputManager::InputManager(BulletManager* gameBulletManager, Player* gamePlayer) {
	bulletManager = gameBulletManager;
	player = gamePlayer;
}

void InputManager::HandleInput() {
	if (_kbhit()) {
		char opt = _getch();
		opt = toupper(opt);

		if (opt == 32) {
			bulletManager->Shoot(false, *player);
		}
		else if (opt == 65 || opt == 68){
			player->Move(opt);
		}
	}
}