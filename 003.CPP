/*
  Curso de Programaci¢n en C
  Leccion 3
*/

#include <stdio.h>
#include <conio.h>

void main()
{
 int x,y,q,i,j;

 clrscr(); getch();
 /*
    Sentencias de control
    Uno de los puntos mas importantes de la programaci¢n radica en que se
    pueden realizar operaciones a velocidades muy altas, as¡ tambi‚n como
    repeticiones sucesivas y toma de decisiones. Para esto funcionan las
    sentencias de control, que en el lenguaje C se componen de:
    if, else, switch, do, while, for
 */

 /*
   Sentencia if - else
   if (expresion)
   {
    sentencias
   }
   else if (expresion)
   {
    sentencias
   }
   else
   {
    sentencia
   }

   La sentencia de control if se utiliza para la toma de decisiones
   basandose en una expresion, la cual puede usar numeros, variables y
   operadores de comparacion
   Notese que se usan las llaves { } para abrir y cerrar lo que contenga el
   if, sin embargo en caso de que solo halla una sentencia o llamada a funcion
   dentro del if, no es necesario que la lleve
 */
 x=5; y=3;  //Pueden modificarse estos valores para pruebas
 if(x > 6) //Primero se prueba que x sea mayor a 5
 {
  i=9+x; //en caso afirmativo, se hacen algunas asignaciones
  printf("Aqui x es mayor a 6\n"); //y hasta desplegar cosas
 }
 else if(x == 6) //Pero si no (if else) si x es menor a 6
 {
  i=9-x;
  printf("Aqui x es igual a 6\n");
  /*Ahora un proceso mas interesante la anidaci¢n*/
  if(y == 3) printf("Y tambi‚n y es a igual 3"); //Notar que al ser 1 sola sentencia no hay llaves
  /*
    La anidaci¢n simplemente se trata de dentro de una sentencia de control
    meter otras del mismo tipo o de diferente tipo...
    El £nico requisito es llevar bien la cuenta de las llaves abiertas y cerradas
  */
 }
 else  //en caso de que no se cumpla nada de esto
 {
  i=x;
  printf("Aqui x no es ni mayor a 6 ni igual\n");
 }

 getch();
 putch('\n');
 /*
   Sentencia switch
   El uso de if - else es muy comun, sin embargo cuando se necesitan varios de
   estos o una naidacion muy profunda es preferible el uso del switch

   switch (variable)
   {
    case 1:
     sentencias
     break;
    .
    .
    .
    case n:
     sentencias
     break;
    default:
     sentencias break;
   }
 */

 switch (x)
 {
  case 1:
   printf("x vale uno\n");
   break;   //esta sentencia rompe algun ciclo o pasa el control a la secuencia siguiente
  case 2:
   printf("x vale dos\n");
   break;
  case 3:
   printf("x vale tres\n");
   break;
  default:    //Este es cuando ninguno se cumple, se considera opcional pero es preferible ponerlo
   printf("x no vale ni 1,2 o 3, si no %d\n",x);
   break;
 }

 getch();
 putch('\n');
 /*
   Sentencias do - while, realizan ciclos
   Hay dos opciones para colocar estas sentencias:

   1.-
   do
   {
    sentencias
   }
   while(expresion);

   En esta se realiza primero el ciclo o las sentencias y despu‚s se evalua
   la expresion para ver si continua o no el ciclo

   2.-
   while(expresion)
   {
    sentencias
   }

   En esta es alrev‚s, pues primero se evalua la expresion y si es verdadera
   se realiza las sentencias

   ***NOTA***
   Debe tenerse mucho cuidado con los cilcos infinitos, o sea aquellos en los
   que la expresion simepre de 1 (como 6>5) pues no errores no detectados
   al compilar y suelen dejar "colgado" al programa, en caso de que ocurra
   esto se debe de hacer uso de la combinaci¢n de teclas Ctrl+pausa
 */

 //Probemos la multiplicacion 5 x 4
 j=1; i=0;
 do
 {
  i+=5; //Aumentemos en 5 cada ciclo
  j++; //y hacemos que j aumente en 1 cada ciclo
 }
 while(j <= 4);
 printf("1.- 5 x 4 = %d\n",i);
 //Ahora con while
 j=1; i=0; //Se le da un "reset" a las variables
 while(j < 5) //Aqui tambi‚n puede usarse j <=4
 {
  i+=5;
  j++;
 }
 printf("2.- 5 x 4 = %d\n",i);
 //Ahora usando un ciclo infinito
 j=1; i=0;
 while(1)
 {
  i+=5; j++;
  if(j > 4) break; //Con esto "rompemos" el ciclo infinito
 }
 printf("3.- 5 x 4 = %d\n",i);

 /*
    Sentencia for, esta se utiliza tmabi‚n para realizar ciclos,
    sin embargo se usa cuando se tiene una idea mas precisa de cuando debe
    parar el ciclo, como en el caso de las multiplicaciones

    for(inicializacion de vars; expresion control;accion)
    {
     sentencias
    }
 */
 getch(); putch('\n');
 //De nuevo probemos la multiplicaci¢n, pero ahora mostrando la tabla del 5 hasta el 10
 for(j=1, i=5; j <= 10; i+=5, j++) //Notar la separacion de sentencias iguales mediante comas
  printf("5 x %d = %d\n",j,i);

 /*
   NOTA FINAL: En cualquiera de estas sentencias de control se puede no poner
   las llaves si solo se trata de 1 sola sentencia a la que contiene el control
 */
 getch();
}