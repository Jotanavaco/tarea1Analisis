#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#define MIN -21474836
#define MAX 21474836
using namespace std;




//metodo encargado de realizar el ordenamiento por seleccion
//espera tener ya el arreglo inicializado y lleno
void seleccion(int * arreglo, int tamano)
{
    //for j = 2 to A.length
    int j = 1;
    int key = 0;
    int i = 0;
    for(j = 2; j <= tamano; j++){
        //key = A[j]
        key = arreglo[j];
        // Insert A[j] into the sorted sequence A[1 .. j - 1].
        //i = j - 1
        i = j - 1;
        //while i > 0 and A[i]> key
        while(i > 0 && arreglo[i] > key){
            //A[i + 1] = A[i]
            arreglo[ i + 1] = arreglo[i];
            //i = i - 1
            i = i -1;
        }
        //A[i + 1] = key
        arreglo[i + 1] = key;
    }
}

//metodo encargador de llenar el arreglo con valores aleatorios
void ordenarArreglo(int* arreglo, int tamano)
{
    for(int indice = 1; indice <= tamano; indice ++){
         arreglo[indice] = MIN + rand()%(MAX - MIN + 1);
    }
}

void impresion(int * arreglo,int tamano)
{
    for(int indice = 1; indice <= tamano; indice ++){
         cout << arreglo[indice] << " ";
    }
    cout << '\n';
}



int main()
{
    int arregloP[20];
    //int arreglo50 [50000];
    //int arreglo100[100000];
    //int arreglo150[150000];
    //int arreglo200[200000];
    srand(time(0));
    clock_t time;
    ordenarArreglo(arregloP, 20);
    impresion(arregloP, 20);
    time = clock();
    //ordenamiento
    seleccion(arregloP, 20);
    time = clock() - time;
    impresion(arregloP, 20);
    cout << "Time: "<< time << '\n';
    return 0;
}
