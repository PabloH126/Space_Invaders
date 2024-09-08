#pragma once
#include "Entity.h"
class Cover: public Entity
{

public:
	Cover(int coverNumber);
	void Draw() override;
	void Draw50();
	void Draw10();
	void Erase();

	void Move() override;
    void Move(char input) override;
};

