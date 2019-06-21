/*
 * Programa para obtener la lista de caractéres ASCII básicos (0 a 127)
 * ASCII (American Standard Code for Information Interchange)
 * Publicado en 1967 que consiste en 128 caracteres disponibles en el lenguaje inglés
 * junto con algunos caracteres de control (entrar, retroceso, etc)
 * Sin emabrgo en 1981, IBM desarrolló una extensión de 8 bits del código ASCII
 * llamada "página de código 437" modificando el original e incorporando 128 caracteres nuevos
 * que permiten la escritura de símbolos, signos y graficos adicionales, así como
 * carcateres del alfabeto latino para la escritura en otras lenguas (como la ñ)
 */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(int argc, char **argv)
{
	// Utilizar un unsigned char (registro de 8 bits)
	unsigned char i;
	
	printf("--Código ASCII--\n");
	printf("Numero\t\tCodigo\n");
	// for es más utilizado para ciclos definidos
	// for(inicio_contador, condicion_paro; incremento_contador)
	for(i = 0; i < 128; i++)
	{
		// Mostrar el número del código ASCII y su representación
		// para mostrar caracteres se puede utilizar "%c"
		// Así como la función putchar() [disponible en stdio.h]
		printf("[%d]\t\t%c\n",i,i);
	}
	return 0;
}
