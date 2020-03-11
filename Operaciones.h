#ifndef OPERACIONES_H
#define OPERACIONES_H
#include "json.hpp"
#include "Matriz.h"
#include "Matriz.cpp"
#include "ListaDobleCircular.h"
#include "ListaDobleCircular.cpp"
#include "ListaDoble.h"
#include "ListaDoble.cpp"
#include "Cola.h"
#include "Cola.cpp"
using namespace std;
using json = nlohmann::json;
typedef class Operaciones Operaciones;
typedef class Jugador Jugador;
class Jugador{
	public:
	int puntaje;
	ListaDoble *fichasJugador;
	char * nombre;
	Jugador(char *nombre);
	
};
class Operaciones
{
	public:
		Matriz *matriz = new Matriz();
		ListaDobleCircular *listaDiccionario = new ListaDobleCircular();
		ListaDoble *fichas = new ListaDoble();
		ListaDoble *fichasCopia = new ListaDoble();
		Cola *fichasDisponibles =new Cola();
		void insertarFichas();
		void LecturaDeArchivo(string archivo);
		void ValidarPalabraHorizontal(string palabra, int columnaInicio, int  columnaFinal, int fila, Jugador *jugador);
		void ValidarPalabraVertical(string palabra, int filaInicio, int filaFinal, int columna,Jugador *jugador);
		void RepartirFichas(Jugador *jugador1, Jugador *jugador2);
		int PosicionRandom();
		int PuntajeHorizontal(string palabra, int fila);
		int PuntajeVertical(string palabra, int columna);
		void turno(Jugador *jugador);
	protected:
};

#endif
