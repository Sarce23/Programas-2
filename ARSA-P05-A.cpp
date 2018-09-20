#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include "arce.h"

void menu(void);
Tnodo GenDatos(void);

int main()
{
	menu();
	return 0;
}

void menu (void)
{
   int op, n,busc,dato;
   Tnodo  temp=NULL, nuevo=NULL, lista=NULL;
   do{
      system("CLS");
      printf("MENU PRINCIPAL:\n\n");
   
      printf("1. Agregar\n");
      printf("2. Buscar\n");
      printf("3. Imprimir\n");
      printf("4. Eliminar\n");
      printf("5. SALIR\n");

      op = ValidaNum(1, 4, "ESCOGE UNA OPCION: \n", "ERROR, OPCION NO VALIDA. \n",1);
   
      switch(op)
      {       
            case 1: 
			 	nuevo=GenDatos();
			 	temp=Buscarl(lista, nuevo->dato);
			 	if(temp)
			 	  {
			 	  	printf("Dato Repetido\n");
			 	  	system("pause");
			 	  	temp=NULL;
				  }
				 else
				  {
				  	Agregarl(&lista,&nuevo);
				  	printf("Exito\n");
				  	system("pause");
				  	temp=NULL;
				  }
        	break;
        	
        	case 2:
        		 busc=ValidaNum(1, 100, "Introduce un numero entre el 1 y el 1000: \n", "ERROR, Numero invalido. \n", 1);
        		 temp=Buscarl(lista,nuevo->dato);
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
        	 	 Imprimirl(lista);
        	 	 system("pause");
        	break;
        	
        	case 4:
        		dato=ValidaNum(1,32000,"num","error",1);
        		
        		temp=Eliminarl(&lista,dato);
        		if(temp)
        		  {
        		  	printf("Dato Eliminado:\n");
        		  	servicio(temp);
        		  	free(temp);
				  }
				 else
				  {
				  	printf("No Existe");
				  }
        		
        	break;
      }
   }while(op != 5); 
   system("PAUSE");           
}

Tnodo GenDatos(void)
{
	Tnodo temp = NULL;
	temp = (Tnodo)malloc(sizeof(Tdato));
	temp->dato = (rand()%100);
	temp->sig = NULL;
	
	return temp;
}

