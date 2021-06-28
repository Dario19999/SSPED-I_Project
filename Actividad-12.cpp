// Actividad-12.cpp :
// Menéndez gómez José Darío

#include <iostream>
#include "Videojuego.h"

int main()
{

	char opc = '\0';
	char opc_a = '\0';
	char opc_c = '\0';
	char opc_b = '\0';

	size_t pos, cant, id;
	string nombre;

	int edad, salud, n_pts;
	string genero;

	float n_x, n_y, combustible;

	Civilizacion c;
	Videojuego v;
	Aldeano a;
	Guerrero g;

	do {
		system("CLS");
		cout << "Ingrese el numero de la opcion" << endl;
		cout << "1.- Nombre de Usuario" << endl;
		cout << "2.- Agregar Civilizacion" << endl;
		cout << "3.- Insertar Civilizacion" << endl;
		cout << "4.- Inicializar Civilizaciones" << endl;
		cout << "5.- Primera" << endl;
		cout << "6.- Ultima" << endl;
		cout << "7.- Ordenar" << endl;
		cout << "8.- Eliminar" << endl;
		cout << "9.- Buscar" << endl;
		cout << "a.- Modificar" << endl;
		cout << "b.- Resumen" << endl;
		cout << "w.- Respaldar Civilizaciones" << endl;
		cout << "r.- Recuperar Civilizaciones" << endl;
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
							cout << "7.- Barcos" << endl;
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
											c_ptr->agregarAdeano_i(a);
											cout << "Aldeano agregado..." << endl;
											c_ptr->setPts(100);
											system("PAUSE");
											break;

										case '2':
											system("CLS");
											cin >> a;
											c_ptr->agregarAdeano_f(a);
											cout << "Aldeano agregado..." << endl;
											c_ptr->setPts(100);
											system("PAUSE");
											break;
									}

								} while (opc_a != 's');
								break;

							case '2':
								if (c_ptr->totalAldeanos() > 0) {
									do {
										system("CLS");
										cout << "Ingrese el numero de la opcion" << endl;
										cout << "1.- Eliminar por Nombre" << endl;
										cout << "2.- Eliminar Aldeanos con Salud Menor a X" << endl;
										cout << "3.- Eliminar Mayores de 60" << endl;
										cout << "s.- Salir" << endl;

										cin >> opc_a;
										switch (opc_a) {
										case '1':
											system("CLS");
											cout << "Ingrese el nombre del aldeano a eliminar..." << endl;
											cin.ignore();
											getline(cin, nombre);

											c_ptr->eliminarNombre(nombre);
											system("PAUSE");
											break;

										case '2':
											system("CLS");
											cout << "Ingrese la salud limite..." << endl;
											cin >> cant;

											c_ptr->eliminarSalud(cant);
											system("PAUSE");
											break;

										case '3':
											system("CLS");
											c_ptr->eliminarEdad();
											system("PAUSE");
											break;
										}
									} while (opc_a != 's');
								}
								else {
									cout << "Error. No hay aldeanos..." << endl;
								}
								break;

							case '3':
								system("CLS");
								if (c_ptr->totalAldeanos() > 0) {
									do {
										system("CLS");
										cout << "Ingrese el numero de la opcion" << endl;
										cout << "1.- Clasificar por Nombre" << endl;
										cout << "2.- Clasificar por Edad" << endl;
										cout << "3.- Clasificar por Salud" << endl;
										cout << "s.- Salir" << endl;

										cin >> opc_a;
										switch (opc_a) {
										case '1':
											system("CLS");
											c_ptr->ordenarNombre();
											system("PAUSE");
											break;

										case '2':
											system("CLS");
											c_ptr->ordenarEdad();
											system("PAUSE");
											break;

										case '3':
											system("CLS");
											c_ptr->ordenarSalud();
											system("PAUSE");
											break;
										}
									} while (opc_a != 's');
								}
								else {
									cout << "Error. No hay aldeanos..." << endl;
								}
								system("PAUSE");
								break;

							case '4':
							{
								system("CLS");
								cout << "Ingrese el nombre del aldeano a buscar..." << endl;
								cin.ignore();
								getline(cin, nombre);

								Aldeano* a_b = c_ptr->buscarAldeano(nombre);

								if (a_b != nullptr) {
									cout << left;
									cout << setw(30) << "Nombre";
									cout << setw(20) << "Edad";
									cout << setw(20) << "Salud";
									cout << setw(20) << "Genero";
									cout << endl;
									cout << *a_b << endl;;
								}
								else {
									cout << "El aldeano no existe..." << endl;
								}
								system("PAUSE");
								break;
							}
							case '5':
								system("CLS");
								if (c_ptr->totalAldeanos() > 0) {
									cout << "Ingrese el nombre del aldeano a modificar..." << endl;
									cin.ignore();
									getline(cin, nombre);
									
									Aldeano* a_m = c_ptr->buscarAldeano(nombre);

									if (a_m != nullptr) {
										do {
											system("CLS");
											cout << "Ingrese el numero de la opcion" << endl;
											cout << "1.- Modificar Nombre de Aldeano" << endl;
											cout << "2.- Modificar Edad de Aldeano" << endl;
											cout << "3.- Modificar Salud de Aldeano" << endl;
											cout << "4.- Modificar Genero de Aldeano" << endl;
											cout << "s.- Salir" << endl;

											cin >> opc_a;
											switch (opc_a) {
											case '1':
												system("CLS");
												cout << "Ingrese el nuevo nombre del aldeano:" << endl;
												cin.ignore();
												getline(cin, nombre);

												a_m->setNombre(nombre);
												system("PAUSE");
												break;

											case '2':
												system("CLS");
												cout << "Ingrese la nueva edad del aldeano:" << endl;
												cin >> edad;

												a_m->setEdad(edad);
												system("PAUSE");
												break;

											case '3':
												system("CLS");
												cout << "Ingrese la nueva salud del aldeano:" << endl;
												cin >> salud;

												a_m->setSalud(salud);
												system("PAUSE");
												break;

											case '4':
												system("CLS");
												cout << "Ingrese el nuevo genero del aldeano:" << endl;
												cin >> genero;

												a_m->setGenero(genero);
												system("PAUSE");
												break;
											}

										} while (opc_a != 's');
									}
									else {
										cout << "El aldeano no existe..." << endl;
									}
									break;
								}
								else {
									cout << "Error. No hay aldeanos..." << endl;
								}
								system("PAUSE");
								break;

							case '6':
								system("CLS");
								if (c_ptr->totalAldeanos() > 0) {
									c_ptr->mostrarAldeanos();
								}
								else {
									cout << "Error. No hay aldeanos..." << endl;
								}
								system("PAUSE");
								break;

							case '7':
								do {
									system("CLS");
									cout << "Ingrese el numero de la opcion" << endl;
									cout << "1.- Agregar Barco" << endl;
									cout << "2.- Mostrar Flota" << endl;
									cout << "3.- Buscar Barco" << endl;
									cout << "4.- Eliminar Barco" << endl;
									cout << "s.- Salir" << endl;

									cin >> opc_b;
									switch (opc_b) {
									case '1':
										system("CLS");
										c_ptr->capturarBarco();
										system("PAUSE");
										break;

									case '2':
										system("CLS");
										if (c_ptr->totalBarcos() > 0) {
											c_ptr->mostrarFlota();
										}
										else {
											cout << "Error. No hay barcos en la flota..." << endl;
										}
										system("PAUSE");
										break;

									case '3':
									{
										system("CLS");
										if (c_ptr->totalBarcos() > 0) {
											cout << "Ingrese el ID del Barco a buscar: ";
											cin >> id;

											Barco* b = c_ptr->buscarBarco(id);

											if (b != nullptr) {
												do {
													system("CLS");
													cout << left;
													cout << setw(10) << "ID";
													cout << setw(20) << "Combustible";
													cout << setw(20) << "Armadura";
													cout << setw(20) << "Velocidad";
													cout << setw(20) << "Guerreros Abordo";
													cout << endl;
													cout << *b << endl << endl;

													cout << "Ingrese el numero de la opcion" << endl;
													cout << "1.- Agregar Guerrero" << endl;
													cout << "2.- Eliminar Guerrero" << endl;
													cout << "3.- Mostrar Ultimo Guerrero" << endl;
													cout << "4.- Mostrar Guerreros Abordo" << endl;
													cout << "s.- Salir" << endl;

													cin >> opc_a;

													switch (opc_a) {
													case '1':
														system("CLS");
														cin >> g;
														b->agregarGuerrero(g);
														cout << "Guerrero agregado a las filas del ejercito..." << endl << endl;
														system("PAUSE");
														break;

													case '2':
														system("CLS");
														if (b->totalGuerreros() > 0) {
															b->eliminarGuerrero();
															cout << "Guerrero eliminado de las filas del ejercito..." << endl << endl;
														}
														else {
															cout << "Error. No hay guerreros" << endl;
														}
														system("PAUSE");
														break;

													case '3':
														system("CLS");
														if (b->totalGuerreros() > 0) {
															cout << "El guerrero mas reciente es: " << endl;
															cout << left;
															cout << setw(10) << "ID";
															cout << setw(20) << "Salud";
															cout << setw(20) << "Fuerza";
															cout << setw(20) << "Escudo";
															cout << setw(20) << "Tipo";
															cout << endl;
															cout << *b->tope() << endl;
														}
														else {
															cout << "Error. No hay guerreros" << endl;
														}
														system("PAUSE");
														break;

													case '4':
														system("CLS");
														if (b->totalGuerreros() > 0) {
															b->mostrarEjercito();
														}
														else {
															cout << "Error. No hay guerreros" << endl;
														}
														system("PAUSE");
														break;
													}
												} while (opc_a != 's');
											}
											else {
												cout << "Error. El barco no existe..." << endl;
											}
										}
										else {
											cout << "Error. No hay barcos en la flota..." << endl;
										}
										system("PAUSE");
										break;
									}
									case '4':
										system("CLS");
										if (c_ptr->totalBarcos() > 0) {
											do {
												system("CLS");
												cout << "Ingrese el numero de la opcion" << endl;
												cout << "1.- Eliminar por ID" << endl;
												cout << "2.- Eliminar por Combustible Menor a X" << endl;
												cout << "s.- Salir" << endl;

												cin >> opc_a;

												switch (opc_a) {
												case '1':
													system("CLS");
													cout << "Ingrese el ID del barco a eliminar: ";
													cin >> id;

													c_ptr->eliminarBarco_id(id);
													system("PAUSE");
													break;

												case '2':
													system("CLS");
													cout << "Ingrese el combustible de referencia para eliminar: ";
													cin >> combustible;

													c_ptr->eliminarBarco_comb(combustible);
													system("PAUSE");
													break;
												}
											} while (opc_a != 's');
										}
										else {
											cout << "Error. No hay barcos en la flota..." << endl;
										}
										system("PAUSE");
										break;
									}

								} while (opc_b != 's');
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

				case 'w':
					system("CLS");
					if (v.total() > 0) {
						v.respaldar();
					}
					else {
						cout << "Error. El vector esta vacio..." << endl;
					}
					system("PAUSE");
					break;

				case 'r':
					system("CLS");
					v.recuperar();
					system("PAUSE");
					break;
		}

	} while (opc != 's');
}