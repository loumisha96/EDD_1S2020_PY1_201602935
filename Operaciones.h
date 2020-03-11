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
class Operaciones
{
	public:
		Matriz *matriz = new Matriz();
		ListaDobleCircular *listaDiccionario = new ListaDobleCircular();
		ListaDoble *fichas = new ListaDoble();
		ListaDoble *fichasJugador1 = new ListaDoble();
		ListaDoble *fichasJugador2 = new ListaDoble();
		Cola *fichasDisponibles =new Cola();
		void insertarFichas();
		void LecturaDeArchivo(string archivo);
		void ValidarPalabraHorizontal(string palabra, int columnaInicio, int  columnaFinal, int fila);
		void ValidarPalabraVertical(string palabra, int filaInicio, int filaFinal, int columna);
		void RepartirFichas();
		int PosicionRandom();
	protected:
};

#endif
