#ifndef ADMINISTRACION_H
#define ADMINISTRACION_H

#define CO "Corto"
#define LA "Largo"
#define INDEF "Indefinido"

#include "contrato.h"
#include "coleccion.h"

using namespace std;

class administracion : public contrato { //esta es el departamento de recursos humanos (RRHH)
public:
	administracion();
	virtual ~administracion();

private:
	string _periodo;
	coleccion** _contratos;
};

#endif // !ADMINISTRACION_H