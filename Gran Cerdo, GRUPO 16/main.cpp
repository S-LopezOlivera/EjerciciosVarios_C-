#include <iostream>
#include <cstdlib> // Necesario para la función rand y srand
#include <time.h>
#include "header GC.h"
using namespace std;

int arranque(string, string);
int SumaDados(int Dado[],int);
int TiradaDados(int Dado[],int);
void CargarDado(int Dado[],int);
int Juego(string Ganadores [],int PDV[],int);
void Menu();
int TiradaAs (int Dado[],int);
int DadosIguales (int Dado[],int);
void mostrarDado(int Dado[],int);
void VisualJuego(int,int ,int,string,string,int);
void Estadistica (string Ganadores [],int PDV[],int);
void Creditos();

int main(){
    int n,J=0,PDV[100];
    string Ganadores[100];
    void Menu();
    void Creditos();
    do {
        system ("cls");
        Menu();
        cout<<"Elija un numero: "<<endl;
        cin>>n;
        switch (n) {
            case 1:
                Juego(Ganadores, PDV, J);
                break;
            case 2:
                Estadistica(Ganadores, PDV, J);
                break;
            case 3:
                Creditos();
                break;
            case 0:
                cout<<"Hasta pronto!"<<endl;
                break;
            default:
                cout<< "Opcion invalida. Por favor, ingrese otro numero."<<endl;
        }
            system("pause");
          J++;
    } while (n != 0);

    return 0;
}
