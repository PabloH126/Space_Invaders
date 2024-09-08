#include "InvaderManager.h"
#include <vector>
#include <iostream>
#include <thread>

using namespace std;

InvaderManager::InvaderManager() {
	step = 0;
	border = false;
	threadStopped = false;
}

void InvaderManager::UpdateInvaders() {
	while (!threadStopped) {
		if (step < 10 && !border) {
			MoveInvaders(1);
			step++;
		}
		else if (step == 10 || step == 0) {
			MoveInvaders(2);
			if (step == 10) {
				border = true;
				step--;
				MoveInvaders(3);
			}
			else
			{
				border = false;
				step++;
				MoveInvaders(1);
			}
		}
		else {
			MoveInvaders(3);
			step--;
		}
		Sleep(1000);
	}
}

void InvaderManager::MoveInvaders(int move) {
	for (Invader& invader : invaders) {
		invader.Move(move);
	}
}

void InvaderManager::DrawInvaders() {
	for (int columns = 0; columns < 6; columns++) {
		for (int rows = 0; rows < 3; rows++) {
			COORD invaderInitCoords = { 8 + columns * 16, 4 + rows * 5 };
			invaders.emplace_back(rows + 1, invaderInitCoords);
		}
	}
}