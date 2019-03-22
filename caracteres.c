#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>	// Librería para manejo de caracteres

int main(int argc, char **argv)
{
    // ~entero de 8 bits [0, 255]
    unsigned char c;
	// Puede utilizarse como char solamente, pero para
	// el uso de los caracteres ASCII extendidos se
	// recomienda el uso de unsigned char
	
    /*
	 * // Esta es la forma "natural" de ingresar un caracter
	 * printf("Dame un caracter: ");
	 * // Se utiliza scanf con el modificador %c, para caracteres
	 * // el programa esperara el ingreso de un caracter y después 
	 * // se debe presionar enter para que el buffer de datos de entrada
	 * // ingrese a ser procesado
	 * scanf("%c",&c);
	 * // También puede convertirse de un número entero a caracter por 
	 * // la codificación ASCII
	 * printf("Dame un número entero: ");
	 * scanf("%d",&c);
	 */
	 
	// Sin embargo C posee ciertas funciones para el ingreso de caracteres
    //printf("Dame un caracter: ");
    //c = getch(); // Toma el caracter
    //c = getche(); // Tomar caracter y hace eco
    //c = getchar(); // = scanf("%c", &c);
	
	// La función kbhit(), regresa un valor entero indicando:
	// 0 -> no se ha presionado ninguna tecla
	// 1 -> se presionó una tecla
    /*while(!kbhit())
    {
        printf("matrix");
    }*/

    do
    {
        printf("\nContinuar [s/n]: ");
        c = getche();
        if((c!='s')&&(c!='n'))
            printf("Te pasas solo va s o n");
        // Limpiar el buffer de entrada estándar (stdin)
        fflush(stdin);
    }
    while((c != 'n'));

    printf("\nLa fayuca es: %d - %c", c, c);
	
	// Sin embargo también se puede utilizar la función putchar
	// para mostrar un caracter en pantalla
	putchar(c);		// o incluso usar un entero como argumento
	
	// Verificación de caracteres
	printf("El caracter es alfanumerico:\t%d", isalnum(c));
	printf("El caracter es alfabetico:\t%d", isalpha(c) );
	printf("El caracter es minuscula:\t%d", islower(c) );
	printf("El caracter es mayuscula:\t%d", isupper(c) );
	printf("El caracter es numerico:\t%d", isdigit(c) );
	printf("El caracter es puntuacion:\t%d", ispunct(c) );

    getch();
    return 0;
}
