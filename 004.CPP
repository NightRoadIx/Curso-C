/*
   Curso de Programaci¢n en C
   Lecci¢n 4
*/

#include <stdio.h>
/*
  scanf(cadena_de_control, var1, var2, var3,...);
  getchar(variable caracter);
  fflush(variable archivo)
*/
#include <conio.h>
/*
  getch(); getche();
*/

void main()
{
 unsigned short int q; //Contador peque¤o
 int vi1,vi2;
 float vf1,vf2;
 char vc1, cada[8], *cadi=NULL;

 clrscr();
 //Uso de entradas estandar
 printf("Escribe dos enteros: \n");
 /*
   scanf es utilizada para la entrada de datos est ndar (por teclado)
   su sintaxis debe de ser:
   scanf("cadena de control", v1, v2, v3,...)
   Donde cadena de control es por ejemplo %d para enteros (ver 001.cpp)
   se pueden colocar varias para diferentes entradas como se muestra
 */
 scanf("%d %d", &vi1, &vi2);
 printf("Los enteros fueron %d & %d\n\n", vi1, vi2);

 fflush(stdin);
 /*
   La funci¢n fflush sirve para limpiar las entradas de archivos que se
   realicen (hay que recordar que C maneja todo como archivos), en caso
   de que se desee limpiar el buffer de entrada del teclado (el est ndar)
   se coloca:
   fflush(stdin);
   Para quitar los posibles ecos o que se deja presionada una tecla
 */
 printf("Ahora escribe un caracter: ");
 /*
   Para entrada de caracteres sencillos se tienen varias opciones
   getchar(); -> se espera a que se colque el caracter y un enter
   getch(); -> Se presiona solo el caracter
   getche(); -> Muestra el eco del caracter
 */
 vc1=getchar();
 printf("Con getchar: %c\n", vc1);
 vc1=getch();
 printf("Con getch  : %c\n",vc1);
 vc1=getche();
 printf("Con getche : %c\n",vc1);
 fflush(stdin);
 scanf("%c",&vc1);
 printf("Con scanf  : %c\n",vc1);

 /*
   Cadenas de caracteres:
   El manejo de cadenas de caracteres en C es algo complejo debido a el uso
   matem tico que se le di¢ a C en un principio, y por lo tanto se fueron
   creando funciones para adecuar el manejo de estas en el entorno de C
 */
 /*
   Para la declaraci¢n de las cadenas de caracteres se tienen 2 opciones:
   1.- Por arreglos
   2.- Por punteros
 */

 /*
   1.-Arreglos
   Los arreglos o vectores son un tipo extendido de datos en C que se manejan mediante
   tipo_dato nombre_variable[tamaño]
   por ejemplo se puede poner int arreglo[8];
   Este por tanto crea una variable entera con 8 espacios disponibles en ella para almacenar
   8 enteros.

   ¨Como se referencia a cada uno de ellos?
   La siguiente figura muestra como es que esta organizado el arreglo

   ÚÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄ¿
   ³ arreglo[0] ³ arreglo[1] ³ arreglo[2] ³ arreglo[3] ³ arreglo[4] ³ arreglo[5] ³ arreglo[6] ³ arreglo[7] ³
   ÀÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÙ

   Por tanto para referenciarse a cada uno de los bloques de memoria asigandos
   a arreglo[n] se debe colocar el n£mero n de "bloque" que se desea

 */
 int arreglo[8];
 //Llenado de un arreglo de ceros
 for(q=0; q <= 7; q++)
  arreglo[q]=0;

 //Se llenan con datos que el usuario adminstra
 for(q=0; q < 8; q++)
 {
  printf("Teclea el n£mero %d del arreglo: ",q);
  scanf("%d", &arreglo[q]);
 }

 //Mostrarlos
 printf("El arreglo: ");
 for(q=0; q < 8; q++)
  printf(" %d ",arreglo[q]);

 //Operar con ellos
 printf("\n arreglo[%d] + 5 = %d + 5 = %d",3,arreglo[3],arreglo[3]+5);
 printf("\n arreglo[%d] - arreglo[%d] = %d - %d = %d",2,1,arreglo[2],arreglo[1],arreglo[2]-arreglo[1]);

 /*
   Ahora no solo es posible crear vectores si no que es posible crear
   matrices bi-tri-tetra-... dimensionales de la forma
   int multidimensional[a][b][c][d]...[z];
   donde cada uno de los numeros a,b,c,d,...,z es el tama¤o de cada dimensi¢n

   Se hace referencia a ellas como:

   Para un arreglo[m][n]

   (1,1) (1,2) (1,3) . . . (1,n)
   (2,1) (2,2) (2,3) . . . (2,n)
   (3,1) (3,2) (3,3) . . . (3,n)
   .       .     .           .
   .       .     .           .
   .       .     .           .
   (m,1) (m,2) (m,3) . . . (m,n)

   Y de esa forma puede selecionarse cualquier valor como:
   arreglo[3][2] para el valor colocado en el bloque (3,2)

*/

 int matrix[3][3];
 unsigned short int i,j;

 getch(); clrscr(); fflush(stdin);
 //Llenarla de ceros
 for(i=0; i < 3; i++)
  for(j=0; j < 3; j++)
   matrix[i][j]=0;

 printf("Una matriz en C: \n");
 //Mostrar la matriz
 for(i=0; i < 3; i++)
 {
  for(j=0; j < 3; j++)
  {
   printf(" %d ",matrix[i][j]);
  }
  printf("\n");
 }

 //Incializacion de arreglos
 int numeros[6] = {10,20,30,40,50,60}; //Definiendo tama¤o
 int nnd[] = {3,4,5}; //Sin definir tama¤o

 printf("\n\n\nVector1 ->  ");
 for(i=0; i < 6; i++)
  printf(" %d ", numeros[i]);

 printf("\n\nVector2 ->  ");
 printf("Tama¤o: %d --",sizeof(nnd));
 //El operador sizeof determina el tama¤o de una variable
 for(i=0; i < sizeof(nnd); i++)
  printf(" %d ", nnd[i]);

 //Para iniciar cadenas
 char st[] = "Hola esta es una cadena";
 //C siempre la termina con el caracter final NULL o '\0'
 printf("\n\n\n %s ",st);

 //Ahora el trato de cadenas con arreglos es sencillo
 //Para obtenerse hay varias formas:
 //1.- Por medio de scanf
 printf("\n Teclea una cadena: ");
 scanf("%s", cada);
 printf("\n La cadena tecleada: %s",cada);
 fflush(stdin);
 //Por la funci¢n gets
 printf("\n\n Otra cadena :");
 gets(cada);
 printf("\n La cadena tecleada: %s",cada);
 //fflush(stdin);

 /*
   2.-Punteros o apuntadores
   Como puede notarse los arreglos estan muy limitados en cuanto al
   espacio, si emabrgo al usar apuntadores hacia caracteres, resulta mas
   sencillo colocar cadenas largas
 */
 printf("\n Teclea una cadena: ");
 gets(cadi);
 printf("Cadena: %s",cadi);

 /*
   El manejo de apuntadores es un tema aparte mucho mas extenso, pues existe
   hasta su propia aritm‚tica entre otras cosas, por lo que concierne
   al manejo de apuntadores a cadenas se dejara hasta aqui
 */
 getch();
}