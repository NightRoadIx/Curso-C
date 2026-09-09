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

    // Operadores lógicos sobre condiciones
    int x = 0;
    printf("%d", (x >= 6)&&(x <= 10));
    printf("%d", !((x >= 6)&&(x <= 10)));
    printf("%d", (x < 6)&&(x > 10));
    printf("%d", (x < 6)||(x > 10));

    // Operador ternario
    char califica = ((x >= 6)&&(x <= 10)) ? 'a': 'r';
    printf("Aprueba: %c", califica);

    // Operadores lógicos sobre enteros
    // Variable de 8 bits
    char num8Bits = 9;
    // 00001001

    // Desplazamiento de bits 
    printf("%d\n", num8Bits << 1);
    printf("%d\n", num8Bits >> 1);

    printf("%d\n", 1 << 20);

    // Enmascaramiento
    printf("%d\n", 9 & 1);
    printf("%d\n", 9 | 1);
    printf("%d\n", 9 ^ 1);

    // Un número...
    int num = 3;
    // Se aplica el operador ternario, el cual puede manejar}
    // Cadenas de caracteres
    char* resp = (num%2) != 0 ? "impar" : "par";
    // e indicar si el número es par o impar
    printf("%d es %s\n", num, resp);
    
    
    return 0;
}
