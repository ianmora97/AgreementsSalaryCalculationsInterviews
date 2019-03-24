#include "puesto.h"

puesto::puesto(float salariobase, string nombrePuesto, int fechapago)
: _salarioBase(salariobase), _nombrePuesto(nombrePuesto), _fechaDePago(fechapago), _salarioBruto(0), _salarioNeto(0) {}
puesto::~puesto(){}

void puesto::setBruto(float b) { _salarioBruto = b; }
void puesto::setNeto(float n) { _salarioNeto = n; }

string puesto::getPuesto() const { return _nombrePuesto; }
float puesto::getBruto() const { return _salarioBruto; }
float puesto::getNeto() const { return _salarioNeto; }
float puesto::getBase() const { return _salarioBase; }
int puesto::getFecha() const { return _fechaDePago; }

string puesto::toString() const {
	stringstream p;
	p << "Puesto en que labora: " << getPuesto() << endl;
	p << "Salario Base: " << getBase() << endl;
	p << "Salario Neto: " << getNeto() << endl;
	p << "Salario Bruto: " << getBruto() << endl;
	p << "Fecha de Pago: " << getFecha() << endl;
	return p.str();
}