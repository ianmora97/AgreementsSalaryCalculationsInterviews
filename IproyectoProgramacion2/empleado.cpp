#include "empleado.h"

empleado::empleado(): _datos(new persona){}
empleado::~empleado(){
}
persona * empleado::getInfo() { return _datos; }

string empleado::toString() const {
	stringstream p;
	p << "Datos del empleado: " << endl;
	p << _datos->toString() << endl;
	return p.str();
}