#include "Civilizacion.h"

Civilizacion::Civilizacion() {}

Civilizacion::Civilizacion(string& nombre, float* x, float* y, int* pts) {
	this->nombre = nombre;
	this->x = *x;
	this->y = *y;
	this->pts = *pts;
}

void Civilizacion::setNombre(const string& nombre) {
	this->nombre = nombre;
}

string Civilizacion::getNombre() {
	return this->nombre;
}

void Civilizacion::setX(float x) {
	this->x = x;
}

float Civilizacion::getX() {
	return this->x;
}

void Civilizacion::setY(float y) {
	this->y = y;
}

float Civilizacion::getY() {
	return this->y;
}

void Civilizacion::setPts(int pts) {
	this->pts += pts;
}

int Civilizacion::getPts() {
	return this->pts;
}

//metodos para aldeanos

void Civilizacion::agregarAdeano_i(const Aldeano& a) {
	aldeanos.push_front(a);
}

void Civilizacion::agregarAdeano_f(const Aldeano& a) {
	aldeanos.push_back(a);
}
