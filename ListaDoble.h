#ifndef LISTADOBLE_H
#define LISTADOBLE_H
#include <iostream>
#include <string.h>
#include <fstream>


using namespace std;
typedef class NodoLD NodoLD;
typedef class ListaDoble ListaDoble;
class NodoLD{
	public:
	char *letra;
	NodoLD* sig;
	NodoLD* ant;
	int cantidad;
	int puntaje;
	NodoLD(char *letra, int cant) ;
	NodoLD(char *letra, int cant, int puntaje);
};
class ListaDoble
{
	public:
		NodoLD* ultimo;
		NodoLD* primero;
		int tamLD;
		int rep;
		ListaDoble();
		void insertar(char *letra, int cantidad, int puntaje);
		void eliminarCantidad(char *letra, int cant);
		void print();
		void reporte();
	protected:
};

#endif
