/*
 * Estructura general de un código fuente en C
 * Desarrollador	: 
 * Fecha creación	: 
 * Revisión			: 
 */
/* * * * INSTRUCCIONES DEL PREPROCESADOR * * * */
// LIBRERÍAS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// DEFINICIONES
#define NUMERO 9

// PROTOTIPO DE FUNCIONES
int miFuncion(int varFun);

// VARIABLES GLOBALES
int varGlobal;

// FUNCIÓN PRINCIPAL CON ARGUMENTOS
int main(int argc, char **argv)
{
	// VARIABLES LOCALES
	int varTmp;
	
	// CUERPO DEL PROGRAMA
	varTmp = 6;
	varGlobal = miFuncion(NUMERO + varTmp);
	printf("El valor es: %d", varGlobal);
	
	// VALOR DE REGRESO (en main generalmente es 0)
	return 0;
}

// DEFINICIÓN DE FUNCIONES
int miFuncion(int varFun)
{
	// VARIABLES LOCALES 
	int regreso;
	
	// CUERPO DE LA FUNCIÓN
	regreso = varFun * 5 + 3;
	
	// VALOR DE REGRESO
	return regreso;
}