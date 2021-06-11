
#include "Aldeano.h"

Aldeano::Aldeano(){}

void Aldeano::setNombre(string& nombre) {
	this->nombre = nombre;
}

string Aldeano::getNombre() {
	return this->nombre;
}

void Aldeano::setEdad(int edad) {
	this->edad = edad;
}

int Aldeano::getEdad() {
	return this->edad;
}

void Aldeano::setSalud(int salud) {
	this->salud = salud;
}

int Aldeano::getSalud() {
	return this->salud;
}

void Aldeano::setGenero(char genero) {
	this->genero = genero;
}

char Aldeano::getGenero() {
	return this->genero;
}