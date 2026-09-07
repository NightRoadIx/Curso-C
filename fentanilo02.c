/*
    Visualización de operaciones en C
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
    // Operaciones realizadas en la Unidad Artimético Logica (ALU)
    // Operaciones aritméticas
    // Preferentemente sobre números enteros
    printf("Suma  %d\n", 2+1);
    printf("Resta %d\n", 2-1);
    printf("Multiplicación %d\n", 2*1);
    printf("División %d\n", 7/2);    // División entera
    printf("División %f\n", 7/2.0);  // División de punto flotante
    printf("Residuo o módulo %d\n", 7%2);

    // Operaciones Lógicas
    // Sobre binarios
    printf("AND %d\n", true & false);
    printf("OR  %d\n", true | false);
    printf("XOR %d\n", true ^ false);
    printf("NOT %d\n", !true);

    // Operaciones de comparación
    // Sobre cualquier tipo de datos, dan como respuesta un booleano
    printf("%d\n", 7 > 2);   // Mayor que
    printf("%d\n", 7 < 2);   // Menor que
    printf("%d\n", 7 == 2);  // Igual a
    printf("%d\n", 7 != 2);  // Diferente de


    
    return 0;
}
