#pragma once
#include "Entity.h"
#include "Bullet.h"
#include "Invader.h"
#include <vector>
#include <iostream>

using namespace std;

class Player : public Entity
{
private:
	int score;
public:	
	Player();
	int GetScore();
	void SetScore(int newScore);
	void UpdateHealth();
	void UpdateScore();
	void Move(char input) override;
	void Draw() override;
	void Move();
};

