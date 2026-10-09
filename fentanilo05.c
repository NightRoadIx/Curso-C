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

    // Factorial de un número n!
    int i;
    long n;
    printf("Ingresar el número para calcular el factorial: ");
    scanf("%ld", &n);
    unsigned long factorial;
    // Calcular en una sola línea el factorial
    for(i = 0, factorial = 1; i < n ; factorial *= (n - i), i++);
        //factorial = factorial * (n - i)
        //factorial *= (n - i);

    printf("%ld! = %ld", n, factorial);

    return 0;
}
