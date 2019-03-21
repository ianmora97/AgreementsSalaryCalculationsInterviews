#ifndef OBJETOBASE
#define OBJETOBASE

#include "tools.h"

using namespace std;

class objetoBase {
public:
	objetoBase();
	virtual ~objetoBase();
	virtual string toString() const  = 0;
};

ostream& operator<<(ostream& out, const objetoBase& objeto) { //sobrecarga del operador de salida para poder imprimir los toString
	out << objeto.toString();
	return out;
}

#endif // !OBJETOBASE