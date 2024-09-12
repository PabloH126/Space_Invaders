#pragma once
#include <Windows.h>
class Entity
{
private:
    int health;
    COORD coord = { 0, 0 };
public:
    Entity();

    bool isDestroyed;

    void SetHealth(const int& newHealth);
    int GetHealth();
    COORD GetCoords();
    void SetCoords(COORD newCoords);
    void Death(int x, int y);
    void Erase();

    virtual void Move() = 0;
    virtual void Move(char input) = 0;
    virtual void Draw() = 0;
};

