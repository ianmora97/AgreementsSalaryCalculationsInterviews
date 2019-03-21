#include "empresa.h"

empresa::empresa(string name, string address, int phone, int cant, int tam) 
	: _name(name), _address(address), _phone(phone), rrhh(new administracion), contabilidad(new depContabilidad), _contrato(new contrato), _cant(0), _tam(tam), _empleados(new coleccion*[tam]) {}
empresa::~empresa(){
	delete rrhh;
	delete contabilidad;
	delete _contrato;

	_name = VACIO;
	_address = VACIO;
	_phone = NULL;
}
unsigned int empresa::getCant() const { return _cant; }
unsigned int empresa::getTam() const { return _tam; }

administracion * empresa::getRRHH() const { return rrhh; }
depContabilidad * empresa::getContabilidad() const { return contabilidad; }
contrato * empresa::getContrato() const { return _contrato; }

void empresa::changeAddress(){
	string aux = VACIO;
	getline(cin, aux, FIN);
	_address = aux;
}

void empresa::changePhoneNumber(){
	int aux = evaluarInt(99999999, 0);
	_phone = aux;
}
