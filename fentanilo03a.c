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
    
    int anno;
    printf("Ingrese un año: ");
    scanf("%d", &anno);

    if( ((anno%4 == 0)&&(anno%100 != 0))||(anno%400 == 0) )
        printf("El año %d es bisiesto", anno);
    else
        printf("El año %d NO es bisiesto", anno);
}
