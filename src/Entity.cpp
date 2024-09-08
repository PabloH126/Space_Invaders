#include "../libraries/Entity.h"
#include "../libraries/Canva.h"
#include <iostream>
using namespace std;

Entity::Entity() {
    health = 100;
}

void Entity::SetHealth(const int& newHealth) {
    health = newHealth;
}

int Entity::GetHealth() {
    return health;
}

COORD Entity::GetCoords() {
    return coord;
}

void Entity::SetCoords(COORD newCoords) {
    coord = newCoords;
}

void Entity::Death(int x, int y) {
    Canva::GoToXY(x, y, coord);
    cout << "'.\\|/.'" << endl;
    Canva::GoToXY(x, y + 1, coord);
    cout << " (\\ /) " << endl;
    Canva::GoToXY(x, y + 2, coord);
    cout << "- -O- -" << endl;
    Canva::GoToXY(x, y + 3, coord);
    cout << ",'/|\\'." << endl;
    Sleep(200);
    Erase();
}

void Entity::Erase() {
    int initX = coord.X;
    int initY = coord.Y;
    Canva::GoToXY(coord.X, coord.Y, coord);
    cout << "       ";
    Canva::GoToXY(coord.X, coord.Y+1, coord);
    cout << "       ";
    Canva::GoToXY(coord.X, coord.Y+1, coord);
    cout << "       ";
    Canva::GoToXY(coord.X, coord.Y+1, coord);
    cout << "       ";
    Canva::GoToXY(initX, initY, coord);
}