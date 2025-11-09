/*Ejemplo:
Hacer un programa que muestre el alfabeto, carácter a carácter, utilizando recursividad mutua o indirecta
*/
#include<iostream>
using namespace std;

//prototipos de funciones
void funcionA(char);
void funcionB(char);

int main(){
    cout<<"Alfabeto: "<<endl;
    funcionA('Z');
    cout<<endl;

    return 0;
}
void funcionA(char letra) {
    if(letra > 'A'){
        funcionB(letra);
    }

    cout<<letra<<" ";
}
void funcionB(char letra){
    funcionA(--letra);
}