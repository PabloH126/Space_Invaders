#include "Cover.h"
#include "Canva.h"
#include <iostream>
using namespace std;

Cover::Cover(int coverNumber) {
    COORD newCoords = { 0,0 };
    switch (coverNumber) {
    case 1:
        newCoords = { 10, 27 };
        break;
    case 2:
        newCoords = { 30, 27 };
        break;
    case 3:
        newCoords = { 50, 27 };
        break;
    case 4:
        newCoords = { 70, 27 };
        break;
    case 5:
        newCoords = { 90, 27 };
        break;
    }
    SetCoords(newCoords);
    Draw();
}

void Cover::Draw() {
    COORD coords = GetCoords();
    Canva::GoToXY(coords.X, coords.Y, coords);
    cout << "   ****   ";
    Canva::GoToXY(coords.X, coords.Y+1, coords);
    cout << "**********";
    Canva::GoToXY(coords.X, coords.Y+1, coords);
    cout << "**********";
    Canva::GoToXY(coords.X, coords.Y+1, coords);
    cout << "***    ***";
    
}

void Cover::Draw50() {
    COORD coords = GetCoords();
    Canva::GoToXY(coords.X, 27, coords);
    cout << "   * **   ";
    Canva::GoToXY(coords.X, 28, coords);
    cout << "* ****** *";
    Canva::GoToXY(coords.X, 29, coords);
    cout << "********* ";
    Canva::GoToXY(coords.X, 30, coords);
    cout << "* *    ***";
    SetCoords(coords);
}

void Cover::Draw10() {
    COORD coords = GetCoords();
    Canva::GoToXY(coords.X, 27, coords);
    cout << "    * *   ";
    Canva::GoToXY(coords.X, 28, coords);
    cout << "* ** *  **";
    Canva::GoToXY(coords.X, 29, coords);
    cout << "*   **  * ";
    Canva::GoToXY(coords.X, 30, coords);
    cout << "* *     **";
    SetCoords(coords);
}

void Cover::Erase() {
    COORD coords = GetCoords();
    Canva::GoToXY(coords.X, 27, coords);
    cout << "          ";
    Canva::GoToXY(coords.X, 28, coords);
    cout << "          ";
    Canva::GoToXY(coords.X, 29, coords);
    cout << "          ";
    Canva::GoToXY(coords.X, 30, coords);
    cout << "          ";
    SetCoords(coords);
}

void Cover::Move() {};
void Cover::Move(char input) {};