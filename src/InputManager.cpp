#include "../libraries/InputManager.h"
#include <iostream>
#include <conio.h>

using namespace std;

void InputManager::HandleInput(Player &player, BulletManager &bulletManager) {
	if (_kbhit()) {
		char opt = _getch();
		opt = toupper(opt);

		if (opt == 32) {
			bulletManager.Shoot(false, player);
		}
		else if (opt == 65 || opt == 68){
			player.Move(opt);
		}
	}
}