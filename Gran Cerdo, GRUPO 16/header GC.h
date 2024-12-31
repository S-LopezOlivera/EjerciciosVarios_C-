#ifndef HEADER_GC_H_INCLUDED
#define HEADER_GC_H_INCLUDED
#include <iostream>
#include <cstdlib> // Necesario para la función rand y srand

using namespace std;

#include <time.h>

int arranque(string, string);
int SumaDados(int Dado[],int);
int TiradaDados(int Dado[],int);
void CargarDado(int Dado[],int);
int Juego(string Ganadores [],int PDV[],int);
void Menu();
int TiradaAs (int Dado[],int);
int DadosIguales (int Dado[],int);
void mostrarDado(int Dado[],int);
void VisualJuego(int,int ,int,string,string,int, int);
void Estadistica (string Ganadores [],int PDV[],int);
void Creditos();

void VisualJuego(int Trufas1,int Trufas2,int Ronda,string j1,string j2,int lanzamiento, int nLanz){
        cout<<"GRAN CERDO"<<endl;
    cout<<"----------------------------------"<<endl;
   cout << j1<<": " << Trufas1 << " trufas acumuladas      "<<j2<<": " << Trufas2 << " trufas acumuladas\n\n";
    cout<<"Es el turno de "<<j1<<endl;

    cout << "+-------------------------+\n";
    cout<<"| RONDAS #"<<Ronda<<"               |\n";
    cout<<"| TRUFAS DE LA RONDA: "<<Trufas1<<"    |\n";
    cout<<"| LANZAMIENTOS: "<< nLanz <<"         |\n";
     cout << "+-------------------------+\n\n";

     cout << "LANZAMIENTO #" <<lanzamiento+1<< "\n\n";
    }

//1 MENU
void Menu() {
        srand(time(NULL));
    cout<<"GRAN CERDO"<<endl;
    cout<<"---------------------"<<endl;
    cout<<"1 - JUGAR"<<endl;
    cout<<"2 - ESTADISTICAS"<<endl;
    cout<<"3 - CERDITOS"<<endl;
    cout<<"---------------------"<< endl;
    cout<<"0 - SALIR"<<endl;
}

