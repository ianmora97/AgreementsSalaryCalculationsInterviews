#ifndef CONTPLAZA_H
#define CONTPLAZA_H

#include "contrato.h"

using namespace std;
class ahorro{
public:
	ahorro() {}
	ahorro(float c, int p, int m)
		: cantidad(c), plazo(p), mensualidad(m) {}
	~ahorro() {}
	float getCantidad() { return cantidad; }
	int getPlazo() { return plazo; }
	int getMensualidad() { return mensualidad; }
	string toString() {
		stringstream s;
		s << "Dinero    : " << cantidad << endl;
		s << "Plazo     : " << plazo << endl;
		s << "Rebajo por: " << mensualidad << endl;
		return s.str();
	}
private:
	float cantidad;
	int plazo, mensualidad;
};
class contPlaza : public contrato {
public:
	contPlaza();
	contPlaza(fecha*,puesto*,ahorro*);
	virtual ~contPlaza();

	virtual string toString();

	virtual float getAguinaldo();
	virtual string getCategoria();

	virtual puesto* getPuesto();
	virtual int getVacaciones();
	virtual void setVacaciones(int v);
	virtual fecha* getFechaIngreso();
	virtual void setFechaCese(fecha*f);

private:
	float aguinaldo;
	puesto* categoriaLaboral;
	fecha* fechaIngreso;
	fecha* fechaCese;
	int vacaciones;
	int cargasSociales;
	float impuestoSobreRenta;
	ahorro* ah;
};

#endif // !CONTPLAZA_H