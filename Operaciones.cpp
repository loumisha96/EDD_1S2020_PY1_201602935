#include "Operaciones.h"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <string.h>
using namespace std;
Jugador::Jugador(char *nombre){
	this->nombre = nombre;
	this->fichasJugador = new ListaDoble();
	this->puntaje = 0;
	
}
void Operaciones::LecturaDeArchivo(string archivo){
	ifstream file(archivo.c_str(), ios::app);
	if(!file.fail()){
		json j3;
		file>>j3;
		cout<<j3.at("dimension")<<endl;
		for(int j=0; j<1;j++){
			int x,y;
			for(int j= 0; j<j3.at("casillas").at("dobles").size();j++){
				 x = j3.at("casillas").at("dobles")[j].at("x");
				 y =j3.at("casillas").at("dobles")[j].at("y");
				 matriz->insertar(x,y,"dobles");
			}
			for(int j= 0; j<j3.at("casillas").at("triples").size();j++){
				x =j3.at("casillas").at("triples")[j].at("x");
				y= j3.at("casillas").at("triples")[j].at("y");
				matriz->insertar(x,y,"triples");
			}
		}
		for(int j= 0; j<j3.at("diccionario").size();j++){
			listaDiccionario->insertar(j3.at("diccionario")[j].at("palabra"));
			
		}
	}
};
void Operaciones::ValidarPalabraHorizontal(string palabra, int columnaInicio, int columnaFinal, int fila, Jugador *jugador){
	int p = palabra.size();
	NodoM *aux ;
	string c ;
	bool bandera = true;
	for(int i = 0; i<p; i++){
		while(columnaInicio <= columnaFinal){
				aux= matriz->buscar(fila, columnaInicio);
				c = c+palabra[i];
				char *d =new char[c.length()+1];
				strcpy(d, c.c_str());
				char *pa=strtok(d, "");
				if(aux == NULL){
					matriz->insertar(fila, columnaInicio, pa);
					c = "";
					columnaInicio++;
					i++;
				}
				else{
					
					if(aux->valor == "dobles" || aux->valor =="triples"){
						aux->valorAnt = aux->valor;
						aux->valor = pa;
						c = "";
						columnaInicio++;
						i++;
						
					}else{
						cout<<"Casilla ocupada";
						c = "";
						i=p;
						bandera = false;
						break;
					}
				}
		}
	}
	if(bandera == true){
		
		Encabezado * eFila =matriz->eFilas->getEncabezado(fila);
		NodoM *aux = eFila->acceso;
		while(aux->derecha != NULL&& (aux->derecha->valor != "dobles" || aux->derecha->valor != "triples")){
			c = c+ aux->valor;
			aux = aux->derecha;
		}
		if(aux->valor != "dobles" && aux->valor != "triples")
			c = c+ aux->valor;
		
	}
	
	nodoLC *aux1 = listaDiccionario->primero;
	
	while(aux1->palabra != c && aux1 != listaDiccionario->ultimo){
		aux1 = aux1->sig;
	}
	if(aux1->palabra == c){
		cout<<"PALABRA INGRESADA CORRECTAMENTE\n";
		jugador->puntaje = jugador->puntaje+PuntajeHorizontal(c,fila);
		cout<<"Puntaje de "<<jugador->puntaje<<endl;
	}else{
		cout<<"PALABRA INGRESADA INCORRECTAMENTE\n";
	}
	
	
}
int Operaciones::PuntajeHorizontal(string palabra, int fila){
	int p = palabra.size();
	int puntaje;
	NodoLD *aux ;
	Encabezado *eFila = matriz->eFilas->getEncabezado(fila);
	NodoM *actual= eFila->acceso;
	string letra;
	for(int i=0; i<=p; i++){
		letra = letra + palabra[i];
		aux = fichasCopia->primero;
		while(letra != aux->letra && aux->sig != 0){
			aux = aux->sig;
		}
		if(letra== aux->letra){
			while(letra != actual->valor && actual->derecha != 0){
				actual = actual->derecha;
			}
			if(letra == actual->valor && actual->valorAnt == "dobles"){
				puntaje = 2*aux->puntaje + puntaje;
			}else{
				puntaje = puntaje+aux->puntaje;
			}
			
		}
		letra = "";
	}
	return puntaje;
}
int Operaciones::PuntajeVertical(string palabra, int columna){
	int p = palabra.size();
	int puntaje;
	NodoLD *aux ;
	Encabezado *eColumna = matriz->eColumnas->getEncabezado(columna);
	NodoM *actual= eColumna->acceso;
	string letra;
	for(int i=0; i<=p; i++){
		letra = letra + palabra[i];
		aux = fichasCopia->primero;
		while(letra != aux->letra && aux->sig != 0){
			aux = aux->sig;
		}
		if(letra== aux->letra){
			while(letra != actual->valor && actual->abajo != 0){
				actual = actual->abajo;
			}
			if(letra == actual->valor && actual->valorAnt == "dobles"){
				puntaje = 2*aux->puntaje + puntaje;
			}else{
				puntaje = puntaje+aux->puntaje;
			}
			
		}
		letra = "";
	}
	return puntaje;
}
void Operaciones::ValidarPalabraVertical(string palabra, int filaInicio, int filaFinal, int columna, Jugador *jugador){
	int p = palabra.size();
	NodoM *aux ;
	string c ;
	bool bandera = true;
	for(int i = 0; i<p; i++){
		while(filaInicio <= filaFinal){
			aux= matriz->buscar(filaInicio, columna);
			c = c+palabra[i];
			char *d =new char[c.length()+1];
			strcpy(d, c.c_str());
			char *pa=strtok(d, "");
			if(aux == NULL){
				matriz->insertar(filaInicio, columna, pa);
				c = "";
				filaInicio++;
				i++;
				
			}
			else{
				
				if(aux->valor == "dobles" || aux->valor =="triples"){
					aux->valor = pa;
					c = "";
					filaInicio++;
					i++;
					
				}else{
					if(c!=aux->valor){
						cout<<"Casilla ocupada";
						c = "";
						i=p;
						bandera = false;
						break;
					}else{
						c = "";
						filaInicio++;
						i++;
					}
				}
			}
		}
	}
	if(bandera == true){
		
		Encabezado * eColumna =matriz->eColumnas->getEncabezado(columna);
		NodoM *aux = eColumna->acceso;
		while(aux->abajo != NULL){
			c = c+ aux->valor;
			aux = aux->abajo;
		}
		c = c+ aux->valor;
		cout <<c;
	}
	
	nodoLC *aux1 = listaDiccionario->primero;
	
	while(aux1->palabra != c && aux1 != listaDiccionario->ultimo){
		aux1 = aux1->sig;
	}
	if(aux1->palabra == c){
		cout<<"PALABRA INGRESADA CORRECTAMENTE\n";
		jugador->puntaje = jugador->puntaje + PuntajeVertical(c,columna);
		cout<<"Puntaje de "<<jugador->puntaje<<endl;
		
	}else{
		cout<<"PALABRA INGRESADA INCORRECTAMENTE\n";
	}
}
void Operaciones::insertarFichas(){
	fichas->insertar("A",12,1);
	fichas->insertar("E",12,1);
	fichas->insertar("O",9,1);
	fichas->insertar("I",6,1);
	fichas->insertar("S",6,1);
	fichas->insertar("N",5,1);
	fichas->insertar("L",4,1);
	fichas->insertar("R",5,1);
	fichas->insertar("U",5,1);
	fichas->insertar("T",4,1);
	fichas->insertar("D",5,2);
	fichas->insertar("G",2,2);
	fichas->insertar("C",4,3);
	fichas->insertar("B",2,3);
	fichas->insertar("M",2,3);
	fichas->insertar("P",2,3);
	fichas->insertar("H",2,4);
	fichas->insertar("F",1,4);
	fichas->insertar("V",1,4);
	fichas->insertar("Y",1,4);
	fichas->insertar("Q",1,5);
	fichas->insertar("J",1,8);
	fichas->insertar("�",1,8);
	fichas->insertar("X",1,8);
	fichas->insertar("Z",1,10);
	fichasCopia = fichas;
	
}
int Operaciones::PosicionRandom(){
	int posicion;
	srand(time(NULL));
	if(fichas->tamLD != -1)
		posicion= 0+rand()%(fichas->tamLD+1-1);
	
	return posicion;
}
void Operaciones::RepartirFichas(Jugador *jugador1, Jugador *jugador2){
	NodoLD *aux = fichas->primero;
	int ingresada=0;
	int i=0;
	int pos;
	while(ingresada<7){
		pos = PosicionRandom();
		aux = fichas->primero;
		while( i!= pos && i<fichas->tamLD ){
			aux = aux->sig;
			i++;
		}
		if(aux->cantidad != 0){
			jugador1->fichasJugador->insertar(aux->letra, 1, aux->puntaje);
			fichas->eliminarCantidad(aux->letra,1);
			ingresada++;
			
		}
		i=0;
	}
		
	
	ingresada =0;
	while(ingresada<7){
		pos = PosicionRandom();
		aux = fichas->primero;
		while( i!= pos&& i<fichas->tamLD){
			aux = aux->sig;
			i++;
		}	
		if(aux->cantidad != 0){
			jugador2->fichasJugador->insertar(aux->letra, 1, aux->puntaje);
			
			fichas->eliminarCantidad(aux->letra,1);
			ingresada++;
		}
		i=0;
	}
	
	while(fichas->tamLD>0){
		aux = fichas->primero;
		if(fichas->tamLD >0)
			pos = PosicionRandom();
		while(i != pos&& i<fichas->tamLD){
			aux = aux->sig;
			i++;
		}
		fichasDisponibles->insertar(aux->letra,aux->puntaje);
		fichas->eliminarCantidad(aux->letra,1);
		i=0;
	}
	fichasDisponibles->insertar(fichas->primero->letra,fichas->primero->puntaje);
	fichas->eliminarCantidad(fichas->primero->letra,1);
}
void Operaciones::turno(Jugador * jugador);

