#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include "arce.h"

void menu(void);
Tnodo GenDatos(void);
void PUSHPILA(Tnodo *tope, Tnodo *num);
Tnodo POPPILA(Tnodo *tope);
void PUSHCOLA(Tnodo *cola, Tnodo *ultimo, Tnodo *nuevo);
Tnodo POPCOLA(Tnodo *cola, Tnodo *ultimo);


int main()
{
	srand(time(NULL));
	menu();
	return 0;
}

void menu (void)
{
   int op, n;
   Tnodo cola=NULL, ultimo=NULL, nuevo=NULL, temp=NULL;
   do{
      system("CLS");
      printf("MENU PRINCIPAL:\n\n");
   
      printf("1. PUSH \n");
      printf("2. POP\n");
      printf("3. SALIR AL MENU PRINCIPAL.\n");      
      op = ValidaNum(1, 2, "ESCOGE UNA OPCION: \n", "ERROR, OPCION NO VALIDA. \n", 1);
   
      switch(op)
      {       
                
        case 1:
             do{
  	  
	            switch(op)
	            {
		            case 1: 
		   			     temp = POPCOLA(&cola, &ultimo);  			
		   			     if(temp)
	   				     {
                            servicio(temp);
		   					free (temp);
                         }
		                 else
				         {
					    	printf("\nCOLA VACIA\n\n");
					    	system("PAUSE");
					     }
						
                     break;
		          
                  }
             }while(op != 3);
             op=0;
        break;
        
        case 2:
        	while (cola)
	  			  {
		  			    temp = POPCOLA(&cola, &ultimo);
	   			        if(temp)
	   				      {
   					        free (temp);
                          }
                  }
		    printf("\nSE HA LIMPIADO TODA LA COLA.\n\n");
            system("PAUSE");
        break;
      }
   }while(op != 3); 
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

void PUSHPILA(Tnodo *tope, Tnodo *nuevo)
{
	(*nuevo)->sig = *tope;
	*tope = *nuevo;
	*nuevo = NULL;
}

Tnodo POPPILA(Tnodo *tope)
{
	Tnodo temp = NULL;
	if(*tope)
		{
			temp = *tope;
			*tope = (*tope)->sig;
			temp->sig = NULL;
		}
	return temp;
}

void PUSHCOLA(Tnodo *cola, Tnodo *ultimo, Tnodo *nuevo)
{
     if(!*cola)
	 {
          *cola = *nuevo;
     }
     else
     {
	      (*ultimo)->sig = *nuevo;
     }
     *ultimo = *nuevo;
     *nuevo = NULL;
}

Tnodo POPCOLA(Tnodo *cola, Tnodo *ultimo)
{
	Tnodo temp = NULL;
	if(*cola)
	{
        temp = *cola;
	    *cola = (*cola)->sig;
	    temp->sig = NULL;
	    if(temp == *ultimo)
	    {
             *ultimo = NULL;
        }
	}
	
	return temp;
}


