#include "puesto.h"

puesto::puesto(float salariobase, string nombrePuesto, int fechapago)
: _salarioBase(salariobase), _nombrePuesto(nombrePuesto), _fechaDePago(fechapago), _salarioBruto(0), _salarioNeto(0) {}
puesto::~puesto(){}
puesto::puesto(const puesto* p) {
	_salarioBase = p->getBase();
	_nombrePuesto = p->getPuesto();
	_fechaDePago = p->getFecha();
	_salarioBruto = p->getBruto();
	_salarioNeto = p->getNeto();
}
puesto * puesto::operator=(const puesto * p){
	puesto* aux = new puesto(p->getBase(), p->getPuesto(), p->getFecha());
	return aux;
}
void puesto::setBruto(float b) { _salarioBruto = b; }
void puesto::setNeto(float n) { _salarioNeto = n; }
void puesto::setFecha(int n) { _fechaDePago = n; }
void puesto::setNombre(string n) { _nombrePuesto = n; }
void puesto::setBase(float b) { _salarioBase = b; }

string puesto::getPuesto() const { return _nombrePuesto; }
float puesto::getBruto() const { return _salarioBruto; }
float puesto::getNeto() const { return _salarioNeto; }
float puesto::getBase() const { return _salarioBase; }
int puesto::getFecha() const { return _fechaDePago; }

string puesto::toString(bool t) const {
	stringstream p;
	if (t == true) {
		p << "Puesto laboral: " << getPuesto() << TAB;
		p << "Base: " << getBase() << TAB;
		p << "Neto: " << getNeto() << TAB;
		p << "Bruto: " << getBruto() << TAB;
		p << "Fecha de Pago: " << getFecha() << endl;
	}
	else{
		p << _nombrePuesto << TAB
			<< _salarioBase << TAB
			<< _salarioNeto << TAB
			<< _salarioBruto << TAB
			<< _fechaDePago << FIN;
	}
	return p.str();
}