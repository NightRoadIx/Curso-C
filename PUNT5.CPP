/*
  Curso de Programaci¢n
  Punteros 5
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*
  Arreglos de apuntadores
  Si se necesitan reservar muchos punteros a muchos valores diferentes, y los
  cuales se conoce su n£mero se pueden declarar arreglos de apuntadores
*/
//Por ejemplo este arreglo de cadenas de caracteres
char *meses[12] = {
"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto",
"Septiembre","Octubre","Noviembre","Diciembre"
};

void main()
{
 clrscr();
 int i;
 printf("Los meses del a¤o:\n");
 for(i=0; i < 12; i++)
  //Se muestra el elemento i del arreglo de punteros
  printf("Mes %d es %s\n",i+1,meses[i]);
 getch(); clrscr();
 //Y tambi‚n se puede usar un apuntador para mover arreglos
 char alfabeto[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
 char *p;
 //Se asigna la direcci¢n
 p=&alfabeto[0]; //o simplemente p=alfabeto;
 printf("Elemento al que apunta p = %c",*p);
 //y puede usarse el apuntador de la siguiente manera para accesar a todos los elementos
 putchar('\n');
 while(*p) //Es lo mismo que while(*p!=NULL)
 {
  printf(" %c ",*p);
  p++;  //Se aumenta el apuntador en una posici¢n
 }
 /*
   A los apuntadores se les puede sumar o restar enteros, puede modificarse
   a donde apunta, pero no pueden sumarse dos punteros, ni restarse, ni
   tampoco esta permitido multiplicarlos o dividirlos
 */
 getch();
}
