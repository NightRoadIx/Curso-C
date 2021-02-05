/*
    Serie de Fibonacci
    
    Se reciben solamente números enteros y positivos en el intervalo (0, 20)
    ya que los datos se almacenan en vector o arreglos
*/
// header
#include <stdio.h>
#include <stdlib.h>

// Variables globales

int main()
{
   // Variables locales
   int n, a, b, c, k;
   int fibonacci[20]; // aquí los índices van de 0 hasta ... 19

   // Ingresar la cantidad de números a mostrar
   // Solamente aceptar números enteros y positivos
   // do - while => pedir perdón
   // while => permiso
   do
   //while(1)
   {
       printf("Cuantos numeros de la serie de Fibonacci: ");
       scanf("%d", &n); // cin >> n;
       //if( (n > 0) && (n < 20) )
       // break;
   }
   while( (n <= 0)||(n >= 20) );  // n > 0 va a salir del ciclo
   // este es el intervalo de recepción de valores (n > 0) && (n < 20)

   for(k = 0, a = 1, b = 0, c = 0; k <= n; c = a + b, a = b, b = c, k++)
    //printf(" %d ", c); // cout << " " << c << " ";
    fibonacci[k] = c;

   for(k = 0; k <= n; k++)
    printf(" %d ", fibonacci[k]);

/*   if(n > 0)
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
   }
   else
   {
       // Error, no es un número correcto
       printf("El numero ingresado no es correcto");
   }*/
}

