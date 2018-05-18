/*
  Curso de Programaci¢n de C
  Punteros 2
*/
#include <stdio.h>
#include <stdlib.h>
/*
  void *malloc(tama¤o de la variable);
  void free(void *bloque_memoria)
*/
#include <conio.h>
#include <string.h>
/*
  int strlen(char *cadena);
  strcpy(char *destino, char *origen);
*/

void main()
{
 clrscr();
 //Cadenas de caracteres
 char cad[121], *ptr;
 int lon;
 puts("\nIntroduce una l¡nea de texto\n");
 gets(cad);
 //Se obtiene la longitud de la cadena de caracteres
 lon=strlen(cad);
 printf("\nTama¤o de cadena (sin NULL)= %d\n",lon);
 /*
   Asignaci¢n din mica de memoria
   Si se desea asignar una variable a un apuntador, pero se desconoce
   el tama¤o de esta, se puede hacer en forma din mica con las sentencias:
   apuntador=(cast_tipo *)malloc(tama¤o_variable)
   (cast_tipo *) -> convierte a un tipo_variable * deseado
   malloc(tama¤o_variable) -> Asigna un bloque de memoria del tama¤o_variable
 */
 //Para este caso el tama¤o_variable = (longitud+1)*tama¤o_char
 ptr=(char *)malloc((lon+1)*sizeof(char));
 printf("Tama¤o asignado en memoria = %d\n",(lon+1)*sizeof(char));
 //Copia la cadena al apuntador
 strcpy(ptr,cad);
 printf("\nptr = %s",ptr); getch();
 /*
   ESTO ES MUY IMPORTANTE!!!!
   Siempre que se asigne en forma din mica la memoria, se tiene que
   colocar la funci¢n free(apuntador)
 */
 free(ptr);
}