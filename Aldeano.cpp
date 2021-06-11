
#include "Aldeano.h"

Aldeano::Aldeano(){}

void Aldeano::setNombre(string& nombre) {
	this->nombre = nombre;
}

string Aldeano::getNombre() const {
	return this->nombre;
}

void Aldeano::setEdad(int edad) {
	this->edad = edad;
}

int Aldeano::getEdad() const {
	return this->edad;
}

void Aldeano::setSalud(int salud) {
	this->salud = salud;
}

int Aldeano::getSalud() const {
	return this->salud;
}

void Aldeano::setGenero(char genero) {
	this->genero = genero;
}

char Aldeano::getGenero() {
	return this->genero;
}