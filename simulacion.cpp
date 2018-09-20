#include "arce.h"

void Simulacion();

int main()
{
	Simulacion();
	
	return 0;
}

void Simulacion()
{
	srand(time(NULL));
	int salir=0,caja=0,cliente=0,atender=0,i=0,j,contador1,contador2,contador3,contador4,mov1 = 0,mov2 = 0,mov3 = 0,mov4 = 0,opc,movA=0,movB,w,cont_al_momento1=0,cont_al_momento2=0,cont_al_momento3=0,cont_al_momento4=0,contadorglobal; 
   	int nuevo_1_num = 0, nuevo_2_num = 0, nuevo_3_num = 0, nuevo_4_num = 0;
	int vcaja1[4]={0,0,0,0},vcaja2[4]={0,0,0,0},vcaja3[4]={0,0,0,0},vcaja4[4]={0,0,0,0},esta1[5],esta2[5];
	Tnodo nuevo1 = NULL, temp1 = NULL, ultimo1 = NULL, cola1 = NULL;
	Tnodo nuevo2 = NULL, temp2 = NULL, ultimo2 = NULL, cola2 = NULL;
	Tnodo nuevo3 = NULL, temp3 = NULL, ultimo3 = NULL, cola3 = NULL;
	Tnodo nuevo4 = NULL, temp4 = NULL, ultimo4 = NULL, cola4 = NULL;
	
	printf("Simulacion de un banco:\n ");
	printf("(Limite de clientes por cola: 5)\n");
	printf("(Limite de movimientos por cliente: 10)\n");
	printf("caja 1:|\t caja 2:|\t caja 3:|\t caja 4:\t\n");
	do{
	caja=(rand()%4)+1;
		
		switch(caja)
		{
			case 1:
            {
   				atender=(rand()%100)%2;
   				switch(atender)
   				{
   					case 1:
                     {
      						//llega cliente
      						nuevo1 = GenDatos();
      						nuevo_1_num = nuevo1->numero;
      						printf("llego un nuevo cliente a la caja 1\n");
      						PUSH( &cola1, &ultimo1, &nuevo1);
      						contador1++;
      						cont_al_momento1++;
      						contadorglobal++;
      						mov1=nuevo_1_num;
      						if(mov1 > movA)
      						{
      							movA=mov1;
      							movB=1;
      						}
      						mov1=mov1+(nuevo_1_num);
                     }
   						break;
   					case 2:
                     {
      						//se va cliente 
      						temp1 = POP(&cola1, &ultimo1);
      						if(temp1)
      						{
      							free(temp1);
      						}
      						cont_al_momento1--;
                     }
   						break;
   				}
   				atender=0;
            }
				break;
			case 2:
            {
   				atender=(rand()%100)%2;
   				switch(atender)
   				{
   					case 1:
                     {
      						//llega cliente
      						nuevo2 = GenDatos();
      						nuevo_2_num = nuevo2->numero;
      						printf("llego un nuevo cliente a la caja 2\n");
      						PUSH( &cola2, &ultimo2, &nuevo2);
      						contador2++;
      						cont_al_momento2++;
      						contadorglobal++;
      						mov2=nuevo_2_num;
      						if(mov2 > movA)
      						{
      							movA=mov2;
      							movB=2;
      						}
      						mov2=mov2+(nuevo_2_num);
                     }
   						break;
   					case 2:
                     {
      						//se va cliente 
      						temp2 = POP(&cola2, &ultimo2);
      						if(temp2)
      						{
      							free(temp2);
      						}
      						cont_al_momento2--;
                     }
   						break;
   				}
   				atender=0;
            }
				break;
			case 3:
            {
   				atender=(rand()%100)%2;
   				switch(atender)
   				{
   					case 1:
                     {
      						//llega cliente
      						nuevo3 = GenDatos();
      						nuevo_3_num = nuevo3->numero;
      						printf("llego un nuevo cliente a la caja 3\n");
      						PUSH( &cola3, &ultimo3, &nuevo3);
      						mov3=nuevo_3_num;
      						contador3++;
      						cont_al_momento3++;
      						contadorglobal++;
      						if(mov3 > movA)
      						{
      							movA=mov3;
      							movB=3;
      						}
      						mov3=mov3+(nuevo_3_num);
                     }
						break;
					case 2:
                  {
   						//se va cliente 
   						temp3 = POP(&cola3, &ultimo3);
   						if(temp3)
   						{
   							free(temp3);
   						}
   						cont_al_momento3--;
                  }
						break;
               }
				atender=0;
            }
				break;
			case 4:
            {
   				atender=(rand()%100)%2;
   				switch(atender)
   				{
   					case 1:
                     {
      						//llega cliente
      						nuevo4 = GenDatos();
      						nuevo_4_num = nuevo4->numero;
      						printf("llego un nuevo cliente a la caja 4\n");
      						PUSH( &cola4, &ultimo4, &nuevo4);
      						mov4=nuevo_4_num;
      						contador4++;
      						cont_al_momento4++;
      						contadorglobal++;
      						if(mov4 > movA)
      						{
      							movA=mov4;
      							movB=4;
      						}
      						mov4=mov4+(nuevo_4_num);
                     }
   						break;
   					case 2:
                     {
      						//se va cliente 
      						temp4 = POP(&cola4, &ultimo4);
      						if(temp4)
      						{
      							free(temp4);
      						}
      						cont_al_momento4--;
                     }
   						break;
   				}
   				atender=0;
            }
				break;
		}
		printf("Clientes en caja 1: %d\n",cont_al_momento1);
		printf("Clientes en caja 2: %d\n",cont_al_momento2);
		printf("Clientes en caja 3: %d\n",cont_al_momento3);
		printf("Clientes en caja 4: %d\n",cont_al_momento4);
		
		printf("\nprecione 1 par salir\n");
		scanf("%d",&opc);
		switch(opc)
		{
			case 1: 
   				salir=1;
   				while((POP(&cola1, &ultimo1)))
   				{
   				}
   				while((POP(&cola2, &ultimo2)))
   				{
   				}
   				while((POP(&cola3, &ultimo3)))
   				{
   				}
   				while((POP(&cola4, &ultimo4)))
   				{
   				}
   				printf("\nBanco cerrado\n");
   				system("pause");
				break;
		}
}while(salir==0);
	
	system("cls");
	printf("Estadisticas de cada caja:\n");
	
	esta1[1]=mov1;
	esta1[2]=mov2;
	esta1[3]=mov3;
	esta1[4]=mov4;
	esta2[1]=contador1;
	esta2[2]=contador2;
	esta2[3]=contador3;
	esta2[4]=contador4;
		
	for(w=1;w <= 4;w++)
	{
		printf("caja %d:",w++);
		printf("\nnumero de clientes atendidos: %d",contadorglobal);
		printf("\nnumero de movimientos realizados en la caja %d: %d",w,esta1[w]);
		printf("\nmayor numero de movimientos realizado por 1 solo cliente: %d",movA);
		printf("\nen la caja %d",movB);
	}
		printf("\nnumero de clientes atendidos globalmente: %d",contadorglobal);
}
