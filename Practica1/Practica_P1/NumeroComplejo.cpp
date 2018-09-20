#include "stdafx.h" //debe ser la primera linea en un .cpp
#include "NumeroComplejo.h"


NumeroComplejo::NumeroComplejo(float real,float imag){
	r=real;
	b=imag;

}
NumeroComplejo  NumeroComplejo::sumar(NumeroComplejo n2){
	NumeroComplejo resultado(0,0);
	return resultado;
}

//sobre cargar sumar
NumeroComplejo  NumeroComplejo::sumar(float real){
	NumeroComplejo resultado(0,0);

	resultado.r=r+real;//parte real, es la parte real del objeto + el numero real resivido
	resultado.b=b;//la parte imaginaria del resultados, es la parte imaginaria de este numero complejo

	return resultado;
}
void NumeroComplejo::imprimir(){
	printf("%f + %fi",r,b);

}


