#ifndef CONTRATO_H
#define CONTRATO_H

#include "tools.h"

#include "fecha.h"
#include "puesto.h"

using namespace std;

class contrato {
public:
	contrato();
	virtual	~contrato();

	virtual float cargasSociales() = 0;
	virtual float ahorroObligatorio() = 0;
	virtual float impuestoSobrelaRenta() = 0;

	virtual void setVacaciones(int v) = 0;
	virtual void setFechaCese(fecha*) = 0;

	virtual float getAguinaldo() = 0;
	virtual puesto* getPuesto() = 0;
	virtual string getPropietario() = 0;
	virtual int getVacaciones() = 0;
	virtual fecha* getFechaIngreso() = 0;

	virtual string toString() = 0;
	
};
#endif // !CONTRATO_H