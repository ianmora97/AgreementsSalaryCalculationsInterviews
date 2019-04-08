#ifndef COLECCIONPUESTOS_H
#define COLECCIONPUESTOS_H

#include "puesto.h"
using namespace std;

class coleccionPuestos {
public:
	coleccionPuestos(int = 100);
	virtual ~coleccionPuestos();

	bool vacio();
	bool hayCampo();
	void agregar(puesto*);
	void eliminaUno(string);

	int getCant();
	int getTam();
	puesto* getPuesto(int i);

	string toString();
private:
	puesto** puestos;
	int cant, tam;
};

#endif // !COLECCIONPUESTOS_H