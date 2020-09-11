#ifndef _CLASE_ORDENADOR
#define _CLASE_ORDENADOR
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "time.h"
using namespace std;

class Ordenador{
	private:
	
	//Defina aqu� los m�todos auxiliares de los algoritmos de ordenamiento solamente.
    //Puede definir cuantos m�todos quiera.
	
	public:
	
	Ordenador(){};
	~Ordenador(){};
	
	//Si piensa no implementar algunos de los m�todos de ordenamiento, no los borre,
	//simplemente d�jelos con el cuerpo vac�o para evitar errores de compilaci�n, ya
	//que se va a ejecutar el mismo �main� para todas las tareas.
	void seleccion(int * arreglo, int tamano){};
	void insercion(int * arreglo, int tamano){};
	void mergesort(int * arreglo, int tamano){}
	void heapsort(int * arreglo, int tamano){};
	void quicksort(int * arreglo, int tamano){};
	void radixsort(int * arreglo, int tamano){};
};
#endif
