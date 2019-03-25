#ifndef CONTSERVICIOS_H
#define CONTSERVICIOS_H

#include "contrato.h"
using namespace std;

class contServicios : public contrato {
public:
	contServicios(fecha*, string, puesto*);
	virtual ~contServicios();

	virtual puesto* getPuesto();
	virtual string getPropietario();
	virtual int getVacaciones();
	virtual void setVacaciones(int v);
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