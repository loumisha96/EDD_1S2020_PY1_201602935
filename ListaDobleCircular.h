#ifndef LISTADOBLECIRCULAR_H
#define LISTADOBLECIRCULAR_H
#include <iostream>
//#include <fstream>
#include  <string.h>
using namespace std;
typedef class nodoLC nodoLC;
typedef class ListaDobleCircular ListaDobleCircular;
class nodoLC
{
	public: 
		string palabra;
		nodoLC *sig;
		nodoLC *ant;
		nodoLC(string palabra);

	
};
class ListaDobleCircular
{
	public:
		nodoLC *ultimo;
		nodoLC *primero;
		int tamLC;
		ListaDobleCircular();
		void insertar(string palabra);
		void print();
		void reporte();
		bool buscar(string palabra);
	protected:
};

#endif
