#ifndef GUERRERO_H
#define GUERRERO_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Guerrero {
	size_t id;
	size_t salud;
	float fuerza;
	float escudo;
	string tipo;

public:

	Guerrero();
	Guerrero(size_t id, size_t salud, float fuerza, float escudo, string &tipo)
		:id(id), salud(salud), fuerza(fuerza), escudo(escudo), tipo(tipo) {}

	void setId(size_t id);
	size_t getId();

	void setSalud(size_t salud);
	size_t getSalud();

	void setFuerza(float fuerza);
	float getFuerza();

	void setEscudo(float escudo);
	float getEscudo();

	void setTipo(string tipo);
	string getTipo();

	friend istream& operator>>(istream& in, Guerrero& g) {

		cout << "Ingrese los datos del guerrero..." << endl;

		cout << "Id: ";
		cin >> g.id;

		cout << "Salud: ";
		cin >> g.salud;

		cout << "Fuerza: ";
		cin >> g.fuerza;

		cout << "Escudo: ";
		cin >> g.escudo;

		cout << "Tipo (Arquero, Paladin, Lancero, Caballero): ";
		cin.ignore();
		getline(cin, g.tipo);

		return in;
	}

	friend ostream& operator<<(ostream& out, Guerrero& g) {

		out << left;
		out << setw(10) << g.id;
		out << setw(20) << g.salud;
		out << setw(20) << g.fuerza;
		out << setw(20) << g.escudo;
		out << setw(20) << g.tipo;
		return out;
	}

};

#endif