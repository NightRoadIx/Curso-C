/*
  Curso de Programaci¢n
  Punteros 9
*/

#include <stdio.h>
#include <conio.h>

/*DECLARACI‡N DE LA ESTRUCTURA*/
typedef struct t_persona
{
 char nombre[30];
 int edad;
 int altura;
 int peso;
}persona;

/*FUNCIONES PROTOTIPO*/
void mostrar_persona(persona *ptr);

/*FUNCION PRINCIPAL*/
void main()
{
 int i;
 /*Se llena la estructura*/
 persona empleados[]={ {"Mart°nez Jose",47,182,85},
		       {"Garc°a Luis",39,170,75},
		       {"Jimenez Roberto",18,175,80} };
 /*Un puntero a la estrucutra*/
 persona *p;
 p=empleados; //Se asigna el puntero a la estrcutura con datos

 clrscr();
 /*Y simplemente se muestran*/
 for(i=0; i < 3; i++, p++) //Se aumenta el puntero
  mostrar_persona(p);
 getch();
}

/*DECLARACION DE FUNCIONES*/
void mostrar_persona(persona *ptr)
{
 /*
   Como manenaj los punteros las estructuras, pues muy sencillo
   ya que se declara el puntero a la estructura en lugar de acceder
   de la forma estructura.dato se hace:
   puntero_estructura->dato;
   Que puede recordarse como el puntero apunta "->" al dato
 */
 printf("\nNombre: %s", ptr->nombre);
 printf("\nEdad  : %d", ptr->edad);
 printf("\nAltura: %d", ptr->altura);
 printf("\nPeso  : %d\n", ptr->peso);
}