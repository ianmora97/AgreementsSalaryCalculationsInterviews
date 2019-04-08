#include "contServicios.h"

contServicios::contServicios(fecha* in, string pr, puesto* p)
	: propietario(pr), fechaIngreso(in), fechaCese(NULL), _puesto(p), vacaciones(0) {}
contServicios::~contServicios(){}

void contServicios::setFechaCese(fecha *f){
	fechaCese = f;
}

puesto * contServicios::getPuesto(){return _puesto;}
string contServicios::getPropietario() { return propietario; }
fecha * contServicios::getFechaIngreso(){return fechaIngreso;}

string contServicios::toString(){
	stringstream s;
	s << "Puesto Laboral de [" << propietario << "]" << endl;
	s << "\t" << _puesto->toString() << endl;
	s << "Fecha de ingreso " << endl;
	s << "\t" << fechaIngreso->toString() << endl;
	s << "Fecha de Cese " << endl;
	if (fechaCese == NULL) {
		s << "\t <<Actualmente Laborando>>" << endl;
	}
	else {
		s << "\t" << fechaCese->toString() << endl;
	}
	return s.str();
}
