/*
  Curso de Programaci¢n en C
  Leccion 9
  Archivos Binarios (escritura)
*/
#include <stdio.h>
/*
  size_t fwrite(const void *ptr, size_t size, size_t n, FILE*stream);
*/
#include <conio.h>
#include <stdlib.h>

/*
  Manejo de archivos binarios en C
  Para abrir un archivo en modo binario hay que especificar la opci¢n "b"
  en el modo de apertura. Una de las caracterisitcas de los archivos binarios
  es que optimizan la memoria ocupada por un archivo, sobre todo con campos
  num‚ricos. El problema con ellos es que solo pueden ser leidos en modo
  binario dentro del entorno de C.
*/

/*Estrucutura para manejo de puntos*/
typedef struct punto
{
 int x,y;
}PUNTO;

void main()
{
 PUNTO p;
 FILE *pp;

 clrscr();
 if( (pp=fopen("Puntos.txt","wb"))==NULL )
 {
  puts("\nError en la apetura de archivo"); getch(); exit(-1);
 }

 printf("\nIntroduce coordenadas de puntos [para acabar (0,0)]:\n");
 do
 {
  scanf("%d %d",&p.x,&p.y);
  //Checar que sea mayor que cero
  while(p.x<0 || p.y<0)
  {
   printf("Coordenadas deben ser >=0 :\n");
   scanf("%d %d",&p.x,&p.y);
  }
  //Cuando sean mayores a cero
  if(p.x>0 || p.y>0)
  {
   /*
     fwrite(direcci¢n del buffer,tama¤o,num_elementos,puntero_archivo);
     Escribe en un buffer de cualquier tipo de dato en un archivo binario
   */
   fwrite(&p,sizeof(PUNTO),1,pp);
  }
 }
 while(p.x>0 || p.y>0);
 getch();
 /*Cerrar archivo*/
 fclose(pp);
}