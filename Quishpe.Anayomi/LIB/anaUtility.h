
#include <stdio.h>
#include <unistd.h>
#include <unistd.h>

#define TIEMPO 100000
enum escapes { 
	BELL 		= '\a', 
	RETROCESO 	= '\b',
	TAB 		= '\t',
	ENTER 		= '\n', 
	TAB_V 		= '\v', 
	RETORNO 	= '\r'
};

enum months { ENE = 1, FEB, MAR, ABR, MAY, JUN, JUL, AGO, SEP, OCT, NOV, DIC };

void clearTerminal()
{
    system("cls||clear"); 
    fflush(stdout); 
    //cout << "\033[H\033[2J\033[3J" ;
    //cn.clear();
}

int getNumeroPositivo(char *label) //
{
    int numero;
    char str[3];  //999 abc
    do
    {
        printf("\n %s", label);
        gets(str);
        sscanf(str,"%d", &numero);   
    } while (numero <= 0 );
    fflush(stdin);
    return numero;  
}

char menuGeneral( char *showOpc)
{
    char opc='-';
    do{
        printf("\n %s", showOpc);
        scanf("%c",&opc);
    }while ( !((opc =='1') || (opc =='2') || (opc =='3')) ) ;
    return opc;
}

void getLinea(char *str)    // line[lim = 10] -->   {h|o|l|a| |c|o|m|o|\n|\0|~|~|~|}
{      
    char c;
    int i =0;  
    do{
        c = getchar();
        str[i++] = c;
    }while(c != '\n');
    str[i]  == '\0';
}

char espacio(int sp)
{
    for (int i=0; i<sp; i++)
    {
       printf(" ");
    }
}


