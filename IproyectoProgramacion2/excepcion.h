#ifndef EXCEPCION_H
#define EXCEPCION_H

#include "tools.h"

using namespace std;

class excepcion { //la clase excepcion es para manejar los errores de ejecucion
public:
	excepcion(int);
	excepcion(string);
	virtual ~excepcion();

};

#endif // !EXCEPCION_H