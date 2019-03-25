#ifndef FECHA_H
#define FECHA_H

#include "tools.h"
using namespace std;

class fecha {
public:

	fecha();
	fecha(int, int, int);
	~fecha();

	virtual void calendario(int anio); //imprimir el calendario
	virtual string nombreMes(int mes); //calcula el nombre del mes
	virtual int calcularDiaMes(int anio, int mes); //calcula el dia del mes
	virtual bool esBisiesto(int anio); //calcula si el año es biciesto en caso de que lo sea
	virtual int espacio(int anio, int mes); //me da los espacios cuando un dia termina lunes 31 y el siguiente es martes 1
	virtual string getCalendarioxMes();
	virtual string toString();

	virtual int getAnio() const;
	virtual int getMes() const;
	virtual int getDia() const;

	virtual void setAnio(int);
	virtual void setMes(int);
	virtual void setDia(int);

private:
	int _anio;
	int _mes;
	int _dia;
	
};

#endif // !FECHA_H