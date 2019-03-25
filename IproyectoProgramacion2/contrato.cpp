#include "contrato.h"

contrato::contrato(){} //solo para heredar
contrato::~contrato() {}

void contrato::setPropietario(string p){propietario = p; }
string contrato::getPropietario() { return propietario; }