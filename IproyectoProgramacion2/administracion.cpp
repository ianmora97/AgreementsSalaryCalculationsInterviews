#include "administracion.h"

administracion::administracion() : contratos(new coleccionContratos){}

administracion::~administracion() {
	delete contratos;
}

void administracion::setFechaActual(fecha* f) { fechaActual = f; }
coleccionContratos* administracion::getColeccion() { return contratos; }

void administracion::calculaVacaciones(contrato* c) {
	if ((fechaActual->getAnio() - c->getFechaIngreso()->getAnio()) == 1) {
		if ((fechaActual->getMes() - c->getFechaIngreso()->getMes()) >= 0) {
			c->setVacaciones(15);
		}	
	}
	else if ((fechaActual->getAnio() - c->getFechaIngreso()->getAnio()) > 1) {
		c->setVacaciones( (fechaActual->getAnio() - c->getFechaIngreso()->getAnio()) * 15);
	}	
}
