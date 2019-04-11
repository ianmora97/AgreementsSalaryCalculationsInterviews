#ifndef EMPRESA_H
#define EMPRESA_H

#include "tools.h"
#include "coleccionContratos.h"
#include "coleccionEmpleados.h"
#include "coleccionPuestos.h"

using namespace std;

class empresa { //Empresa Concepto Central
public:
	empresa(string , string , int); //nombre,direccion,telefono
	virtual ~empresa();

	virtual coleccionEmpleados* getColeccion();
	virtual coleccionPuestos* getPuestos();
	virtual string mostrarPuestos();

	virtual void changeAddress(); //cambio de direccion
	virtual void changePhoneNumber(); //cambio de numero de telefono
	virtual void ingresarEmpleado(contrato*, persona*);
	virtual string getDatos();
	virtual string verRegistroEmpleados(ifstream&);
	virtual void modificaPuesto(puesto*);

	virtual string imprimeDatosEmpleados();
	virtual void cambiaDatos(int n);
	virtual void contratarEmpleado(int n, ofstream&);
	virtual void ingresarPuesto(ofstream&);
	virtual void cambioModalidad(empleado*);

private:
	string _name; //nombre de la empresa
	string _address; //direccion de la empresa
	int _phone; //numero de telefono de la empresa

	coleccionEmpleados* empleados; //contenedor de empleados
	coleccionPuestos* puestos; //contenedor de puestos
};

#endif // !EMPRESA_H