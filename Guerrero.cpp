#include "Guerrero.h"

Guerrero::Guerrero(){}

void Guerrero::setId(size_t id) {
	this->id = id;
}
size_t Guerrero::getId() {
	return this->id;
}

void Guerrero::setSalud(size_t salud) {
	this->salud = salud;
}
size_t Guerrero::getSalud() {
	return this->salud;
}

void Guerrero::setFuerza(float fuerza) {
	this->fuerza = fuerza;
}
float Guerrero::getFuerza() {
	return this->fuerza;
}

void Guerrero::setEscudo(float escudo) {
	this->escudo = escudo;
}
float Guerrero::getEscudo() {
	return this->escudo;
}

void Guerrero::setTipo(string tipo) {
	this->tipo = tipo;
}
string Guerrero::getTipo() {
	return this->tipo;
}