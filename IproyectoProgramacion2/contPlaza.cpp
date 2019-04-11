#include "contPlaza.h"

#include <sstream>
using std::stringstream;

contPlaza::contPlaza(){}
contPlaza::contPlaza(fecha* f, puesto* p,ahorro* a) 
	: fechaIngreso(f),fechaCese(NULL),categoriaLaboral(p),
	vacaciones(0),aguinaldo(0), ah(a){
	cargasSociales = 0;
	impuestoSobreRenta = calculoSobrelaRenta();
}
contPlaza::contPlaza(contrato* c) {
	fechaIngreso = c->getFechaIngreso();
	fechaCese = c->getFechaCese();
	categoriaLaboral = c->getPuesto();
	aguinaldo = 0;
	vacaciones = 0;
	ah = NULL;
	cargasSociales = 0;
}
contPlaza::~contPlaza(){}

int contPlaza::getCargasSociales() const{
	return cargasSociales;
}

int contPlaza::getImpuestos(){
	return impuestoSobreRenta;
}

string contPlaza::toString(){
	stringstream s;
	s << "Puesto Laboral: " << endl;
	s << "\t" << categoriaLaboral->toString(true) << endl;
	s << "Aguinaldo: " << aguinaldo << endl;
	s << "Vacaciones ganadas: " << vacaciones << endl;
	s << "Fecha de ingreso " << endl;
	s << "\t" << fechaIngreso->toString(false) << endl;
	s << "Fecha de Cese " << endl;
	if (fechaCese == NULL) {
		s << "\t <<Actualmente Laborando>>" << endl;
	}
	else {
		s << "\t" << fechaCese->toString(false) << endl;
	}
	return s.str();
}


float contPlaza::getAguinaldo(){
	return aguinaldo;
}

string contPlaza::getCategoria(){
	return categoriaLaboral->getPuesto();
}

puesto * contPlaza::getPuesto(){
	return categoriaLaboral;
}

int contPlaza::getVacaciones(){
	return vacaciones;
}

void contPlaza::setVacaciones(int v){
	vacaciones = v;
}

fecha * contPlaza::getFechaIngreso(){
	return fechaIngreso;
}
void contPlaza::setFechaCese(fecha*f) {
	fechaCese = f;
}

fecha * contPlaza::getFechaCese() const{
	return fechaCese;
}

float contPlaza::calculoSobrelaRenta() {
	if (categoriaLaboral->getBruto() >= 1200000) {
		impuestoSobreRenta = 0.20;
	}
	else {
		impuestoSobreRenta = 1;
	}
	return impuestoSobreRenta;
}