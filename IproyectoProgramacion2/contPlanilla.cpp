#include "contPlanilla.h"

contPlanilla::contPlanilla(fecha* in, puesto* p)
	: fechaIngreso(in), aguinaldo(0), fechaCese(NULL)
	, _puesto(p), vacaciones(0) {}
contPlanilla::contPlanilla(contrato * c){
	fechaIngreso = c->getFechaIngreso();
	fechaCese = c->getFechaCese();
	_puesto = c->getPuesto();
	vacaciones = 0;
}
contPlanilla::~contPlanilla(){}

string contPlanilla::toString(){
	stringstream s;
	s << "Puesto Laboral: " << endl;
	s << "\t" << _puesto->toString(true) << endl;
	s << "Aguinaldo: " << aguinaldo << endl;
	s << "Vacaciones ganadas: " << vacaciones << endl;
	s << "Fecha de ingreso " << endl;
	s << "\t" << fechaIngreso->toString(true) << endl;
	s << "Fecha de Cese " << endl;
	if (fechaCese == NULL) {
		s << "\t <<Actualmente Laborando>>" << endl;
	}
	else {
		s << "\t" << fechaCese->toString(true) << endl;
	}
	return s.str();
}

float contPlanilla::getAguinaldo(){
	return aguinaldo;
}

puesto * contPlanilla::getPuesto(){
	return _puesto;
}

int contPlanilla::getVacaciones(){
	return vacaciones;
}

void contPlanilla::setFechaCese(fecha * f){
	fechaCese = f;
}

void contPlanilla::setVacaciones(int v){
	vacaciones = v;
}

fecha * contPlanilla::getFechaIngreso(){
	return fechaIngreso;
}
fecha* contPlanilla::getFechaCese() const {
	return fechaCese;
}
