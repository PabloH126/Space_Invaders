#include "../libraries/Player.h"
#include "../libraries/Canva.h"
#include "../libraries/Bullet.h"
#include "../libraries/Invader.h"
#include <iostream>
#include <vector>

using namespace std;

Player::Player() {
    score = 0;
    COORD initCoords = { 52, 32 };
    SetCoords(initCoords);
    
    UpdateHealth();
    UpdateScore();

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

int Player::GetScore() {
    return score;
}

void Player::SetScore(int newScore) {
    score = newScore;
    UpdateScore();
}

void Player::UpdateHealth() {
    int playerHealth = GetHealth();
    COORD coords = { 0, 0 };
    Canva::GoToXY(60, 2, coords);
    char heart = 3;

    switch (playerHealth) {
    case 99: cout << "Health: " << char(158) << char(158) << char(158);
        break;
    case 66: cout << "Health: " << char(158) << char(158) << " ";
        break;
    case 33: cout << "Health: " << char(158) << " " << " ";
        break;
    case 0: cout << "Health: " << " ";
        break;
    }
}

void Player::UpdateScore() {
    COORD coords = { 0, 0 };
    Canva::GoToXY(98, 2, coords);
    cout << "Score: " << score;
}
void Player::Move() {};


