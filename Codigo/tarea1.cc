#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include "Ordenador.h"
#define MIN -21474836
#define MAX 21474836
using namespace std;


//metodo encargador de llenar el arreglo con valores aleatorios
void llenarArreglo(int* arreglo, int tamano)
{
    for(int indice = 0; indice < tamano; indice ++){
         arreglo[indice] = 0 + rand()%(MAX - 0 + 1);
    }
}

void impresion(int * arreglo,int tamano)
{
    for(int indice = 0; indice < tamano; indice ++){
         cout << "["<< indice <<"] : " << arreglo[indice] << "\n";
    }
    
}

int comprobar(int* arreglo, int tamano)
{
	for(int indice = 0; indice < tamano-1; indice ++){
		if ( arreglo[ indice ] > arreglo[indice + 1] ){
			cout << "Fallo!\n";
			return 0;
		}
	}
	return 1;
}



int main()
{
	 Ordenador ordenador;
    //int arreglo50 [50000];
    //int arreglo100[100000];
    //int arreglo150[150000];
    int arreglo200[200000];
    
    srand(time(0));
    clock_t time;
    llenarArreglo(arreglo200, 200000);
    time = clock();
    
    
    ordenador.radixsort(arreglo200, 200000);
    
    
    time = clock()- time;
    cout << "Time insercion: "<< float(time)/CLOCKS_PER_SEC << '\n';
    comprobar(arreglo200, 200000);
    
    
    return 0;
}
















