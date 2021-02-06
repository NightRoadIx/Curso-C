/*
    Serie de Fibonacci
*/
// header
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Prototipo de funciones
int obtenerTotal(int minimo, int maximo);

// Variables globales

int main()
{
   // Variables locales
   char opc;
   int n, a, b, c, k, numMenu;
   int fibonacci[20]; // aquí los índices van de 0 hasta ... 19

   printf("Que deseas realizar: \n"); // cout << "Que deseas realizar: " << endl;
   printf("1.-Serie de Fibonacci\n");
   printf("2.-Triángulo de Pascal\n");
   printf("3.-Serie de Padovan\n");
   scanf("%d", &numMenu); // cin << numMenu;

   switch((int)floor(numMenu))
   {
       // if(numMenu == 1)
       case 1:
           printf("Serie de Fibonacci seleccionada\n");
           n = obtenerTotal(0, 20);

           // Llenar el arreglo, todo se puede hacer en una sola línea
           for(k = 0, a = 1, b = 0, c = 0; k < n; c = a + b, a = b, b = c, k++)
            fibonacci[k] = c;

           for(k = 0; k < n; k++)
            printf(" %d ", fibonacci[k]);
           break;
       // if(numMenu == 2)
       case 2:
        printf("Triángulo de Pascal seleccionado\n");
   }

   // float num;
   // if(num <= 3.141592652489)



}

// Declaración de funciones
int obtenerTotal(int minimo, int maximo)
{
    int n1;
   // Ingresar la cantidad de números a mostrar
   // Solamente aceptar números enteros y positivos
   // do - while => pedir perdón
   // while => permiso
   do
   {
       printf("Cuantos numeros de la serie de Fibonacci [%d, %d): ", minimo, maximo);
       // cout << "Cuantos numeros de la serie de Fibonacci [" << minimo << ", " << maximo << ")";
       scanf("%d", &n1); // cin >> n1;

       //if( (n > 0) && (n < 20) )
       // break;
   }
   while( (n1 <= minimo)||(n1 >= maximo) );  // n > 0 va a salir del ciclo

   return(n1);
}
