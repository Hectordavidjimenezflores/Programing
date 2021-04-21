#include <stdio.h>
#define TRUE 1 
#define FALSE 0
#include "calc.h"
#include <stdlib.h> 
#include <ctype.h> 
#include <time.h> 
#define MAXOP 100 

int main()
{
  int mines=0; 
  float upper limit percentage = .75; 
  int lower limit = 1;
  int play= TRUE; 
  int question=0; 
  int found number; 
  int tam; 
  int errors=0; 
  int type;
  char s[MAXOP];
  int counter=0; 
    
    while (play==TRUE){
        if (question==0){
            printf("Number of columns (will be the same number of rows) between 2 and 26\nIf you write a decimal number it will be rounded\n");
            while(question==0 && (type = getop(s)) != EOF) {
                if (question==0){
                switch (tolower(type)) {
                    case NUMBER:
                    found number = atof(s);
                    counter++;
                    break;
                    case '\n':
                    if (errors==0&&found number>=2&&found number<=26&&counter==1){
                        tam=found number;
                        printf("Ready, a new board will be generated %d x %d\n\n", tam, tam);
                        question=1;
                        counter=0;
                       
                    }
                    else {
                        errors=0;
                        counter=0;
                        printf("\nNumber of columns (will be the same number of rows) between 2 and 26\nIf you write a decimal number it will be rounded\n");
                    }
                    break;
                    default:
                    errors++;
                    break;
                
                }
                }
            
            }
        }
        
        if (question==1){
            int upper limit = tam*tam*upper limit percentage;
            printf("Number of mines, between %d and %d\nIf you write a decimal number it will be rounded\n", lower limit, upper limit);
            while(question==1 && (type = getop(s)) != EOF) {
                if (question==1){
                switch (tolower(type)) {
                    case NUMBER:
                    found number = atof(s);
                    counter++;
                    break;
                    case '\n':
                    if (errors==0&&found number>=lower limit&&found number<=upper limit&&counter==1){
                        mines=found number;
                        printf("Ready, the number of mines will be %d\n\n", mines);
                        question=2;
                        counter=0;
                       
                    }
                    else {
                        errors=0;
                        counter=0;
                        printf("\nNumber of mines, between %d and %d\nIf you write a decimal number it will be rounded\n", lower limit, upper limit);
                    }
                    break;
                    default:
                    errors++;
                    break;
                
                }
                }
            
            }
        } 
        
        if (question==2){ 
            
            
            int i, j;
            int** matrix;
            int** discovered; 
            matrix = (int**)malloc(sizeof(int*) * tam);
            
            for (i = 0; i < tam; i ++){
                matrix[i] = (int*)malloc(sizeof(int) * tam);
                 for (j=0; j<tam; j++){
                     matrix[i][j]=0;
                 }
            }
            
            discovered = (int**)malloc(sizeof(int*) * tam);
             
            for (i = 0; i < tam; i ++){
                discovered[i] = (int*)malloc(sizeof(int) * tam);
                 for (j=0; j<tam; j++){
                     discovered[i][j]=0;
                 }
            }
            
            
            srand(time(NULL));
            for (int z=0;z<mines;z++){
                int first random number=rand()%(tam);
                int second random number=rand()%(tam);
                if (matrix[first random number][second random number]==0){
                    matrix[first random number][second random number]=-1; 
                }
                else{
                    z--;
                }
            }
            
            
            for (i = 0; i < tam; i ++){
                 for (j=0; j<tam; j++){
                     if (matrix[i][j]==0){
                         matrix[i][j]=count(matrix,tam,i,j);
                     }
                 }
            }
            
            
            printf("\nPara escribir una coordenada escribe a2 o 2a (Cambia los numeros segun la cordenada que quieras\n");
             
            
            int letter=0;
            int letter counter=0;
            int hits=0;
            int variable = tam*tam-mines;
            showmatrixwhileplay(matrix,tam, discovered); 
            while(question==2 && (type = getop(s)) != EOF) {
                if(question==2){
                    switch (tolower(type)) {
                        case NUMBER:
                        found number=atof(s);
                        counter++;
                        break;
                        case '\n':
                        {
                            if(errors == 0 && counter == 1 && letter counter == 1){
                                printf("\n\nEntrada valida\n\n");
                                if(found number-1 < tam && found number - 1 >= 0 && 
                                    letter < tam && letter >= 0)
                                {
                                    int new hits = discover(matrix, discovered, tam, found number, letter);

                                    
                                    if(new hits == -1){
                                        showcompletematrix(matrix, tam);
                                        printf("\n\nPERDISTE!\n\n");

                                        letter counter = 0;
                                        letter = 0;
                                        found number = 0;
                                        counter = 0;
                                        errors = 0;
                                        question = 0;
                                    }
                                    else if(new hits == 0){
                                        printf("\n\nYa habias seleccionado esta casilla!\n\n");
                                        showmatrixwhileplay(matrix, tam, discovered);
                                    }
                                    else {
                                        hits += new hits;
                                        if(hits >= tam * tam - mines){
                                            showcompletematrix(matrix, tam);
                                            printf("\n\nYOU WIN!\n\n");

                                            letter counter = 0;
                                            letter = 0;
                                            found number = 0;
                                            counter = 0;
                                            errors = 0;
                                            question = 0;
                                        }
                                        else{
                                            showmatrixwhileplay(matrix, tam, discovered);
                                        }
                                    }
                                }
                                else{
                                    printf("\n\nError 7: coordinate out of range\n\n");
                                }
                            }
                            else{
                                printf("\n\nError 6: some invalid character\n\n");
                            }

                            letter counter = 0;
                            letter = 0;
                            found number = 0;
                            counter = 0;
                            errors = 0;
                        }break;
                        default:
                         if (type>=97&&type<=122){
                            letter=type-97;
                            letter counter++;
                         }
                         else {
                            printf("\n\nError 6: Check your input\n\n");
                            errors++;
                         }
                        break;
                    
                    }
                }
            }
            
            if (question==3){
                play=FALSE;
            }  
        }
    } 
}
