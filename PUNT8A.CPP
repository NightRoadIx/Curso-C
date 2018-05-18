/*
  Curso de Programaci¢n
  Punteros 8
  M‚todo de ordenaci¢n qsort
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
/*
  void qsort(void *base, size_t nelem, size_t width, int (*fcmp)(const void *, const void *));
*/

/*FUNCIONES PROTOTIPO*/
int compara_float(const void *a, const void *b);

/*VARIABLES GLOBALES*/
float v[]={34.5, -12.3, 4.5, 9.1, -2.5, 18.0, 10.0, 5.5};

/*FUNCION PRINCIPAL*/
void main()
{
 int j,n;
 int (*pf)(const void*, const void*); //Puntero a funci¢n

 clrscr();
 n=sizeof(v)/sizeof(v[0]); //N£mero de elementos
 printf("\n N£meros de elementos: %d\n",n);
 printf("Elementos: \n");
 for(j=0; j <n; j++)
  printf(" %.2f ", v[j]);

 pf=compara_float; //Asigna puntero a funci¢n
 /*
   Llamada a la funci¢n qsort
   argumentos (void *arreglo,num_de_elem,tama¤o_de_cada_elemento,funcion)
 */
 qsort((void*)v,n,sizeof(v[0]),pf);

 /*En este punto ya estan ordenados los n£meros*/
 printf("\nElementos ordenados: \n");
 for(j=0; j <n; j++)
  printf(" %.2f ", v[j]);

 getch();
}

/*DEFINICION DE FUNCIONES*/
int compara_float(const void *a, const void *b)
{
 float *x,*y;
 //Conversi¢n a un puntero flotante, ya que lo que tiene a & b es un puntero gen‚rico
 x=(float*)a; y=(float*)b;
 /*
   Qsort manda a llamar una funci¢n para comparar, en este caso la forma de
   comparaci¢n es restando los elementos que la funci¢n qsort proporciona
   de la forma: a es la llave de comparaci¢n y b es el elemento a comparar con la llave
   lo que se busca es que esta funci¢n devuelva tres valores diferentes:
   1.-  < 0, lo que indica que la llave (a) es menor al elemento (b)
   2.- == 0, loq ue indica que llave == elemento
   3.-  > 0, esto es que llave > elemento
   El algoritmo utilizado se le conoce como mediana de tres o quick sort
 */
 return(*x - *y);
}