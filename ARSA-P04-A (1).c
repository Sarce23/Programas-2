#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "arce.h"

typedef struct _templeado{
	long matricula;
	char appat[30];
	char apmat[30];
	char nombres[30];
	int edad, sexo;
	struct _tdato *sig;
	}Templeado;
	
typedef Templeado *Tnodoemp;


void menu (void);
Tnodoemp gendatos (void);
Tnodoemp POPC(Tnodoemp *cola, Tnodoemp *ultimo);
void PUSHC(Tnodoemp *cola, Tnodoemp *ultimo, Tnodoemp *nuevo);
void Servicio (Tnodoemp temp);

int main (void)
{
   menu();
   return 0;
}

void menu(void)
{
   Tnodoemp temp=NULL, nuevo=NULL, cola=NULL, ultimo=NULL;
   int op;
   srand(time(NULL));
   do{
      system ("cls");
      printf("\n M  E   N   U   COLA");
	  printf("\n1.- PUSH");
	  printf("\n2.- POP");
	  printf("\n3.- SALIR");
      op= ValidaNum(1, 3, "\nEliga una opcion: ", "\nOPCION NO VALIDA");
	  switch(op)
	    {
	    	case 1:
                nuevo=gendatos(); servicio(nuevo);getch();
                PUSHC(&cola, &ultimo, &nuevo);
                break;
          	case 2:
          		temp= POPC(&cola, &ultimo);
          		if(temp)
          		  {
          		  	servicio(temp);
          		  	free(temp);
				  }
				 else
				  {
				  	printf("\nLA COLA ESTA VACIA.\n");
				  }
				system("pause");
                break;
          	case 3:
          		while(cola)
          		{
					temp= POPC(&cola, &ultimo);
          		  	free(temp);
				}
				system("pause");
				break;
       	}
   }while(op != 3);
}


Tnodoemp gendatos (void)
{
    Tnodoemp temp=NULL;
    temp= (Tnodoemp)malloc(sizeof(Templeado));
    int j, f, x, y, k, repe;
    long t;
    char nomh[15][20]= {"DAMIAN","ROBERTO","OSCAR","SANTIAGO","SERGIO","XAVIER","ANTONIO","JOSE","ALAN","IVAN","ALFONSO","GIOVANNI", "JUAN","ELVER","ARMANDO"};
    char nomm[15][20]= {"MARIA", "PATRICIA", "KAREN", "KARLA", "MONSERRAT", "XIMENA","PAULINA","CAROLINA","MARTHA","PAOLA","KASANDRA","ROSA","GUADALUPE","VANESSA","GLORIA"};
    char app[15][20]= {"MAZIAS", "QUINTERO", "GALLARDO", "HERNANDEZ", "LOPEZ", "TORRES","ARAMBULA","VALDOVINOS","ARCE","GOMEZ","RUELAS","PUTIN","YAMAMOTO","GALARGA","CASTILLO"};
    x= rand()%1000;
    if (x % 2 == 0)
       {
            temp->sexo= 0;
            strcpy(temp->appat, app[rand()%14]);
            strcpy(temp->apmat, app[rand()%14]);
            strcpy(temp->nombres, nomh[rand()%14]);
            y= rand()%1000;
            if (y % 2 == 0)
               {
                    strcat(temp->nombres, "_");
                    strcat(temp->nombres, nomh[rand()%14]);
               }
       }
      else
       {
            temp->sexo= 1;
            strcpy(temp->appat, app[rand()%14]);
            strcpy(temp->apmat, app[rand()%14]);
            strcpy(temp->nombres, nomm[rand()%14]);
            if (y % 2 == 0)
               {
                    strcat(temp->nombres, "_");
                    strcat(temp->nombres, nomm[rand()%14]);
               }
       }
    temp->edad= (rand()%20)+17;
    temp->matricula= (rand()%499)+349000;
    temp->sig=NULL;

}

void PUSHC(Tnodoemp *cola, Tnodoemp *ultimo, Tnodoemp *nuevo)
{
	if(!*cola)
	  {
	  	*cola=*nuevo;
	  }
	 else
	  {
	  	(*ultimo)->sig=*nuevo;
	  }
	*ultimo=*nuevo;
	*nuevo=NULL;
}

Tnodoemp POPC(Tnodoemp *cola, Tnodoemp *ultimo)
{
    Tnodoemp temp=NULL;
    if(*cola)
      {
        temp=*cola;
        *cola=(*cola)->sig;
        temp->sig=NULL;
        if(temp==*ultimo)
          {
            *ultimo=NULL;
          }
      }
    return temp;
}


void Servicio(Tnodoemp temp)
{
    system("cls");
    char strsexo[15];
    if (temp->sexo == 0)
       {
            strcpy (strsexo,"MASCULINO");
       }
      else
       {
            if (temp->sexo == 1)
               {
                    strcpy (strsexo,"FEMENINO");
               }
       }
    printf("\n\n\n");
    printf("MATRICULA: %ld, NOMBRE: %s %s %s, SEXO: %s, EDAD: %d\n", temp->matricula, temp->appat, temp->apmat, temp->nombres, strsexo, temp->edad);
    printf("\n\n");
}
