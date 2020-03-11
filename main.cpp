#include <iostream>
/*#include "Matriz.h"
#include "Matriz.cpp"*/
#include "Arbol.h"
#include "Arbol.cpp"
#include "ListaSimple.h"
#include "ListaSimple.cpp"
/*#include "Cola.h"
#include "Cola.cpp"*/
/*#include "ListaDoble.h"
#include "ListaDoble.cpp"*/
#include<string>
#include "Operaciones.h"
#include "Operaciones.cpp"
using namespace std;


int main(int argc, char** argv) {
	
	ListaDoble *letras = new ListaDoble();
	Jugador *j1 = new Jugador("Carlos");
	Operaciones *op= new Operaciones();
	op->insertarFichas();
	
	//op->RepartirFichas();
	op->LecturaDeArchivo("example.json");
	op->ValidarPalabraHorizontal("MUNDO",6,10,4, j1);
	op->ValidarPalabraVertical("HOLA",3,6,10, j1);
	
	


	return 0;
}
