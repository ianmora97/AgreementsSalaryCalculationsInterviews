#ifndef ADMINISTRACION_H
#define ADMINISTRACION_H

#define CO "Corto"
#define LA "Largo"
#define INDEF "Indefinido"

#define MAX 100
#include "contrato.h"

using namespace std;

class administracion { // Departamento de Recursos Humanos (RRHH)
public:
	administracion(int = MAX);
	virtual ~administracion();

	virtual void eliminaUnContrato(string, string);

	virtual contrato* getContrato(int);
	virtual int getTam() const;
	virtual int getCant();

	virtual string calculaVacaciones(contrato*);
	virtual void agregarContrato();

private:
	contrato** _contratos;
	int _tam, _cant;
};

#endif // !ADMINISTRACION_H
