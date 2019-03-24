#ifndef AHORRO_H
#define AHORRO_H
#include "tools.h"

using namespace std;

class ahorro{
public:
	ahorro(string,int,int);
	virtual ~ahorro();
	
	string getTipo();
	int getDinero();
	int getPlazo();
	
	string toString();

private:
	string tipodeAhorro; //nombre del ahorro
	int dinero; //cuando dinero por el plazo
	int plazo; //cada cuanto quiere el ahorro
};

#endif // !AHORRO_H