#ifndef TOOLS_H
#define TOOLS_H

#define VACIO "Vacio"
#define TAB '\t'
#define FIN '\n'

#define LLENO "Vector Lleno"

#include <iostream>
#include <sstream>
#include <string>
#include <time.h>
#include <Windows.h>
#include <fstream>
#include <iomanip>

using namespace std;


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
	if (!(cin >> valor)) {
		cin.clear();
		cin.ignore(1024, '\n');
		throw 1;
	}
	else {
		if ((valor >= min) && (valor <= max)) {
			cin.clear();
			cin.ignore(1024, '\n');	
		}
		else {
			cin.clear();
			cin.ignore(1024, '\n');
			throw 1;
		}
	}
	return valor;
}
#endif // !TOOLS_H

