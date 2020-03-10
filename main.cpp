#include <iostream>
/*#include "Matriz.h"
#include "Matriz.cpp"*/
#include "Arbol.h"
#include "Arbol.cpp"
#include "ListaSimple.h"
#include "ListaSimple.cpp"
#include "Cola.h"
#include "Cola.cpp"
/*#include "ListaDoble.h"
#include "ListaDoble.cpp"*/
#include<string>
#include "Operaciones.h"
#include "Operaciones.cpp"
using namespace std;


int main(int argc, char** argv) {
	
	ListaDoble *letras = new ListaDoble();
	
	
	
	
	
	Operaciones *op= new Operaciones();
//	op->LecturaDeArchivo("example.json");
	op->insertarFichas();
	op->fichas->reporte();
	//ListaDobleCircular *prueba= new ListaDobleCircular();
/*	string palabra = "mundo";
	string pal = "hola";
	op->ValidarPalabraHorizontal(palabra, 8,12,4);
	op->ValidarPalabraVertical(pal,3,6,12);
	op->matriz->reporte();*/
/*prueba->insertar("hola");
prueba->insertar("mundo");
prueba->insertar("prueba");
prueba->insertar("diccionario");
prueba->print();
prueba->reporte();*/

 /*Arbol * abb = new Arbol();
	char var1[] = "Heidy";
	char var2[] = "Carlos";
	char var3[] = "Antonio";
	char var4[] = "Eduardo";
	char var5[] = "Rodrigo";

	abb->insertar(var1);
    abb->insertar(var2);
    abb->insertar(var3);
    abb->insertar(var4);
    abb->insertar(var5);

	abb->reportePreorden();
   // abb->reporteInorden();
//    abb->reportePostorden();
    //abb->reporte();
    //abb->preOrden();
    //abb->inOrden();
    //abb->postOrden();
    //int h = abb->calcularAltura();
    //cout << endl;
    //cout << "Altura: " << h <<endl;

    //int nh = abb->getNodosHoja();
    //cout << "Nodos Hoja: " << nh <<endl;

    delete abb;
   /* ListaSimple *s = new ListaSimple();
    s->insertarOrdenada(var1, 12);
    s->insertarOrdenada(var2, 25);
    s->insertarOrdenada(var3, 50);
    s->insertarOrdenada(var4, 5);
    s->insertarOrdenada(var5, 24);
    s->print();
	s->reporte();*/

/*	Cola *c = new Cola();
	c->insertar(var1, 2);
	c->insertar(var2, 3);
	c->insertar(var3, 4);
	c->insertar(var4, 2);
	c->insertar(var5, 1);
	c->print();


	c->reporte();
	c->eliminar();
	c->
	c->reporte();*/
/*	Matriz * matriz = new Matriz();
    char var1[] = "Doble";
    char var2[] = "S";
    char var3[] = "O";
    char var4[] = "H";
    char var5[] = "O";
    char var6[] = "L";
    char var7[] = "A";
    matriz->insertar(2, 5, "dobles");
    matriz->insertar(2, 5, "triple");
    /*matriz->insertar(10, 15, "dobles");
    matriz->insertar(0, 1, "triples");
    matriz->insertar(6, 10, "triples");
    matriz->insertar(0, 10, "triples");*/
    //matriz->reporte();
    //delete matriz;


	return 0;
}
