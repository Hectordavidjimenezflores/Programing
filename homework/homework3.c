#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main()
{
int c, number = FALSE, parenthesis = FALSE, quotes = FALSE;
while ((c = getchar()) != EOF)
{
switch(c)
{
      case '(':
          parenthesis=TRUE;
          putchar(c);
          break;
      case ')':
          parenthesis=FALSE;
          putchar(c);
          break;
      case '[':
          parenthesis=TRUE;
          putchar(c);
          break;
      case ']':
          parenthesis=FALSE;
          putchar(c);
          break;
      case '<':
          parenthesis=TRUE;
          putchar(c);
          break;
      case '>':
          parenthesis=FALSE;
          putchar(c);
          break;
      case '{':
          parenthesis=TRUE;
          putchar(c);
          break;
      case '}':
          parenthesis=FALSE;
          putchar(c);
          break;
      case '\'':
          putchar(c);
          quotes++;
          break;

       case '\"':
          putchar(c);
          quotes++;
          break;

      default:
        if(c!='.'&&c!=':'&&c!=';'&&c!='-'&&c!='_'&&c!='!'&&c!='\?')
            {

            if (parenthesis==TRUE||quotes==TRUE){
            putchar(c);

            }
             else
            {
             if (quotes==2)
                {
                    quotes=0;
                }

                if (c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9'||c=='0'){
                    number++;
                }
                else
                {
                  number=0;
                }

                if (number==1){
                    putchar('X');
                }

                if (number==0){
                    putchar(c);
             }
            }
           }
          }
         }
    return 0;
  }
/* this program was made with the help of the book Brian W. Kernighan, Dennis M. Ritchie - The C Programming Language, Second Edition (1988), 
https://github.com/satuelisa/C/tree/main/Ch3 and with help of rulgamer07 */
