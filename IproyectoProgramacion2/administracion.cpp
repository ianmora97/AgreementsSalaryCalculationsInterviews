#include "administracion.h"

administracion::administracion(int tam) : _tam(tam), _cant(0), _contratos(new contrato*[tam]){}

administracion::~administracion() {
	for (int i = 0; i < getCant(); i++) { //los contratos se eliminan si se elimina la administracion
		delete _contratos[i];
	}
	delete[] _contratos;
	_tam = 0;
	_cant = 0;
}
void administracion::eliminaUnContrato(string nombre, string apellidos) {

}
contrato * administracion::getContrato(int)
{
	return nullptr;
}

int administracion::getTam() const
{
	return 0;
}

int administracion::getCant()
{
	return 0;
}

string administracion::calculaVacaciones(contrato* c) {
	stringstream p;
	p << "El empleado " << c->getEmpleado()->getInfo()->getLastName() <<" "<< c->getEmpleado()->getInfo()->getName() << endl;
	
	return p.str();
}
