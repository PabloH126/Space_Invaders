#pragma once
#include <vector>
#include <iostream>
#include "Invader.h"

using namespace std;
class InvaderManager
{
private:
	vector<Invader> invaders;
	int step;
	int border;
	void MoveInvaders(int move);
public:
	InvaderManager();

	bool threadStopped;

	void UpdateInvaders();
	void DrawInvaders();
};

