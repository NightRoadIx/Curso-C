/*
 * Programa para el control de un menú de opciones
 * Uso del switch y funciones de control de caracteres
 */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

int main(int argc, char **argv)
{
	// Opción a ingresar con el teclado
	char opc;
	
	do
	{
		// Se coloca la limpieza de la consola
		// al mandar a llamar la función cls
		// Esto es por estética, de que el menú siempre se vea al inicio de
		// la ventana
		system("cls");
		// Generar el menú de opciones a mostrar al usuario
		printf("<< Menu opciones >>\n");
		printf("a) Opcion 1\n");
		printf("b) Opcion 2\n");
		printf("c) Opcion 3\n");
		printf("s) Salir\n");
		printf("Opcion ingresada: ");
		// Ingresar datos con getche(), para:
		// 1.- Solo requerir presionar una tecla
		// 2.- Mostrar el caracter presionado 
		opc = getche();
		
		// En primer lugar lo que se va a efectuar es revisar si el caracter ingresado
		// es un caracter alfabético (las opciones solo son a,b,c,s)
		// la función isalpha(char) revisa si el argumento de la función (un caracter) es
		// del tipo alfabético, esto es solo letras del alfabeto inglés (ASCII)
		// si lo es, regresa un valor de 1, en otro caso es 0
		if( isalpha(opc) )
		{
			// Utilizar la función char tolower(char) para si el usuario ingresa un 
			// caracter en mayúscula, este se "transforme" en minúscula
			opc = tolower(opc);
			// Después se somete a una prueba mediante el switch para saber que es lo que el
			// programa va a hacer
			switch(opc)
			{
				case 'a':	// Mucho ojo, al tratarse de un char, se debe evaluar contra caracteres ( opc == 'a' )
					printf("\tSeleccionada la opcion 1\n");
					break;	// No olvidar el break
				case 'b':
					printf("\tSeleccionada la opcion 2\n");
					break;
				case 'c':
					printf("\tSeleccionada la opcion 3\n");
					break;
				case 's':
					printf("\tCerrando la aplicacion\n");
					break;
				default:
					printf("\tOpcion no existente\n");
					break;
			}
		}
		else	// En caso de que no sea un caracter alfabético, informarle al usuario
			printf("\tSolo se aceptan caracteres alfabéticos\n");
		
		printf("Presione una tecla para continuar->");
		getch();	// Esperar que se presione una tecla
	}
	while(opc != 's');	// Terminar cuando se presione 's' o 'S'
	// Se usa do - while, porque primero se quieren hacer las acciones y ya posteriormente
	// se pregunta si se desea terminar
	
	return 0;
}
