#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "arce.h"

void menu(void);

int main (void)
{
   menu();
   return 0;
}

void menu(void)
{
   Tnodoemp temp=NULL, nuevo=NULL, listaC=NULL, ultimo=NULL;
   int op, num, dato;
   srand(time(NULL));
   do{
      system ("cls");
      printf("\n M  E   N   U   LISTAS");
	  printf("\n1.- AGREGAR");
	  printf("\n2.- ELIMINAR");
	  printf("\n3.- BUSCAR");
	  printf("\n4.- IMPRIMIR");
	  printf("\n5.- SALIR");
      op= validanum (1, 5, "\nEliga una opcion: ", "\nOPCION NO VALIDA");
	  switch(op)
	    {
		  case 1:
            nuevo=gendatosemp();
            temp= bucarG(lista, nuevo->matricula);
            if(temp)
              {
                printf("Dato Repetido\n\n");
                system("pause");
                temp=NULL;
              }
             else
              {
              	agregarLC(&lista,&nuevo);
                printf("\n\nExito\n\n");
                system("pause");
                temp=NULL;
              }
            break;
        case 2:
        	dato= validanum(340000,349999,"Que dato quieres eliminar? Escribe un numero del 340000 al 349999 ","Error");
			temp= eliminarG(&lista,dato);
			if(temp)
			  {
			  	servicioemp(temp);
			  	free(temp);
			  }
			 else
			  {
			  	printf("\n\nEl dato NO existe\n\n");
			  	system("pause");
			  }
            break;
        case 3:
            num= validanum (1, 350000, "\nDime la matricula que quieras buscar: ", "\nOPCION NO VALIDA");
            temp= bucarG(lista, num);
            if(temp)
              {
              	printf("\n\nExito\n\n");
              	system("pause");
              	servicioemp(temp);
			  }
			 else
			  {
			  	printf("\n\nEl numero %d no existe en la lista\n\n",num);
			  	system("pause");
			  }
            break;
        case 4:
            Imprimirl(lista);
            break;
        }
    }while(op != 5);
}

