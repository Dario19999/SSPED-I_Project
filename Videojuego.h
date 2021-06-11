#ifndef VIDEOJUEGO_H
#define VIDEOJUEGO_H

#include "Civilizacion.h"
#include <vector>

class Videojuego {
	private:
		string nombre_u;
		vector<Civilizacion> civs;

	public:
		Videojuego();
		void setNombreUsuario(const string& nombre);
		string getNombreUsuario();
		void agregar(const Civilizacion& c);
		void resumen();
		void insertar(const Civilizacion& c, size_t pos);
		void inicializar(const Civilizacion& c, size_t cant);
		void eliminar(const string& nombre);
		void primera();
		void ultima();
		void ordenar_n();
		void ordenar_x();
		void ordenar_y();
		void ordenar_pts();
		Civilizacion* modificar(const string& nombre);
		size_t total();
		Civilizacion* buscar(const string& nombre);

		friend Videojuego& operator<<(Videojuego& v, const Civilizacion& c) {
			v.agregar(c);
			return v;
		}
};
#endif