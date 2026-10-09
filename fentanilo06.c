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

    // Suma de N números
    int i;
    long N;
    printf("Ingresar el número hasta el cual deseas sumar: ");
    scanf("%ld", &N);
    unsigned long suma;
    // Calcular la suma de números de 1 hasta N
    // se inicia la variable suma a 0
    // ya que se trata del nulo aditivo
    // cualquier cosa más 0, da eso mismo XD
    for(i = 1, suma = 0; i <= N ; suma += i, i++);

    printf("Total = %ld", suma);

    return 0;
}
