#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "persona.h"
#include "contrato.h"
using namespace std;


class empleado {
public:
	empleado(contrato*,persona*);
	empleado();
	virtual ~empleado();

	void setContrato(contrato*);
	contrato* getContrato();
	persona* getInfo();
	virtual string toString() const;


private:
	contrato* _contrato;
	persona* _datos;
};

#endif // !EMPLEADO_H
