#ifndef COLA_H
#define COLA_H
typedef class nodoC nodoC;
typedef class Cola Cola;

class nodoC
{
	public:
		char *letra;
		int punteo;
		nodoC *sig;
		nodoC(char *letra, int punteo);
	
	
};
class Cola
{
	public:
		nodoC * primero;
		nodoC *ultimo;
		int tamC;
		Cola();
		void insertar(char *letra, int punteo);
		nodoC* eliminar();
		void reporte();
		void print();
	protected:
};

#endif
