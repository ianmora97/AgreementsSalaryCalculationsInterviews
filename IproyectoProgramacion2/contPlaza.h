#ifndef CONTPLAZA_H
#define CONTPLAZA_H

#include "fecha.h"
#include "puesto.h"
using namespace std;

class contPlaza {
public:
	contPlaza();
	virtual ~contPlaza();

	virtual string toString();

	virtual float cargasSociales();
	virtual float ahorroObligatorio();
	virtual float impuestoSobrelaRenta();

	virtual float getAguinaldo();
	virtual string getCategoria();

	virtual puesto* getPuesto();
	virtual string getPropietario();
	virtual int getVacaciones();
	virtual void setVacaciones(int v);
	virtual fecha* getFechaIngreso();

private:

	float aguinaldo;
	string categoriaLaboral;
	fecha* fechaIngreso;
	fecha* fechaCese;
	string propietario;
	int vaciones;
};

#endif // !CONTPLAZA_H