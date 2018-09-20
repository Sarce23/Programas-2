#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "ARCE.h"

typedef struct _tdato{
	
	int dato;
	struct _tdato *sig;
	
}Tdato;

typedef Tdato *Tpila;

void Principal(void);
Tpila GenDatos(int fac);

int main ()
{
	principal();
	return 0;
}

void Principal( void )
{	
	int fac,fac2,i;
	long res=1;
	
	Tpila nuevo = NULL;
	Tpila temp = NULL;
	Tpila tope = NULL;
  	
  	printf("ingrese el numero del cual desea el factorial:");
  	fac=Validar(1,12);
  	fac2=fac;
  	do{
  		nuevo=GenDatos(fac);
		PUSH(&tope,&nuevo);
		fac2--;
		
	  }while( fac2 != 0);
	
	for(i=0; i<fac ; i++)
	{
		temp=POP(&tope);
		res= res*temp->sig;
		free(temp);
	}
	printf("el factorial de %d es : %d",fac,res);
}

Tpila GenDatos(int fac)
{
	Tpila temp = NULL;
	temp = (Tpila) malloc( sizeof(Tdato) );
	temp->dato=fac;
	temp -> sig = NULL;
	return temp;
}
