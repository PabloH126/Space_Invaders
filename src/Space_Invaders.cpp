#include "../libraries/Game.h"
#include <conio.h>

using namespace std;

bool Menu(int);
void DrawTitle(int, int, COORD&);
void DrawPerdiste(int, int, COORD&);
void DrawGanaste(int, int, COORD&);
void DrawCounter();
void DrawMenu(int);
void DrawSigns(int);

int main()
{
	int typeMenu = 1;
	if (Menu(typeMenu))
	{
		do {
			Game game;
			typeMenu = game.Run();
		} while (Menu(typeMenu));
	};
}

bool Menu(int isStart) {

	DrawMenu(isStart);

	COORD coords = { 0, 0 };
	Canva::GoToXY(64, 24, coords);
	cout << "<";

	char input;

	while ((input = _getch()) != 13) {
		input = toupper(input);

		switch (input) {
		case 83:
			if (!(coords.Y == 26)) {
				Canva::GoToXY(64, 24, coords);
				cout << " ";
				Canva::GoToXY(61, 26, coords);
				cout << "<";
			}
			break;
		case 87:
			if (!(coords.Y == 24)) {
				Canva::GoToXY(61, 26, coords);
				cout << " ";
				Canva::GoToXY(64, 24, coords);
				cout << "<";
			}
		}
	}

	system("cls");

	if (coords.Y == 24) {
		DrawCounter();
		return true;
	}
	else {
		return false;
	}
}

void DrawMenu(int typeMenu) {
	DrawSigns(typeMenu);
	COORD coords = { 0 , 0 };

	Canva::GoToXY(51, 24, coords);
	typeMenu ? cout << "Empezar juego" : cout << "Reintentarlo!";

	Canva::GoToXY(56, 26, coords);
	cout << "Salir";
}

void DrawSigns(int signOption) {
	int x = 20, y = 15;
	COORD coords = { 0 , 0 };

	system("cls");
	if (signOption == 2) {
		DrawGanaste(x, y, coords);
	}
	else {
		signOption ? DrawTitle(x, y, coords) : DrawPerdiste(x, y, coords);
	}
}

void DrawTitle(int x, int y, COORD &coords) {
	Canva::GoToXY(x, y, coords);
	cout << "   _____                        _____                     _               " << endl;
	Canva::GoToXY(x, y + 1, coords);
	cout << "  / ____|                      |_   _|                   | |              " << endl;
	Canva::GoToXY(x, y + 2, coords);
	cout << " | (___  _ __   __ _  ___ ___    | |  _ ____   ____ _  __| | ___ _ __ ___ " << endl;
	Canva::GoToXY(x, y + 3, coords);
	cout << "  \\___ \\| '_ \\ / _` |/ __/ _ \\   | | | '_ \\ \\ / / _` |/ _` |/ _ | '__/ __|" << endl;
	Canva::GoToXY(x, y + 4, coords);
	cout << "  ____) | |_) | (_| | (_|  __/  _| |_| | | \\ V | (_| | (_| |  __| |  \\__ \\" << endl;
	Canva::GoToXY(x, y + 5, coords);
	cout << " |_____/| .__/ \\__,_|\\___\\___| |_____|_| |_|\\_/ \\__,_|\\__,_|\\___|_|  |___/" << endl;
	Canva::GoToXY(x, y + 6, coords);
	cout << "        |_|                                                              " << endl;
}

void DrawPerdiste(int x, int y, COORD &coords) {
	Canva::GoToXY(x+10, y, coords);
	std::cout << "  _____  ______ _____  _____ _____  _____ _______ ______ " << std::endl;
	Canva::GoToXY(x+10, y + 1, coords);
	std::cout << " |  __ \\|  ____|  __ \\|  __ \\_   _|/ ____|__   __|  ____|" << std::endl;
	Canva::GoToXY(x+10, y + 2, coords);
	std::cout << " | |__) | |__  | |__) | |  | || | | (___    | |  | |__   " << std::endl;
	Canva::GoToXY(x+10, y + 3, coords);
	std::cout << " |  ___/|  __| |  _  /| |  | || |  \\___ \\   | |  |  __|  " << std::endl;
	Canva::GoToXY(x+10, y + 4, coords);
	std::cout << " | |    | |____| | \\ \\| |__| || |_ ____) |  | |  | |____ " << std::endl;
	Canva::GoToXY(x+10, y + 5, coords);
	std::cout << " |_|    |______|_|  \\_\\_____/_____|_____/   |_|  |______|" << std::endl;
}

void DrawGanaste(int x, int y, COORD& coords) {
	Canva::GoToXY(x + 10, y, coords);
	std::cout << "   _____          _   _           _____ _______ ______ " << std::endl;
	Canva::GoToXY(x + 10, y + 1, coords);
	std::cout << "  / ____|   /\\   | \\ | |   /\\    / ____|__   __|  ____|" << std::endl;
	Canva::GoToXY(x + 10, y + 2, coords);
	std::cout << " | |  __   /  \\  |  \\| |  /  \\  | (___    | |  | |__   " << std::endl;
	Canva::GoToXY(x + 10, y + 3, coords);
	std::cout << " | | |_ | / /\\ \\ | . ` | / /\\ \\  \\___ \\   | |  |  __|  " << std::endl;
	Canva::GoToXY(x + 10, y + 4, coords);
	std::cout << " | |__| |/ ____ \\| |\\  |/ ____ \\ ____) |  | |  | |____ " << std::endl;
	Canva::GoToXY(x + 10, y + 5, coords);
	std::cout << "  \\_____/_/    \\_\\_| \\_/_/    \\_\\_____/   |_|  |______|" << std::endl;
}

void DrawCounter() {
	int x = 55, y = 15;
	COORD coords = { 0 , 0 };

	Canva::GoToXY(x, y, coords);
	cout << "  ____  " << endl;
	Canva::GoToXY(x, y + 1, coords);
	cout << " |___ \\ " << endl;
	Canva::GoToXY(x, y + 2, coords);
	cout << "   __) |" << endl;
	Canva::GoToXY(x, y + 3, coords);
	cout << "  |__ < " << endl;
	Canva::GoToXY(x, y + 4, coords);
	cout << "  ___) |" << endl;
	Canva::GoToXY(x, y + 5, coords);
	cout << " |____/ " << endl;

	Sleep(1000);
	system("cls");

	Canva::GoToXY(x, y, coords);
	std::cout << "  ___  " << std::endl;
	Canva::GoToXY(x, y + 1, coords);
	std::cout << " |__ \\ " << std::endl;
	Canva::GoToXY(x, y + 2, coords);
	std::cout << "    ) |" << std::endl;
	Canva::GoToXY(x, y + 3, coords);
	std::cout << "   / / " << std::endl;
	Canva::GoToXY(x, y + 4, coords);
	std::cout << "  / /_ " << std::endl;
	Canva::GoToXY(x, y + 5, coords);
	std::cout << " |____|" << std::endl;

	Sleep(1000);
	system("cls");

	Canva::GoToXY(x, y, coords);
	std::cout << "  __  " << std::endl;
	Canva::GoToXY(x, y + 1, coords);
	std::cout << " /_ | " << std::endl;
	Canva::GoToXY(x, y + 2, coords);
	std::cout << "  | | " << std::endl;
	Canva::GoToXY(x, y + 3, coords);
	std::cout << "  | | " << std::endl;
	Canva::GoToXY(x, y + 4, coords);
	std::cout << "  | | " << std::endl;
	Canva::GoToXY(x, y + 5, coords);
	std::cout << "  |_| " << std::endl;

	Sleep(1000);
	system("cls");

}