// STanDard Input Output
#include <stdio.h>
// STanDard LIBrary
#include <stdlib.h>
// Manejo de cadenas de caracteres+
#include <string.h>
// STandard BOOLean
#include <stdbool.h>
// Esta librería ayuda a la configuración del entorno local
#include <locale.h>

// Función principal
int main()
{
    /*
    Apuntador void *, este es un apuntador genérico, esto es
    que puede asignarse a cualquier tipo de datos, pues si se declarase
    int *pint;
    pint solo puede apuntar a direcciones de memoria ocupadas por enteros
    sin embargo, con un void *pg, pg puede apuntar a cualquier dirección
    de memoria válida
    */
    void *p;
    int i;
    int m = 0;
    printf("Prueba de asignación de memoria dinámica\n");
    for(i = 1; i < 100; i++)     // Se intentará asignar memoria 10 veces
    {
        p = malloc(1000);   // Asigna un bloque de 1000 bytes
        // Cuando ya no se pueda asignar mas espacio
        if(p==NULL) break;
        m += 1;
    }
    printf("\nTotal de memoria asignada %.2f Kb\n",(m*1000.0)/1024);

    // Liberar la memoria asignada
    free(p);

    return 0;
}
