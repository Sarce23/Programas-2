#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include "arce.h"

void menu(void);
Tnodo GenDatos(void);
void Agregar(Tnodo *lista, Tnodo *nuevo);
Tnodo Buscar(Tnodo lista, int dato);
void Imprimir(Tnodo lista);
Tnodo GenDatos(void);

int main()
{
	menu();
	return 0;
}

void menu (void)
{
   int op, n,busc;
   Tnodo  temp=NULL, nuevo=NULL, lista=NULL;
   do{
      system("CLS");
      printf("MENU PRINCIPAL:\n\n");
   
      printf("1. Agregar\n");
      printf("2. Buscar\n");
      printf("3. Imprimir\n");
      printf("4. SALIR\n");

      op = ValidaNum(1, 3, "ESCOGE UNA OPCION: \n", "ERROR, OPCION NO VALIDA. \n", 1);
   
      switch(op)
      {       
            case 1: 
			 	nuevo=GenDatos();
			 	temp=Buscar(lista, nuevo->dato);
			 	if(temp)
			 	  {
			 	  	printf("Dato Repetido\n");
			 	  	system("pause");
			 	  	temp=NULL;
				  }
				 else
				  {
				  	Agregar(&lista,&nuevo);
				  	printf("Exito\n");
				  	system("pause");
				  	temp=NULL;
				  }
        	break;
        	
        	case 2:
        		 busc=ValidaNum(1, 100, "Introduce un numero entre el 1 y el 1000: \n", "ERROR, Numero invalido. \n", 1);
        		 temp=Buscar(lista,nuevo->dato);
        		 if(temp)
			 	  {
			 	  	printf("El Numero: %d si se encuentra en la lista",busc);
			 	  	system("pause");
			 	  	temp=NULL;
				  }
				 else
				  {
				  	printf("El Numero: %d no se encuentra en la lista",busc);
				  	system("pause");
				  	temp=NULL;
				  }
        		 
        	break;
        	
        	case 3:
        	 	 Imprimir(lista);
        	 	 system("pause");
        	break;
      }
   }while(op != 4); 
   system("PAUSE");           
}

void Agregar(Tnodo *lista, Tnodo *nuevo)
{
	Tnodo temp=NULL;
	if(!*lista || (*nuevo)->dato < (*lista)->dato)
	  {
	  	(*nuevo)->sig=*lista;
	  	*lista=*nuevo;
	  	*nuevo=NULL;
	  }
	 else
	  {
	  	temp=*lista;
	  	while(temp->sig && (temp->sig)->dato < (*nuevo)->dato)
	  		 {
	  		 	temp=temp->sig;
			 }
		(*nuevo)->sig=temp->sig;
		temp->sig=*nuevo;
		nuevo=NULL;
	  }
}

Tnodo Buscar(Tnodo lista, int dato)
{
	Tnodo temp=NULL;
	
	if(lista)
	  {
	  	temp=lista;
	  	while(temp)
	  		 {
	  		 	if(temp->dato == dato)
	  		 	  {
	  		 	  	return temp;
				  }
				  temp=temp->sig;
			 }
	  }
	return temp;
}

void Imprimir(Tnodo lista)
{
	Tnodo temp=NULL;
	
	if(lista)
	  {
	  	temp=lista;
	  	while(temp)
	  		 {
				servicio(temp);
				  temp=temp->sig;
			 }
	  }
}

Tnodo GenDatos(void)
{
	Tnodo temp = NULL;
	temp = (Tnodo)malloc(sizeof(Tdato));
	temp->dato = (rand()%100);
	temp->sig = NULL;
	
	return temp;
}

