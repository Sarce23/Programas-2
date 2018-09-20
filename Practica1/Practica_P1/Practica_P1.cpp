// Practica_P1.cpp : Defines the entry point for the console application.


#include "stdafx.h"
#include <conio.h>
#include "NumeroComplejo.h"


int _tmain(int argc, _TCHAR* argv[])
{
	NumeroComplejo n1(5.0,2.0);
	NumeroComplejo n2(0,0);

	n2=n1.sumar(4.0);

	printf("EL resultado de la suma del numero complejo es:");
	n2.imprimir();
	_getch();

	return 0;
}

