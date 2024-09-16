#pragma once
#include <vector>
#include <iostream>
#include "Invader.h"
#include "BulletManager.h"

using namespace std;
class InvaderManager
{
private:
	vector<Invader> invaders;
	BulletManager* bulletManager;
	int step;
	int border;
	void MoveInvaders(int move);
public:
	InvaderManager(BulletManager* gameBulletManager);

	bool threadStopped;

	vector<Invader>& GetInvaders();
	void UpdateInvaders();
	void DrawInvaders();
	void InvaderShoot();
};

