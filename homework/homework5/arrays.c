#include "calc.h"
#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h> 
void showcompletematrix(int** m, int dim)  {
  int i, j;
  int w=1;
  char c;
  printf("   ");
  for (i = 0; i < dim; i++) {
     c=i+65;
    printf ("   %c", c);
  }
  printf("\n");
  printf(" 1 ");
  for (i = 0; i < dim; i++) {
     
    for (j = 0; j < dim; j++) {
      if (m[i][j]!=-1){
      if (m[i][j]!=0){
      printf(" %3d", m[i][j]);
      }
      else{
        printf("    ");  
      }
      }
      else{
          printf("   X");
      }
    }
    printf("\n");
    w++;
    if (w<=dim){
    printf("%2d ", w);
    }
  }
   for (i = 0; i < (dim*4+4); i++) {
  printf("-"); 
   }
   printf("\n");
}

void showmatrixwhileplay(int** m, int dim, int** d){ 
    int i, j;
    char c;
    int w=1;
    printf("   ");
    for (i = 0; i < dim; i++) {
     c=i+65;
    printf ("   %c", c);
    }
    printf("\n");
  
    printf(" 1 ");
    for (i = 0; i < dim; i++) {
    for (j = 0; j < dim; j++) {
      if (m[i][j]!=-1&&d[i][j]==1){
      if (m[i][j]!=0){
      printf(" %3d", m[i][j]);
      }
      else{
        printf("    ");  
      }
      }
      else{
          printf("   #");
      }
    }
    printf("\n");
    w++;
    if (w<=dim){
    printf("%2d ", w);
    }
  }
   for (i = 0; i < (dim*4+4); i++) {
  printf("-"); 
   }
   printf("\n");
}
    
int count(int** m, int tam, int a, int b){
    int i, j;
    int copy[tam][tam];
    for (i = 0; i < tam; i++) {
    for (j = 0; j < tam; j++) {
      copy[i][j]=m[i][j];
      }
    }
  int x, y, z=0;
  for (x=a-1; x<3+a-1; x++){
      for (y=b-1;y<3+b-1;y++){
          if (x>=0&&x<tam&&y>=0&&y<tam&&copy[x][y]==-1){
              z++;
    }
   }
  }
  return z;
}

int discover(int** array, int** discovered, int tam, int foundnumber, int letter)
{
    if(array[foundnumber-1][letter] == -1){
        return -1;
    }
    else if(discovered[foundnumber-1][letter] == 1){
        return 0;
    }
    else{
        
        if(array[foundnumber-1][letter] == 0){
          
            discovered[foundnumber-1][letter] = 1;
            int result = 1;

            {
                int row = foundnumber - 1;
                int column = letter - 1;

                if ((row - 1) >= 0 && (row - 1) < tam && 
                    column >= 0 && column < tam
                ){
                    result += discover(array, discovered, tam, row, column);
              }
            }

            {
                int row = foundnumber;
                int column = letter - 1;

                if ((row - 1) >= 0 && (row - 1) < tam && 
                    column >= 0 && column < tam
                ){
                    result += discover(array, discovered, tam, row, column);
              }
            }

            {
                int row = foundnumber + 1;
                int column = letter - 1;

                if ((row - 1) >= 0 && (row - 1) < tam && 
                    column >= 0 && column < tam
                ){
                    result += discover(array, discovered, tam, row, column);
              }
            }

            {
                int row = foundnumber + 1;
                int column = letter;

                if ((row - 1) >= 0 && (row - 1) < tam && 
                    column >= 0 && column < tam
                ){
                    result += discover(array, discovered, tam, row, column);
              }
            }

            {
                int row = foundnumber + 1;
                int column = letter + 1;

                if ((row - 1) >= 0 && (row - 1) < tam && 
                    column >= 0 && column < tam
                ){
                    result += discover(array, discovered, tam, row, column);
              }
            }

            {
                int row = foundnumber;
                int column = letter + 1;

                if ((row - 1) >= 0 && (row - 1) < tam && 
                    column >= 0 && column < tam
                ){
                    result += discover(array, discovered, tam, row, column);
              }
            }
            
            {
                int row = foundnumber - 1;
                int column = letter + 1;

                if ((row - 1) >= 0 && (row - 1) < tam && 
                    column >= 0 && column < tam
                ){
                    result += discover(array, discovered, tam, row, column);
              }
            }

            {
                int row = foundnumber - 1;
                int column = letter;

                if ((row - 1) >= 0 && (row - 1) < tam && 
                    column >= 0 && column < tam
                ){
                    result += discover(array, discovered, tam, row, column);
              }
            }
            return result;
        }
        else{
            
         discovered[foundnumber-1][letter] = 1;
          return 1;
    }
  }
}
/* This program was made with the help of https://github.com/satuelisa/C/tree/main/Ch5, Brian W. Kernighan, Dennis M. Ritchie - The C Programming Language, Second Edition (1988),
and with the help of rulgamer07 */
