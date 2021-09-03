#include "scanner.h"

char caracter;
int i;

struct Token get_token()
{
    token.tipo=0;
    token.buffer[0]='\0';

    caracter=getchar();
    while(caracter != EOF)
    {
            if(caracter == ',')
            {
                token.tipo=SEP;    
                token.buffer[0]=',';
                token.buffer[1]='\0';

                return token;
            }
            else
            {
                if(!isspace(caracter))
                {
                    i=0;
                    while((caracter!=',') && (!isspace(caracter)) && (caracter != EOF))
                    {  
                        token.buffer[i]=caracter;
                        i++;
                        caracter=getchar();
                    }
                    ungetc(caracter,stdin);

                    token.tipo=CAD;
                    token.buffer[i]='\0';

                    return token;
                }
            }
        caracter=getchar();
    }

    token.tipo=FDT;
    token.buffer[0]='\0'; 

    return token;
}