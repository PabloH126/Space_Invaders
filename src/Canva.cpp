#include "../libraries/Canva.h"
#include <windows.h>
#include <iostream>

using namespace std;

Canva::Canva() {
    width = 100;
    height = 34;
    DrawCanva();
}

void Canva::DrawCorners(int x, int y, int caracter) {
    GoToXY(x, y, borders);
    cout << char(caracter);
}

void Canva::GoToXY(const int x, const int y, COORD &coords) {
    coords.X = x;
    coords.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coords);
}

void Canva::DrawCanva() {
    DrawCorners(5, 3, 201);
    DrawCorners(105, 3, 187);
    DrawCorners(5, 37, 200);
    DrawCorners(105, 37, 188);

    for (int i = 0; i < width-1; i++) {
        GoToXY(6+i, 3, borders);
        cout << char(205);
        GoToXY(6+i, 37, borders);
        cout << char(205);
    }

    for (int i = 0; i < height-1; i++) {
        GoToXY(5, 4+i, borders);
        cout << char(186);
        GoToXY(105, 4+i, borders);
        cout << char(186);
    }
}