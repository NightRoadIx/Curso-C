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

    // El caso especial de la decisión, switch
    // La instrucción switch es una construcción especial de decisión (if)
    // para condicionales complejas, dividiéndolas en casos
    // No tiene límite de casos, sin embargo, ANSI C permite hasta 257
    // casos diferentes
    // OJO: Preferentemente se usan como valores de decisión los enteros
    int valor;

    // Hagamos Hardcode
    valor = 40;

    switch(valor)   // valor es la variable a comparar
    {
        // Cada caso se separa mediante la palabra clave case
        case 1:     // Esto es como colocar if(valor == 1)
            // Y luego el cuerpo del case
            // (observar que no se requiere de llaves dentro de los case)
            printf("Se ingreso al caso 1\n");
            printf("Es posible tener más instrucciones aquí");
            break; //esta sentencia rompe algun ciclo o pasa el control a la secuencia siguiente
        case 2:
            printf("Se ingreso al caso 2\n");
            break;
        case 3:
            printf("Se ingreso al caso 3\n");
            break;
        case 4:
            printf("Se ingreso al caso 4\n");
            break;
        default:    //Este es cuando ninguno se cumple, se considera opcional pero es preferible ponerlo
            printf("valor no vale ni 1,2,3 o 4, si no %d\n",valor);
            break;  // Igualmente este break es opcional
    }


    return 0;
}
