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


void gotoxy(int x, int y);
void color(int color);
int evaluarInt(int max, int min);
void pause();
void cls();
#endif // !TOOLS_H

