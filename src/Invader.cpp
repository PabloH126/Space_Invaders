#include "../libraries/Invader.h"
#include "../libraries/Canva.h"
#include <iostream>
using namespace std;

Invader::Invader(int typeInvader, COORD initCoords) {
	type = typeInvader;

    switch (type) {
    case 1: SetHealth(150);
        break;
    case 2: SetHealth(100);
        break;
    case 3: SetHealth(50);
        break;
    }
    SetCoords(initCoords);
    Draw();
}

void Invader::Draw() {
    COORD coords = GetCoords();
    COORD initCoords = coords;
    Canva::GoToXY(coords.X, coords.Y, coords);
    cout << char(32) << char(201) << char(205) << char(205) << char(205) << char(187) << char(32);
    Canva::GoToXY(coords.X, coords.Y + 1, coords);
    cout << char(32) << char(204) << char(203) << char(203) << char(203) << char(185) << char(32);
    Canva::GoToXY(coords.X, coords.Y + 1, coords);
    cout << char(174) << char(35) << char(35) << char(35) << char(35) << char(35) << char(175);
    Canva::GoToXY(coords.X, coords.Y + 1, coords);
    cout << char(94) << char(32) << char(32) << char(94) << char(32) << char(32) << char(94);
    Canva::GoToXY(initCoords.X, initCoords.Y, coords);
}

void Invader::Move(char optMove) {
    COORD coords = GetCoords();
    Erase();
    switch (optMove) {
    case 1: UpdatePos(coords.X + 1, coords.Y);
        break;
    case 2: UpdatePos(coords.X, coords.Y + 1);
        break;
    case 3: UpdatePos(coords.X - 1, coords.Y);
    }
};

void Invader::UpdatePos(int x, int y) {
    COORD coords = { x, y };
    SetCoords(coords);
    Draw();
}
void Invader::Move() {};


