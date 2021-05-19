#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int piedra1=0, piedra2=0, piedra3=0, piedra4=0, piedra5=0, aux=0, conteo=0, puntaje=0;
    int i,j,h;
    int opc;
    char matriz[10][20];
    char pal1[20];
    char recep[strlen(pal1)+1];
    char pie1[4]="rubi";
    
    for(i=0;i<10;i++){
        for(j=0;j<20;j++){
            matriz[i][j]= 'a' + (rand() % ('z' - 'a'));
             
        }
    }

//palabras para buscar
matriz[1][0]='r',matriz[1][1]='u',matriz[1][2]='b',matriz[1][3]='i';
matriz[2][10]='o',matriz[2][11]='n',matriz[2][12]='y',matriz[2][13]='x';
matriz[4][5]='o',matriz[4][6]='p',matriz[4][7]='a',matriz[4][8]='l',matriz[4][9]='o';
matriz[8][8]='d',matriz[8][9]='i',matriz[8][10]='a',matriz[8][11]='m',matriz[8][12]='a',matriz[8][13]='n',matriz[8][14]='t',matriz[8][15]='e';
matriz[9][3]='a',matriz[9][4]='l',matriz[9][5]='e',matriz[9][6]='j',matriz[9][7]='a',matriz[9][8]='n',matriz[9][9]='d',matriz[9][10]='r',matriz[9][11]='i',matriz[9][12]='n',matriz[9][13]='a';

//Hacer Menu
do
{
   system("clear");
   printf("\t\t\n Antes de empezar a jugar favor de leer las intrucciones primero");
   printf("\t\t\n SOPA DE LETRAS");
   printf("\t\t\n Opcion (1)......Jugar");
   printf("\t\t\n Opcion (2)......Instrucciones");
   printf("\t\t\n Opcion (3)......Puntaje");
   printf("\t\t\n Opcion (4)......Salir");
   printf("\t\t\n Elija una opcion ( )\b\b");
   scanf("%d", &opc);
   system("clear");
   
   switch (opc) {
    case 1:
    conteo=5;
    puntaje=0;
    do {
        for(i=0;i<10;i++){
        for(j=0;j<20;j++){
            printf("%c", matriz[i][j]);
        }
        if(j==20)
            printf ("\n");
        }
        printf("\n");
        printf("Escribe la palabra encontrada :  ");
        scanf("%s", pal1);
//Hacer que la palabra este en letras minusculas
        for(h=0,h<strlen(pal1);h++;){
            pal1[h]=tolower(pal1[h]);
        }
        
            if(strcmp(pal1,"rubi") == 0 && (piedra1 == 0)){
                printf("\n\t Felicidades ya encontraste una piedra");
                printf("\n\t Ganaste 100 puntos");
                puntaje=puntaje+100;
                printf("\n\t Tu puntaje es de : %d", puntaje);
                printf("\n\t Enter para continuar...");
                piedra1=1;
                conteo=conteo-1;
                getchar();
                getchar();
                system("clear");
            } else
            if(strcmp(pal1,"onyx") == 0 && (piedra2 == 0)){
                printf("\n\t Felicidades ya encontraste una piedra");
                printf("\n\t Ganaste 100 puntos");
                puntaje=puntaje+100;
                printf("\n\t Tu puntaje es de : %d", puntaje);
                printf("\n\t Enter para continuar...");
                piedra2=1;
                conteo=conteo-1;
                getchar();
                getchar();
                system("clear");
            } else
            if(strcmp(pal1,"opalo") == 0 && (piedra3 == 0)){
                printf("\n\t Felicidades ya encontraste una piedra");
                printf("\n\t Ganaste 100 puntos");
                puntaje=puntaje+100;
                printf("\n\t Tu puntaje es de : %d", puntaje);
                printf("\n\t Enter para continuar...");
                piedra3=1;
                conteo=conteo-1;
                getchar();
                getchar();
                system("clear");
            } else
            if(strcmp(pal1,"diamante") == 0 && (piedra4==0)){
                printf("\n\t Felicidades ya encontraste una piedra");
                printf("\n\t Ganaste 100 puntos");
                puntaje=puntaje+100;
                printf("\n\t Tu puntaje es de : %d", puntaje);
                printf("\n\t Enter para continuar...");
                piedra4=1;
                conteo=conteo-1;
                getchar();
                getchar();
                system("clear");
            } else
            if(strcmp(pal1,"alejandrina") == 0 && (piedra5==0)){
                printf("\n\t Felicidades ya encontraste una piedra");
                printf("\n\t Ganaste 100 puntos");
                puntaje=puntaje+100;
                printf("\n\t Tu puntaje es de : %d", puntaje);
                printf("\n\t Enter para continuar...");
                piedra5=1;
                conteo=conteo-1;
                getchar();
                getchar();
                system("clear");
            } else
            if((pal1 != "rubi") || (pal1 != "opalo") || (pal1 != "onyx") || (pal1 != "diamante") || (pal1 != "alejandrina")){
            printf("\n\t Fallaste, vuelve a intentarlo");
            puntaje=puntaje-100;
            printf("\n\t Tu puntaje es de : %d", puntaje);
            printf("\n\t Enter para continuar...");
            conteo=conteo-1;
            getchar();
            getchar();
            system("clear");
            }
    } while (conteo>0);
        printf("\n\t Se agotaron tus 5 oportunidades...Fin del juego");
        printf("\n\t Enter para continuar...");
        getchar();
        //getchar();
        system("clear");
        break;
    case 2:
        system("clear");
        printf("\n\t INSTRUCCIONES  ");
        printf("\n\t");
        printf("\n\t Opcion 1");
        printf("\n\t En esta opcion el jugador va a empezar a jugar en el palabragrama");
        printf("\n\t Las palabras a buscar son:");
        printf("\n\t 1.- rubi\n\t 2.- onyx\n\t 3.- opalo\n\t 4.- diamante\n\t 5.- alejandrina");
        printf("\n\t Palabra correcta +100 pts");
        printf("\n\t Palabra incorrecta -100 pts");
        printf("\n\t El jugador solo tiene 5 oportunidades para encontrar las 5 palabras");
        printf("\n\t");
        printf("\n\t Opcion 2");
        printf("\n\t Instrucciones del juego que en este momento estas leyendo");
        printf("\n\t");
        printf("\n\t Opcion 3");
        printf("\n\t Se te muestra el puntaje de la partida que jugastes");
        printf("\n\t");
        printf("\n\t Opcion 4");
        printf("\n\t Esta opcion sirve para salir del juego y cerrar el programa");
        printf("\n\t");
        printf("\n\t Favor de elejir la opcion 4 antes de jugar de nuevo para cerrar el programa y correrlo de nuevo");
        printf("\n\t");
        printf("\n\t Enter para continuar...");
        getchar();
        getchar();
        break;
    case 3:
        system("clear");
        printf("\n\t Puntaje : %d", puntaje);
        printf("\n\t Enter para continuar...");
        getchar();
        getchar();
        break;
    case 4:
        printf("\n\t Adios.....<Enter> para terminar");
        getchar();
        getchar();
        break;
    }

} 

while (opc!=4);

    return 0;
}

/* This program was carried out with what was learned in the structured programming class, in addition I used
the following videos as a support to give me an idea of how to structured the mentioned program:

https://www.youtube.com/watch?v=0ytH4s74Fj0
https://www.youtube.com/watch?v=tiMwyicsPeI

I also used the following website: 

https://www.aprendeaprogramar.com/

And the c-refcard.pdf with which I rely to detect and write the correct syntax of the comands used in this program. */
