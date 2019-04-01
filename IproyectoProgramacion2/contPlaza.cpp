#include "contPlaza.h"



contPlaza::contPlaza()
{
}


contPlaza::~contPlaza()
{
}

string contPlaza::toString()
{
	return string();
}

float contPlaza::cargasSociales()
{
	return 0.0f;
}

float contPlaza::ahorroObligatorio()
{
	return 0.0f;
}

float contPlaza::impuestoSobrelaRenta()
{
	return 0.0f;
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

string contPlaza::getPropietario()
{
	return string();
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
