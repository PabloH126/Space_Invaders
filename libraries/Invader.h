#pragma once
#include "Entity.h"
class Invader : public Entity 
{
private: 
	int type;
	void UpdatePos(int x, int y);
public:
	Invader(int typeInvader, COORD initCoords);

	bool isDestroyed;

	void Draw() override;
	void Move() override;
	void Move(char optMove) override;
};

