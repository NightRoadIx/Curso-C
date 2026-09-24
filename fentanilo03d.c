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
    
    // Saber si se trata de un triángulo
    float a, b, c;
    printf("Armado de triángulos... amorosos\n");
    printf("a: ");
    scanf("%f", &a);
    printf("b: ");
    scanf("%f", &b);
    printf("c: ");
    scanf("%f", &c);

    // Si la suma de dos lados es mayor al otro
    // se puede armar un triángulo
    // es posible salvar la expresión en una variable entera
    // o para mayor precisión boolean
    bool maya = ((a + b) > c)&&((a + c) > b)&&((b + c) > a);
    if(maya)
        printf("Es un triángulo.... amoroso");

    return 0;
}