//2 OPCION 1
int Juego(string Ganadores [],int PDV[],int J) {
    srand(time(NULL));
    string Vjugador1, Vjugador2;
    char Jugar, S, N, Entrada;
    int n=2,i,TrufasJ1=0, TrufasJ2=0, As,Dado[3],Igualdad=0,OinkJ1=0,OinkJ2=0,LanzamientoJ1=0,LanzamientoJ2=0;
    int LanzamientoMayorJ1=0,LanzamientoMayorJ2=0,RONDA, nLnaz=0;
    int PDVJ1=0, PDVJ2=0, CadaCincuentaJ1=0, CadaCincuentaJ2=0;
    bool band;
    cout<<" ";
    cout<<"Ingrese el nombre del jugador 1: ";
    cin>>Vjugador1;
    cout<<" ";
    cout<<"Ingrese el nombre del jugador 2: ";
    cin>>Vjugador2;
    cout<<" ";
            system("pause");
            system ("cls");
   band=arranque(Vjugador1,Vjugador2);



    system("pause");
    system ("cls");

if(band==1){
     for (i=0;i<5;i++){
    int RONDA=i+1;
       Jugar='S';
        while (Jugar=='S'){
    VisualJuego(TrufasJ1,TrufasJ2,RONDA,Vjugador1,Vjugador2,LanzamientoJ1, nLanz);
        TiradaDados(Dado,n);
        As=TiradaAs (Dado,n);
        Igualdad=DadosIguales(Dado,n);

        if(Igualdad==0 && As==0){
            mostrarDado(Dado,n);
            TrufasJ1+=SumaDados(Dado,n);
            cout<<"Sumas estos puntos: "<<SumaDados(Dado,n)<<endl;
            cout<<"Las trufas acumuladas son: "<<TrufasJ1<<endl;
            cout<<" ";
            cout<<"¿Quieres seguir tirando? (S/N)"<<endl;
            cin>>Jugar;
            if (Jugar=='S'){
                    LanzamientoJ1++;
                    nLanz=LanzamientoJ1;}
            system("pause");
            system ("cls");
            }

        if(Igualdad==n && As==0){
            mostrarDado(Dado,n);
            cout<<"tu cerdo hizo OINK!!! Sumas el doble de puntos y vuelves a tirar."<<endl;
        TrufasJ1+=SumaDados(Dado,n)*2;
        OinkJ1++;
        LanzamientoJ1++;
        nLanz=LanzamientoJ1;
            cout<<" ";
        cout<<"Las trufas acumuladas son: "<<TrufasJ1<<endl;
        system("pause");
        system ("cls");
        }

        if(Igualdad==0 && As>0 && As<n){
            mostrarDado(Dado,n);
            cout<<"Al tener un AS entre tus dados, pierdes las trufas obtenidas en esta ronda. Cedes el turno!"<<endl;
            Jugar='N';
            cout<<" ";
            cout<<"Las trufas acumuladas son: "<<TrufasJ1<<endl;
            system("pause");
            system ("cls");
        }

        if(Igualdad==n && As==n){
            mostrarDado(Dado,n);
            cout<<"Tu cerdo se hundio en el BARRO!"<<endl;
            cout<<"Al tener puros ases, pierdes las trufas obtenidas hasta este momento. Cedes el turno!"<<endl;
            Jugar='N';
            TrufasJ1=0;
            n=3;
            cout<<" ";
            cout<<"Las trufas acumuladas son: "<<TrufasJ1<<endl;
            system("pause");
            system ("cls");
        }

        if (TrufasJ1>=50){
            n=3;
        }
   }


        if (LanzamientoJ1>LanzamientoMayorJ1){
            LanzamientoMayorJ1=LanzamientoJ1;
        }
        LanzamientoJ1=0;
           Jugar='S';



        while (Jugar=='S'){
    VisualJuego(TrufasJ2,TrufasJ1,RONDA,Vjugador2,Vjugador1,LanzamientoJ2);
        TiradaDados(Dado,n);
        As=TiradaAs (Dado,n);
        Igualdad=DadosIguales(Dado,n);

        if(Igualdad==0 && As==0){
            mostrarDado(Dado,n);
            TrufasJ2+=SumaDados(Dado,n);
            cout<<"Sumas estos puntos: "<<SumaDados(Dado,n)<<endl;
            cout<<"Las trufas acumuladas son: "<<TrufasJ2<<endl;
            cout<<" "<<endl;
            cout<<"¿Quieres seguir tirando? (S/N)"<<endl;
            cin>>Jugar;
            if (Jugar=='S'){
                    LanzamientoJ2++;
                    nLanz=LanzamientoJ2;}
            system("pause");
            system ("cls");
            }

        if(Igualdad>=n && As==0){
            mostrarDado(Dado,n);
            cout<<"tu cerdo hizo OINK!!! Sumas el doble de puntos y vuelves a tirar."<<endl;
        TrufasJ2+=SumaDados(Dado,n)*2;
        OinkJ2++;
             cout<<" "<<endl;
           cout<<"Las trufas acumuladas son: "<<TrufasJ2<<endl;
        LanzamientoJ2++;
        nLanz=LanzamientoJ2;
        system("pause");
        system ("cls");
        }

        if(Igualdad==0 && As>0 && As<n){
            mostrarDado(Dado,n);
            cout<<"Al tener un AS entre tus dados, pierdes las trufas obtenidas en esta ronda. Cedes el turno!"<<endl;
            Jugar='N';
            cout<<" "<<endl;
            cout<<"Las trufas acumuladas son: "<<TrufasJ2<<endl;
            system("pause");
            system ("cls");
        }

        if(Igualdad>=n && As==n){
            mostrarDado(Dado,n);
            cout<<"Tu cerdo se hundio en el BARRO!"<<endl;
            cout<<"Al tener puros ases, pierdes las trufas obtenidas hasta este momento. Cedes el turno!"<<endl;
            Jugar='N';
            TrufasJ2=0;
             cout<<" "<<endl;
           cout<<"Las trufas acumuladas son: "<<TrufasJ2<<endl;
            system("pause");
            system ("cls");
        }

            if (TrufasJ2>=50){
            n=3;
        }
   }


        if (LanzamientoJ2>LanzamientoMayorJ2){
            LanzamientoMayorJ2=LanzamientoJ2;
        }
        LanzamientoJ2=0;
   }
}
else {
 for (i=0;i<5;i++){
    RONDA=i+1;
       Jugar='S';
        while (Jugar=='S'){
    VisualJuego(TrufasJ2,TrufasJ1,RONDA,Vjugador2,Vjugador1,LanzamientoJ2);
        TiradaDados(Dado,n);
        As=TiradaAs (Dado,n);
        Igualdad=DadosIguales(Dado,n);

        if(Igualdad==0 && As==0){
            mostrarDado(Dado,n);
            TrufasJ2+=SumaDados(Dado,n);
            cout<<"Sumas estos puntos: "<<SumaDados(Dado,n)<<endl;
            cout<<" "<<endl;
            cout<<"Las trufas acumuladas son: "<<TrufasJ2<<endl;
            cout<<" "<<endl;
            cout<<"¿Quieres seguir tirando? (S/N)"<<endl;
            cin>>Jugar;
            if (Jugar=='S'){
                    LanzamientoJ2++;
                    nLanz=LanzamientoJ2;}
            system("pause");
            system ("cls");
            }

        if(Igualdad>=n && As==0){
            mostrarDado(Dado,n);
            cout<<"tu cerdo hizo OINK!!! Sumas el doble de puntos y vuelves a tirar."<<endl;
        TrufasJ2+=SumaDados(Dado,n)*2;
        OinkJ2++;
            cout<<" "<<endl;
            cout<<"Las trufas acumuladas son: "<<TrufasJ2<<endl;
        LanzamientoJ2++;
        system("pause");
        system ("cls");
        }

        if(Igualdad==0 && As>0 && As<n){
            mostrarDado(Dado,n);
            cout<<"Al tener un AS entre tus dados, pierdes las trufas obtenidas en esta ronda. Cedes el turno!"<<endl;
            Jugar='N';
              cout<<" "<<endl;
          cout<<"Las trufas acumuladas son: "<<TrufasJ2<<endl;
            system("pause");
            system ("cls");
        }

        if(Igualdad==n && As==n){
            mostrarDado(Dado,n);
            cout<<"Tu cerdo se hundio en el BARRO!"<<endl;
            cout<<"Al tener puros ases, pierdes las trufas obtenidas hasta este momento. Cedes el turno!"<<endl;
            Jugar='N';
            TrufasJ2=0;
             cout<<" "<<endl;
           cout<<"Las trufas acumuladas son: "<<TrufasJ2<<endl;
            system("pause");
            system ("cls");
        }

            if (TrufasJ2>=50){
            n=3;
        }
   }

            system("pause");
            system ("cls");

        if (LanzamientoJ2>LanzamientoMayorJ2){
            LanzamientoMayorJ2=LanzamientoJ2;
        }
        LanzamientoJ2=0;

           Jugar='S';


       while (Jugar=='S'){
    VisualJuego(TrufasJ1,TrufasJ2,RONDA,Vjugador1,Vjugador2,LanzamientoJ1);

        TiradaDados(Dado,n);
        As=TiradaAs (Dado,n);
        Igualdad=DadosIguales(Dado,n);

        if(Igualdad==0 && As==0){
            mostrarDado(Dado,n);
            TrufasJ1+=SumaDados(Dado,n);
            cout<<"Sumas estos puntos: "<<SumaDados(Dado,n)<<endl;
             cout<<" "<<endl;
           cout<<"Las trufas acumuladas son: "<<TrufasJ1<<endl;
              cout<<" "<<endl;
          cout<<"¿Quieres seguir tirando? (S/N)"<<endl;
            cin>>Jugar;
            if (Jugar=='S'){
                    LanzamientoJ1++;
                    nLanz=LanzamientoJ1;}
            system("pause");
            system ("cls");
            }

        if(Igualdad>=n && As==0){
            mostrarDado(Dado,n);
            cout<<"tu cerdo hizo OINK!!! Sumas el doble de puntos y vuelves a tirar."<<endl;
        TrufasJ1+=SumaDados(Dado,n)*2;
        OinkJ1++;
             cout<<" "<<endl;
       cout<<"Las trufas acumuladas son: "<<TrufasJ1<<endl;
        system("pause");
        system ("cls");
        }

        if(Igualdad==0 && As>0 && As<n){
            mostrarDado(Dado,n);
            cout<<"Al tener un AS entre tus dados, pierdes las trufas obtenidas en esta ronda. Cedes el turno!"<<endl;
            Jugar='N';
              cout<<" "<<endl;
          cout<<"Las trufas acumuladas son: "<<TrufasJ1<<endl;
            system("pause");
            system ("cls");
        }

        if(Igualdad==n && As==n){
            mostrarDado(Dado,n);
            cout<<"Tu cerdo se hundio en el BARRO!"<<endl;
            cout<<"Al tener puros ases, pierdes las trufas obtenidas hasta este momento. Cedes el turno!"<<endl;
            Jugar='N';
            TrufasJ1=0;
            n=3;
            cout<<" "<<endl;
            cout<<"Las trufas acumuladas son: "<<TrufasJ1<<endl;
            system("pause");
            system ("cls");
        }

        if (TrufasJ1>=50){
            n=3;
        }
   }


        if (LanzamientoJ1>LanzamientoMayorJ1){
            LanzamientoMayorJ1=LanzamientoJ1;
        }
        LanzamientoJ1=0;
   }}

if (TrufasJ1>TrufasJ2){
    PDVJ1+=5;
    }
    else {
        PDVJ2+=5;
    }

CadaCincuentaJ1=TrufasJ1/50;
PDVJ1+=CadaCincuentaJ1;
PDVJ1+=OinkJ1*2;

CadaCincuentaJ2=TrufasJ2/50;
PDVJ2+=CadaCincuentaJ2;
PDVJ2+=OinkJ2*2;

if (LanzamientoMayorJ1>LanzamientoMayorJ2){
    PDVJ1+=3;
}
else {
    PDVJ2+=3;
}

cout<<"TRUFAS EN TOTAL DE "<<Vjugador1<<": "<<TrufasJ1<<endl;
cout<<"--------------------------------"<<endl;
cout<<"TRUFAS EN TOTAL DE "<<Vjugador2<<": "<<TrufasJ2<<endl;
cout<<"--------------------------------"<<endl;
cout<<" "<<endl;
cout<<"El jugador con mayor cantidad de trufas se lleva 5 PUNTOS DE VICTORIA"<<endl;
if (TrufasJ1>TrufasJ2){
    cout<<Vjugador1<<" se lleva 5 TRUFAS."<<endl;
}
else {
    cout<<Vjugador2<<" se lleva 5 TRUFAS."<<endl;
}

    system("pause");
    system ("cls");

cout<<"Cada 50 trufas, cada jugador se lleva 1 PUNTO DE VICTORIA"<<endl;
cout<<" "<<endl;
cout<<Vjugador1<<" se lleva "<<TrufasJ1/50<<" PUNTOS DE VICTORIA "<<endl;
cout<<" "<<endl;
cout<<Vjugador2<<" se lleva "<<TrufasJ2/50<<" PUNTOS DE VICTORIA "<<endl;

    system("pause");
    system ("cls");

cout<<"LA CANTIDAD DE OINKS DE "<<Vjugador1<<" SON: "<<OinkJ1<<endl;
cout<<"--------------------------------"<<endl;
cout<<"LA CANTIDAD DE OINKS DE "<<Vjugador2<<" SON: "<<OinkJ2<<endl;
cout<<"--------------------------------"<<endl;
cout<<" "<<endl;
cout<<"Cada jugador se lleva 2 PUNTOS DE VICTORIA por cada OINK"<<endl;
    system("pause");
    system ("cls");

cout<<"LA MAYOR CANTIDAD DE LANZAMIENTOS EN UNA RONDA DE "<<Vjugador1<<" FUERON: "<<LanzamientoMayorJ1<<endl;
cout<<"--------------------------------"<<endl;
cout<<"LA MAYOR CANTIDAD DE LANZAMIENTOS EN UNA RONDA DE "<<Vjugador2<<" FUERON: "<<LanzamientoMayorJ2<<endl;
cout<<"--------------------------------"<<endl;
cout<<" "<<endl;
cout<<"El jugador con la mayor cantidad de lanzamientos se lleva 3 PUNTOS DE VICTORIA"<<endl;
    system("pause");
    system ("cls");

cout<<"PUNTOS DE VICTORIA TOTALES"<<endl;
cout<<"--------------------------"<<endl;
cout<<"  "<<endl;
cout<<Vjugador1<<": "<<PDVJ1<<endl;
cout<<"  "<<endl;
cout<<Vjugador2<<": "<<PDVJ2<<endl;
cout<<"  "<<endl;
cout<<"  "<<endl;

if (PDVJ1>PDVJ2){
    cout<<Vjugador1<<" ES QUIEN GANO!"<<endl;
    cout<<"  "<<endl;
    cout<<"  "<<endl;
    PDV[J]=PDVJ1;
    Ganadores[J]=Vjugador1;

}
    else {
        if (PDVJ2>PDVJ1){
    cout<<Vjugador2<<" ES QUIEN GANO!"<<endl;
    cout<<"  "<<endl;
    cout<<"  "<<endl;
    PDV[J]=PDVJ2;
    Ganadores[J]=Vjugador2;

}
else {
    cout<<"ES UN EMPATE!!"<<endl;
    cout<<"  "<<endl;
    cout<<"  "<<endl;
}
    }
return 0;
}



