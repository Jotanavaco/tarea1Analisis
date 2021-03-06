//Juan Jose Navarro Coto
//B85590
#ifndef _CLASE_ORDENADOR
#define _CLASE_ORDENADOR

#include <iostream>
#include <cstdlib>
#include <cmath>
#include "time.h"
#include <ctime>
#include <climits>
#include <stdio.h>
#include <string.h>
#include <new>  
#define MIN -21474836
#define MAX 21474836
using namespace std;

class Ordenador{
	private:
	
	//Defina aqu� los m�todos auxiliares de los algoritmos de ordenamiento solamente.
    //Puede definir cuantos m�todos quiera.
    void merge(int *arregloI,int tamanoI,int *arregloD,int tamanoD,int *arreglo);
    void actualiza(int* arreglo, int bajo, int alto);
    void monticular(int* arreglo, int bajo, int alto);
    void quicksort(int * arreglo, int primero, int ultimo);
    int particion (int * arreglo, int primero, int ultimo);
    void swap(int* a, int* b);
    void ordenar(int* arreglo, int tamano, int indice); 
    int max(int* arreglo, int tamano);
	
	public:
	
	Ordenador(){};
	~Ordenador(){};
	
	//Si piensa no implementar algunos de los m�todos de ordenamiento, no los borre,
	//simplemente d�jelos con el cuerpo vac�o para evitar errores de compilaci�n, ya
	//que se va a ejecutar el mismo �main� para todas las tareas.
	
	
	void seleccion(int * arreglo, int tamano);
	void insercion(int * arreglo, int tamano);
	void mergesort(int *arreglo,int tamano);
	void heapsort(int * arreglo, int tamano);
	void quicksort(int * arreglo, int tamano);
	void radixsort(int * arreglo, int tamano);
};


#endif
