#ifndef CONTPLANILLA_H
#define CONTPLANILLA_H

#include "contrato.h"

using namespace std;

class contPlanilla : public contrato {
public:
	contPlanilla(fecha*,string ,float,puesto*);
	virtual ~contPlanilla();

	virtual float cargasSociales();
	virtual float ahorroObligatorio();
	virtual float impuestoSobrelaRenta();

	virtual void agregarAhorro(ahorro* a);

	virtual void setFechaCese(fecha* f);
	virtual void setVacaciones(int v);

	virtual ahorro* getAhorro();
	virtual float getAguinaldo();
	virtual puesto* getPuesto();
	virtual string getPropietario();
	virtual int getVacaciones();
	virtual fecha* getFechaIngreso();

	virtual string toString();

private:
	ahorro** ahorros;
	int cant;
	puesto* _puesto;
	int vacaciones;
	float aguinaldo;
	fecha* fechaIngreso;
	fecha* fechaCese;
	string propietario;
};

#endif // !CONTPLANILLA_H