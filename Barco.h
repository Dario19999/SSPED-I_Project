#ifndef BARCO_H
#define BARCO_H

#include "Guerrero.h"
#include <stack>
#include <iomanip>



class Barco {
	size_t id;
	float combustible;
	float armadura;
	float velocidad;

	stack<Guerrero> ejercito;

public:

	Barco();
	Barco(size_t id, float combustible, float armadura, float velocidad)
		:id(id), combustible(combustible), armadura(armadura), velocidad(velocidad) {}

	void setId(size_t id);
	size_t getId() const;

	void setCombustible(float combustible);
	float getCombustible() const;

	void setArmadura(float armadura);
	float getArmadura();

	void setVelocidad(float velocidad);
	float getVelocidad();

	//guerreros
	void agregarGuerrero(const Guerrero& g);
	void eliminarGuerrero();
	Guerrero* tope();
	void mostrarEjercito();
	size_t totalGuerreros();

	friend ostream& operator<<(ostream& out, Barco& b) {

		out << left;
		out << setw(10) << b.id;
		out << setw(20) << b.combustible;
		out << setw(20) << b.armadura;
		out << setw(20) << b.velocidad;
		out << setw(20) << b.ejercito.size();

		return out;
	}
};

#endif