//ESTADISTICA
void Estadistica(string Ganadores[], int PDV[],int J){
int x=0, n=1;
cout<<"ESTADISTICAS DE GANADORES:"<<endl;
    for(x=0;x<J;x++){
            if(x%2==0 || x==0){
                cout<<n<<") "<<Ganadores[x]<<" con "<<PDV[x]<<" PUNTOS DE VICTORIA."<<endl;
                n++;
         }
    }
}



//cargartiradaDados
void CargarDado(int Dado[],int N){
    int n;
     cout<<"Ingrese ambos numeros del dado: "<<endl;
    for (int i=0;i<N;i++){
        cin>>n;
    }
}

//TIRADA DE DADOS
int TiradaDados(int Dado[],int N){
    int DadoMayor=0;
    for (int i=0;i<N;i++){
        Dado[i]= (rand()%6+1);
        if(Dado[i]>=DadoMayor){
            DadoMayor=Dado[i];
        }
    }
    return DadoMayor;
}

//Dados Iguales

int DadosIguales(int Dado[], int N) {
    int Iguales=0;
    for (int i=0; i<N-1; i++) {

            for (int x=i+1;x<N;x++) {

            if (Dado[i] == Dado[x]) {
                Iguales++;
            }
        }
    }
    return Iguales;
}

