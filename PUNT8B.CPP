/*
  Curso de Programaci¢n
  Punteros 8B
*/
#include <stdio.h>
#include <conio.h>
#include <search.h>
/*
  void *bsearch(const void *key, const void *base, size_t nelem,
		size_t width, int (*fcmp)(const void*, const void*));
*/
#include <stdlib.h>
/*
  void randomize(void);
  int random(int num);
*/
#include <time.h>

/*FUNCIONES PROTOTIPO*/
int comparar(const void *arg1, const void *arg2);

void main()
{
 int i,x;
 int tabla[15];
 int *b;

 clrscr();
 //Inicia el generador de n£meros aleatorios
 randomize();
 /*Genera una tabla de 15 elementos aleatorios de 1 a 100*/
 for(i=0; i<15; i++)
  tabla[i]=random(100);
 /*Mostrar la tabla original*/
 printf("\n\nLista Original:\n");
 for(i=0; i<15; i++)
  printf("%d ",tabla[i]);

 /*Ordena la tabla utilizando el algotimo quick sort*/
 qsort((void *)tabla,(size_t)15,sizeof(int),comparar);

 /*Lista ordenada*/
 printf("\n\nLista Ordenada:\n");
 for(i=0; i<15; i++)
  printf("%d ",tabla[i]);

 printf("\n\nClave a buscar: ");
 scanf("%d",&x);
 /*
   Parametros de la funci¢n de busqueda binaria bsearch();
   &x -> Direcci¢n de la clave a buscar
   (void *)tabla -> Arreglo con los valores a buscar
   (size_t)15 -> N£mero de elementos del arreglo
   sizeof(int) -> Tama§o en bytes de cada elemento del arreglo
   comparar() -> Nombre de la funci¢n para comparaci¢n
 */
 b=(int *)bsearch(&x,(void *)tabla,(size_t)15,sizeof(int),comparar);

 if(b) //Elemento hallado
  printf("\nEl elemento %d esta en la tabla",x);
 else  //Elemento no hallado
  printf("\nEl elemento %d no esta en la tabla",x);

 getch();
}

/*DECLARACI‡N FUNCIONES*/
int comparar(const void *arg1, const void *arg2)
{
 return *(int *)arg1 - *(int *)arg2;
}