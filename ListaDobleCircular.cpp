#include "ListaDobleCircular.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


nodoLC::nodoLC(string palabra)
{
	this->palabra = palabra;
	this->sig = 0;
	this->ant = 0;	
}
ListaDobleCircular::ListaDobleCircular(){
	this->ultimo = 0;
	this->primero = 0;
	this->tamLC = -1;
}

void ListaDobleCircular::insertar(string palabra){
	nodoLC * nuevo= new nodoLC(palabra);
	if(primero == 0){
		primero = nuevo;
		ultimo = nuevo;
		primero->ant = ultimo;
		ultimo->sig = primero;
		primero->sig = ultimo;
		tamLC = 0;
	}
	else{
		primero->ant = nuevo;
		ultimo->sig = nuevo;
		nuevo->ant = ultimo;
		nuevo->sig = primero;
		ultimo = nuevo;
		tamLC++;
	}
}
void ListaDobleCircular::print(){
	if(tamLC == -1)
		cout<<"Lista Vacia";
	else{
		nodoLC *aux = primero;
		while(aux != ultimo){
			cout<<aux->palabra<<endl;
			aux = aux->sig;
		}
		cout<<aux->palabra<<endl;
		
	}
}
bool ListaDobleCircular::buscar(string palabra){
	nodoLC *aux = primero;
	while(aux != ultimo){
		if(aux->palabra == palabra)
			return true;
		else
			aux = aux->sig;
	}
	if(aux->palabra == palabra)
		return true;
	else
		return false;
}
void ListaDobleCircular::reporte(){
	ofstream reporte;
	reporte.open("RepDiccionario.dot", ios::out);
	if(reporte.fail()){
		cout<<"No se creo el reporte"<<endl;
		
	}
	else{
		reporte<<"digraph G{\n";
		reporte<<"rankdir = LR;\n";
		reporte<<"node [shape= record];\n";
		nodoLC* aux = primero;
		for (int i = 0; i <= tamLC; i++) {
			reporte<<aux->palabra;
			reporte<<"->";
			reporte<<aux->sig->palabra;
			reporte<<"\n";
			reporte<<aux->ant->palabra;
			reporte<<"->";
			reporte<<aux->ant->ant->palabra;
			reporte<<"\n";
			
			aux = aux->sig;
		}
		reporte<<"}";
		reporte.close();
		system("dot -Tpng RepDiccionario.dot -o RepDiccionario.png");
		system("RepDiccionario.png &");
	}
	
}
