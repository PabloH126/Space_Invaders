#include "../libraries/InputManager.h"
#include <iostream>
#include <conio.h>
#include "../libraries/Player.h"

using namespace std;

void InputManager::HandleInput(Player& player) {
	if (_kbhit()) {
		char opt = _getch();
		opt = toupper(opt);

		if (opt == 32) {
			player.Shoot();
		}
		else if (opt == 65 || opt == 68){
			player.Move(opt);
		}
	}
}