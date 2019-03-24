#ifndef CONTRATO_H
#define CONTRATO_H

#include "tools.h"
#include "ahorro.h"
using namespace std;


class contrato {
public:
	contrato();
	virtual	~contrato();

	virtual string toString() = 0;
	
};
#endif // !CONTRATO_H