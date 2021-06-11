#ifndef ALDEANO_H
#define ALDEANO_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Aldeano {
	private:
		string nombre;
		int edad;
		int salud;
		char genero;

	public:

		Aldeano();
		Aldeano(string &nombre, int edad, int salud, char genero)
			:nombre(nombre), edad(edad), salud(salud),genero(genero) {}

		void setNombre(string& nombre);
		string getNombre();

		void setEdad(int edad);
		int getEdad();

		void setSalud(int salud);
		int getSalud();

		void setGenero(char genero);
		char getGenero();

		friend istream& operator>>(istream& in, Aldeano& a) {

			cout << "Ingrese los datos del aldeano..." << endl;
			cout << "Nombre: ";
			cin.ignore();
			getline(cin, a.nombre);

			cout << "Edad: ";
			cin >> a.edad;

			cout << "Salud: ";
			cin >> a.salud;

			cout << "Genero: ";
			cin >> a.genero;

			return in;
		}
};


#endif