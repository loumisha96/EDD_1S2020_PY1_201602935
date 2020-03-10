#ifndef ARBOL_H
#define ARBOL_H
#include <fstream>
#include <string.h>
#include <iostream>
using namespace std;
typedef class Nodo Nodo;
typedef class Arbol Arbol;
class Nodo
{
	public:
    Nodo * izq;
    Nodo * der;
    char * info;
    Nodo(char * info);
};

class Arbol
{
	public:
	Nodo * raiz;
	string texto;
	Arbol();
    Nodo * buscar(char * info);
    Nodo * buscar(Nodo * actual, char * info);
    bool insertar(char * info);
    bool insertar(Nodo * actual, Nodo * nuevo);
    void preOrden();
    void preOrden(Nodo * actual);
    void inOrden();
    void inOrden(Nodo * actual);
    void postOrden();
    void postOrden(Nodo * actual);
    int calcularAltura();
    int calcularAltura(Nodo * actual);
    int getNodosHoja();
    int getNodosHoja(Nodo * actual);
    Nodo * reporte(Nodo *actual);
    void reporte();
    Nodo * reportePreorden(Nodo *actual);
    void reportePreorden();
    Nodo * reporteInorden(Nodo *actual);
    void reporteInorden();
    Nodo * reportePostorden(Nodo *actual);
    void reportePostorden();
    

};

#endif // ARBOL_H


