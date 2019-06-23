/*
 * Programa que muestra de que forma se puede enmascarar los datos
 * que se reciben mediante la función scanf()
 */
#include <stdio.h>

int main(int argc, char *argv[])
{
	char str[128];
	
	printf("\nIngresar una cadena: ");
	// Esto solo recibe los caracteres que sean mayúsculas
	scanf("%[A-Z]s", str);
	printf("\nLos datos ingresados: %s\n", str);
	getch(); fflush(stdin);
	
	printf("\nIngresar una cadena: ");
	// Esto recibe hasta encontrar una "o" minúscula
	scanf("%[^o]s", str);
	printf("\nLos datos ingresados: %s\n", str);
	
	return 0;
}