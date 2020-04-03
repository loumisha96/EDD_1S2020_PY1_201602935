#include <iostream>
#include<string>
#include "Operaciones.h"
#include "Operaciones.cpp"

using namespace std;


int main(int argc, char** argv) {
	Operaciones *op= new Operaciones();
	op->menu();
	/*for(int i = 0 ; i<12; i++){
		for (int j = 0; j<12; j++){
			if(i != j)
				op->matriz->insertar(i,j, ".");
		}
	}
	op->matriz->reporte();*/
	return 0;
}
