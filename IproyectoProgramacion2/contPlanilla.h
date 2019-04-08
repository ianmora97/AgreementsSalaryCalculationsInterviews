#ifndef CONTPLANILLA_H
#define CONTPLANILLA_H

#include "contrato.h"

using namespace std;

class contPlanilla : public contrato{
public:
	contPlanilla(fecha*,float,puesto*);
	virtual ~contPlanilla();

	virtual float cargasSociales();
	virtual float ahorroObligatorio();
	virtual float impuestoSobrelaRenta();
	virtual void setVacaciones(int v);
	virtual float getAguinaldo();
	virtual int getVacaciones();

	//metodos virtuales puros
	virtual puesto* getPuesto();
	virtual void setFechaCese(fecha* f);
	virtual fecha* getFechaIngreso();
	virtual string toString();

private:

	int cant;
	puesto* _puesto;
	int vacaciones;
	float aguinaldo;
	fecha* fechaIngreso;
	fecha* fechaCese;
};

#endif // !CONTPLANILLA_H