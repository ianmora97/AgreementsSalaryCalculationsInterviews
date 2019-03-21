#include "contrato.h"

contrato::contrato(){} //solo para heredar
contrato::contrato(float base, float bruto, float neto, int fecha)
	: _sarioBruto(bruto), _salarioBase(base), _salarioNeto(neto), _fechaDePago(fecha) {}

contrato::~contrato() {
	_sarioBruto = NULL;
	_salarioBase = NULL;
	_salarioNeto = NULL;
	_fechaDePago = NULL;
}

float contrato::getBruto() const { return _sarioBruto; }
float contrato::getNeto() const { return _salarioNeto; }
float contrato::getBase() const { return _salarioBase; }
unsigned int contrato::getFecha() const { return _fechaDePago; }