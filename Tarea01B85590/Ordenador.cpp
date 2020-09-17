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
		int min = i;
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

