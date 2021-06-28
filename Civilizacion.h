#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include "Aldeano.h"
#include "Barco.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <list>
#include <fstream>

using namespace std;

class Civilizacion {
	string nombre;
	float x;
	float y;
	int pts;
	
	list<Aldeano> aldeanos;
	list<Barco*> flota;

	public:
		//Metodos para civilizacion

		Civilizacion();
		Civilizacion(string& nombre, float* x, float* y, int* pts);
		
		void setNombre(const string& nombre);
		string getNombre();

		void setX(float x);
		float getX();

		void setY(float y);
		float getY();

		void setPts(int pts);
		int getPts();

		void setPtsF(int pts);

		//Metodos para aldeanos

		void agregarAdeano_i(const Aldeano& a);
		void agregarAdeano_f(const Aldeano & a);

		void eliminarNombre(string& nombre);
		void eliminarSalud(int x);
		void eliminarEdad();

		size_t totalAldeanos();
		void mostrarAldeanos();

		void ordenarNombre();
		void ordenarEdad();
		void ordenarSalud();

		Aldeano* buscarAldeano(string & nombre);

		void respaldarAldeanos();
		void recuperarAldeanos();

		//Metodos para barcos

		void agregarBarco(Barco* b);
		void capturarBarco();
		void mostrarFlota();
		Barco* buscarBarco(size_t id);
		void eliminarBarco_id(size_t id);
		void eliminarBarco_comb(float combustible);
		size_t totalBarcos();

		//Sobrecargas

		friend ostream& operator<<(ostream& out, Civilizacion& c) {

			out << left;
			out << setw(30) << c.nombre;
			out << setw(20) << c.x;
			out << setw(20) << c.y;
			out << setw(20) << c.pts;
			out << endl;

			return out;
		}

		friend istream& operator>>(istream& in, Civilizacion& c) {

			cout << "Ingrese los datos de la Civilizacion..." << endl;
			cout << "Nombre: ";
			cin.ignore();
			getline(cin, c.nombre);

			cout << "Coordenadas en X: ";
			cin >> c.x;

			cout << "Coordenadas en Y: ";
			cin >> c.y;

			cout << "Puntuacion: ";
			cin >> c.pts;

			return in;
		}

		bool operator==(const Civilizacion& c) {
			return this->nombre == c.nombre;
		}
};
#endif