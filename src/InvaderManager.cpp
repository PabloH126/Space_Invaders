#include "../libraries/InvaderManager.h"
#include <vector>
#include <iostream>
#include <thread>

using namespace std;

InvaderManager::InvaderManager(BulletManager* gameBulletManager) {
	step = 0;
	row = 0;
	border = false;
	isReverse = false;
	threadStopped = false;
	bulletManager = gameBulletManager;

	DrawInvaders();
}

void InvaderManager::UpdateInvaders() {
	while (!threadStopped) {
		if (!isReverse) {
			if (step < 10 && !border) {
				MoveInvaders(1);
				step++;
			}
			else if (step == 10 || step == 0) {
				MoveInvaders(2);
				row++;
				if (row == 13) {
					isReverse = true;
				}
				if (step == 10) {
					border = true;
					step--;
					MoveInvaders(3);
				}
				else {
					border = false;
					step++;
					MoveInvaders(1);
				}
			}
			else {
				MoveInvaders(3);
				step--;
			}
		}
		else {
			if (step > 0 && border) {
				MoveInvaders(3);
				step--;
			}
			else if (step == 0 || step == 10) {
				MoveInvaders(4);
				row--;
				if (row == 0) {
					isReverse = false;
				}
				else if (step == 0) {
					border = false;
					step++;
					MoveInvaders(1);
				}
				else {
					border = true;
					step--;
					MoveInvaders(3);
				}
			}
			else {
				MoveInvaders(1);
				step++;
			}
		}
		InvaderShoot();
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

vector<Invader>& InvaderManager::GetInvaders() {
	return invaders;
}

void InvaderManager::InvaderShoot() {
	int invaderIndex = 0;
	Invader* invaderShooting = nullptr;
	do {
		invaderIndex = rand() % invaders.size();
		invaderShooting = &invaders[invaderIndex];
	} while (invaderShooting->isDestroyed);

	bulletManager->Shoot(true, *invaderShooting);
}