// STanDard Input Output
#include <stdio.h>
// STanDard LIBrary
#include <stdlib.h>
// STandard BOOLean
#include <stdbool.h>
// Esta librería ayuda a la configuración del entorno local
#include <locale.h>

// Función principal
int main()
{
    // Establece la región a español para mostrar acentos y la ñ
    setlocale(LC_ALL, "spanish");  
    
    // Iniciar el valor de i a 0
    int i = 0;
    // Comenzar con el ciclo que primero pide permiso
    while(i < 5)
    {
        printf("Número %d\n", i);
        // Incrementar en 1 el valor de i
        i = i + 1;
    }
    printf("Salí del primer while\n");

    // Para probar do-while, el que hace primero
    // y luego pide permiso
    i = 0;
    do
    {
        printf("Número %d\n", i);
        // Incrementar en 1 el valor de i
        i = i + 1;
    }
    while(i < 5);  // IMPORTANTE, colocar el ;
    printf("Salí del do - while\n");

    return 0;
}