//TiradaAs
int TiradaAs (int Dado[],int N){
    int AS=0;
    for( int i=0;i<N;i++){
        if (Dado[i]==1){
            AS+=Dado[i];
        }
    }
    return AS;
}

//SumaNumeros;
int SumaDados(int Dado[],int N){
    int suma=0;
    for(int i=0;i<N;i++){
        suma+=Dado[i];
    }
return suma;}

//MostrarDado;
void mostrarDado(int Dado[],int N){
    for(int i=0;i<N;i++){
        cout<<"Dado "<<i+1<<"= "<<Dado[i]<<endl;
    }}

//arranque
int arranque(string Vjugador1,string Vjugador2){
    int n=2,DadoMayor1=0, DadoMayor2=0, suma1=0,suma2=0,A=0,Dado[2];
    bool Band;

    while (A==0){
    cout<<"Los dados de "<<Vjugador1<<" son: "<<endl;

    DadoMayor1=TiradaDados(Dado,n);
    suma1=SumaDados(Dado,n);
    mostrarDado(Dado,n);
    cout<<" "<<endl;

    cout<<"La suma total es: "<<suma1<<endl;
    cout<<" "<<endl;
    cout<<"Los dados de "<<Vjugador2<<" son: "<<endl;

    DadoMayor2=TiradaDados(Dado,n);
    suma2=SumaDados(Dado,n);
    mostrarDado(Dado,n);
    cout<<" "<<endl;

    cout<<"La suma total es: "<<suma2<<endl;
    cout<<" "<<endl;
    if (suma1>suma2){
        Band=1;
        A=1;}
        else {
            if(suma2>suma1){
                    Band=0;
                    A=1;}
        else {
            if(DadoMayor1>DadoMayor2){
                Band=1;
                A=1;
            }
            else {
                if (DadoMayor2>DadoMayor1){
                    Band=0;
                    A=1;
                }
                else {
                    A=0;
                }
            }
        }
    }
}
return Band; }


void Creditos(){
    cout<<"Las alumnas encargadas de hacer este juego somos:"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Emilse Narela Pericles"<<endl;
    cout<<endl;
    cout<<"Selva Lopez Olivera"<<endl;
    cout<<endl;
    cout<<"Brenda Anahi Segovia"<<endl;
    cout<<endl;
    }





#endif // HEADER_GC_H_INCLUDED
