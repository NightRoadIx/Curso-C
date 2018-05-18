/*
  Curso de Programaci¢n en C
  Leccion 1
*/

/*
   El compilador de C es realmente sencillo y la sintaxis del codigo
   tambien es una de las mas sencillas (tal vez con excepcion de QBASIC)
   Para comenzar las lineas de comentario se colocan como:
   // para comentarios de una sola linea
   o como se encuentra este para varias lineas
   Para cerrar las lineas de c¢digo, se usa el ; y gralmente. es para finalizar
   la llamada a una funci¢n o asignacion de variables.
   La extensi¢n de los archivos que contienen el c¢digo fuente por lo general
   llevan una extensi¢n de .c o .cpp (la mas recomendable), mientras que las librerias
   llevan extensi¢n .h.
   Para compilar el archivo (esto es se chequean los posibles errores en el c¢digo,
   estos son errores de escritura o de comandos) se debe de acceder al menu
   Compile o presionar Alt+F9 y el TurboC mostrara posibles errores, adem s
   de generar los archivos objeto (.obj) y recupareaci¢n (.bak).
   Para ejecutar el archivo y crear el ejecutable (.exe) se debe de ir al
   menu Compile y presionar Make Exe File o por medio de la combinacion Ctrl+F9,
   y as¡ se pueden verificar errores en tiempo de ejecuci¢n.
*/

/*
  Linea de librerias, aqui es en donde se colocan las librerias que C cuenta,
  La sintaxis puede ser de 2 formas:
  #include<libreria.h> para librerias que estan en el directorio \INCLUDE
  #include"libreria.h" para aquellas librerias que no estan en el directorio
  mencionado y ademas se encuentran en donde esta el c¢digo
*/
//En los primeros programas se hara un listado de las funciones de las librerias usadas
#include<stdio.h>
/*
   Listado de funciones
   1.-printf();
*/
#include<conio.h>
/*
   1.-clrscr();
   2.-getch();
*/

/*
   Linea de Definiciones
   Aqui se pueden hacer definiciones de constantes, ya sea n£mericas o
   alfabeticas, la declaraci¢n es de la forma:
   #define NOMBRE valor
   Para el nombre de la definici¢n es preferible colocarlo con mayusculas
   y de longitud menor a 12. Para mas info. vease la seccion de variables.
*/
#define DEFINICION 50

/*
  Variables Globales.
  Las variables son nombres de valores que pueden ser utilizados dentro
  del programa, en este caso se creo una variable global que puede ser
  manipulada en todo el programa a diferencia de una variable local.
  Se declaran como:
  tipo_dato nombre_variable;
  El tipo_dato puede ser:
  char  -> Caracter, este es un solo caracter ASCII (de 0 a 255) (1 byte)
  int   -> entero con un rango de -32,768 a 32,767 (con signo) y 0 a 65,535 (sin signo) (2 bytes)
	   para declarar un entero con signo solo es necesario colocar el int
	   mientras que un entero sin signo debe de ser unsigned int
  long  -> es el tipo entero de formato largo, con un rango de -2147483648 a 2147483648 (4 bytes)
  float -> numeros con punto flotante, de rango 3.4E-38 a 3.4E+38 (4 bytes)
  double-> numeros ocn punto flotante de rango 3.4E-4932 a 1.1E+4932, mucho mas precisos que float (8 bytes)
  Estos son los mas comunes en caso de usar algun otro durante el curso
  se hara mencion de el.
  Los nombres de las variables no deben repetirse y pueden tener una longitud
  de 128 caracteres, pero por simplicidad se recomienda que no sean mayores a 8,
  adem s deben de tener solo caracteres alfanumericos y se puede incluir el _
  Nota C es sensible a las mayusculas por lo que "var" es diferente de "VAR"
*/
int var_glo;

/*
  Funcion principal main, el C es un lenguaje funcional (ademas de que sirve muy bien)
  el cual se organiza mediante funciones, estas son como declaraciones de
  ciertas partes en las que se compone un programa, o como el caso de una
  funcion matem tica la cual recibe algun valor o valores y regresa algun otro
  pero en este caso las funciones de C pueden recibir varios valores y solo
  regresar uno solo, aunque existen algunos "trucos" que permiten regresar
  varios mas.
  Las funciones se declaran como:
  valor_a_regresar nombre_funcion(valores_a_recibir)
  valor_a_regresar -> puede ser de cualquier tipo, pero tambi‚n puede
		      declrarase que no regrese nada mediante la palabra void
		      main siempre debe de ser void
  nombre_funcion   -> aqui va el nombre de la funcion, no se permiten
		      repeticiones (en C++ se permiten pero eso se ver  despues)
*/
void main()
{
 //Variable local esta solo es funcional dentro de esta funcion (main en este caso)
 int var_loc;

 //la funcion que limpia la pantalla de cualquier basura que halla quedado
 clrscr();

 //Asignacion de valores
 var_glo=35;
 var_loc=21;

 /*
    Uso de la funcion printf
    printf se usa para mostrar valores o caracteres en la unidad de salida
    predeterminada (en este caso el monitor), y su sintaxis es:
    printf( "caracteres %id \uso", variable );
    caracteres -> una cadena de caracteres normal
    %id	       -> identificador, este funciona para identificar a la variable
		  dependiendo de su tipo de dato:
		  %d -> para entero
		  %x -> hexadecimal (para minusculas y %X mayusculas)
		  %f -> tipo flotante
		  %e -> forma exponencial o cientifica
		  %c -> caracter
		  %s -> cadena de caracteres
    /uso       -> Este es para realizar alguna accion como:
		  \n -> Nueva linea, cambia de linea
		  \t -> Tabulacion
		  \a -> Pitido
		  \' -> Colocar comilla simple
		  \" -> Colocar comilla doble
		  \\ -> Colocar "la backslash"
		  \b -> Retroceso de espacio
		  \f -> Avance de p gina
		  \r -> Retorno de carro
		  \v Tabulaci¢n vertical
    variable   -> aqui va la variable a mostrar
 */
 printf("\tPrimer programa en C\n");
 printf("\"Variable Global\" %d\n", var_glo);
 printf("\"Variable Local\"  %d\n", var_loc);
 printf("\"Variable Definicion\" %d\a\n", DEFINICION);

 //getch se usa para esperar una pulsacion del teclado
 getch();

 printf("Tambien se puede operar %d + %d = %d",var_glo,var_loc,var_glo+var_loc);
 //... pero las operaciones se ver n en la siguiente leccion
 getch();
}