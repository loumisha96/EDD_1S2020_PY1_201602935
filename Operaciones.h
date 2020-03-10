#ifndef OPERACIONES_H
#define OPERACIONES_H
#include "json.hpp"
#include "Matriz.h"
#include "Matriz.cpp"
#include "ListaDobleCircular.h"
#include "ListaDobleCircular.cpp"
#include "ListaDoble.h"
#include "ListaDoble.cpp"
using namespace std;
using json = nlohmann::json;
typedef class Operaciones Operaciones;
class Operaciones
{
	public:
		Matriz *matriz = new Matriz();
		ListaDobleCircular *listaDiccionario = new ListaDobleCircular();
		ListaDoble *fichas = new ListaDoble();
		void insertarFichas();
		void LecturaDeArchivo(string archivo);
		void ValidarPalabraHorizontal(string palabra, int columnaInicio, int  columnaFinal, int fila);
		void ValidarPalabraVertical(string palabra, int filaInicio, int filaFinal, int columna);
	protected:
};

#endif
