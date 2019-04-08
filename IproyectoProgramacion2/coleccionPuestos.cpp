#include "coleccionPuestos.h"



coleccionPuestos::coleccionPuestos(int n)
	:tam(n), cant(0), puestos(new puesto*[n]) {}
coleccionPuestos::~coleccionPuestos(){}

bool coleccionPuestos::vacio() { return (cant == 0); }
bool coleccionPuestos::hayCampo() { return (cant < tam); }
void coleccionPuestos::agregar(puesto* e) {
	if (hayCampo()) {
		puestos[cant] = e;
		cant++;
	}
	else {
		throw LLENO;
	}
}

void coleccionPuestos::eliminaUno(string nombre) {
	for (int i = 0; i < cant; i++) {
		if ((puestos[i]->getPuesto() == nombre)) {
			puestos[i] = puestos[cant - 1]; //para no hacer el delete solo paso el ultimo al que quiero borrar
			delete puestos[cant - 1];
			cant--;
		}
	}
}

int coleccionPuestos::getCant() { return cant; }
int coleccionPuestos::getTam() { return tam; }
puesto * coleccionPuestos::getPuesto(int i) { return puestos[i]; }


string coleccionPuestos::toString(){
	stringstream s;
	s << "Puestos de la empresa: " << endl;
	s << "--------------------------------" << endl << endl;
	for (int i = 0; i < cant; i++) {
		s << "Puesto [" << i + 1 << "]" << endl;
		s << "\t" << puestos[i]->toString() << endl;
	}
	s << "--------------------------------" << endl << endl;
	return s.str();
}
