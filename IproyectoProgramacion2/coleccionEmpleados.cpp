#include "coleccionEmpleados.h"

coleccionEmpleados::coleccionEmpleados(int t)
: tam(t), cant(0), empleados(new empleado*[t]) {}

coleccionEmpleados::~coleccionEmpleados(){
	for (int i = 0; i < cant; i++) {
		delete empleados[i];
	}
	delete[] empleados;
	cant = 0;
	tam = 0;
}

bool coleccionEmpleados::vacio() { return (cant == 0); }
bool coleccionEmpleados::hayCampo() { return (cant < tam); }
void coleccionEmpleados::agregar(empleado* e){
	if (hayCampo()) {
		empleados[cant] = e;
		cant++;
	}
	else {
		throw LLENO;
	}
}

void coleccionEmpleados::eliminaUno(string nombre, string apellidos){
	for (int i = 0; i < cant; i++) {
		if ((empleados[i]->getInfo()->getName() == nombre) && (empleados[i]->getInfo()->getLastName() == apellidos)) {
			empleados[i] = empleados[cant - 1]; //para no hacer el delete solo paso el ultimo al que quiero borrar
			delete empleados[cant - 1];
			cant--;
		}
	}
}

int coleccionEmpleados::getCant() { return cant; }
int coleccionEmpleados::getTam() { return tam; }
empleado * coleccionEmpleados::getEmpleado(int i) { return empleados[i]; }

string coleccionEmpleados::toString() {
	stringstream s;
	s << "Empleados en la empresa: "<<endl;
	s << "--------------------------------" << endl << endl;
	for (int i = 0; i < cant; i++) {
		s << "Empleado [" << i + 1 << "]" << endl;
		s << "\t" << empleados[i]->getInfo()->toString() << endl;
	}
	s << "--------------------------------" << endl << endl;
	return s.str();
}