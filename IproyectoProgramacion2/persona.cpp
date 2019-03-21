#include "persona.h"

persona::persona() : _name(VACIO), _id(VACIO), _lastName(VACIO), _birth(VACIO), _address(VACIO), _phone(VACIO) {}
persona::persona(string name, string id, string lastName, string birth, string address, string phone) : _name(name), _id(id), _lastName(lastName), _birth(birth), _address(address), _phone(phone){}

persona::~persona(){
	_name = VACIO;
	_id = VACIO;
	_lastName = VACIO;
	_birth = VACIO;
	_address = VACIO;
	_phone = VACIO;
}

string persona::getName() const { return _name; }
string persona::getId() const { return _id; }
string persona::getLastName() const { return _lastName; }
string persona::getBirth() const { return _birth; }
string persona::getAddress() const { return _address; }
string persona::getPhone() const { return _phone; }

string persona::toString() const {
	stringstream p;
	p << "[ " << getName() 
	  << ", " << getLastName() 
	  << ", " << getId() 
	  << ", " << getBirth() 
	  << ", " << getAddress() 
	  << ", " << getPhone() << " ]" << FIN;
	return p.str();
}
