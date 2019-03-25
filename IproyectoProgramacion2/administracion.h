#ifndef ADMINISTRACION_H
#define ADMINISTRACION_H

#define CO "Corto"
#define LA "Largo"
#define INDEF "Indefinido"

#include "coleccionContratos.h"

using namespace std;

class administracion { // Departamento de Recursos Humanos (RRHH)
public:
	administracion();
	virtual ~administracion();

	virtual void setFechaActual(fecha*);
	virtual coleccionContratos* getColeccion();
	virtual void calculaVacaciones(contrato*);

private:
	coleccionContratos* contratos;
	fecha* fechaActual;
};

#endif // !ADMINISTRACION_H
