#include <stdio.h>
#include <stdlib.h>
/*
  void *malloc(tamaño de la variable);
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
    // Cadenas de caracteres
    char cad[121], *ptr;
    int lon;
    printf("\nIntroduce una linea de texto\n");
    gets(cad);
    // Se obtiene la longitud de la cadena de caracteres
    lon = strlen(cad);
    printf("\nTamaño de cadena (sin NULL)= %d\n",lon);
    /*
    Asignación dinámica de memoria
    Si se desea asignar una variable a un apuntador, pero se desconoce
    el tamaño de esta, se puede hacer en forma dinámica con las sentencias:
    apuntador=(cast_tipo *)malloc(tama¤o_variable)
    (cast_tipo *) -> convierte a un tipo_variable * deseado
    malloc(tama¤o_variable) -> Asigna un bloque de memoria del tamaño_variable
    */
    // Para este caso el tamaño_variable = (longitud+1)*tamaño_char
    ptr = (char *)malloc((lon+1)*sizeof(char));
    printf("Tamaño asignado en memoria = %d\n",(lon+1)*sizeof(char));
    // Copia la cadena al apuntador
    strcpy(ptr,cad);
    printf("\nptr = %s",ptr); getch();
    /*
    ESTO ES MUY IMPORTANTE!!!!
    Siempre que se asigne en forma dinámica la memoria, se tiene que
    colocar la función free(apuntador)
    */
    free(ptr);
}
