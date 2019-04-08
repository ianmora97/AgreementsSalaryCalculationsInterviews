#include "empresa.h"


empresa::empresa(string name, string address, int phone) 
	: _name(name), _address(address), _phone(phone)
	, empleados(new coleccionEmpleados) {}
empresa::~empresa(){

	delete[] empleados; //se borra unicamente el contenedor, los empleados siguen existiendo pero no pertenecen a la empresa

	_name = VACIO;
	_address = VACIO;
	_phone = NULL;
}

coleccionEmpleados* empresa::getColeccion() { return empleados; }

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

void empresa::ingresarEmpleado(contrato* c, persona* p){
	empleado* e = new empleado(c,p);
	empleados->agregar(e);
}
string empresa::getDatos() {
	stringstream s;
	s << "Datos de la empresa:\n";
	s << "\tNombre   : " << _name << "\n";
	s << "\tDireccion: " << _address << "\n";
	s << "\tTelefono : " << _phone << "\n";
	return s.str();
}
string empresa::verRegistroEmpleados(ifstream& archivo) {
	string datos;
	stringstream s;
	if (!archivo.fail()) {
		cout << "Abierto correctamente\n";
		while (!archivo.eof()) {
			getline(archivo,datos,FIN);
			s << datos<<"\n";
		}
	}
	else {
		cerr << "El archivo no se pudo abrir!\n";
	}
	return s.str();
}
string empresa::imprimeDatosEmpleados() {
	stringstream s;
	for (int i = 0; i < getColeccion()->getCant(); i++) {
		s<<"#"<<i+1<<getColeccion()->getEmpleado(i)->getInfo()->toString()<<"\n";
	}
	return s.str();
}

void empresa::cambiaDatos(int n) {
	string cambio = "indef";
	cout << "Digite el numero del empleado que quiere cambiar\n";
	cout << imprimeDatosEmpleados() << "\n";
	int e;
	e = evaluarInt(empleados->getCant(), 1);
	cls();
	switch (n) {
	case 1:
		cout << "Nombre > ";
		getline(cin, cambio);
		empleados->getEmpleado(e - 1)->getInfo()->setName(cambio);
		cout << "\n";
		cout << empleados->getEmpleado(e-1)->getInfo()->toString()<<"\n";
		break;
	case 2:
		cout << "Apellido > ";
		getline(cin, cambio);
		empleados->getEmpleado(e - 1)->getInfo()->setLastName(cambio);
		cout << "\n";
		cout << empleados->getEmpleado(e - 1)->getInfo()->toString() << "\n";
		break;
	case 3:
		cout << "Anio Nacimiento > ";
		getline(cin, cambio);
		empleados->getEmpleado(e - 1)->getInfo()->setBirth(cambio);
		cout << "\n";
		cout << empleados->getEmpleado(e - 1)->getInfo()->toString() << "\n";
		break;
	case 4:
		cout << "Direccion > ";
		getline(cin, cambio);
		empleados->getEmpleado(e - 1)->getInfo()->setAdd(cambio);
		cout << "\n";
		cout << empleados->getEmpleado(e - 1)->getInfo()->toString() << "\n";
		break;
	default:
		cout << "Telefono > ";
		getline(cin, cambio);
		empleados->getEmpleado(e - 1)->getInfo()->setPhone(cambio);
		cout << "\n";
		cout << empleados->getEmpleado(e - 1)->getInfo()->toString() << "\n";
		break;
	}
	pause();
	cambio = "indef";
}