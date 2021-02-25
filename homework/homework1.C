#include <stdio.h>

int main(){

    int c;
    int state = 0;
    int s;
    int i = 0;
    char strong[7]={"strong"};

    while((c = getchar()) != EOF){

            if(c == '<'){
                    state = 0;
                    for(s = 0; (c = getchar()) == strong[s]; s++){
                            ;
                    }
                if (s != 6){
                while( (c = getchar()) != '>' ){
                        ;
                }
            }
            else {
                while( c != '>' ){
                        ;
                }
            }
                ++ i;
            if( (c = getchar()) == '<'){
                state = 1;
                while( (c = getchar()) != '>' ){
                    ;
                }
                i++;
            }

        }
        if(c != '<' && c!= '>'){
            i = 0;
        }
           if(state == 0 && i == 0 && s != 6){
            putchar(c);
            i = 0;
           }
           if(s == 6){
                if(c == ' '){
                    printf("_");
                    c = getchar();
                }
            putchar(c);
           }
        if ( c == '>' && s == 6){
            s=0;
        }
    }
}
/* i did this program based on the book Brian W. Kernighan, Dennis M. Ritchie - The C Programming Language, Second Edition (1988) 
and based on the programs https://github.com/satuelisa/C/blob/main/nocomment.c" and  https://github.com/satuelisa/C/blob/main/spaces.c */
