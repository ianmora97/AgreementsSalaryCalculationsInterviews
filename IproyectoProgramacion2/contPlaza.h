#ifndef CONTPLAZA_H
#define CONTPLAZA_H

#include "contrato.h"

using namespace std;

class contPlaza : public contrato {
public:
	contPlaza();
	virtual ~contPlaza();

	virtual string toString();

	float cargasSociales();
	float ahorroObligatorio();
	float impuestoSobrelaRenta();

	ahorro* getAhorro();
	float getAguinaldo();
	string getCategoria();

private:
	ahorro* ahorro;
	float aguinaldo;
	string categoriaLaboral;
};

#endif // !CONTPLAZA_H