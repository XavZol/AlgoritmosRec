/*Ejemplo:
Algoritmo recursivo de la búsqueda binaria
*/
#include<iostream>
using namespace std;

int busquedaBinaria(int a[], int dato, int inferior, int superior){
    int mitad;

    if(inferior > superior){ //No encontrado
        return-1;
    }
    else{ 
        mitad = (inferior + superior) / 2;
        if(dato == a[mitad]){ //Caso base
            return mitad;
        }
        else if(dato > a[mitad]){ //Casosrecursivos
            return busquedaBinaria(a, dato, mitad + 1, superior);
        }
        else{
            return busquedaBinaria(a, dato, inferior, mitad - 1);
        }
    }
}

int main(){
    cout<<"Busqueda binaria"<<endl;
    cout<<"----------------"<<endl;
    cout<<"Arreglo: "<<endl;
    int a[] = {1, 3, 4, 5, 7, 6};
    int dato = 8;
    int inferior = 0;
    int superior = 5;
    int indice = busquedaBinaria(a, dato, inferior, superior);

    if(indice != -1){
        cout<<"El numero "<<dato<<" se encuentra en la posicion: "<<indice<<endl;
    }

    else{
        cout<<"El numero "<<dato<<" no se encuentra en el arreglo"<<endl;
    }

    cout<<endl;
    
    return 0;
}