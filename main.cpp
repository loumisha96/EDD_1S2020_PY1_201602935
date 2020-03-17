#include <iostream>
/*#include "Matriz.h"
#include "Matriz.cpp"
//#include "Arbol.h"
//#include "Arbol.cpp"
//#include "ListaSimple.h"
//#include "ListaSimple.cpp"
//#include "Cola.h"
//#include "Cola.cpp"
//#include "ListaDoble.h"
//#include "ListaDoble.cpp"*/
#include<string>
#include "Operaciones.h"
#include "Operaciones.cpp"

using namespace std;


int main(int argc, char** argv) {
	Operaciones *op= new Operaciones();
	op->menu();
	//Jugador *j1 = new Jugador("Carlos");
	//op->usuaios->insertar(j1->nombre);
	
/*
	Jugador *j1 = new Jugador("Carlos");
	Jugador *j2 = new Jugador("Carlos");
	Operaciones *op= new Operaciones();
	op->insertarFichas(op->fichas);
	op->insertarFichas(op->fichasCopia);
	op->RepartirFichas(j1,j2);
	op->LecturaDeArchivo("example.json");*/
	//op->ValidarPalabraVertical("HOLA",3,6,10, j1);
	//op->ValidarPalabraHorizontal("MUNDO",6,10,4, j1);
	//op->matriz->reporte();
    
    //op->matriz->reporte();
    //op->matriz->insertar(11,9,"triples");
    /*op->ValidarPalabraVertical("A",11,11,9, j1);
    op->matriz->reporte();
    op->matriz->reporte();*/
    
	
	
	


	return 0;
}
