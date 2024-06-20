#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int tam=20, pos1A=0, pos2A=0, pos1, pos2, cantO, cantB;
    char matriz[tam][tam], mov, limpio;

    //Pedimos los datos
    printf("Ingrese el tamaño de la matriz (entre 5 y 20):");
    scanf("%d", &tam);
    if (tam>20 || tam<5)
        tam=10;
    printf("Ingrese la cantidad de obstáculos (entre 5 y 20):");
    scanf("%d", &cantO);
    if (cantO>20 || cantO<5)
        cantO=10;
    printf("Ingrese la cantidad de bombas (entre 5 y 20):");
    scanf("%d", &cantB);
    if (cantB>20 || cantB<5)
        cantB=10;
    if(cantB>(tam*tam)-cantO -1)//Por si las dimensiones no son suficientes
        cantB=(tam*tam)- cantO -2;

    //Inicializamos la matriz
    for(pos1=0;pos1<tam;pos1++)
        for(pos2=0;pos2<tam;pos2++)
            matriz[pos1][pos2]=' ';
    matriz[0][0]='*';
    //Ponemos los obstáculos
    while(cantO>0){
        pos1=rand()%tam;
        pos2=rand()%tam;
        if( matriz[pos1][pos2]==' '){
            matriz[pos1][pos2]='O';
            cantO--;
        }
    }
    //Ponemos las bombas
    while(cantB>0){
        pos1=rand()%tam;
        pos2=rand()%tam;
        if( matriz[pos1][pos2]==' '){
            matriz[pos1][pos2]='B';
            cantB--;
        }
    }

    do{
        printf("\nMueva el asterisco como quiera: Arriba(W), Abajo(S), Derecha(D), Izquierda(A)\n");
        for(pos1=0;pos1<tam;pos1++){
            for(pos2=0;pos2<tam;pos2++)
                if(matriz[pos1][pos2]!='B')
                    printf("|%c",matriz[pos1][pos2]);
                else
                    printf("| ");
            printf("|\n");
        }
        printf("Movimiento: ");
        do{//Limpio el buffer, me quedo solo con la primer letra
            limpio=getchar();
        }while(limpio!='\n');
        mov=getchar();


        //Hago un movimiento ficticio para ver si nos deja en un lugar adecuado
        pos1=pos1A;
        pos2=pos2A;
        switch(mov){
            case 'A':case 'a': pos2--; break; //Izquierda
            case 'D':case 'd': pos2++; break; //Derecha
            case 'W':case 'w': pos1--; break; //Subir
            case 'S':case 's': pos1++; break; //Bajar
            default: printf("Comando equivocado\n"); break;
        }
        if(pos1>=0 && pos1<tam && pos2>=0 && pos2<tam)
            if(matriz[pos1][pos2]=='B'){//Hay una bomba, debo terminar, e indicar que pierde
                matriz[tam-1][tam-1]='*';//Fuerzo la salida
                matriz[pos1A][pos2A]='B';
            }
            else if(matriz[pos1][pos2]!='O'){
                matriz[pos1A][pos2A]=' ';
                matriz[pos1][pos2]='*';
                pos1A=pos1;
                pos2A=pos2;
            }

    }while(matriz[tam-1][tam-1]!='*');

    if(matriz[pos1A][pos2A]=='B')//Se había forzado la salida
        printf("BOOM! Perdiste");
    else
        printf("Ganaste!\n");

    return 0;
}

