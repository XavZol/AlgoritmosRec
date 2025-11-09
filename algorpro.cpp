/*Salto del Caballo */
#include <iostream>
#include <conio.h>
using namespace std;

const int N = 8;
int tablero[N][N];

//Desplazamientos relativos del caballo
int d[8][2] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

void escribirTablero(){
    int i, j;

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            cout<<tablero[i][j]<<"|";
        }
        cout<<endl;
    }
}

void saltoCaballo(int i, int x, int y, bool &exito)
{
    int nx, ny;
    int k = 0; // inicializa contador de posibles 8 movimientos
    exito = false;

    do
    {
        k++;
        nx = x + d[k - 1][0];
        ny = y + d[k - 1][1];

        // Determina si nuevas coordenadas son aceptables
        if ((nx >= 0) && (nx < N) && (ny >= 0) && (ny < N) && (tablero[nx][ny] == 0))
        {
            // Anota moviemiento
            tablero[nx][ny] = i;
            escribirTablero(); // funcion para mostrar el tablero (matriz)

            if (i < N * N)
            {
                saltoCaballo(i + 1, nx, ny, exito);

                if (!exito)
                {
                    tablero[nx][ny] = 0; // no se alcanzo la solucion, se borra anotacion
                }
            }
            else
            {
                exito = true; // caballo a cubierto el tablero
            }
        }
    } while ((k < 8) && !exito);
}
int main(){
    bool exito;
    int fila=1;
    int columna=0;

    tablero[fila][columna] = 1;

    saltoCaballo(2, fila, columna, exito);

    if(exito){ //Si exito es verdadero, hemos encontrado un camino
        cout<<"Camino encontrado"<<endl; 
        escribirTablero();
    }
    else{
        cout<<"No hay camino"<<endl;
    }

    return 0;
}