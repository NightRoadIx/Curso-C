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
    
    // Hardcode, se refiere al proceso de dar valores a variables
    // para realizar pruebas de los programas
    int rogaste = 100;
    bool lloraste = 1;
    bool arrastraste = 0;

    if( ((rogaste  >= 5 )&&(lloraste))&&(arrastraste) )
        printf("Lo siento, eres todo un migajero, a nivel Maya");
    else
        printf("No eres Maya, felicidades!");
}
