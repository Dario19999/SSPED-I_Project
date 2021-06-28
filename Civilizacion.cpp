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

//metodos para barcos

void Civilizacion::agregarBarco(Barco* b) {
	flota.push_back(b);
}

void Civilizacion::capturarBarco() {

	size_t id;
	float combustible;

	Barco* b = new Barco();

	cout << "Ingrese el ID: ";
	cin >> id;

	cout << "Ingrese el combustible: ";
	cin >> combustible;

	b->setId(id);
	b->setCombustible(combustible);
	b->setArmadura(100);
	b->setVelocidad(0.0);

	agregarBarco(b);
}

void Civilizacion::mostrarFlota() {
	cout << left;
	cout << setw(10) << "ID";
	cout << setw(20) << "Combustible";
	cout << setw(20) << "Armadura";
	cout << setw(20) << "Velocidad";
	cout << setw(20) << "Guerreros Abordo";
	cout << endl;

	for (auto const& b : flota) {
		cout << *b << endl;
	}
}

Barco* Civilizacion::buscarBarco(size_t id) {
	for (auto const& b : flota) {
		if (b->getId() == id) {
			return b;
		}
	}
	return nullptr;
}

size_t Civilizacion::totalBarcos() {
	return flota.size();
}

void Civilizacion::eliminarBarco_id(size_t id) {

	flota.remove_if([id](const Barco* b) {
		if (b->getId() == id) {
			delete b;
			return true;
		}
		else {
			return false;
		}
	});

	cout << "El barco con id " << id << " ha sido eliminado..." << endl;
}

void Civilizacion::eliminarBarco_comb(float combustible) {
	flota.remove_if([combustible](const Barco* b) { 
		if (b->getCombustible() < combustible) {
			delete b;
			return true;
		}
		else {
			return false;
		}
	});
	cout << "Los barcos con combustible menor a " << combustible << " han sido eliminados..." << endl;
}