#ifndef PUESTO_H
#define PUESTO_H

#include "tools.h"

using namespace std;

class puesto{
public:
	puesto(float,string,int);
	virtual ~puesto();

	virtual void setBruto(float);
	virtual void setNeto(float);

	virtual string getPuesto() const;
	virtual float getBruto() const;
	virtual float getNeto() const;
	virtual float getBase() const;
	virtual int getFecha() const;

	virtual string toString() const;
private:
	string _nombrePuesto;
	float _salarioBruto;   // lo que se gana con beneficios, salario base + beneficios
	float _salarioNeto;  // lo que gana al final, lo que se recibe, lo que se le quita, salario bruto - rebajas
	float _salarioBase;  // lo que gana sin rebajos ni beneficios, lo que sale en la planilla
	int _fechaDePago;

};

#endif // !PUESTO_H