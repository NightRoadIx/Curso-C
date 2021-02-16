/*
  Curso de Programaci¢n de C
  Punteros 1
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*
  Cuando una variable se declara existen tres atributos fundamentales:
  ->su tipo (int, float, char) [Da el tamaño que tiene que asignarse]
  ->su nombre [Como se llama la variable, la forma en que se referencia a ella]
  ->su dirección en memoria (0XFFFF p.e.) [El "lugar" en donde se coloca la variable]
*/

//VARIABLE GLOBAL
char c;

int main()
{
    /*
    Apuntador a caracter
    Para declarar un apuntador:
    tipo_variable *nombre_variable; (no importa si se coloca * nombre_variable)
    */
    char *pc;
    /*
    Se asigna la dirección de la variable c al apuntador pc, esto es
    que con esta sentencia el apuntador pc apunta al espacio en memoria
    de la variable c
    Operador dirección &
    (Asignación estática de memoria o inicializacion de punteros)
    */
    pc = &c;
    //Ahora se recorre la variable c desde A hasta Z
    for(c = 'A'; c <= 'Z'; c++)
        /*
        Lo que se hace es mostrar el contenido de lo que apunta pc
        mediante *pc
        Operador indirección *
        */
        printf(" %c ", *pc);

    getch();
    printf("\n\nAhora un entero:\n");
    int entero=30;
    int *p = &entero;
    printf("entero = %d , &entero = 0x%X \n",entero,&entero);
    printf("p = 0x%X , *p = %d , &p = 0x%X",p,*p,&p);
    printf("");
    getch();
}
