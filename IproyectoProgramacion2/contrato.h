#ifndef CONTRATO_H
#define CONTRATO_H

#include "tools.h"

#include "fecha.h"
#include "puesto.h"

using namespace std;

class contrato {
public:
	contrato();
	virtual	~contrato();

	virtual void setFechaCese(fecha*f) = 0;

	virtual puesto* getPuesto() = 0;
	virtual fecha* getFechaIngreso() = 0;

	virtual string toString() = 0;
	
};
#endif // !CONTRATO_H