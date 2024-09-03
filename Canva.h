#pragma once
#include <Windows.h>
class Canva
{
private:
    int width;
    int height;
    COORD borders = {0, 0};
    void DrawCorners(int x, int y, int caracter);
public:
    Canva();
    void DrawCanva();
    static void GoToXY(const int x, const int y, COORD &coords);
};

