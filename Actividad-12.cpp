// Actividad-12.cpp :
// Menéndez gómez José Darío

#include <iostream>
#include "Videojuego.h"

int main(){

	char opc = '\0';
	char opc_a = '\0';
	char opc_c = '\0';

	size_t pos;
	size_t cant;
	string nombre;

	float n_x;
	float n_y;
	int n_pts;

	Civilizacion c;
	Videojuego v;
	Aldeano a;

	do {
		system("CLS");
		cout << "Ingrese el numero de la opcion" << endl;
		cout << "1.- Nombre de Usuario" << endl;
		cout << "2.- Agregar" << endl;
		cout << "3.- Insertar" << endl;
		cout << "4.- Inicializar" << endl;
		cout << "5.- Primera" << endl;
		cout << "6.- Ultima" << endl;
		cout << "7.- Ordenar" << endl;
		cout << "8.- Eliminar" << endl;
		cout << "9.- Buscar" << endl;
		cout << "a.- Modificar" << endl;
		cout << "b.- Resumen" << endl;
		cout << "s.- Salir" << endl;

		cin >> opc;

		switch (opc) {
			case '1':
				system("CLS");
				cout << "Ingrese el Nombre de Usuario:" << endl;
				cin.ignore();
				getline(cin, nombre);

				v.setNombreUsuario(nombre);

				cout << "Bienvenido " << v.getNombreUsuario() << endl;
				system("PAUSE");
				break;

			case '2':
				system("CLS");
				cin >> c;
				v << c;
				cout << "Civilizacion agregada exitosamente." << endl;
				system("PAUSE");
				break;

			case '3':
				system("CLS");
				cin >> c;

				cout << "Ingrese la posicion para insertar: " << endl;
				cin >> pos;

				if (pos >= v.total() || pos < 0) {
					cout << "Posicion invalida..." << endl;
				}
				else {
					v.insertar(c, pos);
				}
				system("PAUSE");
				break;

			case '4':
				system("CLS");
				cout << "Ingrese la cantidad de civilizaciones a crear: " << endl;
				cin >> cant;
				cin >> c;

				v.inicializar(c, cant);
				system("PAUSE");
				break;

			case '5':
				system("CLS");
				if (v.total() > 0) {
					v.primera();
				}
				else {
					cout << "Error. El vector esta vacio..." << endl;
				}
				system("PAUSE");
				break;

			case '6':
				system("CLS");
				if (v.total() > 0) {
					v.ultima();
				}
				else {
					cout << "Error. El vector esta vacio..." << endl;
				}
				system("PAUSE");
				break;

			case '7':
				system("CLS");
				if (v.total() > 0) {
					cout << "Ingrese el numero de la opcion" << endl;
					cout << "1.- Ordenar por Nombre" << endl;
					cout << "2.- Ordenar por Coordenadas en X" << endl;
					cout << "3.- Ordenar por Coordenadas en Y" << endl;
					cout << "4.- Ordenar por Puntuacion" << endl;
					cout << "s.- Salir" << endl;

					cin >> opc;

					switch (opc) {
						case '1':
							system("CLS");
							v.ordenar_n();
							system("PAUSE");
							break;

						case '2':
							system("CLS");
							v.ordenar_x();
							system("PAUSE");
							break;

						case '3':
							system("CLS");
							v.ordenar_y();
							system("PAUSE");
							break;

						case '4':
							system("CLS");
							v.ordenar_pts();
							system("PAUSE");
							break;
					}
				}
				else {
					cout << "Error. El vector esta vacio..." << endl;
				}
				break;

				system("PAUSE");
				break;

			case '8':
				system("CLS");
				if (v.total() > 0) {
					cout << "Ingrese el nombre de la civilizacion a eliminar..." << endl;
					cin.ignore();
					getline(cin, nombre);

					v.eliminar(nombre);
				}
				else {
					cout << "Error. El vector esta vacio..." << endl;
				}

				system("PAUSE");
				break;

			case 'b':
				system("CLS");
				if (v.total() > 0) {
					v.resumen();
				}
				else {
					cout << "Error. El vector esta vacio..." << endl;
				}
				system("PAUSE");
				break;

			case 'a':
				system("CLS");
				if (v.total() > 0) {
					cout << "Ingrese el nombre de la civilizacion a modificar..." << endl;
					cin.ignore();
					getline(cin, nombre);				

					Civilizacion *c_mod = v.modificar(nombre);
					system("CLS");

					if (c_mod == nullptr) {
						cout << "No se encontro la civilizacion..." << endl;
					}
					else {

						cout << "Ingrese el numero de la opcion" << endl;
						cout << "1.- Modificar Nombre" << endl;
						cout << "2.- Modificar Coordenadas en X" << endl;
						cout << "3.- Modificar Coordenadas en Y" << endl;
						cout << "4.- Modificar Puntuacion" << endl;
						cout << "s.- Salir" << endl;

						cin >> opc;

						switch (opc) {
						case '1':
							system("CLS");
							cout << "Ingrese el nuevo nombre:" << endl;
							cin.ignore();
							getline(cin, nombre);
							c_mod->setNombre(nombre);
							cout << "El nombre ha sido modificado..." << endl;
							break;

						case '2':
							system("CLS");
							cout << "Ingrese la nueva coordenada en x:" << endl;
							cin >> n_x;
							c_mod->setX(n_x);
							cout << "La coordenada en x ha sido modificada..." << endl;						
							break;

						case '3':
							system("CLS");
							cout << "Ingrese la nueva coordenada en y:" << endl;
							cin >> n_y;
							c_mod->setY(n_y);
							cout << "La coordenada en y ha sido modificada..." << endl;
							break;

						case '4':
							system("CLS");
							cout << "Ingrese la nueva puntuacion:" << endl;
							cin >> n_pts;
							c_mod->setPts(n_pts);
							cout << "La puntuacion ha sido modificada..." << endl;
							break;
						}
					}
				}
				else {
					cout << "Error. El vector esta vacio..." << endl;
				}
				system("PAUSE");
				break;

			case '9':
				system("CLS");
				if (v.total() > 0) {
					cout << "Ingrese el nombre de la civilizacion a buscar..." << endl;
					cin.ignore();
					getline(cin, nombre);

					Civilizacion* c_ptr = v.buscar(nombre);

					if (c_ptr == nullptr) {
						cout << "No se encontro la civilizacion..." << endl;
						system("PAUSE");
					}
					else {

						do {
							system("CLS");
							cout << left;
							cout << setw(30) << "Nombre de la Civilizacion";
							cout << setw(20) << "Coordenadas en X";
							cout << setw(20) << "Coordenadas en Y";
							cout << setw(20) << "Puntuacion";
							cout << endl;
							cout << *c_ptr << endl;

							cout << "Ingrese el numero de la opcion" << endl;
							cout << "1.- Agregar Aldeano" << endl;
							cout << "2.- Eliminar Aldeano" << endl;
							cout << "3.- Clasificar Aldeanos" << endl;
							cout << "4.- Buscar Aldeano" << endl;
							cout << "5.- Modificar Aldeano" << endl;
							cout << "6.- Mostrar Aldeanos" << endl;
							cout << "s.- Salir" << endl;

							cin >> opc_c;

							switch (opc_c) {

							case '1':
								do {
									system("CLS");
									cout << "Ingrese el numero de la opcion" << endl;
									cout << "1.- Agregar Aldeano al Inicio" << endl;
									cout << "2.- Agregar Aldeano al Final" << endl;
									cout << "s.- Salir" << endl;

									cin >> opc_a;
									switch (opc_a) {
										case '1':
											system("CLS");
											cin >> a;
											c.agregarAdeano_i(a);
											cout << "Aldeano agregado..." << endl;
											c_ptr->setPts(100);
											system("PAUSE");
											break;

										case '2':
											system("CLS");
											cin >> a;
											c.agregarAdeano_f(a);
											cout << "Aldeano agregado..." << endl;
											c_ptr->setPts(100);
											system("PAUSE");
											break;
									}

								} while (opc_a != 's');
								break;

							case '2':
								do {
									system("CLS");
									cout << "Ingrese el numero de la opcion" << endl;
									cout << "1.- Eliminar por Nombre" << endl;
									cout << "2.- Eliminar Menores a X" << endl;
									cout << "3.- Eliminar Mayores de 60" << endl;
									cout << "s.- Salir" << endl;

									cin >> opc_a;
									switch (opc_a) {
									case '1':
										system("CLS");
										system("PAUSE");
										break;

									case '2':
										system("CLS");
										system("PAUSE");
										break;
									}
								} while (opc_a != 's');
								break;

							}
						} while (opc_c != 's');
					}
				}
				else {
					cout << "Error. El vector esta vacio..." << endl;
					system("PAUSE");
				}
				break;
		}

	} while (opc != 's');
}