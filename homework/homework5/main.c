/* To compile the code in the correct in gdb you may add first the main.c program, then you add the getch.c program,
next you will add the getop.c program, then add the calc.h program and finally and the array.c program, when you did that 
then you will be asked to write the number of rows and columns, then you will be asked to write the number of mines and at the end
you can play the game by typing the coordinate that you want (a2, f5, c8, etc). */

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
  float upperlimitpercentage = .50; 
  int lowerlimit = 1;
  int play= TRUE; 
  int question=0; 
  int foundnumber; 
  int tam; 
  int errors=0; 
  int type;
  char s[MAXOP];
  int counter=0; 
    
    while (play==TRUE){
        if (question==0){
            printf("Number of columns (that will be the same number of rows) between 2 and 20\nIf you write a decimal number it will be rounded\n");
            while(question==0 && (type = getop(s)) != EOF) {
                if (question==0){
                switch (tolower(type)) {
                    case NUMBER:
                    foundnumber = atof(s);
                    counter++;
                    break;
                    case '\n':
                    if (errors==0&&foundnumber>=2&&foundnumber<=26&&counter==1){
                        tam=foundnumber;
                        printf("Ready, a new board will be generated %d x %d\n\n", tam, tam);
                        question=1;
                        counter=0;
                       
                    }
                    else {
                        errors=0;
                        counter=0;
                        printf("\nNumber of columns (that will be the same number of rows) between 2 and 20\nIf you write a decimal number it will be rounded\n");
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
            int upperlimit = tam*tam*upperlimitpercentage;
            printf("Number of mines, between %d and %d\nIf you write a decimal number it will be rounded\n", lowerlimit, upperlimit);
            while(question==1 && (type = getop(s)) != EOF) {
                if (question==1){
                switch (tolower(type)) {
                    case NUMBER:
                    foundnumber = atof(s);
                    counter++;
                    break;
                    case '\n':
                    if (errors==0&&foundnumber>=lowerlimit&&foundnumber<=upperlimit&&counter==1){
                        mines=foundnumber;
                        printf("Ready, the number of mines will be %d\n\n", mines);
                        question=2;
                        counter=0;
                       
                    }
                    else {
                        errors=0;
                        counter=0;
                        printf("\nNumber of mines, between %d and %d\nIf you write a decimal number it will be rounded\n", lowerlimit, upperlimit);
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
                int firstrandomnumber=rand()%(tam);
                int secondrandomnumber=rand()%(tam);
                if (matrix[firstrandomnumber][secondrandomnumber]==0){
                    matrix[firstrandomnumber][secondrandomnumber]=-1; 
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
           
            printf("\nTo write a coordinate write b5 or 5b (Change the numbers according to the coordinate you want\n");
            
            int letter=0;
            int lettercounter=0;
            int hits=0;
            int variable = tam*tam-mines;
            showmatrixwhileplay(matrix,tam, discovered); 
            while(question==2 && (type = getop(s)) != EOF) {
                if(question==2){
                    switch (tolower(type)) {
                        case NUMBER:
                        foundnumber=atof(s);
                        counter++;
                        break;
                        case '\n':
                        {
                            if(errors == 0 && counter == 1 && lettercounter == 1){
                                printf("\n\nValid input\n\n");
                                if(foundnumber-1 < tam && foundnumber - 1 >= 0 && 
                                    letter < tam && letter >= 0)
                                {
                                    int newhits = discover(matrix, discovered, tam, foundnumber, letter);

                                    if(newhits == -1){
                                        showcompletematrix(matrix, tam);
                                        printf("\n\nYOU LOSE!!! TRY AGAIN\n\n");

                                        lettercounter = 0;
                                        letter = 0;
                                        foundnumber = 0;
                                        counter = 0;
                                        errors = 0;
                                        question = 0;
                                    }
                                    else if(newhits == 0){
                                        printf("\n\nYou have already selected this box!!!\n\n");
                                        showmatrixwhileplay(matrix, tam, discovered);
                                    }
                                    else {
                                        hits += newhits;
                                        if(hits >= tam * tam - mines){
                                            showcompletematrix(matrix, tam);
                                            printf("\n\nYOU WIN!!!!!\n\n");

                                            lettercounter = 0;
                                            letter = 0;
                                            foundnumber = 0;
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

                            lettercounter = 0;
                            letter = 0;
                            foundnumber = 0;
                            counter = 0;
                            errors = 0;
                        }break;
                        default:
                         if (type>=97&&type<=122){
                            letter=type-97;
                            lettercounter++;
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
/* This program was made with the help of https://github.com/satuelisa/C/tree/main/Ch5, Brian W. Kernighan, Dennis M. Ritchie - The C Programming Language, Second Edition (1988),
and with the help of rulgamer07 */
