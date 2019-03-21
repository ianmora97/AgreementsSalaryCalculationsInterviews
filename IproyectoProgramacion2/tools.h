#ifndef TOOLS_H
#define TOOLS_H

#define VACIO "Vacio"
#define TAB '\t'
#define FIN '\n'

#include <iostream>
#include <sstream>
#include <string>
#include <time.h>
#include <Windows.h>
#include <fstream>

using namespace std;

void color(int c) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c);} //para mostrar colores

string toUpper(string palabra) { //para poder pasar todo a mayusculas si es necesario
	for (int i = 0; i < palabra.length(); i++) {
		palabra[i] = toupper(palabra[i]);
	}
	return palabra;
}

int evaluarInt(int max, int min) {  //evalua un numero entero, por parametros recibe el rango
	int valor = NULL;               //en el que se pueda evaluar un entero
	bool ciclo = true;
	while (ciclo == true) {
		cout << " > ";
		if (!(cin >> valor)) {
			cin.clear();
			cin.ignore(1024, '\n');
			ciclo = true;
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
				ciclo = true;
			}
		}
	}
	return valor;
}

void pause() {
	cin.ignore();
	cin.get();
}
void cls() {
	system("cls");
}




#endif // !TOOLS_H

