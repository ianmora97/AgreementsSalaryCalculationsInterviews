#include "empleado.h"

empleado::empleado(){}
empleado::empleado(contrato* c, persona* p): _datos(p), _contrato(c){}
empleado::~empleado(){}

contrato* empleado::getContrato() { return _contrato; }
persona * empleado::getInfo() { return _datos; }

string empleado::toString() const {
	stringstream p;
	p << "Datos del empleado: " << endl;
	p << _datos->toString() << endl;
	return p.str();
}