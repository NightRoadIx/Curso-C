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

    // Ahora si, ahí les va...
    //¡ ARREGLOS !
    // tipoDeDato nombreVariable[N] = {, , , , };
    int chernobyl[6] = {4, 666, 69, 42, 67, 13};     // Esto es para iniciarlos
    // Los índices son solamente del tipo entero
    int indice = 3;
    // Probar los valores
    printf("Valor %d del arreglo es: %d\n", indice, chernobyl[indice]);
    // Luego se hace una modificación en uno de los elementos
    chernobyl[3] = 0;
    // Se recorren los elementos para mostrarlos
    for(indice = 0; indice < 6; indice++)
        printf(" %d ", chernobyl[indice]);

    // Para crear matrices, se agrega una dimensión adicional
    int matrix[2][2] = {{4, 13},
                        {69, 67}};
    // Luego su manejo se hace considerando FC Filas-Columnas
    int f = 0, c = 1, i, j;
    printf("\nElemento (%d, %d) es %d\n", f, c, matrix[f][c]);
    // Y la parte interesante, el manejo de matrices se hace considerando
    // "anidar" los for, de la siguiente manera
    for(i = 0; i < 2; i++)      // Control de las filas
        for(j = 0; j < 2; j++)  // Control de las columnas
            printf("matrix[%d, %d] = %d\n", i, j, matrix[i][j]);

    return 0;
}
