#ifndef CONTPLAZA_H
#define CONTPLAZA_H

#include "contrato.h"

using namespace std;

class contPlaza : public contrato {
public:
	contPlaza();
	virtual ~contPlaza();

	virtual string toString();

	float cargasSociales();
	float ahorroObligatorio();
	float impuestoSobrelaRenta();

	ahorro* getAhorro();
	float getAguinaldo();
	string getCategoria();
	virtual puesto* getPuesto();
	virtual string getPropietario();
	virtual int getVacaciones();
	virtual void setVacaciones(int v);
	virtual fecha* getFechaIngreso();

	virtual string toString();

private:
	ahorro* ahorro;
	float aguinaldo;
	string categoriaLaboral;
	fecha* fechaIngreso;
	fecha* fechaCese;
	string propietario;
	int vaciones;
};

#endif // !CONTPLAZA_H