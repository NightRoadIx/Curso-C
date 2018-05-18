/*
  Curso de Programaci¢n
  Punteros 7
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define N 4

/*FUNCIONES PROTOTIPO*/
/*
  Los apuntadores y las funciones
  A veces se desea que una funci¢n regrese mas de un valor, y esto es
  posible con el uso de apuntadores, ya que cuando se pasa una variable
  a una fucni¢n, solo se pasa el valor de esta variable, pero cuando
  se pasa un apuntador a una fucni¢n se pasa su direcci¢n en memoria
*/
void salida(char*[], int *);
void entrada(char*[]);
int vocales(char*);

void main()
{
 //Arreglo de apuntadores
 char *cad[N];
 int j,voc[N];

 clrscr();
 //Se pasa el arreglo de apuntadores cad, esto es se pasa la direcci¢n de
 //este espacio en memoria
 entrada(cad);
 //En este punto del programa cad ya esta modificado
 for(j=0;j<N;j++)
  //Se manda cada elemento del arreglo de punteros
  voc[j]=vocales(cad[j]);
 //Se muestra por ultimo, mandando todo el arreglo de punteros y el de enteros
 salida(cad,voc);
 getch();
}

/*FUNCIONES DECLARACION*/
void entrada(char *cd[])
{
 char B[121];
 int j,tam;
 printf("\n\tEscribe %d lineas de texto\n",N);
 for(j=0;j<N;j++)
 {
  //Se obtiene una cadena que se guarda en el arreglo B
  gets(B);
  //Se realiza la asignaci¢n de memoria
  tam=(strlen(B)+1)*sizeof(char);
  cd[j]=(char*)malloc(tam);
  //Se copia la cadena B a cd[j] que no es mas que la direcci¢n en memoria
  //del arreglo de apuntadores *cad[N] que se encuentra en main
  strcpy(cd[j],B);
 }
}

//Se recibe una cadena
int vocales(char *c)
{
 int k,j;
 //Se revisara toda la cadena letra por letra
 for(j=k=0;j<strlen(c);j++)
  //Cuando ocurra una vocal se suma la variable k
  switch(tolower(*(c+j)))
  {
   case 'a':;
   case 'e':;
   case 'i':;
   case 'o':;
   case 'u': k++;
  }
 return k;
}

//Aqui se recibe el arreglo de apuntadores y el arreglo de enteros, pero este
//ultimo se recibe en forma de apuntador
void salida(char *cd[], int *v)
{
 int j;
 puts("\n\tSalida de las l¡neas junto al numero de vocales\n");
 for(j=0;j<N;j++)
  printf("%s : %2d\n",cd[j],v[j]);
}