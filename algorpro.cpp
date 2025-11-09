/*Ejemplo:
Dado un numero natural N, obtener la suma de los dígitos de que consta. Presentar un algoritmo recursivo y otro iterativo.
*/
#include<iostream>
using namespace std;

//Suma recursiva
int sumaRecursiva(int n){
    if(n<9){ //caso base
        return n;
    }
    else { //caso recursivo 12 3
        return sumaRecursiva(n/10) + n%10;
    }
}

//Solucion iterativa
int sumaIterativa(int n){
    int suma = 0;

    while(n > 9){
        suma += n%10;
        n /= 10;
    }

    return (suma + n);
}

int main(){
    int numero;

    cout<<"Digite un numero: "<<endl;
    cin>>numero;

    cout<<"\nLa suma de los digitos del numero es: "<<endl;
    cout<<"Algoritmo recursivo: "<<sumaRecursiva(numero)<<endl;
    cout<<"Algoritmo iterativo: "<<sumaIterativa(numero)<<endl;
    
    return 0;
}