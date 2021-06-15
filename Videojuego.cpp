#include "Videojuego.h"
#include <algorithm>

Videojuego::Videojuego(){}

void Videojuego::setNombreUsuario(const string& nombre) {
	this->nombre_u = nombre;
	cout << "Nombre registrado..." << endl;
}

string Videojuego::getNombreUsuario() {
	return this->nombre_u;
}

void Videojuego::agregar(const Civilizacion& c) {
	civs.push_back(c);
}

void Videojuego::insertar(const Civilizacion& c, size_t pos) {
	civs.insert(civs.begin() + pos, c);
}

void Videojuego::inicializar(const Civilizacion& c, size_t cant) {
	civs = vector<Civilizacion>(cant, c);
}

void Videojuego::eliminar(const string& nombre) {
	int i = 0;
	auto idx = find_if(civs.begin(), civs.end(),
		[&nombre, &i](Civilizacion& c) {
			i++;
			return c.getNombre() == nombre;
		});

	if (idx == civs.end()) {
		cout << "Error. Civilizacion no encontrada..." << endl;
	}
	else {
		civs.erase(civs.begin() + i-1);
		cout << "Civilizacion eliminada..." << endl;

	}
}

void Videojuego::primera() {
	cout << left;
	cout << endl;
	cout << setw(30) << "Nombre de la Civilizacion";
	cout << setw(20) << "Coordenadas en X";
	cout << setw(20) << "Coordenadas en Y";
	cout << setw(20) << "Puntuacion";
	cout << endl;
	cout << civs.front();
}

void Videojuego::ultima() {
	cout << left;
	cout << endl;
	cout << setw(30) << "Nombre de la Civilizacion";
	cout << setw(20) << "Coordenadas en X";
	cout << setw(20) << "Coordenadas en Y";
	cout << setw(20) << "Puntuacion";
	cout << endl;
	cout << civs.back();
}

void Videojuego::ordenar_n() {
	sort(civs.begin(), civs.end(),
		[](Civilizacion c1, Civilizacion c2) {
			return c1.getNombre() < c2.getNombre();
		});
	cout << "Ordenado por nombre" << endl;

}

void Videojuego::ordenar_x() {
	sort(civs.begin(), civs.end(),
		[](Civilizacion c1, Civilizacion c2) {
			return c1.getX() < c2.getX();
		});
	cout << "Ordenado por coordenadas en x" << endl;

}

void Videojuego::ordenar_y() {
	sort(civs.begin(), civs.end(),
		[](Civilizacion c1, Civilizacion c2) {
			return c1.getY() < c2.getY();
		});
	cout << "Ordenado por coordenadas en y" << endl;

}

void Videojuego::ordenar_pts() {
	sort(civs.begin(), civs.end(),
		[](Civilizacion c1, Civilizacion c2) {
			return c1.getPts() > c2.getPts();
		});
	cout << "Ordenado por puntuacion" << endl;

}

size_t Videojuego::total() {
	return civs.size();
}

Civilizacion* Videojuego::buscar(const string& nombre) {

	auto idx = find_if(civs.begin(), civs.end(),
		[&nombre](Civilizacion& c) {
			return c.getNombre() == nombre;
		});

	if (idx == civs.end()) {
		return nullptr;
	}
	else {
		return &*idx;
	}
}

Civilizacion* Videojuego::modificar(const string& nombre) {
	auto civ = find_if(civs.begin(), civs.end(),
		[&nombre](Civilizacion& c) {
			return c.getNombre() == nombre;
		});

	if (civ == civs.end()) {
		return nullptr;
	}
	else {
		return &*civ;
	}
}

void Videojuego::resumen() {

	cout << left;
	cout << endl;
	cout << setw(30) << "Nombre de la Civilizacion";
	cout << setw(20) << "Coordenadas en X";
	cout << setw(20) << "Coordenadas en Y";
	cout << setw(20) << "Puntuacion";
	cout << endl;
	for (size_t i = 0; i < civs.size(); i++) {

		Civilizacion& c = civs[i];

		cout << c;
	}

}

void Videojuego::respaldar() {

	ofstream civsF("civilizaciones.txt", ios::out);

	for (int i = 0; i < civs.size(); i++) {
		Civilizacion& c = civs[i];

		civsF << c.getNombre() << endl;
		civsF << c.getX() << endl;
		civsF << c.getY() << endl;
		civsF << c.getPts() << endl;

		c.respaldarAldeanos();
	}

	civsF.close();
}

void Videojuego::recuperar() {
	ifstream civsF("civilizaciones.txt");

	if (civsF.is_open()) {
		string t_s;

		while (true) {
			Civilizacion c;

			getline(civsF, t_s);
			if (civsF.eof()) {
				break;
			}
			c.setNombre(t_s);

			getline(civsF, t_s);
			c.setX(stof(t_s));

			getline(civsF, t_s);
			c.setY(stof(t_s));

			getline(civsF, t_s);
			c.setPtsF(stoi(t_s, nullptr, 10));
			
			c.recuperarAldeanos();

			civs.push_back(c);

		}
	}
}