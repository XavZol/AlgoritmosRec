/*Problema de las N-Reinas */
#include <iostream>
#include <conio.h>
using namespace std;

//Prototipo de funciones
void ponerReina(int, bool&);
bool valido(int);

void mostrarTablero();

const int N = 8;
int reinas[N];

int main(){
    bool solucion;

    ponerReina(0, solucion);

    if(solucion){
        cout<<"Si existe combinacion de reinas"<<endl;
        mostrarTablero();
    }
    else{
        cout<<"No existe combinacion de reinas"<<endl;
    }

    return 0;
}

void ponerReina(int i, bool &solucion){
    int k = 0; //inicializa contador de movimientos
    solucion = false;

    do{
        reinas[i] = k; //Coloca y anota reina i en la fila k
        k++;

        mostrarTablero();
        cout<<endl;

        if(valido(i)){
            if(i<(N-1)){
                ponerReina(i+1, solucion);

                //vuelta atras
                if(!solucion){
                    reinas[i] = 0;
                }
            }
            else{ //Todas las reinas colocadas
                solucion = true;
            }
        }
    }while(!solucion && (k<N));
}
bool valido(int i){
    /*Comprobar si la reina de la columna i no se amenaza con ninguna reina ya puesta*/

    bool v = true;

    for(int r = 0; r<i; r++){
        v = v && (reinas[i] != reinas[r]); //Comprobar si la fila esta vacía.
        v = v && ((reinas[i]-i) != (reinas[r]-r)); //Diagonal 1
        v = v && ((reinas[i]+i) != (reinas[r]+r)); //Diagonal 2
    }

    return v;
}

void mostrarTablero(){
    int tablero[N][N];

    //Asignamos los valores del tablero a 0
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            tablero[i][j] = 0;
        }
    }

    cout<<"\nMostrando arreglo"<<endl;
    for(int i = 0; i<N; i++){
        cout<<reinas[i]<<"|";
    }

    cout<<endl<<endl;

    //Asignamos el valor del arreglo hacia el tablero
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            tablero[reinas[i]][j] = 1;
        }
    }

    cout<<"\nMostrando el tablero"<<endl;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cout<<tablero[i][j]<<"|";
        }
        cout<<endl;
    }

    cout<<endl<<endl;
}