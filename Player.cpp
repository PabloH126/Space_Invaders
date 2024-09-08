#include "Player.h"
#include "Canva.h"
#include "Bullet.h"
#include <iostream>
#include <vector>

using namespace std;

Player::Player() {
    COORD initCoords = { 52, 32 };
    SetCoords(initCoords);
    Draw();
}

void Player::Move(char input) {
    COORD coord = GetCoords();

    (input == 65) ? coord.X-- : coord.X++;

    if (coord.X > 5 && coord.X+7 < 105) {
        Erase();
        SetCoords(coord);
        Draw();
    }
}


void Player::Draw() {
    COORD coords = GetCoords();
    COORD initCoords = coords;
    Canva::GoToXY(coords.X, coords.Y, coords);
    cout << char(32) << char(32) << char(32) << char(94) << char(32) << char(32) << char(32) << endl;
    Canva::GoToXY(coords.X, coords.Y + 1, coords);
    cout << char(32) << char(32) << char(201) << char(32) << char(187) << char(32) << char(32) << endl;
    Canva::GoToXY(coords.X, coords.Y + 1, coords);
    cout << char(174) << char(35) << char(35) << char(35) << char(35) << char(35) << char(175) << endl;
    Canva::GoToXY(coords.X, coords.Y + 1, coords);
    cout << char(94) << char(32) << char(32) << char(94) << char(32) << char(32) << char(94) << endl;
    Canva::GoToXY(initCoords.X, initCoords.Y, coords);
}

void Player::Shoot() {
    COORD coords = GetCoords();
    bulletsFired.push_back(new Bullet(coords, false));
}

void Player::MoveBullets() {
    for (it = bulletsFired.begin(); it != bulletsFired.end(); it++) {
        (*it)->Move();
    }
}

void Player::Move() {};


