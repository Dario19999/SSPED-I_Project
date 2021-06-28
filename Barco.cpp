#include "Barco.h"

Barco::Barco(){}

void Barco::setId(size_t id) {
	this->id = id;
}
size_t Barco::getId() const {
	return this->id;
}

void Barco::setCombustible(float combustible) {
	this->combustible = combustible;
}
float Barco::getCombustible() const {
	return this->combustible;
}

void Barco::setArmadura(float armadura) {
	this->armadura = armadura;
}
float Barco::getArmadura() {
	return this->armadura;
}

void Barco::setVelocidad(float velocidad) {
	this->velocidad = velocidad;
}
float Barco::getVelocidad() {
	return this->velocidad;
}

//guerreros
void Barco::agregarGuerrero(const Guerrero& g) {
	ejercito.push(g);
}

void Barco::eliminarGuerrero() {
	ejercito.pop();
}

Guerrero* Barco::tope() {
	return &ejercito.top();
}

void Barco::mostrarEjercito() {
	stack<Guerrero> copia(ejercito);
	cout << left;
	cout << setw(10) << "ID";
	cout << setw(20) << "Salud";
	cout << setw(20) << "Fuerza";
	cout << setw(20) << "Escudo";
	cout << setw(20) << "Tipo";
	cout << endl;
	while (!copia.empty()) {
		auto& g = copia.top();
		cout << g << endl;
		copia.pop();
	}
}

size_t Barco::totalGuerreros() {
	return ejercito.size();
}