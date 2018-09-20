/*practica 2, pop y push*/
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define ENTER 13

typedef struct _tdato{
	int dato;
	struct _tdato *sig;
}Tdato;

typedef Tdato *Tpila;

Tpila GenDatos(void);
void PUSH(Tpila *tope, Tpila *nuevo);
void menu(void);
Tpila POP(Tpila *tope);
int validanum(long r1, long r2);
void servicio(Tpila temp);

int main()
{
	srand(time(NULL));
	menu();
	return 0;
}

void menu(void)
{
   int op;
   Tpila nuevo=NULL,temp=NULL,tope=NULL;
  
   do{
      system ("cls");
      printf("\n M  E   N   U");
	  printf("\n1.- PUSH ");
	  printf("\n2.- POP ");
	  printf("\n3.- Salir ");
	  printf("\nESCOGE UNA OPCION.");
  	  op=validanum(1,3);
  	  
	  switch(op)
	    {
		  case 1:
					nuevo=GenDatos();
					PUSH(&tope,&nuevo);
					
		             break;
		  case 2: 
		   			temp=POP(&tope);  			
		   			if(temp)
		   				{
		   					servicio(temp);
		   					free (temp);
						}
					   else
					    {
					    	printf("Pila Vacia");
						}
						
		  			break;
		  case 3:
		  		while (tope)
		  			{
		  			temp=POP(&tope);
		   			if(temp)
		   				{
		   					servicio(temp);
		   					free (temp);
						}
					}
					break;	       
		}
   }while(op !=3);	
}

Tpila GenDatos(void)
{
	Tpila temp=NULL;
	temp=(Tpila)malloc(sizeof(Tdato));
	temp->dato=(rand()%100);
	temp->sig=NULL;
	
	return temp;
}

void PUSH(Tpila *tope, Tpila *nuevo)
{
	(*nuevo)->sig=*tope;
	*tope=*nuevo;
	*nuevo=NULL;
}

Tpila POP(Tpila *tope)
{
	Tpila temp=NULL;
	if(*tope)
		{
			temp=*tope;
			*tope=(*tope)->sig;
			temp->sig=NULL;
		}
	
	return temp;
}

void servicio(Tpila temp)
{
	printf("\n %d \n",temp->dato);
	system("pause");
}

int validanum(long ri, long rs)
{
	char xnum[10] = {NULL}, caracter ;
	int num ;
	int i = 0 ;
	
	do{
				
			do{
				
				fflush(stdin);
			
				caracter = getch();
				
				if( caracter >= 48 && caracter <= 57 )
				{
					printf("%c",caracter);
					xnum[i++] = caracter;
				}
				
			}while( caracter != ENTER );
			
			xnum[i] = '\0' ;
			
			num = atoi(xnum);
			
			if( num < ri || num > rs )
			{
				printf("\nSeleccion invalida...\n");
				system("pause");
			}
	
		}while( num < ri || num > rs );
	
	return num;
}

