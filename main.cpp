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
	
	Operaciones *op= new Operaciones();
	op->insertarFichas();
	
	op->RepartirFichas();
//	op->LecturaDeArchivo("example.json");
	


	return 0;
}
