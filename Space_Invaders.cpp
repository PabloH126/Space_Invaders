// Space_Invaders.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Canva.h"
#include "Invader.h"
#include "Cover.h"
#include "Player.h"
#include "InvaderManager.h"
#include <thread>
#include <mutex>
#include "CoversManager.h"
#include "InputManager.h"

using namespace std;

mutex consoleMutex;

float frameTime(1000 / 60);
void updateThreadInvaders(InvaderManager& iM) {
    while (true) {
        iM.UpdateInvaders();
        consoleMutex.lock();
        Sleep(1000);
        consoleMutex.unlock();
    }
}

int main()
{
    Canva canvas;
    
    InvaderManager invaderManager;
    Player player;
    CoversManager coverManager;
    InputManager inputManager;
    
    canvas.DrawCanva();
    thread invadersThread(updateThreadInvaders, ref(invaderManager));
    
    while (true) {
        inputManager.HandleInput(player);
        Sleep(frameTime);
    }
    cout << endl << endl << endl;
    system("pause");
}






// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
