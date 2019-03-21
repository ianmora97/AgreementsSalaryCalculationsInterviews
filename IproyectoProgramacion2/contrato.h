#ifndef CONTRATO_H
#define CONTRATO_H

#include "objetoBase.h"
using namespace std;

class contrato : public objetoBase {
public:
	contrato();
	contrato(float base, float bruto, float neto, int fecha);
	virtual	~contrato();

	virtual float getBruto() const;
	virtual float getNeto() const;
	virtual float getBase() const;
	virtual unsigned int getFecha() const;

private:
	float _sarioBruto; // lo que se gana con beneficios, salario base + beneficios
	float _salarioNeto;  // lo que gana al final, lo que se recibe, lo que se le quita, salario bruto - rebajas
	float _salarioBase;  // lo que gana sin rebajos ni beneficios, lo que sale en la planilla
	int _fechaDePago;
};
#endif // !CONTRATO_H