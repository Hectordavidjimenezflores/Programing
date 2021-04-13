#include <stdio.h>
#include "calc.h"
#define MAXVAL 100
int sp=0;
double val[MAXVAL];

void push(double f)
{
  if(sp < MAXVAL)
     val[sp++]=f;
   else
   printf("error:stack full, cant push %g\n",f);
}

double pop(void)
{
    if(sp>0)
      return val[--sp];
    else
    {
      printf("error: stack empty\n");
      return 0.0;
    }
}

/* this program was made with the help of the book Brian W. Kernighan, Dennis M. Ritchie - The C Programming Language, Second Edition (1988), 
https://github.com/satuelisa/C/tree/main/Ch4 and with the help of rulgamer03 */
