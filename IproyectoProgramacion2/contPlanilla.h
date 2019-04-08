#ifndef CONTPLANILLA_H
#define CONTPLANILLA_H


#include "fecha.h"
#include "puesto.h"
using namespace std;

class contPlanilla{
public:
	contPlanilla(fecha*,string ,float,puesto*);
	virtual ~contPlanilla();

	virtual float cargasSociales();
	virtual float ahorroObligatorio();
	virtual float impuestoSobrelaRenta();

	virtual void setFechaCese(fecha* f);
	virtual void setVacaciones(int v);


	virtual float getAguinaldo();
	virtual puesto* getPuesto();
	virtual string getPropietario();
	virtual int getVacaciones();
	virtual fecha* getFechaIngreso();

	virtual string toString();

private:

	int cant;
	puesto* _puesto;
	int vacaciones;
	float aguinaldo;
	fecha* fechaIngreso;
	fecha* fechaCese;
	string propietario;
};

#endif // !CONTPLANILLA_H