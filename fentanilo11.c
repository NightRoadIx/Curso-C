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
    // Cadenas de caracteres
    char cad[121], *ptr;
    int lon;
    printf("\nIntroduce una línea de texto\n");
    // Antiguamente se usaba gets(*cadena); para recibir una cadena de 
    // caracteres, pero esta función es peligrosa, ya que no se puede 
    // controlar el tamaño de la cadena y puede provocar un desbordamiento 
    // de búfer. Por lo tanto, se recomienda usar fgets() en su lugar.
    fgets(cad, sizeof(cad), stdin);
    // Se obtiene la longitud de la cadena de caracteres
    lon = strlen(cad);
    printf("\nTamaño de cadena (sin NULL)= %d\n",lon);
    /*
    Asignación dinámica de memoria
    Si se desea asignar una variable a un apuntador, pero se desconoce
    el tamaño de esta, se puede hacer en forma dinámica con las sentencias:
    apuntador=(cast_tipo *)malloc(tamaño_variable)
    (cast_tipo *) -> convierte a un tipo_variable * deseado
    malloc(tamaño_variable) -> Asigna un bloque de memoria del tamaño_variable
    */
    // Para este caso el tamaño_variable = (longitud+1)*tamaño_char
    ptr = (char *)malloc((lon+1)*sizeof(char));
    printf("Tamaño asignado en memoria = %d\n",(lon+1)*sizeof(char));
    // Copia la cadena al apuntador
    strcpy(ptr,cad);
    printf("\nptr = %s",ptr);
    /*
    ESTO ES MUY IMPORTANTE!!!!
    Siempre que se asigne en forma dinámica la memoria, se tiene que
    colocar la función free(apuntador)
    para liberar la memoria asignada, de lo contrario se puede 
    provocar una fuga de memoria
    */
    free(ptr);

    return 0;
}
