#include "empresa.h"

empresa::empresa(string name, string address, int phone) 
	: _name(name), _address(address), _phone(phone), rrhh(new administracion)
	, contabilidad(new depContabilidad), empleados(new empleado*[100]) 
	, tam(100), cant(0){}
empresa::~empresa(){
	delete rrhh;
	delete contabilidad;
	delete[] empleados; //se borra unicamente el contenedor, los empleados siguen existiendo pero no pertenecen a la empresa

	_name = VACIO;
	_address = VACIO;
	_phone = NULL;
}

administracion * empresa::getRRHH() const { return rrhh; }
depContabilidad * empresa::getContabilidad() const { return contabilidad; }
empleado* empresa::getEmpleado(int i) { return empleados[i]; }

void empresa::changeAddress(){
	string aux = VACIO;
	getline(cin, aux, FIN);
	_address = aux;
}

void empresa::changePhoneNumber(){
	string message = " ";
	int aux;
	ofstream write;
	try {
		aux = evaluarInt(99999999, 10000000);
	}
	catch (int e) {
		write.open("errores/bitacora.txt", ios::out);
		if (e == 1) { message = "Numero Mal Escrito '\n'"; }
		if (e == 2) { message = "Numero No Esta en el Rango '\n'"; }
		write << message;
		write.close();
		cerr << message;
	}
	_phone = aux;
}

void empresa::ingresarEmpleado(empleado *e){
	empleado * aux = NULL;
	if (cant < tam) {

	}
}
