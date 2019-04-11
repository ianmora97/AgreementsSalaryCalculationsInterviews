#ifndef CONTSERVICIOS_H
#define CONTSERVICIOS_H

#include "contrato.h"

using namespace std;

class contServicios : public contrato {
public:
	contServicios(fecha*, puesto*);
	virtual ~contServicios();
	virtual int getCargasSociales() const { return 1; }
	virtual int getImpuestos() { return 1; }
	virtual void setFechaCese(fecha*);
	virtual puesto* getPuesto();
	virtual fecha* getFechaIngreso();
	virtual fecha* getFechaCese() const;

	virtual string toString();
	virtual string getTipo() { return "Servicios"; }
private:
	fecha* fechaIngreso;
	fecha* fechaCese;
	puesto* _puesto;
};

#endif // !CONTSERVICIOS_H