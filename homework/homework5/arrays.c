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
    

int contar(int** m, int tam, int a, int b){
    int i, j;
    int copia[tam][tam];
    for (i = 0; i < tam; i++) {
    for (j = 0; j < tam; j++) {
      copia[i][j]=m[i][j];
      }
    }
  int x, y, z=0;
  for (x=a-1; x<3+a-1; x++){
      for (y=b-1;y<3+b-1;y++){
          if (x>=0&&x<tam&&y>=0&&y<tam&&copia[x][y]==-1){
              z++;
    }
   }
  }
  return z;
  
}

int descubrir(int** matrix, int** descubiertas, int tam, int numero_encontrado, int letra)
{
    if(matrix[numero_encontrado-1][letra] == -1){
        return -1;
    }
    else if(descubiertas[numero_encontrado-1][letra] == 1){
        return 0;
    }
    else{
        
        if(matrix[numero_encontrado-1][letra] == 0){
          
            descubiertas[numero_encontrado-1][letra] = 1;
            int resultado = 1;

           
            {
                int fila = numero_encontrado - 1;
                int columna = letra - 1;

                if ((fila - 1) >= 0 && (fila - 1) < tam && 
                    columna >= 0 && columna < tam
                ){
                    resultado += descubrir(matrix, descubiertas, tam, fila, columna);
              }
            }

           
            {
                int fila = numero_encontrado;
                int columna = letra - 1;

                if ((fila - 1) >= 0 && (fila - 1) < tam && 
                    columna >= 0 && columna < tam
                ){
                    resultado += descubrir(matrix, descubiertas, tam, fila, columna);
              }
            }

            
            {
                int fila = numero_encontrado + 1;
                int columna = letra - 1;

                if ((fila - 1) >= 0 && (fila - 1) < tam && 
                    columna >= 0 && columna < tam
                ){
                    resultado += descubrir(matrix, descubiertas, tam, fila, columna);
              }
            }

            
            {
                int fila = numero_encontrado + 1;
                int columna = letra;

                if ((fila - 1) >= 0 && (fila - 1) < tam && 
                    columna >= 0 && columna < tam
                ){
                    resultado += descubrir(matrix, descubiertas, tam, fila, columna);
              }
            }

            
            {
                int fila = numero_encontrado + 1;
                int columna = letra + 1;

                if ((fila - 1) >= 0 && (fila - 1) < tam && 
                    columna >= 0 && columna < tam
                ){
                    resultado += descubrir(matrix, descubiertas, tam, fila, columna);
              }
            }

            
            {
                int fila = numero_encontrado;
                int columna = letra + 1;

                if ((fila - 1) >= 0 && (fila - 1) < tam && 
                    columna >= 0 && columna < tam
                ){
                    resultado += descubrir(matrix, descubiertas, tam, fila, columna);
              }
            }

            
            {
                int fila = numero_encontrado - 1;
                int columna = letra + 1;

                if ((fila - 1) >= 0 && (fila - 1) < tam && 
                    columna >= 0 && columna < tam
                ){
                    resultado += descubrir(matrix, descubiertas, tam, fila, columna);
              }
            }

            
            {
                int fila = numero_encontrado - 1;
                int columna = letra;

                if ((fila - 1) >= 0 && (fila - 1) < tam && 
                    columna >= 0 && columna < tam
                ){
                    resultado += descubrir(matrix, descubiertas, tam, fila, columna);
              }
            }

            return resultado;
        }
        else{
            
         descubiertas[numero_encontrado-1][letra] = 1;
          return 1;
    }
  }
}
