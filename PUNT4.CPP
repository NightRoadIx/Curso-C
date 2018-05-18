/*
  Curso de Programaci¢n de C
  Punteros 4
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

/*
  Punteros a punteros
  Los punteros no solo pueden ser asignados a variables "estaticas", sino
  que tambi‚n es posible hacer punteros a punteros (y si fuera necesario
  es posible hacer punteros a punteros a punteros, a punteros ...)
  Este tipo de variables se usa en programas mas complejos en donde sea necesario
  mover direcciones de memoria de varias variables
*/

void main()
{
 clrscr();
 //La declaraci¢n se realiza como tipo_variable **variable;
 char c='z';		//Un caracter
 char *pc=&c;		//Se asigna la direcci¢n de c a pc
 char **ppc=&pc;	//Se asigna la direcci¢n de pc a ppc
 char ***pppc=&ppc;	//Se asigna la direcci¢n de ppc a pppc
 /*
   Esto implica que pppc tiene la direcci¢n de ppc que tiene la direcci¢n
   de pc que tiene la direcci¢n de c, por lo tanto por medio de pppc puede
   accesarse a c
 */
 printf("c = %c en 0X%X\n\n",c,&c);
 printf("pc apunta a 0X%X que contiene %c, y pc tiene direcci¢n 0X%X\n\n",pc,*pc,&pc);
 printf("ppc apunta a 0X%X que contiene 0X%X que contiene %c, direcci¢n ppc es 0X%X\n\n",ppc,*ppc,**ppc,&ppc);
 printf("pppc apunta a 0X%X que contiene 0X%x que contiene 0X%X que contiene %c\n",pppc,*pppc,**pppc,***pppc);
 printf("Direcci¢n pppc es 0X%X",&pppc);
 getch();
 clrscr();
 /*
   Ahora la utilidad de estos apuntadores a apuntadores es que con ellos
   es posible crear matrices de 2D en adelante que no necesariamente tengan
   el mismo numero de filas o volumnas por cada columna o fila

   Primero se muestra el uso de apuntadores en arreglos, ya que el nombre de
   un arreglo es simplemente un puntero
   supongamos que:
   int lista[5] = {10,20,30,40,50};
   para acceder a un elemento se hace lista[2] que nos dar¡a 30 como resultado
   sin embargo tambi‚n es posible acceder al n£mero mediante *(lista+2)
*/
 int lista[5] = {10,20,30,40,50};
 printf("Accediendo a lista[2]   = %d\n",lista[2]);
 printf("Accediendo a *(lista+2) = %d\n",*(lista+2));
 printf("Si se coloca solo lista = %d es igual que colocar lista[0] = %d\n",*lista, lista[0]);
 printf("Y lista = 0X%X es igual que &lista[0] = 0X%X\n\n",lista,&lista[0]);

 //Y tambi‚n por medio de un puntero puede hacerse un arreglo
 float *ap=NULL;
 int j;
 for(j=0; j < 10; j++)
 {
  *(ap+j) = j*10.0;  //Notar como se suma el puntero
  printf("Elemento %d = %.2f\n",j,*(ap+j));
 }
 ap=NULL; //Se evitan errores con esta sentencia
 getch(); clrscr();

 /*
   Ahora para crear una matriz mediante punteros
 */
 int **p,n,m[100],i;
 //Se pide el n£mero de filas que tendr  la matriz siempre mayor a cero
 do
 { printf("No. de filas: "); scanf("%d",&n);}
 while(n<=0);
 //Asignaci¢n din mica de memoria para doble apuntador
 p=(int **)malloc(n*sizeof(int *));
 //Aceptar elementos de cada fila
 for(i=0; i<n; i++)
 {
  printf("No. de elementos de fila (<100) %d: ",i+1);
  scanf("%d",&m[i]);
  //Asigna memoria para cada vector
  p[i]=(int*)malloc(m[i]*sizeof(int));
  //Acepta los elementos
  for(j=0;j<m[i];j++)
  {
   printf("Elemento %d -> ",j);
   scanf("%d",&p[i][j]);
  }
 }

 int x, y;
 //Mostrar elementos
 //Filas
 for(i=0,y=2;i<n;i++,y++)
 {
  //Elementos de fila
  for(j=0,x=2;j<m[i];j++,x+=2)
  {
   printf(" %d ",p[i][j]);
  }
  printf("\n");
 }
 getch();

/*  char cadena[30];
  cadena = "Esta es una cadena";*/
/*  char *cadena;
  cadena = "Esta es una cadena";*/
}
/*
  Los punteros presentan varias ventajas sobre los arreglos ya que el nombre
  de un arreglo es una constante puntero, no una variable puntero, por
  lo que no se puede cambiar el valor de un nombre de array, como no se pueden
  cambiar valores constantes, por ejemplo si se declara:
  char cadena[30];
  y se intenta asiganr
  cadena = "Esta es una cadena";
  la sentencia provoca un error
  en cambio si se hubiese declarado
  char *cadena;
  cadena = "Esta es una cadena";
  no provoca error
*/