#include "tools.h"

void gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

void color(int color) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); }

int evaluarInt(int max, int min) {
	int valor;
	cout << " > ";
	bool ciclo = true;
	while (ciclo) {
		if (!(cin >> valor)) {
			cin.clear();
			cin.ignore(1024, '\n');
			throw 1;
		}
		else {
			if ((valor >= min) && (valor <= max)) {
				cin.clear();
				cin.ignore(1024, '\n');
				ciclo = false;
			}
			else {
				cin.clear();
				cin.ignore(1024, '\n');
				throw 1;
			}
		}
	}
	return valor;
}

void pause() { system("pause"); }
void cls() { system("cls"); }

