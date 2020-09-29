//Juan Jose Navarro Coto
//B85590
#include "Ordenador.h"

void Ordenador::merge(int *arregloI,int tamanoI,int *arregloD,int tamanoD,int *arreglo)
{
	//se declaran los indices y variables temporales
	int i=0;
	int j=0;
	int k=0;
	//mientras los indices de cada arreglo sean menores
 	while( ( i < tamanoI ) && ( j < tamanoD ) ){
 		//se comparan los valores de los subarreglos
 		//si el valor de la izquierda es mayor
  		if( arregloI[i] <= arregloD[j]){
  			//el arreglo original toma el valor del de la izquierda
   			arreglo[k] = arregloI[i];
   			//se aumenta el indice del arreglo de la izquierda
   			i++;
   		//si el valor de la derecha es mayor
  		}else{
  			//el arreglo original toma el valor del de la derecha
   			arreglo[k] = arregloD[j];
   			//se aumenta el indice del arreglo de la derecha
   			j++;
  		}
  		//se aumenta el indice del arreglo principal
		k++;
 	}

 	//se ordenan el resto de los valores en el arreglo principal
 	//mientras el indice de la izquierda sea menor que su tamano
 	while(i < tamanoI){
 		//el valor del arreglo original toma el valor de subarreglo izquierdo
  		arreglo[k] = arregloI[i];
  		//se incrementan los indices
  		i++;
  		k++;
 	}
 	//mientras el indice de la derecha sea menor que su tamano
 	while(j < tamanoD){
 		//el valor del arreglo original toma el valor de subarreglo derecho
  		arreglo[k] = arregloD[j];
  		//se incrementan los indices
  		j++;
  		k++;
 	}
}


//metodo encargado de realizar el ordenamiento por seleccion
//espera tener ya el arreglo inicializado y lleno
void Ordenador::seleccion(int * arreglo, int tamano)
{
	//se declaran los indices y variables temporales
	int i = 0;
	int j = 0;
	int min = 0;
	int temp = 0;
	//ciclo de i=0 hasta n
	for(i = 0; i < tamano; i++){
		//se establece el i como minimo
		min = i;
		//ciclo de j=i+1 hasta n
		for(j = i+1; j < tamano; j++){
			//si arreglo[j] es menor que arreglo[min]
			if(arreglo[j] < arreglo[min]){
				//se establece el j como minimo
				min = j;
			}
		}
		//se intercambia el valor i con el nuevo minimo
		temp = arreglo[i];
		//A[i] = A[min]
		arreglo[i] = arreglo[min];
		//A[min] = temp
		arreglo[min] =  temp;
	}
}


//metodo encargado de realizar el ordenamiento por inserccion
//espera tener ya el arreglo inicializado y lleno
void Ordenador::insercion(int * arreglo, int tamano)
{
	//se declaran los indices y variables temporales
	int j = 0;
	int key = 0;
	int i = 0;
	 //ciclo de j=1 hasta n
	for(j = 1; j < tamano; j++){
	    //key toma el valor de donde esta el indice j
	    key = arreglo[j];
	    //i toma el valor del indice -1
	    i = j - 1;
	    //mientras i sea mayor o igual que cero y el valor la posicion de i sea mayor que key
	    while(i >= 0 && arreglo[i] > key){
	        //arreglo[i + 1] = A[i]
	        arreglo[ i + 1] = arreglo[i];
	        //i = i - 1
	        i = i -1;
	    }
	    //arreglo[i + 1] = key
	    arreglo[i + 1] = key;
	}
}



//metodo encargado de realizar el ordenamiento por mezcla
//espera tener ya el arreglo inicializado y lleno
void Ordenador::mergesort(int *arreglo,int tamano){
	//si el tamano del arreglo es 1, es trivial
		if(tamano==1)
			return;

		//se calcula la mitad del tamano del arreglo
		int mitad = tamano / 2;
		//se generan dos nuevos arreglo apartir del principal
		int *arregloI = new int[mitad];
		int *arregloD = new int[tamano-mitad];

		//se llena cada uno de los nuevos arreglos con el arreglo original
		for(int i=0; i<mitad; i++)
			arregloI[i] = arreglo[i];
		for(int i=mitad; i<tamano; i++)
			arregloD[i-mitad] = arreglo[i];

		//se llama de manera recursica al mismo metodo
		mergesort(arregloI, mitad);
		mergesort(arregloD, tamano-mitad);
		//se ordena el arreglo principal con los subarreglos
		merge(arregloI, mitad, arregloD, tamano-mitad, arreglo);
}

