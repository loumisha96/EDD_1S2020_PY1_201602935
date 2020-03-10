#include "Cola.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

nodoC::nodoC(char *letra, int punteo){
	this->letra = letra;
	this->punteo = punteo;
	this->sig = 0;
}
Cola::Cola(){
	this->primero = 0;
	this->ultimo = 0;
}
void Cola::insertar(char *letra, int punteo){
	nodoC *nuevo = new nodoC(letra, punteo);
	if(primero== 0){
		primero = nuevo;
		ultimo = nuevo;
		tamC = 0;
	}
	else{
		nuevo->sig = ultimo;
		ultimo = nuevo;
		tamC++;
	}
}
void Cola::eliminar(){
	nodoC *aux= ultimo;
	while(aux->sig != primero){
		aux = aux->sig;
	}
	aux->sig = 0;
	primero = aux;
	tamC--;
}
void Cola::print(){
	nodoC *aux = ultimo;
	while(aux->sig != 0){
		cout<<aux->letra;
		cout<<",";
		cout<<aux->punteo;
		cout<<"\n";
		aux = aux->sig;
	}
	cout<<aux->letra;
	cout<<",";
	cout<<aux->punteo;
}
void Cola::reporte(){
	ofstream reporte;
	reporte.open("RepFichasDisponibles.dot", ios::out);
	if(reporte.fail()){
		cout<<"No se creo el reporte"<<endl;
		
	}else{
		reporte<<"digraph G{\n";
		reporte<<"rankdir = LR;\n";
		reporte<<"node [shape= record,width=.1,height=.1];\n";
		reporte<<"node0[label =\"";
		nodoC* aux = ultimo;
		for(int i= 0; i<=tamC; i++){
			if(aux->sig != 0){
				
				reporte<<aux->letra;
				reporte<<"x";
				reporte<<aux->punteo;
				reporte<<"|";
				aux = aux->sig;
			}
			else{
				reporte<<aux->letra;
				reporte<<"x";
				reporte<<aux->punteo;
			}
				
		}
		reporte<<"\",height=2.5];";
		reporte<<"}";
		reporte.close();
		system("dot -Tpng RepFichasDisponibles.dot -o RepFichasDisponibles.png");
		system("RepFichasDisponibles.png &");
	}
}
