/*
  Curso de Programaci¢n en C
  Leccion 9
  Archivos Binarios (lectura)
*/

#include <stdio.h>
/*
   size_t fread(void *ptr, size_t size, size_t n, FILE *stream);
*/
#include <conio.h>
#include <stdlib.h>

/*
  Programa lectura para los puntos guardados en el archivo Puntos.txt
  Obtiene el n£mero de veces que aparece un punto dado
  Y dado el valor de j, obtener las media de i para los puntos que contiene a j
*/

/*VARIABLES GLOBALES*/
typedef struct punto
{
 int i,j;
}PUNTO;

FILE *pp;

/*FUNCIONES PROTOTIPO*/
int cuenta_pto(PUNTO w);

void main()
{
 PUNTO p;
 float media,nmd,dnm;

 clrscr();
 if( (pp=fopen("Puntos.txt","rb"))==NULL )
 {
  puts("\nError en la apetura de archivo"); getch(); exit(-1);
 }
 printf("Puntos Encontrados:\n");
 while(!feof(pp))
 {
  fread(&p,sizeof(PUNTO),1,pp);
  printf("(%d,%d)\n",p.i,p.j);
 } rewind(pp);

 printf("Introduce las coordenadas del punto a buscar: ");
 scanf("%d %d",&p.i,&p.j);
 printf("Repeticiones del punto (%d,%d): %d",p.i,p.j,cuenta_pto(p));

 /*C†lculo de la media i para un valor j*/
 printf("\n\nValor de j: "); scanf("%d",&p.j);
 media=nmd=dnm=0.0;
 for(p.i=1; p.i <= 10; p.i++)
 {
  int st;
  rewind(pp);
  st=cuenta_pto(p);
  nmd+=(float)st*p.i;
  dnm+=(float)st;
 }

 if(dnm > 0.0)
  media=nmd/dnm;
 printf("Media de los valores de i para %d = %.2f",p.i,media);

 getch();
}

/*FUNCIONES DECLARACI‡N*/
int cuenta_pto(PUNTO w)
{
 PUNTO p;
 int r;
 r=0;
 while(!feof(pp))
 {
  /*
    Para lectura de archivos binarios, lee de un archivo n bloques de bytes
    y los almacena en un buffer
    fread(dir_buffer,tama§o,n,puntero_archivo);
    Regresa el n£mero de bloques que lee, el cual debe coincidir con n
  */
  fread(&p,sizeof(PUNTO),1,pp);
  if(p.i==w.i && p.j==w.j) r++;
 }
 return r;
}