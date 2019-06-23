/*
 * Programa que imprime en pantalla los número del 1 al 10
 * Sin utilizar un solo ";"
 */
// Inlcluir solo la librería stdio
#include <stdio.h>
// Realizar esta definición de N que es el límite máximo de números
#define N 10 

int main(int num) 
{ 
	// En este caso se toma en consideración que:
	// num < N
	// Se debe imprimir algo en pantalla o printf debe regresar 1 como valor
	// se manda a llamar a la misma función main con el argumento main + 1
	if (num <= N && printf("%d ", num) && main(num + 1)) 
	{ }
} 