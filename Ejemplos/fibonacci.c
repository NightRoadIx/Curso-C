/*
    Serie de Fibonacci
*/
// header
#include <stdio.h>
#include <stdlib.h>

// Variables globales

int main()
{
   // Variables locales
   int n, a, b, c, k;

   // Ingresar la cantidad de números a mostrar
   // Solamente aceptar números enteros y positivos
   printf("Cuantos numeros de la serie de Fibonacci: ");
   scanf("%d", &n);

   if(n > 0)
   {
       // Aceptar los valores y calcular
       printf("Numeros a mostrar %d\n", n);

       // Algoritmo de la serie
       // El for se ejecuta:
       // 1.-Valores de inicio, una sola vez
       // 2.-Prueba lógica para ver si se continua con el ciclo
       // 3.-Cuerpo del for
       // 4.-Operaciones
       // Los pasos 2 al 4 se ejecutan hasta que la prueba lógica en 2 es falsa
       for(k = 0, a = 1, b = 0, c = 0; c <= n; c = a + b, a = b, b = c, k++)
        printf(" %d ", c);
   }
   else
   {
       // Error, no es un número correcto
       printf("El numero ingresado no es correcto");
   }
}
