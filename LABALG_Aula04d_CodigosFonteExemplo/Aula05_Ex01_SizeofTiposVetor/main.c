#include <stdio.h>
#include <stdlib.h>

/* Chamada principal comentada 
int main(int argc, char *argv[]) {
	return 0;
}
*/

void main () {
	int a = 327967;          //signed int; -32768 a 32767.
	unsigned int b = 65535;  //0 a 65535.
	short int c = -32768;    //-32768 a 32767.
	long int d = 2147483647; //2147483648 a 2147483647
	unsigned long int e = 4294967295; 
	
	float  f = 0.0;
	double g = 0.0;
	long double h = 0.0;
	
	printf("TAMANHO DOS TIPOS (em bytes)) \n");
	printf("Tamanho tipo int: %d \n", sizeof(int));
	printf("Tamanho tipo unsigned int: %d \n", sizeof(unsigned int));
	printf("Tamanho tipo short int: %d \n", sizeof(short int));
	printf("Tamanho tipo long int: %d \n", sizeof(long int));
	printf("Tamanho tipo unsigned long int: %d \n", sizeof(unsigned long int));
	printf("Tamanho tipo float: %d \n", sizeof(float));
	printf("Tamanho tipo double: %d \n", sizeof(double));
	printf("Tamanho tipo long double: %d \n", sizeof(long double));
	
	
	/*
	printf("Tamanho tipo short: %d \n", sizeof(short));
	printf("Tamanho tipo float: %d \n", sizeof(float));
	printf("Tamanho tipo double: %d \n", sizeof(double));
	printf("Tamanho tipo long double: %d \n", sizeof(long double));
	
	printf("\n");
	printf("VARIAVEIS, a (int), b (short) e c (float) \n");
	printf("Valor contido em a: %i \n", a);
	printf("Valor contido em b: %i \n", b);
	printf("Valor contido em c: %f \n", c);
	printf("Tamanho variavel a: %i \n", sizeof(a));
	printf("Tamanho variavel b: %i \n", sizeof(b));
	printf("Tamanho variavel c: %i \n", sizeof(c));
	*/
	
	system("pause");
}