void Ordenador::actualiza(int* arreglo, int bajo, int alto){
   int raiz = bajo;
   while ((raiz*2)+1 <= alto){
       int nodoIzq = (raiz * 2) + 1;
       int nodoDer = nodoIzq + 1;
       int swap = raiz;
       //revisa si la raiz es menor que el hijo nodoIzq
       if (arreglo[swap] < arreglo[nodoIzq]){
           swap = nodoIzq;
       }
       //si existe nodoDer revisa que sea menor que la raiz
       if ((nodoDer <= alto) && (arreglo[swap] < arreglo[nodoDer]))
       {
           swap = nodoDer;
       }
       if (swap != raiz)
       {
           int tmp = arreglo[raiz];
           arreglo[raiz] = arreglo[swap];
           arreglo[swap] = tmp;
           //continua actualizando mientras cumpla que la raiz sea mayor que sus hijos
           raiz = swap;
       }else{
           break;
       }
   }
}

void Ordenador::monticular(int* arreglo, int bajo, int alto){
   //se utiliza el elemento del medio para el monticulo
   int medio = (alto - bajo -1)/2;
   while (medio >= 0){
       //actualiza los monticulos
       actualiza(arreglo, medio, alto);
       --medio;
   }
}

void Ordenador::heapsort(int* arreglo, int tamano){
    //Coloca el elemento mayor en el arreglo
    monticular(arreglo, 0, tamano-1);
    int altura = tamano - 1;
    while (altura > 0){
        //cambia el maximo elemnto con el mas alto del monticulo
        int tmp = arreglo[altura];
        arreglo[altura] = arreglo[0];
        arreglo[0] = tmp;
        --altura;
        //actualiza los elementos para mantener el orden
        actualiza(arreglo, 0, altura);
    }
}

//funcion de intercambio
void Ordenador::swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


int Ordenador::particion (int * arreglo, int primero, int ultimo){
    int pivote = arreglo[ultimo]; // pivote
    int i = (primero - 1);

    for (int j = primero; j <= ultimo - 1; j++)
    {
        //si el elemento es menor que el pivote
        if (arreglo[j] < pivote)
        {
            i++; // incrementa el indice del menor
            swap(&arreglo[i], &arreglo[j]);
        }
    }
    swap(&arreglo[i + 1], &arreglo[ultimo]);
    return (i + 1);
}


void Ordenador::quicksort(int * arreglo, int primero, int ultimo){
    if (primero < ultimo)
    {
        //se realiza la particion
        int pi = particion(arreglo, primero, ultimo);

        quicksort(arreglo, primero, pi - 1);  // antes de pi
        quicksort(arreglo, pi + 1, ultimo); // despues de pi
    }
}

void Ordenador::quicksort(int * arreglo, int tamano){
    quicksort(arreglo, 0, tamano-1);
}


// Obtiene el valor mayor del arreglo
int Ordenador::max(int* arreglo, int tamano) {
  int max = arreglo[0];
  for (int i = 1; i < tamano; i++)
    if (arreglo[i] > max)
      max = arreglo[i];
  return max;
}


void Ordenador::ordenar(int* arreglo, int tamano, int indice) {
  const int max = 10;
  int retorno[tamano];
  int cont[max];

  for (int i = 0; i < max; ++i)
    cont[i] = 0;

  
  for (int i = 0; i < tamano; i++)
    cont[(arreglo[i] / indice) % 10]++;

  
  for (int i = 1; i < max; i++)
    cont[i] += cont[i - 1];

  // Ordena los elementos de arreglo
  for (int i = tamano - 1; i >= 0; i--) {
    retorno[cont[(arreglo[i] / indice) % 10] - 1] = arreglo[i];
    cont[(arreglo[i] / indice) % 10]--;
  }

	//ordena los valores en el arreglo de retorno
  for (int i = 0; i < tamano; i++)
    arreglo[i] = retorno[i];
}


void Ordenador::radixsort(int* arreglo, int tamano) {
  // obtiene el maximo elemento del arreglo
  int m = max(arreglo, tamano);

  
  for (int indice = 1; m / indice > 0; indice *= 10)
    ordenar(arreglo, tamano, indice);
}



