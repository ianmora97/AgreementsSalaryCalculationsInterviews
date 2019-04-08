#include "control.h"

control::control(){}
control::~control(){}

void control::opciones(){
	empresa* _empresa = new empresa("Smart-System","Zona Franca Metropolitana",22002200);
	
	persona* p1 = new persona("Ian","116890118","Mora Rodriguez","03/10/97","Hatillo","84018895");
	fecha* f1 = new fecha(3,10,1997);
	puesto* pu1 = new puesto(41000, "Publicidad", 5);
	contrato* c1 = new contServicios(f1,"Ian", pu1);
	empleado* e1 = new empleado(c1,p1);
	_empresa->getColeccion()->agregar(e1);

	bool cicloMenu = true;
	while (cicloMenu) {
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
					cout<<_empresa->imprimeDatosEmpleados()<<"\n";
					pause();
					cls();
				}
				else if (opcRRHH == 4) {
					cls();
					cout << "Contratar un Empleado\n";
					empleado* e;
					puesto* p;
					fecha* ingreso;
					fecha* anioNa;
					persona* pers;

					cout << "Que tipo de contratacion desea utilizar?\n";
					cout << "(1) Indefinido\n(2) Plaza\n(3) Planilla\n > ";
					int tipo;
					if (tipo == 1) {
						cls();
						cout << "Contrato Indefinido\n";

					}
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
