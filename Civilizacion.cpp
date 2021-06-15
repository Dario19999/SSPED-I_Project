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

void Civilizacion::setPtsF(int pts) {
	this->pts = pts;
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

void Civilizacion::eliminarNombre(string& nombre) {
	for (auto idx = aldeanos.begin(); idx != aldeanos.end(); idx++) {
		Aldeano& a = *idx;
		if (a.getNombre() == nombre) {
			aldeanos.erase(idx);
			cout << "El aldeano ha sido eliminado..." << endl;
			return;
		}
	}
	cout << "El aldeano no existe..." << endl;
}

void Civilizacion::eliminarSalud(int x) {
	aldeanos.remove_if([x](const Aldeano& a) { return a.getSalud() < x; });
	cout << "Los aldeanos con salud menor a "<< x << " han sido eliminados..." << endl;
}

void Civilizacion::eliminarEdad() {
	aldeanos.remove_if([](const Aldeano& a) { return a.getEdad() >= 60; });
	cout << "Los aldeanos mayores de 60 han sido eliminados" << endl;
}

void Civilizacion::ordenarNombre() {
	aldeanos.sort();
}

bool comparadorEdad(const Aldeano& a1, const Aldeano& a2) {
	return a1.getEdad() > a2.getEdad();
}
void Civilizacion::ordenarEdad() {
	aldeanos.sort(comparadorEdad);
}

bool comparadorSalud(const Aldeano& a1, const Aldeano& a2) {
	return a1.getSalud() > a2.getSalud();
}
void Civilizacion::ordenarSalud() {
	aldeanos.sort(comparadorSalud);
}

Aldeano* Civilizacion::buscarAldeano(string & nombre ) {
	for (auto idx = aldeanos.begin(); idx != aldeanos.end(); idx++) {
		Aldeano& a = *idx;
		if (a.getNombre() == nombre) {
			return &a;
		}
	}
	return nullptr;
}


size_t Civilizacion::totalAldeanos() {
	return aldeanos.size();
}

void Civilizacion::mostrarAldeanos() {
	cout << left;
	cout << setw(30) << "Nombre";
	cout << setw(20) << "Edad";
	cout << setw(20) << "Salud";
	cout << setw(20) << "Genero";
	cout << endl;
	for (auto idx = aldeanos.begin(); idx != aldeanos.end(); idx++) {
		cout << *idx << endl;
	}
}

void Civilizacion::respaldarAldeanos() {

	ofstream aldeanosF(getNombre() + ".txt", ios::out);

	for (auto idx = aldeanos.begin(); idx != aldeanos.end(); idx++) {
		Aldeano& a = *idx;
		aldeanosF << a.getNombre() << endl;
		aldeanosF << a.getEdad() << endl;
		aldeanosF << a.getSalud() << endl;
		aldeanosF << a.getGenero() << endl;
	}

	aldeanosF.close();
}

void Civilizacion::recuperarAldeanos() {
	ifstream aldeanosF(getNombre() + ".txt");

	if (aldeanosF.is_open()) {

		string s_t;
		Aldeano a;

		while (true) {

			getline(aldeanosF, s_t);
			if (aldeanosF.eof()) {
				break;
			}
			a.setNombre(s_t);

			getline(aldeanosF, s_t);
			a.setEdad(stoi(s_t, nullptr, 10));

			getline(aldeanosF, s_t);
			a.setSalud(stoi(s_t, nullptr, 10));

			getline(aldeanosF, s_t);
			a.setGenero(s_t);

			this->agregarAdeano_f(a);
		}

	}

}