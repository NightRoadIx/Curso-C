/*
 * Programa que muestra los valores que regresa la función printf
 */
#include <stdio.h>

int main(int argc, char *argv[])
{
	char st[] = "CODIFICA";
	long n = 123456789;
	
	// En el caso de printf, esta regresa como valor, el número de caracteres de una cadena
	printf("\n\nMientras se imprime ");
	printf(" , el valor que regresa printf() es: %d", printf("%s", st));
	
	// En el caso de printf, esta regresa como valor, el número de caracteres que componen un número
	printf("\n\nMientras se imprime ");
	printf(" , el valor que regresa printf() es: %d", printf("%ld", n));
	
	retunr 0;
}