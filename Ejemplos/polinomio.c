/*
 * Generar un programa que
 * cree un polinomio de grado "n"
 * que ingrese el usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

int main()
{
    unsigned int grado, i;
    float coef[6], tmp, x = 3.0, total = 0.0;

    printf("Ingrese el grado maximo [0,6]: ");
    scanf("%d", &grado);

    for(i=grado; i > 0; i--)
    {
        printf("Coeficiente x^%d: ", i-1);
        scanf("%f", &tmp);
        coef[i-1] = tmp;
    }

    printf("\nEl polinomio es: ");
    for(i=grado; i > 0; i--)
    {
        printf(" %.2fx^%d +", coef[i-1], i-1);

        // Evaluar polinomio
        total += coef[i-1] * pow(x, i-1);
    }
    printf("\nEvaluado en %.2f = %.2f", x, total);

    return 0;
}
