#include "coleccion.h"
					
coleccion::coleccion(unsigned int tam) : tam(tam), cant(0), objetos(new objetoBase*[tam]) {} // el unsigned es para valores positivos
coleccion::~coleccion() { delete[] objetos; }

void coleccion::agregar(objetoBase *obj){
	if (hayCampo()) {
		objetos[cant++] = obj;
	}
	else {
		throw 1;
	}
}
objetoBase* coleccion::borrarUltimo(bool e) {
    objetoBase* aux = NULL; //asigno un objeto con valor null
    if (cant > 0) {
        aux = objetos[cant--]; // busco la ultima posicion
        if (e) {
            delete objetos[cant];
        }
    }
    return aux;
}
void coleccion::borrarTodos(bool e){
	while (!(vacio())) {
		borrarUltimo(e);
	}
}

unsigned int coleccion::getCant() const { return cant; }
unsigned int coleccion::getTam() const { return tam; }
objetoBase* coleccion::getObjeto(unsigned int o) const { //me devuelve un objeto del arreglo en la posicion "o"
	objetoBase* aux = NULL;
	if (o < cant) {
		aux = objetos[o];
	}
	return aux;
}

bool coleccion::vacio() const { return (cant == 0); } //revisa si el arreglo esta vacio
bool coleccion::hayCampo() const { return (cant < tam); } //revisa si en el arreglo hay campo

string coleccion::toString() const {
	stringstream p;
	p << "{ ";
	for (int i = 0; i < getCant(); i++) {
		p << getObjeto(i)->toString() << FIN;
	}
	p << " }";
	return p.str();
}