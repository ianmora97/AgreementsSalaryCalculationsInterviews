#include "empleado.h"

empleado::empleado(){}
empleado::empleado(contrato* c, persona* p): _datos(p), _contrato(c){}
empleado::~empleado(){}

void empleado::setContrato(contrato *c){
	_contrato = c;
}

contrato* empleado::getContrato() { return _contrato; }
persona * empleado::getInfo() { return _datos; }

string empleado::toString() const {
	stringstream p;
	p << _datos->toString();
	return p.str();
}