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

void color(int c) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c);} //para mostrar colores

string toUpper(string palabra) { //para poder pasar todo a mayusculas si es necesario
	for (int i = 0; i < palabra.length(); i++) {
		palabra[i] = toupper(palabra[i]);
	}
	return palabra;
}

int evaluarInt(int max, int min) {  //evalua un numero entero, por parametros recibe el rango
	int valor = NULL;               //en el que se pueda evaluar un entero
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
			throw 2;
				
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

