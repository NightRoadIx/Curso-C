/*
  Curso de Programaci¢n
  Punteros 8
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*
  Punteros a funciones
  Tal y como una variable, una funci¢n tiene direcci¢n en memoria y puede
  ser "apuntada" mediante un puntero. En C se pueden asignar direcciones iniciales
  de funciones a punteros. Tales funciones se pueden llamar en un modo indirecto,
  es decir, mediante un puntero cuyo valor es igual a la direcci¢n inicial de
  la funci¢n.
  Se declara de la siguiente forma:

  tipo_dato (*nombre_puntero_funci¢n)(lista de par metros funci¢n);

  por ejemplo:
  int f(int);		//Declara la funci¢n
  int (*pf)(int);	//Define el puntero pf a una funci¢n int con argumento int
  pf=f;			//Asigna la direcci¢n de la funci¢n al puntero

*/

/*FUNCIONES PROTOTIPO*/
float ejemplo(int, int);
double inversos(int k);
double cuadrados(int k);
//Asi tambi‚n es posible usar estos apuntadores a funci¢n como argumentos
double funcsuma(int n, double(*f)(int k));

void main()
{
 clrscr();

 //Se declara el puntero funci¢n
 float (*p)(int, int);
 //Se asigna a la funci¢n
 p=ejemplo;
 //p(1,1) devuelve lo mismo que si se escribiera ejemplo(12,45);
 printf("Valor de la funci¢n: %f",p(1,1));

 //Ahora usando punteros a funciones como argumentos
 printf("\n\n");
 //Se llama a la funci¢n un entero y una funci¢n
 printf("Suma de cinco inversos: %.3lf \n",funcsuma(5,inversos));
 printf("Suma de tres cuadrados: %.3lf \n",funcsuma(3,cuadrados));

 getch();
}

/*FUNCIONES DECLARACION*/
float ejemplo(int i, int j)
{
 return 3.1416 * i * i + j;
}

/*
  Aqui es donde se manda a llamar una funci¢n double con un argumento int
  mediante el apuntador f
*/
double funcsuma(int n, double (*f)(int k))
{
 double s=0;
 int i;
 for(i=1; i <= n; i++)
  s+=f(i);  //Aqui se manda a llamar a la funci¢n que se paso como argumento
 return s;
}

double inversos(int k)
{
 return 1.0/k;
}

double cuadrados(int k)
{
 return (double)k * k;
}