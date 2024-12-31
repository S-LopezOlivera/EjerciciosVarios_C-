#include <iostream>
#include <cstdlib>

using namespace std;
int main(){
int numeros[5];
int i;
int contadorN=0;

cout<<"GUIA DE VECTORES, ejercicio 1"<<endl<<endl;

 for (int i=0; i<5; i++){
    cout<<"Ingrese un numero "<<endl;
    cin>>numeros[i];

 }

 cout<<"   --------------------------------------------   "<<endl<<endl;

  for (int j=0; j<5; j++){
    cout<<"Los numeros en el vector son "<<numeros[j]<<endl;

if(numeros[j]<0){
       contadorN++;

}
 }
cout<<"  "<<endl;
 cout<<"   --------------------------------------------   "<<endl<<endl;

cout<<"La cantidad de numeros negativos es de "<<contadorN<<endl<<endl;

return 0;}
