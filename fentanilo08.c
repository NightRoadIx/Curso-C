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

    // Este es el número de punto flotate que se va a convertir
    float num = 13.22;

    // Conversión a binario, en primer lugar la parte entera
    int numero = (int)num;
    int res, coc;

    // Obtener la división y el residuo
    do
    {
        res = numero % 2;   // residuo
        coc = numero / 2;   // cociente
        numero = coc;       // sustituir dividendo por cociente
        // Mostrar en pantalla
        printf("%d | %d\n", coc, res);
    } while(coc != 0);

    // La parte decimal
    // se obtiene quitándole la parte entera al número dado
    float dec = num - (int)num, nuevo;
    int i, entero;
    printf("%f\n", dec);
    for(i = 0, entero = 0; i < 32; i++)
    {
        // Obtener el valor nuevo
        nuevo = (dec - entero) * 2.0;
        dec = nuevo;
        // Obtener el valor entero de dec
        entero = (int)dec;        
        printf("%d \t %.4f\n", entero, nuevo);
    }

    return 0;
}
