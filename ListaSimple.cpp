#include "ListaSimple.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

nodoLS::nodoLS(char * nombre, int punteo)
{
	this->nombre = nombre;
	this->punteo = punteo;
	this->sig = 0;
}
ListaSimple::ListaSimple(){
	this->primero = 0;
	
}
void ListaSimple::insertarOrdenada(char*nombre, int punteo){
	nodoLS *nuevo= new nodoLS(nombre, punteo);
	if(primero == 0){//insertar al inicio
		primero = nuevo;
		tamLS = 0;	
	}
	else{
		bool i =true;
		nodoLS *aux = primero;
		
		while(i==true){
			if(punteo > primero->punteo){
				nuevo->sig = primero;
				primero = nuevo;
				tamLS++;
				i=false;
			}else if(punteo== primero->punteo){
				nuevo->sig = primero;
				primero = nuevo;
				tamLS++;
				i=false;
			}
			else {
				if(aux->sig != 0){
					if(punteo< aux->punteo && punteo>aux->sig->punteo){
						nuevo->sig =aux->sig;
						aux->sig = nuevo;
						tamLS++;
						i=false;
					}else if(punteo == aux->punteo){
						nuevo->sig =aux->sig;
						aux->sig = nuevo;
						tamLS++;
						i=false;
					}
					else{
						
						aux = aux->sig;
					}
				}
				else{
					aux->sig = nuevo;
					tamLS++;
					i= false;
				}
			}
		}
		
		
	}
}
void ListaSimple::print(){
	nodoLS *aux = primero;
	while(aux->sig != 0){
		cout<<aux->punteo;
		aux = aux->sig;
	}
	cout<<aux->punteo<<endl;
	
}
void ListaSimple::reporte(){
	ofstream reporte;
	reporte.open("RepScoreboard.dot", ios::out);
	if(reporte.fail()){
		cout<<"No se creo el reporte"<<endl;
		
	}else{
		reporte<<"digraph G{\n";
		reporte<<"rankdir = LR;\n";
		reporte<<"node [shape= record];\n";
		nodoLS* aux = primero;
		for(int i= 0; i<=tamLS; i++){
			if(aux->sig != 0){
				reporte<<i;
				reporte<<"[label = \"{<ref> | <data>";
				reporte<<aux->nombre;
				reporte<<",";
				reporte<<aux->punteo;
				reporte<<" | }\"]\n";
				reporte<<i+1;
				reporte<<"[label = \"{<ref> | <data>";
				reporte<<aux->sig->nombre;
				reporte<<",";
				reporte<<aux->sig->punteo;
				reporte<<" | }\"]\n";
				reporte<<i;
				reporte<<"->";
				reporte<<i+1;
				reporte<<"\n";
				aux = aux->sig;
			}else  if(i==tamLS && aux != 0 && aux->sig == 0){
				reporte<<i;
				reporte<<"[label = \"{<ref> | <data>";
				reporte<<aux->nombre;
				reporte<<",";
				reporte<<aux->punteo;
				reporte<<" | }\"]\n";
			}
			
			
		}
		reporte<<"}";
		reporte.close();
		system("dot -Tpng RepScoreboard.dot -o RepScoreboard.png");
		system("RepScoreboard.png &");
	}
}
void ListaSimple::reporteJugador(char* nombre){
	ofstream reporte;
	reporte.open("RepJugador.dot", ios::out);
	if(reporte.fail()){
		cout<<"No se creo el reporte"<<endl;
		
	}else{
		reporte<<"digraph G{\n";
		reporte<<"rankdir = LR;\n";
		reporte<<"node [shape= record];\n";
		nodoLS* aux = primero;
		for(int i= 0; i<=tamLS; i++){
			int comparacion = strcmp(nombre, aux->nombre);
			if(aux->sig != 0&& comparacion == 0){
				reporte<<aux->punteo;
				reporte<<"->";
				reporte<<aux->sig->punteo;
				reporte<<"\n";
				aux = aux->sig;
			}
			else{
				aux = aux->sig;
			}
		}
		reporte<<"}";
		reporte.close();
		system("dot -Tpng RepJugador.dot -o RepJugador.png");
		system("RepJugador.png &");
	}
}
