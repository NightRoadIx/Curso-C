/*
 * Separación de factores
 * Mi name es Yo Merol
 */
#include <stdio.h>  // E/S estándar
#include <stdlib.h> // Librería estándar
#include <conio.h>  // E/S adicionales
#include <math.h>   // Funciones màtemátïcas

// Función principal
int main(int argc, char **argv)
{
    // Variables locales
    int N, Nfin, pote;
	
	// Mostrar letrero al usuario de lo que debe ingresar
	printf("Ingresa un numero entero: ");
	// Ingresa el número entero (identificador %d) a la variable N
	scanf("%d",&N);
	
    // AQUÍ YA TENEMOS EL VALOR DE N
	// Se realiza una asignación del valor del número ingresado por el usuario
    Nfin = N;	
	
	// Ciclo para ir saltando sobre el número
	// El número debe de 
    while(N >= 1)
    {
		// Verificar si se ha llegado al númeroN/( pow(10,pote) ) < 10 
		// Ya que lo que se hace es estar buscando las unidades que conforman al número ingresado por el usuario
		// Esto es si se ingresa N = 1666, cada unidad es 1, 6, 6, 6 que es lo que se busca
		for(pote=0; ( N/( pow(10,pote) ) ) >= 10; pote++); 
		// Si las acciones dentro de las llaves del for estan comentadas, se debe usar un ; al finalizar el for
		/*{
			printf("\n %.0lf \n", N/( pow(10,pote) ));
		}*/
		// Finalmente se muestra en pantalla la unidad multiplicada por 10^potencia para formar el número
        printf("(%d x %d) + ", (int)( N/pow(10,pote) ), (int)pow(10, pote) );
        N = N % (int)(pow(10,pote));
    }
	// Finalmente mostrar el número
    printf(" = %d ", Nfin);
	
	// Resolviendo el problema en solo 12 líneas
    return 0;
}
