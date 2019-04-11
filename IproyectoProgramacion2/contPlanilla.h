#ifndef CONTPLANILLA_H
#define CONTPLANILLA_H

#include "contrato.h"


using namespace std;

class contPlanilla : public contrato{
public:
	contPlanilla(fecha*,puesto*);
	contPlanilla(contrato*);
	virtual ~contPlanilla();

	virtual int getCargasSociales() const { return 1; }
	virtual int getImpuestos() { return 1; }

	virtual void setVacaciones(int v);
	virtual float getAguinaldo();
	virtual int getVacaciones();


	//metodos virtuales puros
	virtual puesto* getPuesto();
	virtual void setFechaCese(fecha* f);
	virtual fecha* getFechaIngreso();
	virtual string toString();
	virtual fecha* getFechaCese() const;
	virtual string getTipo() { return "Planilla"; }
private:
	
	puesto* _puesto;
	int vacaciones;
	float aguinaldo;
	fecha* fechaIngreso;
	fecha* fechaCese;
};

#endif // !CONTPLANILLA_H