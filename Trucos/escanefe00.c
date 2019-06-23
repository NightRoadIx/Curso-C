/*
 * Programa que muestra el uso del comodín * en los caracteres de formato
 * de la función scanf
 */
#include <stdio.h>

int main(int argc, char *argv[])
{
	int a;
	
	printf("Ingresar dato: ");
	// %*s es utilizado para ignorar lo que se ingresa hasta que haya un espacio o un salto de línea
	// De manera similar si se escribe %*d o %*f ignorará el entero o el flotante hasta espacio o salto de linea
	scanf("%*s %d", &a);
	printf("\n\nEntonces el dato es: %d\n", a);
	
	return 0;
}