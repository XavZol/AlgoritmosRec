/*Ejemplo:
Algoritmo MergeSort
*/
#include<iostream>
using namespace std;
void  mezcla(int a[], int izquierda, int medio, int derecha){
	int *aux; 
	int i,k,z;
	
	aux= new int[derecha-izquierda +1];
	i = z = izquierda;
	k= medio +1;
	
	while(i<=medio && k<=derecha){ //bucle para la mezcla, utiliza aux[] como arreglo auxiliar 
		if(a[i]<=a[k]){
			aux[z++] = a[i++];
		}
		else{
			aux[z++] = a[k++];
		}
	}
	
	while(i<=medio){  //Se mueven elementos no mezclados de sublistas
		aux[z++] =a[i++];
	}
	
	while(k<=derecha){
		aux[z++] = a[k++];
	}

    for(int i=izquierda; i<=derecha; i++){ //Copia de elementos de aux[] hacia a[]
        a[i] = aux[i];
    }

    delete [] aux;
}
void mergesort(int a[], int primero, int ultimo){
    int central;

    if(primero < ultimo){
        central = (primero+ultimo)/2;
        mergesort(a,primero,central); //ordena primera mitad de la lista
        mergesort(a, central+1, ultimo); //Ordenamos segunda mitad de la lista
        mezcla(a, primero, central, ultimo); //fusiona las dos sublistas ordenadas, delimitadas por los extremos.
    }
    else{
        return;
    }

}

int main(){
    cout<<"Ejemplo de algoritmo MergeSort"<<endl;
    int a[] = {5, 3, 4, 1, 2};

    cout<<"Lista original: "<<endl;

    for(int i=0; i<5; i++){
        cout<<a[i]<<" ";
    }

    cout<<"\nLista ordenada: "<<endl;
    mergesort(a, 0, 4);
    for(int i=0; i<5; i++){
        cout<<a[i]<<" ";
    }

    cout<<endl;
    
    return 0;
}