#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>


#define SALIR 3
#define TRUE 1
#define FALSE 0
#define ESC 27

typedef struct _tdato{
	
	long matricula;
	
	char nombres[50];
	char appat[50];
	char apmat[50];
	
	int edad ;
	int sexo ;
	
	struct _tdato * sig;
	
}Tdato;

typedef Tdato * Tpila;

void Principal( void );
Tpila GenDatos( void );
void PUSH( Tpila * tope, Tpila * nuevo );
Tpila POP( Tpila * tope );
void servicio( Tpila temp );
void Gen_alum( Tpila temp );
int Validar(int ri,int rs);

int main ( void )
{
	srand(time(0));
   	Principal();
   
   return 0;
}

void Principal( void )
{	

	int op;
	Tpila nuevo = NULL;
	Tpila temp = NULL;
	Tpila tope = NULL;
   
   do{
   	
      system ("cls");
      printf("\t MENU \n");
      printf("1.- PUSH \n");
      printf("2.- POP \n");
      printf("3.- Salir \n");
      printf("Seleccion: ");
      
      op = Validar( 1, 3 );
      
	  switch( op )
	    {
	    	case 1:
	    		nuevo = GenDatos();
	    		PUSH( &tope, &nuevo );
	    		break;
	    		
	    	case 2:
	    		temp = POP( &tope );
	    		if( temp )
	    		{
	    			servicio( temp );
	    			free( temp );
				}
				else
				{
					printf("\nPila vacia \n");
					system("pause");
				}
	    		break;
	    		
	    	case 3:
	    		while( tope )
	    		{
	    			temp = POP( &tope );
		    		if( temp )
		    		{
		    			free( temp );
					}
				}
	    		break;
		} 
		
   }while( op != SALIR );	
}

Tpila GenDatos( void )
{
	Tpila temp = NULL;
	
	temp = (Tpila) malloc( sizeof(Tdato) );
	
	Gen_alum( temp );
	
	temp -> sig = NULL;
	
	servicio( temp );
	
	return temp;
}

void PUSH( Tpila * tope, Tpila * nuevo )
{
	(*nuevo) -> sig = *tope;
	*tope = *nuevo;
	*nuevo = NULL;
}

Tpila POP( Tpila * tope )
{
	Tpila temp = NULL;
	
	if( *tope )
	{
		temp = *tope;
		*tope = (*tope) -> sig;
		temp -> sig = NULL;
	}
	
	return temp;
}

void servicio( Tpila temp )
{
	system("cls");
	printf("Nombre: %s %s %s \n",temp -> nombres, temp -> appat, temp -> apmat);
	printf("Sexo: %d \tEdad: %d \n",temp -> sexo, temp -> edad);
	printf("Matricula: %ld \n",temp -> matricula);
	system("pause");
}

void Gen_alum( Tpila temp )
{	
	char Female[10][20] = {"DIANA","LIZETH","ALASKA","SAMANTHA","SARA","LIA","ROSELLA","MARTHA","DARA","GABRIELA"};
	char Female2[3][20] = {"MARIA","MARIA_DE","CARMEN"};
	
	char Male[10][20] = {"SARID","ABDIEL","ENRIQUE","EFRA","ABRAHAM","LUIS","ESTEBAN","SAID","DAVID","ITAMAR"};
	char Male2[4][20] = {"JOSE","JOSE_DE","JESUS","JORGUE"};
	
	char Ap[10][20] = {"GARCIA","PEREZ","HERNANDEZ","MARTINEZ","JIMENEZ","REZA","ARENAS","PONCE","AGUILAR","CALDERON"};
	
	if( ( rand() % 500 ) % 2 == 0 ) 
	{
		temp -> sexo = 1;
		
		if( ( rand() % 10 ) % 2 == 0 )  				
		{
			strcpy( temp -> nombres , Male[rand()%10] );			
		}
		else
		{
			strcpy( temp -> nombres , Male2[rand()%4] );			
			strcat( temp -> nombres , "_" );
			strcat( temp -> nombres , Male[rand()%10] );
		}
	}
	else
	{
		temp -> sexo = 0;
		
		if( ( rand() % 10 ) % 2 == 0 )					
		{
			strcpy( temp -> nombres , Female[rand()%10] );		
		}
		else
		{
			strcpy( temp -> nombres , Female2[rand()%3] );		
			strcat( temp -> nombres , "_" );
			strcat( temp -> nombres , Female[rand()%10] );
		}
	}
	
	strcpy( temp -> appat , Ap[rand()%10] );
	strcpy( temp -> apmat, Ap[rand()%10] );
	
	temp -> edad = rand()% 32 + 18 ; 
	
	temp -> matricula = rand()%500 + 349000;
}

int Validar(int ri,int rs)
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
