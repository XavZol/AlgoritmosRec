/*Ejemplo:
Algoritmo recursivo para resolver las torres de Hanoi
*/
#include<iostream>
using namespace std;

void hanoi(char varinicial, char varcentral, char varfinal, int n){
    if(n==1){
        cout<<"Mover disco "<<n<<"desde varilla "<<varinicial<<" a varilla "<<varfinal<<endl;
    }
    else{
        hanoi(varinicial, varfinal, varcentral, n-1);
        cout<<"Mover disco "<<n<<"desde varilla"<<varinicial<<" a varilla "<<varfinal<<endl;
        hanoi(varcentral, varinicial, varfinal, n-1);
    }
}

int main(){

    cout<<"Ingrese el numero de discos: ";
    int n;
    cin>>n;

    hanoi('A', 'B', 'C', n);
    cout<<endl;
    cout<<"Fin del programa"<<endl;

    return 0;
}