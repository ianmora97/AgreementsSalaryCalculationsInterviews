#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "persona.h"
#include "contrato.h"

using namespace std;

class empleado : public objetoBase {
public:
	empleado();
	virtual ~empleado();
private:

	contrato* _contrato;
	persona* _datos;

};

#endif // !EMPLEADO_H