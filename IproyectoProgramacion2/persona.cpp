#include "persona.h"

persona::persona() : _name(VACIO), _id(VACIO), _lastName(VACIO), _birth(NULL), _address(VACIO), _phone(VACIO) {}
persona::persona(string name, string id, string lastName, fecha* birth, string address, string phone) 
	: _name(name), _id(id), _lastName(lastName), _birth(new fecha), _address(address), _phone(phone){}

persona::~persona(){
	_name = VACIO;
	_id = VACIO;
	_lastName = VACIO;
	_birth = NULL;
	_address = VACIO;
	_phone = VACIO;
}

string persona::getName() const { return _name; }
string persona::getId() const { return _id; }
string persona::getLastName() const { return _lastName; }
fecha* persona::getBirth() const { return _birth; }
string persona::getAddress() const { return _address; }
string persona::getPhone() const { return _phone; }

void persona::setName(string s) { _name = s; }
void persona::setLastName(string s) { _lastName = s; }
void persona::setBirth(fecha* s) { _birth = s; }
void persona::setAdd(string s) { _address = s; }
void persona::setPhone(string s) { _phone = s; }

string persona::toString() const {
	stringstream p;
	p << "[ " << getName() 
	  << ", " << getLastName() 
	  << ", " << getId() 
	  << ", " << getBirth()->getDia()<<"/"<<getBirth()->getMes()<<"/"<<getBirth()->getAnio()
	  << ", " << getAddress() 
	  << ", " << getPhone() << " ]" << FIN;
	return p.str();
}
