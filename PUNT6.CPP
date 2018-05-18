/*
  Curso de Programaci¢n
  Punteros 6
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
/*
  strcat(char *destino, char *origen);
*/

void main()
{
 char *cadena;
 int tam;
 clrscr();
 /*Se obtiene el tama¤o de la cadena "Primavera"*/
 tam=(strlen("Primavera")+1)*sizeof(char);
 /*Despu‚s se asigna espacio en memoria*/
 cadena=(char*)malloc(tam);
 /*Se copia la cadena entonces despu‚s de asignar el espacio*/
 strcpy(cadena,"Primavera");
 /*Se muestra en pantalla*/
 printf("Tama¤o de la primera cadena: %d\n",tam);
 puts(cadena);
 /*Amplia el bloque de memoria sumando lo de la cadena " en Morelos"*/
 tam+=(strlen(" en Morelos\n")+1)*sizeof(char);
 /*Despu‚s se re-asigna espacio en memoria*/
 cadena=(char*)realloc(cadena,tam);
 /*
   Se copia la nueva cadena a la anterior al final de la primera
   La cadena origen se copia al final de la destino
 */
 strcat(cadena," en Morelos\n");
 /*Y la mostramos en pantalla*/
 printf("Tama¤o de la cadena ampliada: %d\n",tam);
 puts(cadena);
 /*Liberacion de memoria*/
 free(cadena);
 getch();
}