#include <stdio.h>
#include <ctype.h>
#include "calc.h"
int getop(char s[])
{
  int i,c;
  char a;
    while((s[0] = c = getch()) == ' ' || c =='\t');
    s[1] = '\0';
    i = 0;
    if(!isdigit(c) && c!='.' && c!='-'){
        if (!isalpha(c))
        return c; 
        if (isalpha(c)){
        return tolower(c);
        }
    }
    if(c=='-')
        if(isdigit(c=getch()) || c == '.')
          s[++i]=c;
        else
        {
            if(c!=EOF)
             ungetch(c);
            return '-';
        }
    if(isdigit(c))
        while(isdigit(s[++i] =c =getch()));
    if(c=='.')
        while(isdigit(s[++i] = c=getch()));
    s[i] = '\0';
    if(c!=EOF)
     ungetch(c);
    return NUMBER;
}
/* This program was made with the help of https://github.com/satuelisa/C/tree/main/Ch5, Brian W. Kernighan, Dennis M. Ritchie - The C Programming Language, Second Edition (1988),
and with the help of rulgamer07 */
