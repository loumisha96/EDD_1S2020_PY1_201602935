#include "ListaDoble.h"

using namespace std;
NodoLD::NodoLD(char*letra, int cantidad){
	this->letra = letra;
	this->cantidad = cantidad;
	this->puntaje = 0;
	this->sig = 0;
	this->ant = 0;
}
NodoLD::NodoLD(char*letra, int cantidad, int puntaje){
	this->letra = letra;
	this->cantidad = cantidad;
	this->puntaje = puntaje;
	this->sig = 0;
	this->ant = 0;
}
ListaDoble::ListaDoble(){
	this->primero = 0;
	this->tamLD=-1;
	
}
void ListaDoble::insertar(char *letra, int cantidad, int puntaje){
	NodoLD *nuevo = new NodoLD(letra, cantidad,puntaje);
	if(tamLD == -1){
		primero = nuevo;
		tamLD = 0;
	}
	else{
		NodoLD*aux = primero;
		bool bandera = false;
		while(aux->sig != NULL){
			if(aux->letra == letra){
				aux->cantidad ++;
				bandera = true;
			}else{
				aux = aux->sig;
			}
		}
		if(aux->letra != letra && bandera == false){
			aux->sig = nuevo;
			nuevo->ant = aux;
			aux = nuevo;
			
			tamLD++;
		}else{
			aux->cantidad ++;
		}
	}
}
void ListaDoble::print(){
	if(tamLD == -1){
		cout<<"Lista Vac�a";
	}else{
		NodoLD * aux = primero;
		while(aux->sig != 0){
			cout<<aux->letra;
			cout<<aux->cantidad;
			aux = aux->sig;
		}
		cout<<aux->letra;
		cout<<aux->cantidad;
	}
}
void ListaDoble::eliminarCantidad(char*letra, int cant){
	NodoLD *aux= primero;
	while(aux->sig != 0){
		if(aux->letra == letra){
			if(aux->cantidad != 0){
				aux->cantidad = aux->cantidad -cant;
				if(aux->cantidad <0){
					aux->cantidad=0;
				}
				break;
			}else{
				break;
			}
		}else{
			aux = aux->sig;
		}
	}
}
void ListaDoble::reporte(){
	ofstream reporte;
		reporte.open("RepFichas.dot", ios::out);
		if (reporte.fail()) {
			cout << "No se creo el reporte" << endl;
			exit(1);
		}
		else {
			reporte << "digraph G{\n";
			reporte << "rankdir = LR;\n";
			reporte << "node[shape = record]; \n";
			NodoLD* aux = primero;
			
				
				for (int i = 0; i <= tamLD; i++) {
					if(aux->sig != 0 && aux != primero){
						reporte<<aux->letra;
						reporte<<aux->cantidad;
						reporte<<"->";
						reporte<<aux->sig->letra;
						reporte<<aux->sig->cantidad;
						reporte<<"\n";
						aux = aux->sig;
					}else if (aux == primero){
						reporte<<aux->letra;
						reporte<<aux->cantidad;
						reporte<<"->";
						reporte<<aux->sig->letra;
						reporte<<aux->sig->cantidad;
						reporte<<"\n";
						aux = aux->sig;
					}
					else{
						while(aux->ant != 0){
							reporte<<aux->letra;
							reporte<<aux->cantidad;
							reporte<<"->";
							reporte<<aux->ant->letra;
							reporte<<aux->ant->cantidad;
							reporte<<"\n";
							aux = aux->ant;
						}
					}
					
				}
				
				
				aux = aux->sig;

			
			reporte << "}";
			reporte.close();
			//string str = "dot -o imagen.out reporte.dot" ;
			system("dot -Tpng RepFichas.dot -o RepFichas.png");
			system("RepFichas.png &");
		}
	
}

