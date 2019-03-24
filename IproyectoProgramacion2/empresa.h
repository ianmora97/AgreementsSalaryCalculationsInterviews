#ifndef EMPRESA_H
#define EMPRESA_H

#include "tools.h"
#include "administracion.h"
#include "depContabilidad.h"
#include "empleado.h"

using namespace std;

class empresa { //Empresa Concepto Central
public:
	empresa(string, string, int);
	virtual ~empresa();

	administracion* getRRHH() const;
	depContabilidad* getContabilidad() const;
	empleado* getEmpleado(int);

	virtual void changeAddress(); //cambio de direccion
	virtual void changePhoneNumber(); //cambio de numero de telefono

	virtual void ingresarEmpleado(empleado*);

private:
	string _name; //nombre de la empresa
	string _address; //direccion de la empresa
	int _phone; //numero de telefono de la empresa

	administracion* rrhh; //departamento de recursos humanos
	depContabilidad* contabilidad; //departamento de contabilidad
	empleado** empleados; //contenedor de empleados
	int cant, tam;
};

#endif // !EMPRESA_H