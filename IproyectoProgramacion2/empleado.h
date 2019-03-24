#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "persona.h"
#include "puesto.h"
#include "contrato.h"
using namespace std;


class empleado {
public:
	empleado();
	virtual ~empleado();

	persona* getInfo();
	virtual string toString() const;

	virtual void 

private:
	contrato* _contrato;
	puesto* _puesto;
	persona* _datos;
};

#endif // !EMPLEADO_H
