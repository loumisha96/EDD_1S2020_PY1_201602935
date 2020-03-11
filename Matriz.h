#ifndef MATRIZ_H
#define MATRIZ_H

typedef class NodoM NodoM;
typedef class Encabezado Encabezado;
typedef class ListaEncabezados ListaEncabezados;
typedef class Matriz Matriz;

class NodoM
{
public:
    int fila;
    int columna;
    char * valor;
    char *valorAnt;
    NodoM * derecha;
    NodoM * izquierda;
    NodoM * arriba;
    NodoM * abajo;
    NodoM(int fila, int columna, char * valor);
};

class Encabezado
{
public:
    int id;
    Encabezado * siguiente;
    Encabezado * anterior;
    NodoM * acceso;
    Encabezado(int id);
};

class ListaEncabezados
{
public:
    Encabezado * primero;
    void insertar(Encabezado * nuevo);
    Encabezado * getEncabezado(int id);
};

class Matriz
{
public:
    ListaEncabezados * eFilas;
    ListaEncabezados * eColumnas;
    Matriz();
    void insertar(int fila, int columna, char * valor);
    void recorrerFilas();
    void recorrerColumnas();
    void eliminar(int fila, int columna);
    void reporte();
	NodoM *buscar(int fila, int columna);
};

#endif // MATRIZORTOGONAL

