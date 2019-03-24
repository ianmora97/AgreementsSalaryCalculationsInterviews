#include "ahorro.h"
ahorro::ahorro(string n, int d, int p)
: tipodeAhorro(n), dinero(d), plazo(p) {}
ahorro::~ahorro(){}

string ahorro::getTipo() { return tipodeAhorro; }
int ahorro::getDinero() { return dinero; }
int ahorro::getPlazo(){	return plazo;}
string ahorro::toString(){
	stringstream p;
	p << "Tipo de ahorro: " << tipodeAhorro << endl;
	p << "Dinero ahorrado: " << dinero << endl;
	p << "Plazo de ahorro: " << plazo << endl;
	return p.str();
}
