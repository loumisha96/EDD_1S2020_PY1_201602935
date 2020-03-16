#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H

typedef class nodoLS nodoLS;
typedef class ListaSimple ListaSimple;

class nodoLS
{
	public:
	char *nombre;
	int punteo;
	nodoLS *sig;
	nodoLS(char * nombre, int punteo);
};
class ListaSimple
{
	public:
		nodoLS *primero;
		int tamLS;
		ListaSimple();
		void insertarOrdenada(char *nombre, int punteo);
		void print();
		void reporte();
		void reporteJugador(char *nombre);
	protected:
};

#endif
