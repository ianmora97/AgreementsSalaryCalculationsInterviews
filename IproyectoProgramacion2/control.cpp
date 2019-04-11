#include "control.h"

control::control(){}
control::~control(){}
void control::opciones(){
	empresa* _empresa = new empresa("Smart-System","Zona Franca Metropolitana",22002200);
	
	fecha* f1 = new fecha(3, 10, 1997);
	fecha* f2 = new fecha(7, 12, 1994);
	fecha* f3 = new fecha(25, 4, 1990);
	persona* pe1 = new persona("Ian", "116890118", "Mora Rodriguez", f1, "San Jose", "84018895");
	persona* pe2 = new persona("Sylvia", "116890118", "Porras Hidalgo", f2, "San Jose", "55224411");
	persona* pe3 = new persona("Ambar", "116890118", "Sancho Porras", f3, "San Jose", "88995566");
	puesto* p1 = new puesto(450000, "Publicidad", 15);
	puesto* p2 = new puesto(105000, "Diseniador", 15);
	puesto* p3 = new puesto(550000, "Front end", 15);
	puesto* p4 = new puesto(510000, "Back end", 15);
	_empresa->getPuestos()->agregar(p1);
	_empresa->getPuestos()->agregar(p2);
	_empresa->getPuestos()->agregar(p3);
	_empresa->getPuestos()->agregar(p4);
	contrato* c1 = new contServicios(f1, p1);
	contrato* c2 = new contPlanilla(f2, p2);
	contrato* c3 = new contPlaza(f3, p3,NULL);

	empleado* e1 = new empleado(c1, pe1);
	empleado* e2 = new empleado(c1, pe2);
	empleado* e3 = new empleado(c1, pe3);
	_empresa->getColeccion()->agregar(e1);
	_empresa->getColeccion()->agregar(e2);
	_empresa->getColeccion()->agregar(e3);

	ofstream emple;
	emple.open("registros/registroEmpleados.txt", ios::out);
	if (!emple.fail()) {
		emple << e1->toString()<<endl;
		emple << e2->toString() << endl;
		emple << e3->toString() << endl;
	}
	emple.close();

	int diaA, mesA, anioA;
	time_t now = time(NULL);
	tm *today = localtime(&now);

	diaA = today->tm_mday;
	mesA = today->tm_mon + 1;
	anioA = today->tm_year + 1900;
	
	fecha* fechaActual = new fecha(diaA,mesA,anioA); // fechaactual

	ofstream ar;
	ar.open("registros/puestos.txt", ios::out);
	if (!ar.fail()) {
		ar << p1->toString(false);
		ar << p2->toString(false);
		ar << p3->toString(false);
		ar << p4->toString(false);
	}
	ar.close();
	//!empleados
	cout << fechaActual->toString(false) << endl;
	bool cicloMenu = true;
	while (cicloMenu) {
		{//cambioDeModalidadAutomaticoContrato
			int anioEm;
			int mesEm;
			for (int i = 0; i < _empresa->getColeccion()->getCant(); i++) {
				anioEm = _empresa->getColeccion()->getEmpleado(i)->getContrato()->getFechaIngreso()->getAnio();
				mesEm = _empresa->getColeccion()->getEmpleado(i)->getContrato()->getFechaIngreso()->getMes();
				if ((fechaActual->getMes() - mesEm) > 3) {
					contrato* cambio = _empresa->getColeccion()->getEmpleado(i)->getContrato();
				}
			}
		}
		//imprimeMenu();
		cout << "1. Datos de la Empresa\n2. Departamento de RRHH\n3. Departamento de Contabilidad\n0. Salir\n";
		int opc = menu();
		if (opc == 0) {
			cicloMenu = false;
			//salida();
		}
		else if (opc == 1) {

			cls();
			bool cicloDatos = true;
			while (cicloDatos) {
				cls();
				cout << "Datos de la empresa:\n";
				cout << "(1) Actualizar Telefono\n(2) Actualizar Direccion \n(3) Mostrar Datos\n(4) Volver al Menu\n";
				int opcAct = evaluarInt(3, 1);
				if (opcAct == 0) {
					cicloDatos = false;
					cls();
				}
				else if (opcAct == 1) {
					cls();
					cout << "Actualizacion de Telefono\n";
					_empresa->changePhoneNumber();
					cout << "Cambio realizado!\n";
					cout << _empresa->getDatos() << "\n";
					pause();
					cls();
				}
				else if (opcAct == 2) {
					cls();
					cout << "Actualizacion de Direccion\n";
					_empresa->changeAddress();
					cout << "Cambio realizado!\n";
					cout << _empresa->getDatos() << "\n";
					pause();
					cls();
				}
				else {
					cls();
					cout << _empresa->getDatos() << "\n";
					pause();
					cls();
				}
			}
		}
		else if (opc == 2) {
			cls();
			int opcRRHH;
			bool cicloRRHH = true;
			while (cicloRRHH) {
				cls();
				cout << "Departamento de RRHH\n\n";
				cout << "(1) Ver Registro de Empleados\n";
				cout << "(2) Actualizar datos de Empleados\n";
				cout << "(3) Lista de Empleados\n";
				cout << "(4) Contratar Empleado\n";
				cout << "(5) Cambio de Modalidad de Contrato\n";
				cout << "(0) Volver al Menu principal\n";
				opcRRHH = evaluarInt(5, 0);
				if (opcRRHH == 0) {
					cicloRRHH = false;
					cls();
				}
				else if (opcRRHH == 1) {
					cls();
					ifstream archivo;
					archivo.open("registros/registroEmpleados.txt",ios::in);
					cout<<_empresa->verRegistroEmpleados(archivo);
					archivo.close();
					pause();
					cls();
				}
				else if (opcRRHH == 2) {
					cls();
					cout << "Actualizacion de Datos de Empleados\n";
					cout << "Que desea Actualizar?\n";
					cout << "(1) Nombre\n";
					cout << "(2) Apellidos\n";
					cout << "(3) Anio Nacimiento\n";
					cout << "(4) Direccion\n";
					cout << "(5) Telefono\n";
					cout << "(0) Cancelar\n";
					int opcAE;
					opcAE = evaluarInt(5, 0);
					cls();
					if (opcAE > 0 && opcAE <=5) {
						_empresa->cambiaDatos(opcAE);
					}
					pause();
					cls();
				}
				else if (opcRRHH == 3) {
					cls();
					cout << "Lista de Empleados en la Empresa\n";
					cout<<_empresa->getColeccion()->toString()<<"\n";
					pause();
					cls();
				}
				else if (opcRRHH == 4) {
					cls();
					cout << "Contratar un Empleado\n";	
					cout << "Que tipo de contratacion desea utilizar?\n";
					cout << "(1) Indefinido\n(2) Plaza\n(3) Planilla\n(0) Cancelar > ";
					int tipo;
					tipo = evaluarInt(3, 0);
					ofstream archivow;
					if (tipo >= 1 && tipo <= 3) {
						archivow.open("registros/registroEmpleados.txt", ios::app);
						if (!archivow.fail()) {
							_empresa->contratarEmpleado(tipo, archivow);
						}
						archivow.close();
					}
					pause();
					cls();
				}
				else if (opcRRHH == 5) {
					cls();
					cout << "Cambio de modalidad de contrato\n";
					cout << "Digite el empleado que quiere modificar la contratacion\n";
					int opcem;
					cout << _empresa->getColeccion()->toString() << "\n";
					opcem = evaluarInt(_empresa->getColeccion()->getCant(),1);
					opcem--;
					_empresa->cambioModalidad(_empresa->getColeccion()->getEmpleado(opcem));
					pause();
					cls();
				}
			}
		}
		else if (opc == 3) {
			cls();
			int opcConta;
			bool cicloconta = true;
			while (cicloconta) {
				cls();
				cout << "Departamento de contabilidad\n\n";
				cout << "(1) Mantenimiento de puestos y Modificacion de salarios\n";
				cout << "(2) Cese de Empleados\n";
				cout << "(0) Volver al Menu principal\n";
				opcConta = evaluarInt(2,0);
				if (opcConta == 1) {
					int opcMante;
					bool cicloMante = true;
					while (cicloMante) {
						cls();
						cout << "Mantenimiento de puestos\n\n";
						cout << "(1) Ingresar puestos\n";
						cout << "(2) Eliminar puestos\n";
						cout << "(3) Modificacion puestos\n";
						cout << "(0) Volver al Menu principal\n";
						opcMante = evaluarInt(3,0);
						if (opcMante == 1) {
							cls();
							cout << "Ingresar un puesto\n";
							ofstream arch;
							arch.open("registros/puestos.txt", ios::app);
							_empresa->ingresarPuesto(arch);
							arch.close();
							pause();
							cls();
						}
						else if (opcMante == 2) {
							cls();
							cout << "Eliminar un puesto\n";
							cout << "Digite un puesto: \n";
							cout << _empresa->getPuestos()->toString()<<endl;
							int opelimina;
							opelimina = evaluarInt(_empresa->getPuestos()->getCant(), 1);
							opelimina--;
							_empresa->getPuestos()->eliminaUno(_empresa->getPuestos()->getPuesto(opelimina)->getPuesto());
							pause();
							cls();
						}
						else if (opcMante == 3) {
							cls();
							cout << "Modificar un puesto\n";
							cout << "Digite un puesto: \n";
							cout << _empresa->getPuestos()->toString() << endl;
							int opelimina;
							opelimina = evaluarInt(_empresa->getPuestos()->getCant(), 1);
							opelimina--;
							_empresa->modificaPuesto(_empresa->getPuestos()->getPuesto(opelimina));
							pause();
							cls();
						}
						else {
							cicloMante = false;
						}
					}
				}
				else if (opcConta == 2) {
					cls();
					if (_empresa->getColeccion()->getCant() > 0) {
						cout << "Cese de empleados\n";
						cout << "Digite el empleado:\n";
						cout << "Lista de Empleados en la Empresa\n";
						cout << _empresa->getColeccion()->toString() << "\n";
						int opEm = evaluarInt(_empresa->getColeccion()->getCant(), 1);
						opEm--;
						_empresa->getColeccion()->getEmpleado(opEm)->getContrato()->setFechaCese(fechaActual);

					}
					else {
						cout << "No hay empleados";
					}
					pause();
					cls();
				}
				else {
					cicloconta = false;
				}
			}

		}
}
}
int control::menu(){
	int opc;
	opc = evaluarInt(3,0);
	return opc;
}
