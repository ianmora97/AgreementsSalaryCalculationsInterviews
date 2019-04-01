#include "contPlanilla.h"

contPlanilla::contPlanilla(fecha* in, string pr, float ag, puesto* p)
	: fechaIngreso(in), propietario(pr), aguinaldo(ag), fechaCese(NULL)
	, _puesto(p), vacaciones(0), cant(0) {}
contPlanilla::~contPlanilla(){

}

string contPlanilla::toString(){
	stringstream s;
	s << "Puesto Laboral de [" << propietario << "]" << endl;
	s << "\t" << _puesto->toString() << endl;
	s << "Aguinaldo: " << aguinaldo << endl;
	s << "Vacaciones ganadas: " << vacaciones << endl;
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

float contPlanilla::cargasSociales()
{
	return 0.0f;
}

float contPlanilla::ahorroObligatorio()
{
	return 0.0f;
}

float contPlanilla::impuestoSobrelaRenta()
{
	return 0.0f;
}

float contPlanilla::getAguinaldo()
{
	return 0.0f;
}

puesto * contPlanilla::getPuesto()
{
	return nullptr;
}

string contPlanilla::getPropietario()
{
	return string();
}

int contPlanilla::getVacaciones()
{
	return 0;
}

void contPlanilla::setFechaCese(fecha * f)
{
}

void contPlanilla::setVacaciones(int v)
{
}

fecha * contPlanilla::getFechaIngreso()
{
	return nullptr;
}
