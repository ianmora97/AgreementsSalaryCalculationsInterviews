#ifndef EMPRESA_H
#define EMPRESA_H

#include "tools.h"
#include "administracion.h"
#include "depContabilidad.h"
#include "coleccionEmpleados.h"

using namespace std;

class empresa { //Empresa Concepto Central
public:
	empresa(string , string , int); //nombre,direccion,telefono
	virtual ~empresa();

	virtual void setRRHH(administracion*);
	virtual void setContabilidad(depContabilidad*);

	administracion* getRRHH() const;
	depContabilidad* getContabilidad() const;
	coleccionEmpleados* getColeccion();

	virtual void changeAddress(); //cambio de direccion
	virtual void changePhoneNumber(); //cambio de numero de telefono

	virtual void ingresarEmpleado(contrato*,persona*);

private:
	string _name; //nombre de la empresa
	string _address; //direccion de la empresa
	int _phone; //numero de telefono de la empresa

	administracion* rrhh; //departamento de recursos humanos
	depContabilidad* contabilidad; //departamento de contabilidad
	coleccionEmpleados* empleados; //contenedor de empleados
};

#endif // !EMPRESA_H