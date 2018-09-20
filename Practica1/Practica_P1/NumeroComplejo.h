class NumeroComplejo{

private:

	float r; //parte real
	float b; //parte imaginaria
public:
	NumeroComplejo(float real,float imag);
	NumeroComplejo sumar(NumeroComplejo n2);
	//sobrecarga de sumar
	NumeroComplejo sumar(float real);
	void imprimir(); //para mostrar el numero en pantalla
};