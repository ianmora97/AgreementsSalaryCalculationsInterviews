#ifndef COLECCIONEMPLEADOS_H
#define COLECCIONEMPLEADOS_H

#include "empleado.h"

using namespace std;

class coleccionEmpleados {
public:
	coleccionEmpleados(int = 100);
	virtual ~coleccionEmpleados();

	bool vacio();
	bool hayCampo();
	void agregar(empleado*);
	void eliminaUno(string,string);

	int getCant();
	int getTam();
	empleado* getEmpleado(int i);

	string toString();

private:
	empleado** empleados;
	int tam, cant;
};

#endif // !COLECCIONEMPLEADOS_H