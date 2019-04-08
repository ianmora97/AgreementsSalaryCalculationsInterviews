#ifndef COLECCIONCONTRATOS_H
#define COLECCIONCONTRATOS_H

#include "tools.h"
#include "contrato.h"
#include "contPlaza.h"
#include "contPlanilla.h"
#include "contServicios.h"
using namespace std;

class coleccionContratos{
public:
	coleccionContratos(int = 100);
	virtual ~coleccionContratos();

	bool vacio();
	bool hayCampo();
	void agregar(contrato*);
	void eliminaUno(string);

	int getCant();
	int getTam();
	contrato* getContrato(int i);

	string toString();
private:
	contrato** contratos;
	int cant, tam;
};
#endif // !COLECCIONCONTRATOS_H