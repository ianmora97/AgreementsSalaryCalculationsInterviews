#include "coleccionContratos.h"

coleccionContratos::coleccionContratos(int t)
	: tam(t), cant(0), contratos(new contrato*[t]) {}
coleccionContratos::~coleccionContratos(){
	for (int i = 0; i < cant; i++) {
		delete contratos[i];
	}
	delete[] contratos;
	tam = 0;
	cant = 0;
}

bool coleccionContratos::vacio() { return (cant == 0); }
bool coleccionContratos::hayCampo() { return (cant < tam); }

void coleccionContratos::agregar(contrato *c){
	if (hayCampo()) {
		contratos[cant] = c;
		cant++;
	}
	else {
		throw LLENO;
	}
}

void coleccionContratos::eliminaUno(string p){
	for (int i = 0; i < cant; i++) {
		if (contratos[i]->getPropietario() == p) {
			contratos[i] = contratos[cant - 1];
			delete contratos[cant - 1];
			cant--;
		}
	}
}

int coleccionContratos::getCant() { return cant; }
int coleccionContratos::getTam() { return tam; }
contrato * coleccionContratos::getContrato(int i) { return contratos[i]; }

string coleccionContratos::toString(){
	stringstream s;
	s << "Contratos en la Empresa: " << endl;
	s << "-----------------------------" << endl;
	for (int i = 0; i < cant; i++) {
		s << "Contrato [" << cant + 1 << "]" << endl;
		s << "\t" << contratos[i]->toString() << endl;
	}
	s << "-----------------------------" << endl;
	return s.str();
}
