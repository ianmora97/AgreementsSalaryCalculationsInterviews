#ifndef CONTSERVICIOS_H
#define CONTSERVICIOS_H

#include "contrato.h"

using namespace std;

class contServicios : public contrato {
public:
	contServicios(fecha*, string, puesto*);
	virtual ~contServicios();

	virtual void setFechaCese(fecha*);
	virtual puesto* getPuesto();
	virtual string getPropietario();
	virtual fecha* getFechaIngreso();

	virtual string toString();

private:
	fecha* fechaIngreso;
	fecha* fechaCese;
	puesto* _puesto;
	string propietario;
	int vacaciones;
};

#endif // !CONTSERVICIOS_H