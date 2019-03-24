#include "fecha.h"

fecha::fecha(){}
fecha::fecha(int dia, int mes, int anio) : _dia(dia), _mes(mes), _anio(anio) {}
fecha::~fecha(){}
void fecha::calendario(int anio){
	for (int mes = 1; mes <= 12; mes++) {
		cout << "Mes: " << nombreMes(mes) << endl;
		cout << " Dom Lun Mar Mie Jue Vie Sab" << endl;
		int z = espacio(anio, mes);
		for (int i = 0; i < z; i++) {
			cout << "    ";
		}
		int diasMes = calcularDiaMes(anio, mes);
		for (int dia = 1; dia <= diasMes; dia++) {
			cout << setw(4) << dia;
			z++;
			if (z % 7 == 0) {
				cout << endl;
			}
		}
		cout << endl;
	}
}
string fecha::getCalendarioxMes() {
	cout << "Mes: " << nombreMes(_mes) << endl;
	cout << " Dom Lun Mar Mie Jue Vie Sab" << endl;
	int e = espacio(_anio, _mes);
	for (int i = 0; i < e; i++) {
		cout << "    ";
	}
	int diasMes = calcularDiaMes(_anio, _mes);
	for (int dia = 1; dia <= diasMes; dia++) {
		cout << setw(4) << dia;
		e++;
		if (e % 7 == 0) {
			cout << endl;
		}
	}

	cout << endl;

}
string fecha::nombreMes(int mes){
	switch (mes){
	case 1: return "Enero";
	case 2: return "Febrero";
	case 3: return "Marzo";
	case 4: return "Abril";
	case 5: return "Mayo";
	case 6: return "Junio";
	case 7: return "Julio";
	case 8: return "Agosto";
	case 9: return "Septiembre";
	case 10: return "Octubre";
	case 11: return "Noviembre";
	default: return "Diciembre";
		break;
	}
}

int fecha::calcularDiaMes(int anio, int mes){
	if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
		return 31;
	}
	if (mes == 2) {
		if (esBisiesto(anio)) {
			return 29;
		}
		return 28;
	}
	return 30;
}

bool fecha::esBisiesto(int anio){
	if (anio % 4 != 0) {
		return false;
	}
	if (anio % 100 != 0) {
		return true;
	}
	if (anio % 400 != 0) {
		return false;
	}
	return true;
}

int fecha::espacio(int anio, int mes){
	int a = (14 - mes) / 12;
	int y = anio - a;
	int m = mes + 12 * a - 2;
	int dia = 1, d;
	d = (dia + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
	return d;
}

int fecha::getAnio() const { return _anio; }
int fecha::getMes() const { return _mes; }
int fecha::getDia() const { return _dia; }

void fecha::setAnio(int anio) { _anio = anio; }
void fecha::setMes(int mes) { _mes = mes; }
void fecha::setDia(int dia) { _dia = dia; }
