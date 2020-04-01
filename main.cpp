#include <iostream>
#include<string>
#include "Operaciones.h"
#include "Operaciones.cpp"

using namespace std;


int main(int argc, char** argv) {
	Operaciones *op= new Operaciones();
	op->menu();
/*	op->insertarFichas(op->fichas);
	char *a = "A";
	op->fichas->buscar(a);*/
	return 0;
}
