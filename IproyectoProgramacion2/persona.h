#ifndef PERSONA_H
#define PERSONA_H

#include "tools.h"
#include "objetoBase.h"

class persona : public objetoBase { //es la clase empleado
public:
	persona();
	persona(string, string, string, string, string, string);
	virtual ~persona();

	string getName() const;
	string getId() const;
	string getLastName() const;
	string getBirth() const;
	string getAddress() const;
	string getPhone() const;

	virtual string toString() const;

private:
	string _name;
	string _id;
	string _lastName;
	string _birth;
	string _address;
	string _phone;
};
#endif // !PERSONA_H