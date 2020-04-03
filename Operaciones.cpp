#include "Operaciones.h"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <string.h>
using namespace std;

Operaciones::Operaciones(){
	this->dimension = 0;
	this->auxJ1 = 0;
	this->auxJ2=0;
	this->usuaios = new Arbol();
	this->matriz = new Matriz();
	this->auxMatriz = new Matriz();
	this->listaDiccionario = new ListaDobleCircular();
	this->fichas = new ListaDoble();
	this->fichasCopia = new ListaDoble();
	this->fichasDisponibles = new Cola();
	this->scoreboard = new ListaSimple();
}
void Operaciones::menu(){
	
	system("cls");
	string entrada;
	int opcion;
	Nodo *j1,*j2;
	cout<<"1. LECTURA DE ARCHIVO\n";
	cout<<"2. JUGAR\n";
	cout<<"3. Reportes\n";
	usuaios->insertar("RODRI");
	usuaios->insertar("PALM");
	usuaios->insertar("ALEX");
	cin>>opcion;
	switch(opcion){
		case 1:
			system("cls");
			cout<<"INGRESAR NOMBRE DE ARCHIVO\n";
			cin>>entrada;
			entrada = entrada +".json";
			LecturaDeArchivo(entrada);
			menu();
			break;
		case 2:
			system("cls");
			cout<<"1. INGRESAR NUEVO JUGADOR\n";
			cout<<"2. SELECCIONAR JUGADOR\n";
			cin>>opcion;
			if(opcion ==1){
				IngresarJugador();
				
			}else if(opcion == 2){
				
				SeleccionarJugador();
			}
			break;
		case 3:
			system("cls");
			cout<<"1.  PALABRAS DICCIONARIO \n";
			cout<<"2.  FICHAS DISPPONIBLES \n";
			cout<<"3.  USUARIOS \n";
			cout<<"4.  RECORRIDO PREORDEN \n";
			cout<<"5.  RECORRIDO INORDEN \n";
			cout<<"6.  RECORRIDO POSTORDEN \n";
			cout<<"7.  PUNTAJE POR JUGADOR \n";
			cout<<"8.  SCOREBOARD \n";
			cout<<"9.  TABLERO \n";
			cout<<"10. FICHAS DE JUGADOR 1 \n";
			cout<<"11. FICHAS DE JUGADOR 2 \n";
			cin>>opcion;
			reportes(opcion);
			menu();
			break;
	}
		
}
void Operaciones::jugar(Nodo *j1, Nodo * j2){
	bool juego = true;
	bool turnoJ1= true;
	bool turnoJ2 = false;
	while(juego == true){
		string palabra;
		if(turnoJ1 == true){
			system("cls");
			sdf(j1, j2);
			turnoJ1 = false;
			turnoJ2 = true;
		}else if(turnoJ2 == true){
			system("cls");
			sdf(j2, j1);
			turnoJ2 = false;
			turnoJ1 = true;
		}
	}
}
void Operaciones::SeleccionarJugador(){
	matriz = auxMatriz;
	string nombre;
	Nodo *j1,*j2;
	this->usuaios->preOrden(usuaios->raiz);
	cout<<"INGRESAR NOMBRE JUGADOR 1 \n";
	cin>>nombre;
	char *d =new char[nombre.length()+1];
	strcpy(d, nombre.c_str());
	char *pa=strtok(d, "");
	j1 =usuaios->buscar(pa);
	if(j1== NULL){
		
		cout<<"USUARIO NO ENCONTRADO\n";
		SeleccionarJugador();
	}
	
	cout<<"INGRESAR NOMBRE JUGADOR 2 \n";
	cin>>nombre;
	d =new char[nombre.length()+1];
	strcpy(d, nombre.c_str());
	pa=strtok(d, "");
	j2 = usuaios->buscar(pa);
	
	while(j2== NULL){
		cout<<"USUARIO NO ENCONTRADO\n";
		cout<<"INGRESAR NOMBRE JUGADOR 2 \n";
		cin>>nombre;
		char *d =new char[nombre.length()+1];
		strcpy(d, nombre.c_str());
		char *pa=strtok(d, "");
		j2 = usuaios->buscar(pa);
	}
	auxJ1 =j1;
	auxJ2 = j2;
	insertarFichas(fichas);
	insertarFichas(fichasCopia);
	RepartirFichas(j1, j2);
	system("cls");
	jugar(j1,j2);
	
	
}
void Operaciones::IngresarJugador(){
	char *nombre;
	cout<<"INGRESAR NOMBRE JUGADOR 1\n";
	cin>>nombre;
	usuaios->insertar(nombre);
	
	cout<<"INGRESAR NOMBRE JUGADOR 2\n";
	cin>>nombre;
	usuaios->insertar(nombre);
	
	menu();
	
	
}
void Operaciones::reportes(int opcion){
	
	switch(opcion){
		case 1:
			listaDiccionario->reporte();
			break;
		case 2:
			fichasDisponibles->reporte();
			break;
		case 3:
			usuaios->reporte();
			break;
		case 4:
			usuaios->reportePreorden();
			break;
		case 5:
			usuaios->reporteInorden();
			break;
		case 6:
			usuaios->reportePostorden();
			break;
		case 7:
			ReportePorJugador();
			break;
		case 8:
			scoreboard->reporte();
			break;
		case 9:
			matriz->reporte();
			break;
		case 10:
			auxJ1->jugador->fichasJugador->reporte();
			break;
		case 11:
			auxJ2->jugador->fichasJugador->reporte();
			break;
	}
}
void Operaciones::ReportePorJugador(){
	string nombre;
	cout<<"INGRESAR NOMBRE DEL JUGADOR \n";
	cin>>nombre;
	char *d =new char[nombre.length()+1];
	strcpy(d, nombre.c_str());
	char *pa=strtok(d, "");
	Nodo *aux = usuaios->buscar(pa);
	if(aux!=NULL){
		aux->jugador->listapunteo->reporte();
		//scoreboard->reporteJugador(pa);
	}
	else{
		cout<<"USUARIO NO ENCONTRADO\n";
	}
	
}
void Operaciones::LecturaDeArchivo(string archivo){
	ifstream file(archivo.c_str(), ios::out);
	if(!file.fail()){
		json j3;
		file>>j3;
		this->dimension =j3.at("dimension");
		for(int j=0; j<1;j++){
			int x,y;
			for(int j= 0; j<j3.at("casillas").at("dobles").size();j++){
				 x = j3.at("casillas").at("dobles")[j].at("x");
				 y =j3.at("casillas").at("dobles")[j].at("y");
				matriz->insertar(x,y,"dobles");
				auxMatriz->insertar(x,y,"dobles");
			}
			
			for(int j= 0; j<j3.at("casillas").at("triples").size();j++){
				x =j3.at("casillas").at("triples")[j].at("x");
				y= j3.at("casillas").at("triples")[j].at("y");
				matriz->insertar(x,y,"triples");
				auxMatriz->insertar(x,y,"triples");
			}
			
		}
		for(int j= 0; j<j3.at("diccionario").size();j++){
			listaDiccionario->insertar(j3.at("diccionario")[j].at("palabra"));
			
		}
	}
}
void Operaciones::IngresarPalabraHorizontal(string palabra, int columnaInicio, int columnaFinal, int fila, Nodo *jugador){
	int p = palabra.size();
	NodoM *aux ;
	string c ;
	bool bandera = true;
	int columna = columnaInicio;
	columnaFinal = columnaInicio +columnaFinal;
	for(int i = 0; i<p; i++){
		while(columnaInicio < columnaFinal){
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
						if(c!=aux->valor){
							cout<<"Casilla ocupada";
							c = "";
							i=p;
							bandera = false;
							break;
						}else{
							aux->valorAnt = aux->valor;
							c="";
							columnaInicio++;
							i++;
						}
						
					}
				}
		}
	}
	if(bandera == true){
		
		Encabezado * eFila =matriz->eFilas->getEncabezado(fila);
		NodoM *aux = eFila->acceso;
		while(aux->derecha != NULL&& (aux->valor != "dobles" || aux->valor != "triples")){
			if(aux->valor != "dobles"){
				if(aux->valor != "triples"){
					c = c+ aux->valor;
					aux = aux->derecha;
				}else{
					aux= aux->derecha;
				}
			}else
				aux =aux->derecha;
			
		}
		if(aux->valor != "dobles" && aux->valor != "triples")
			c = c+ aux->valor;
		
	}
	
	bool t=listaDiccionario->buscar(c);
	if(t==true){
		nodoC *actualC;
		for(int i = 0; i<=p; i++){
			actualC = fichasDisponibles->primero;
			
			jugador->jugador->fichasJugador->insertar(actualC->letra,1, actualC->punteo);
			
			fichasDisponibles->eliminar();
		}
		cout<<"PALABRA INGRESADA CORRECTAMENTE\n";
		jugador->jugador->puntaje = jugador->jugador->puntaje+PuntajeHorizontal(c,fila);
		
		cout<<"Puntaje de "<<jugador->jugador->puntaje;
	}else{
		NodoLD * actual;
		cout<<"PALABRA INGRESADA INCORRECTAMENTE\n";
		for(int i= 0; i<=p; i++){
			
			while(columna < columnaFinal){
				c= palabra[i];
				aux= matriz->buscar(fila, columna);
				char *d =new char[c.length()+1];
				strcpy(d, c.c_str());
				char *pa=strtok(d,"");
				if(aux->valorAnt == 0){
					matriz->eliminar(fila, columna);
					actual = fichasCopia->buscar(pa);
					jugador->jugador->fichasJugador->insertar(pa,1,actual->puntaje);
					columna++;
					i++;
				}
				else{
					aux->valor = aux->valorAnt;
					actual = fichasCopia->buscar(pa);
					jugador->jugador->fichasJugador->insertar(pa,1,actual->puntaje);
					fila++;
					i++;
					
				}
			}
		}
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
		aux->sig->letra;
		
		while(letra != aux->letra&&aux->sig != 0){
			
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
void Operaciones::IngresarPalabraVertical(string palabra, int filaInicio, int filaFinal, int columna, Nodo *jugador){
	int p = palabra.size();
	NodoM *aux ;
	string c ;
	bool bandera = true;
	int fila = filaInicio;
	filaFinal = filaInicio + filaFinal;
	for(int i = 0; i<p; i++){
		while(filaInicio < filaFinal){
			//matriz->reporte();
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
					aux->valorAnt = aux->valor;
					aux->valor = pa;
					c = "";
					filaInicio++;
					i++;
					
				}else{
					if(c!=aux->valor){
						cout<<"Casilla ocupada " ;
						cout<<aux->valor;
						cout<<"fila";
						cout<<aux->fila;
						cout<<"Columna";
						cout<<aux->columna;
						c = "";
						i=p;
						bandera = false;
						break;
					}else{
						aux->valorAnt = aux->valor;
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
		
		while(aux->abajo != NULL &&(aux->valor!="dobles"|| aux->valor!="triples")&& aux->abajo->fila <= filaFinal+1){
			if((aux->valor != "dobles"&& aux->valor!="triples")){
				
				c = c+ aux->valor;
				aux = aux->abajo;
			}else{
				aux = aux->abajo;
			}
			
			
		}
		if(aux->valor != "dobles"&& aux->valor != "triples" && aux->valor != 0)
			c = c+ aux->valor;
		
	}
	
	bool t = listaDiccionario->buscar(c);
	if(t==true){
		nodoC *actualC;
		for(int i = 0; i<=p; i++){
			actualC = fichasDisponibles->primero;
			jugador->jugador->fichasJugador->insertar(actualC->letra,1, actualC->punteo);
			fichasDisponibles->eliminar();
		}
		
		cout<<"PALABRA INGRESADA CORRECTAMENTE\n";
		jugador->jugador->puntaje = jugador->jugador->puntaje + PuntajeVertical(c,columna);
		
		cout<<"Puntaje de "<<jugador->jugador->puntaje;
		
	}else{
		NodoLD *actual;
		cout<<"PALABRA INGRESADA INCORRECTAMENTE\n";
		for(int i= 0; i<=p; i++){
			
			while(fila < filaFinal){
				c= palabra[i];
				aux= matriz->buscar(fila, columna);
				char *d =new char[c.length()+1];
				strcpy(d, c.c_str());
				char *pa=strtok(d,"");
				if(aux->valorAnt == 0){
					matriz->eliminar(fila, columna);
					actual = fichasCopia->buscar(pa);
					jugador->jugador->fichasJugador->insertar(pa,1,actual->puntaje);
					fila++;
					i++;
				}
				else{
					aux->valor = aux->valorAnt;
					actual = fichasCopia->buscar(pa);
					jugador->jugador->fichasJugador->insertar(pa,1,actual->puntaje);
					fila++;
					i++;
					
				}
			}
		}
	}
}
void Operaciones::insertarFichas(ListaDoble *fichas){
	fichas->insertar("X",1,8);
	fichas->insertar("Z",1,10);
	fichas->insertar("F",1,4);
	fichas->insertar("S",6,1);
	fichas->insertar("N",5,1);
	fichas->insertar("L",4,1);
	fichas->insertar("R",5,1);
	fichas->insertar("U",5,1);
	fichas->insertar("T",4,1);
	fichas->insertar("E",12,1);
	fichas->insertar("D",5,2);
	fichas->insertar("G",2,2);
	fichas->insertar("I",6,1);
	fichas->insertar("C",4,3);
	fichas->insertar("A",12,1);
	fichas->insertar("B",2,3);
	fichas->insertar("O",9,1);
	fichas->insertar("M",2,3);
	fichas->insertar("J",1,8);
	fichas->insertar("P",2,3);
	fichas->insertar("H",2,4);
	fichas->insertar("V",1,4);
	fichas->insertar("Y",1,4);
	fichas->insertar("Q",1,5);
	
}
int Operaciones::PosicionRandom(){
	int posicion;
	srand((unsigned)time(0));
	if(fichas->tamLD != 0){
		posicion=rand()%(fichas->tamLD+1);
		return posicion;
	}
	else
		return 0;
	
	
}
void Operaciones::RepartirFichas(Nodo *j1, Nodo *j2){
	NodoLD *aux = fichas->primero;
	int ingresada=0;
	int i=0;
	int pos;
	while(ingresada<7){
		pos = PosicionRandom();
		aux = fichas->primero;
		fichas->primero->letra;
		aux->letra;
		while( i!= pos && i<=fichas->tamLD ){
			aux = aux->sig;
			i++;
		}
		if(aux->cantidad != 0){
			
			j1->jugador->fichasJugador->insertar(aux->letra, 1, aux->puntaje);
			fichas->eliminarCantidad(aux->letra,1);
			ingresada++;
			
		}
		i=0;
	}
		
	
	ingresada =0;
	while(ingresada<7){
		pos = PosicionRandom();
		aux = fichas->primero;
		while( i!= pos&& i<=fichas->tamLD){
			aux = aux->sig;
			i++;
		}	
		if(aux->cantidad != 0){
			j2->jugador->fichasJugador->insertar(aux->letra, 1, aux->puntaje);
			
			fichas->eliminarCantidad(aux->letra,1);
			ingresada++;
		}
		i=0;
	}
	
	while(fichas->tamLD>0){
		aux = fichas->primero;
		if(fichas->tamLD >0)
			pos = PosicionRandom();
		while(i != pos&& i<=fichas->tamLD){
			aux = aux->sig;
			i++;
		}
		fichasDisponibles->tamC;
		fichasDisponibles->insertar(aux->letra,aux->puntaje);
		fichas->eliminarCantidad(aux->letra,1);
		fichas->primero->letra;
		i=0;
	}
	fichasDisponibles->insertar(fichas->primero->letra,fichas->primero->puntaje);
	fichas->eliminarCantidad(fichas->primero->letra,1);
	
}
bool Operaciones::turno(string palabra,Nodo* jugador){
	int p = palabra.size();
	string c;
	bool correcta = true;
	
	int i=0;
	while(correcta== true && i<=p){
		c = c+palabra[i];
		char *d =new char[c.length()+1];
		strcpy(d, c.c_str());
		char *pa=strtok(d, "");
		NodoLD *aux = jugador->jugador->fichasJugador->primero;
		while(c != aux->letra && aux->sig != 0){
			aux = aux->sig;
		}
		if(c == aux->letra){
			c="";
			i++;
		}
		else{
			if(i!=p)
				correcta=false;
			i++;
		}
	}
	i=0;
	if(correcta == false){
		cout<<"VERIFICAR FICHAS\n";
		return false;
	}
	while(correcta==true && i<=p){
		c = palabra[i];
		char *d =new char[c.length()+1];
		strcpy(d, c.c_str());
		char *pa=strtok(d, "");
		NodoLD *aux = jugador->jugador->fichasJugador->primero;
		while(c!=aux->letra && aux->sig !=0){
			aux = aux->sig;
		}
		if(c == aux->letra){
			jugador->jugador->fichasJugador->eliminarCantidad(aux->letra,1);
			c="";
			i++;
		}else {
			if(i!=p)
				correcta=false;
			i++;
			return true;
				//cout<<"SIGUIENTE TURNO\n";
				
			
			
				
		}
	}
}
void Operaciones::sdf(Nodo *Jactual, Nodo *Jsiguiente){
	string palabra;
	int p, columna,fila, opcion;
	cout<<"TURNO DE: ";
	cout<<Jactual->info<<"  PUNTEO "<< Jactual->jugador->puntaje<<"\n";
	Jactual->jugador->fichasJugador->print();
	cout<<"1.INGRESAR PALABRA\n";
	cout<<"2. CAMBIAR FICHAS\n";
	cout<<"3. TERMINAR JUEGO\n";
	cin>>opcion;
	if(opcion==2){
		cout<<"INGRESAR LETRAS\n";
		cin>>palabra;
		CambiarFichas(palabra,Jactual);
	}else if(opcion ==1){
		cout<<"INGRESAR PALABRA\n";
		cin>>palabra;
		p = palabra.size();
		bool t;
		t=turno(palabra,Jactual);
		if(t==true){
			cout<<"INGRESAR FILA Y COLUMNA DE INICIO\n";
			cin>>fila;
			cin>>columna;
			while(fila> this->dimension || columna > this->dimension){
				cout<<"INGRESAR FILA Y COLUMNA DE INICIO\n";
				cout<<"VALORES NO MAYOR A "<<dimension<<"\n";
				cin>>fila;
				cin>>columna;
			}
			cout<<"1. HORIZONTAL\n";
			cout<<"2. VERTICAL\n";
			cin>>opcion;
			if(opcion==1){
				IngresarPalabraHorizontal(palabra,columna, p, fila, Jactual);
				matriz->reporte();
			}else if(opcion == 2){
				IngresarPalabraVertical(palabra, fila, p, columna, Jactual);
				matriz->reporte();
			}
		}
	}
	else if(opcion ==3){
		scoreboard->insertarOrdenada(Jactual->info, Jactual->jugador->puntaje);
		scoreboard->insertarOrdenada(Jsiguiente->info, Jsiguiente->jugador->puntaje);
		Jactual->jugador->listapunteo->insertarOrdenada(Jactual->info, Jactual->jugador->puntaje);
		Jsiguiente->jugador->listapunteo->insertarOrdenada(Jsiguiente->info, Jsiguiente->jugador->puntaje);
		Jactual->jugador->puntaje = 0;
		Jsiguiente->jugador->puntaje = 0;
		
		menu();
	}
	
}
void Operaciones::CambiarFichas(string letras, Nodo * jugador){
	int l = letras.size();
	string c;
	for(int i = 0; i< l; i++){
		c = letras[i];
		char *d =new char[c.length()+1];
		strcpy(d, c.c_str());
		char *pa=strtok(d, " ");
		char *letra = pa;
		NodoLD*aux = jugador->jugador->fichasJugador->buscar(d);
		if(aux!=NULL){
			//fichasDisponibles->reporte();
			fichasDisponibles->insertar(aux->letra, aux->puntaje);
			//fichasDisponibles->reporte();
			//jugador->jugador->fichasJugador->reporte();
			jugador->jugador->fichasJugador->eliminarCantidad(aux->letra,1);
			//jugador->jugador->fichasJugador->reporte();
			nodoC*nuevo = fichasDisponibles->eliminar();
			jugador->jugador->fichasJugador->insertar(nuevo->letra, 1, nuevo->punteo);
		}
		
	}
}
bool Operaciones::validar(){
	Encabezado *eFila = matriz->eFilas->primero;
	Encabezado *eColumna = matriz->eColumnas->primero;
	int i = 0;
	string palabra;
	//verificando horizontalmente
	nodoLC *aux = listaDiccionario->primero;
	NodoM *actual = eFila->acceso;
	bool t ;
	while(eFila->siguiente !=0){
		i=actual->columna;
		while( i==actual->columna && eFila->siguiente != 0){
			if(actual->derecha!= 0){
				if(actual->derecha != 0&&(actual->valor != "dobles" || actual->valor != "triples")){
					palabra = palabra + actual->valor;
					actual = actual->derecha;
					eColumna = eColumna->siguiente;
					i++;
				}else{
					t= listaDiccionario->buscar(palabra);
					if(t==true){
						if(actual->derecha->valor == "dobles" || actual->derecha->valor == "triples")
						actual = actual->derecha;
							validar(actual);
					}else{
						return false;
					}
					
					
				}
			}else{
				if(actual->valor != "dobles" || actual->valor != "triples"){
					palabra = palabra + actual->valor;
					actual = actual->derecha;
					eFila = eFila->siguiente;
					eColumna= matriz->eColumnas->primero;
					i=0;
				}else{
					
				}
			}
		}
	}
	if(actual->valor != "dobles" || actual->valor != "triples"){
		palabra = palabra+ actual->valor;	
	}
	
	
	
	
	return NULL;
}
bool Operaciones::validar(NodoM * actual){
	
}
