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
		string getNombre() const;

		void setEdad(int edad);
		int getEdad() const;

		void setSalud(int salud);
		int getSalud() const;

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

		friend ostream& operator<<(ostream& out, Aldeano& a) {

			out << left;
			out << setw(30) << a.nombre;
			out << setw(20) << a.edad;
			out << setw(20) << a.salud;
			out << setw(20) << a.genero;

			return out;
		}

		bool operator<(const Aldeano& a) {
			return nombre < a.nombre;
		}
};


#endif