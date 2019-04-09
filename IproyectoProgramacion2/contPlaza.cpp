#include "contPlaza.h"

#include <sstream>
using std::stringstream;

contPlaza::contPlaza(){}
contPlaza::contPlaza(fecha* f, puesto* p,ahorro* a) 
	: fechaIngreso(f),fechaCese(NULL),categoriaLaboral(p),
	vacaciones(0),aguinaldo(0), ah(a){}
contPlaza::~contPlaza(){}

string contPlaza::toString(){
	stringstream s;
	s << "Puesto Laboral: " << endl;
	s << "\t" << categoriaLaboral->toString() << endl;
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


float contPlaza::getAguinaldo()
{
	return 0.0f;
}

string contPlaza::getCategoria()
{
	return string();
}

puesto * contPlaza::getPuesto()
{
	return nullptr;
}

int contPlaza::getVacaciones()
{
	return 0;
}

void contPlaza::setVacaciones(int v)
{
}

fecha * contPlaza::getFechaIngreso()
{
	return nullptr;
}
void contPlaza::setFechaCese(fecha*f) {
	fechaCese = f;
}