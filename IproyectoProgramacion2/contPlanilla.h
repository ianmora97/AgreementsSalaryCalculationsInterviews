#ifndef CONTPLANILLA_H
#define CONTPLANILLA_H

#include "contrato.h"

using namespace std;

class contPlanilla : public contrato {
public:
	contPlanilla();
	virtual ~contPlanilla();

	virtual string toString();

	float cargasSociales();
	float ahorroObligatorio();
	float impuestoSobrelaRenta();

	ahorro* getAhorro();
	float getAguinaldo();

private:
	ahorro* ahorro;
	float aguinaldo;
};

#endif // !CONTPLANILLA_H