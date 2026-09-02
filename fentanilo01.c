/*
    Programa inicial que sirve para farmear aura
*/

// STanDard Input Output
#include <stdio.h>
// STanDard LIBrary
#include <stdlib.h>
// STandard BOOLean
#include <stdbool.h>

// Función principal
int main()
{
    /* OJO, DE PREFERENCIA COLOCAR TODAS LAS VARIABLES AQUÍ */
    // Variables en programación
    // Lenguajes de programación
    // fuertemente tipados
    // Buleano (1 bit), requiere librería stdbool.h
    bool valorBuleano = true; // false, 1 || 0
    // Caracter (8 bits)
    char valorCaracter = 'a';   // 64
    // Entero corto (16 bits)
    short variableCorta = 42;
    // Entero (32 bits)
    int valoresEnteros = 67;
    // Entero largo (64 bits)
    long variableLarga = 234567;

    // Valor decimal (32 bits)
    float valorFlotante = 3.1416;
    // Valor decimal (64 bits)
    double valorDoble = 3.1415926539;

    float valorGrande = 4567890987;

    int pelox;

    /* LUEGO, YA COLOCAR TODO EL CÓDIGO */
    // Cadena de texto "entre comillas"
    printf("A farmear aura\n");
    printf("El valor es: %d\n", valoresEnteros);
    printf("El valor es: %x\n", valoresEnteros);
    printf("El valor es: %c\n", valorCaracter);
    printf("El valor es: %.2f\n", valorFlotante);
    printf("El valor es: %lf\n", valorDoble);
    printf("Valor con mantisa: %e\n", valorGrande);

    // Ingresar datos
    printf("Ingresa un entero: ");
    scanf("%d", &pelox);
    printf("El valor ingresado fue %d", pelox);

    return 0;
}
