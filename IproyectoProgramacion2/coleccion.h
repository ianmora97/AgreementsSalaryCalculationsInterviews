#ifndef COLECCION_H
#define COLECCION_H

#include "tools.h"
#include "objetoBase.h"


class coleccion : public objetoBase { //la clase cleccion va a servir para cualquier objeto 
public:
	coleccion(unsigned int);
	virtual ~coleccion();

	virtual void agregar(objetoBase*);
	virtual objetoBase* borrarUltimo(bool e);
	virtual void borrarTodos(bool e);

	virtual unsigned int getCant() const; //seters
	virtual unsigned int getTam() const;
	virtual objetoBase* getObjeto(unsigned int) const;

	virtual bool vacio() const;    //validaciones
	virtual bool hayCampo() const;

	virtual string toString() const;

private:
	int cant, tam;
	objetoBase **objetos;
};

#endif // !COLECCION_H