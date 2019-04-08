#ifndef CONTSERVICIOS_H
#define CONTSERVICIOS_H

#include "contrato.h"

using namespace std;

class contServicios : public contrato {
public:
	contServicios(fecha*, puesto*);
	virtual ~contServicios();

	virtual void setFechaCese(fecha*);
	virtual puesto* getPuesto();
	virtual fecha* getFechaIngreso();

	virtual string toString();

private:
	fecha* fechaIngreso;
	fecha* fechaCese;
	puesto* _puesto;

	int vacaciones;
};

#endif // !CONTSERVICIOS_H