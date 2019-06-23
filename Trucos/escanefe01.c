/*
 * Programa que muestra lo que regresa como valor la función scanf
 * al ingresar datos por medio de la consola
 */
#include <stdio.h>

int main(int argc, char *argv[])
{
	char b[100], c[100];
	
	printf("\n>> ");
	// En cambio scanf regresa el número total de entradas ingresadas de manera correcta o un EOF si hay algún error
	printf("\n\nLo que regresa un scanf(): %d", scanf("%s", b));
	printf("\n>> ");
	// En cambio scanf regresa el número total de entradas ingresadas de manera correcta o un EOF si hay algún error
	printf("\n\nLo que regresa un scanf(): %d", scanf("%s%s", b,c));
	
	return 0;
	
}