/*
 * Programa que muestra el uso de argumentos enviados a la línea de comandos
   en el lenguaje C
   El programa se manda a ejecutar en la línea de comandos como:
   argumentos arg1 arg2 arg3 ... argn
 */
#include <stdio.h>

int main(int argc, char *argv[])
{
	int i;
	
	// Recibir los argumentos que se envían al mandar a llamar al programa
	// NOTAR QUE ARGUMENTO SE RECIBE SIEMPRE QUE SE EJECUTA EL PROGRAMA
	printf("Numero de argumento recibidos: %d\n", argc);
	printf("Argumentos recibidos: \n");
	for(i = 0; i < argc; i++)
		printf("%d . - %s\n", i, argv[i]);
	
	return 0;
}