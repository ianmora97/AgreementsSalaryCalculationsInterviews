#include "empresa.h"


empresa::empresa(string name, string address, int phone) 
	: _name(name), _address(address), _phone(phone)
	, empleados(new coleccionEmpleados), puestos(new coleccionPuestos) {}
empresa::~empresa(){

	delete[] empleados; //se borra unicamente el contenedor, los empleados siguen existiendo pero no pertenecen a la empresa

	_name = VACIO;
	_address = VACIO;
	_phone = NULL;
}

coleccionEmpleados* empresa::getColeccion() { return empleados; }
coleccionPuestos * empresa::getPuestos(){return puestos;}

string empresa::mostrarPuestos(){
	stringstream s;
	s << "Puestos:\n";
	for (int i = 0; i < puestos->getCant(); i++) {
		s << "#" << i + 1 << puestos->getPuesto(i)->getPuesto() << "\n";
	}
	return s.str();
}

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
	s << "Empleados: \n";
	s << empleados->toString() << "\n";
	return s.str();
}

void empresa::cambiaDatos(int n) {
	string cambio = "indef";
	fecha* f;
	int dia, mes, anio;
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
		cout << "Anio Nacimiento: ";
		cout << "Dia(1-31) > "; dia = evaluarInt(31, 1);
		cout << "Mes(1-12) > "; mes = evaluarInt(12, 1);
		cout << "Anio(1950-2019) > "; anio = evaluarInt(2019, 1950);
		f = new fecha(dia,mes,anio);
		empleados->getEmpleado(e - 1)->getInfo()->setBirth(f);
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
void empresa::contratarEmpleado(int n, ofstream& archivo) {
	empleado* e = new empleado;
	puesto* p;
	fecha* ingreso;
	fecha* anioNa;
	persona* pers;
	contrato* cont;
	ahorro* ah;
	string nombre, apellido, direccion, telefono, id;

	int dia, mes, anio;
	if (n == 1) {
		cls();
		cout << "Contrato por Servicios\n\n";
		cout << "Digite los siguientes datos del empleado:\n";
		cout << "Nombre > ";
		getline(cin, nombre);
		cout << "Apellidos > ";
		getline(cin,apellido);
		cout << "Direccion de Casa > ";
		getline(cin,direccion);
		cout << "Telefono > ";
		getline(cin,telefono);
		cout << "Identificacion > ";
		getline(cin,id);
		cout << "Fecha de nacimiento:\n";
		cout << "Dia(1-31) > "; dia = evaluarInt(31,1);
		cout << "Mes(1-12) > "; mes = evaluarInt(12,1);
		cout << "Anio(1920-2001) > "; anio = evaluarInt(2001,1920);
		anioNa = new fecha(dia,mes,anio);
		pers = new persona(nombre,id,apellido,anioNa,direccion,telefono);
		cout << "\nNombre del Puesto: ";
		cout<<mostrarPuestos()<<"\n";
		int oPuesto;
		oPuesto = evaluarInt(puestos->getCant(), 1);
		p = new puesto(puestos->getPuesto(oPuesto - 1));
		cout << "Digite una fecha de pago para el puesto\n";
		cout << "(1) Quincenal - 15 dias\n(2) Mensual - 30 dias\n > ";
		int oFe;
		oFe = evaluarInt(2, 1);
		if (oFe == 1) {
			p->setFecha(15);
		}
		else {
			p->setFecha(30);
		}
		cout << "Digite la fecha de Ingreso del empleado:\n";
		cout << "Dia(1-31) > "; dia = evaluarInt(31, 1);
		cout << "Mes(1-12) > "; mes = evaluarInt(12, 1);
		cout << "Anio(1950-2019) > "; anio = evaluarInt(2019, 1950);
		ingreso = new fecha(dia, mes, anio);
		cont = new contServicios(ingreso, p);
		e = new empleado(cont,pers);
	}
	else if (n == 2) {
		cls();
		cout << "Contrato por Planilla\n\n";
		cout << "Digite los siguientes datos del empleado:\n";
		cout << "Nombre > ";
		getline(cin, nombre);
		cout << "Apellidos > ";
		getline(cin, apellido);
		cout << "Direccion de Casa > ";
		getline(cin, direccion);
		cout << "Telefono > ";
		getline(cin, telefono);
		cout << "Identificacion > ";
		getline(cin, id);
		cout << "Fecha de nacimiento:\n";
		cout << "Dia(1-31) > "; dia = evaluarInt(31, 1);
		cout << "Mes(1-12) > "; mes = evaluarInt(12, 1);
		cout << "Anio(1920-2001) > "; anio = evaluarInt(2001, 1920);
		anioNa = new fecha(dia, mes, anio);
		pers = new persona(nombre, id, apellido, anioNa, direccion, telefono);
		cout << "\nNombre del Puesto: ";
		cout << mostrarPuestos() << "\n";
		int oPuesto;
		oPuesto = evaluarInt(puestos->getCant(), 1);
		p = new puesto(puestos->getPuesto(oPuesto - 1));
		cout << "Digite una fecha de pago para el puesto\n";
		cout << "(1) Quincenal - 15 dias\n(2) Mensual - 30 dias\n > ";
		int oFe;
		oFe = evaluarInt(2, 1);
		if (oFe == 1) {
			p->setFecha(15);
		}
		else {
			p->setFecha(30);
		}
		cout << "Digite la fecha de Ingreso del empleado:\n";
		cout << "Dia(1-31) > "; dia = evaluarInt(31, 1);
		cout << "Mes(1-12) > "; mes = evaluarInt(12, 1);
		cout << "Anio(1950-2019) > "; anio = evaluarInt(2019, 1950);
		ingreso = new fecha(dia, mes, anio);
		cont = new contPlanilla(ingreso, 0, p);
		e = new empleado(cont, pers);
	}
	else if (n == 3) {
		cls();
		cout << "Contrato por Plaza\n\n";
		cout << "Digite los siguientes datos del empleado:\n";
		cout << "Nombre > ";
		getline(cin, nombre);
		cout << "Apellidos > ";
		getline(cin, apellido);
		cout << "Direccion de Casa > ";
		getline(cin, direccion);
		cout << "Telefono > ";
		getline(cin, telefono);
		cout << "Identificacion > ";
		getline(cin, id);
		cout << "Fecha de nacimiento:\n";
		cout << "Dia(1-31) > "; dia = evaluarInt(31, 1);
		cout << "Mes(1-12) > "; mes = evaluarInt(12, 1);
		cout << "Anio(1920-2001) > "; anio = evaluarInt(2001, 1920);
		anioNa = new fecha(dia, mes, anio);
		pers = new persona(nombre, id, apellido, anioNa, direccion, telefono);
		cout << "\nNombre del Puesto: ";
		cout << mostrarPuestos() << "\n";
		int oPuesto;
		oPuesto = evaluarInt(puestos->getCant(), 1);
		p = new puesto(puestos->getPuesto(oPuesto - 1));
		cout << "Digite una fecha de pago para el puesto\n";
		cout << "(1) Quincenal - 15 dias\n(2) Mensual - 30 dias\n > ";
		int oFe;
		oFe = evaluarInt(2, 1);
		if (oFe == 1) {
			p->setFecha(15);
		}
		else {
			p->setFecha(30);
		}
		cout << "Digite la fecha de Ingreso del empleado:\n";
		cout << "Dia(1-31) > "; dia = evaluarInt(31, 1);
		cout << "Mes(1-12) > "; mes = evaluarInt(12, 1);
		cout << "Anio(1950-2019) > "; anio = evaluarInt(2019, 1950);
		ingreso = new fecha(dia, mes, anio);
		cout << "Digite su ahorro:\n";
		int m, plazo;
		float a;
		cout << "Dinero : "; cin >> a;
		cout << "Plazo  : "; cin >> plazo;
		cout << "Ahorro por: "; cin >> m;
		ah = new ahorro(a,plazo,m);
		cont = new contPlaza(ingreso,p,ah);
		e = new empleado(cont, pers);
	}
	if (archivo.is_open()) {
		archivo << e->toString() << "\n";
	}
	else {
		cerr << "El archivo no se pudo abrir";
	}
	empleados->agregar(e);
}