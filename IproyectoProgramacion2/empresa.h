#ifndef EMPRESA_H
#define EMPRESA_H

#include "tools.h"
#include "administracion.h"
#include "depContabilidad.h"
#include "contrato.h"
#include "coleccion.h"

using namespace std;

class empresa {
public:
	empresa(string, string, int, int , int);
	virtual ~empresa();

	virtual unsigned int getCant() const;
	virtual unsigned int getTam() const;

	administracion* getRRHH() const;
	depContabilidad* getContabilidad() const;
	contrato* getContrato() const;

	virtual void changeAddress();
	virtual void changePhoneNumber();

private:
	
	string _name;
	string _address;
	int _phone;

	administracion* rrhh;
	depContabilidad* contabilidad;
	contrato* _contrato;

	coleccion** _empleados;
	int _cant, _tam;
};

#endif // !EMPRESA_H