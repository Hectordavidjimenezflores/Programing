#include <stdio.h>
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;
int getch(void)
{
 return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
 if(bufp >= BUFSIZE)
   printf("ungetch: too many characters\n");
     else
       buf[bufp++] = c;
}
/* This program was made with the help of https://github.com/satuelisa/C/tree/main/Ch5, Brian W. Kernighan, Dennis M. Ritchie - The C Programming Language, Second Edition (1988),
and with the help of rulgamer07 */
