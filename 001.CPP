/*
  Curso de Programación en C
  Leccion 1
*/

/*
   Sintaxis del lenguaje
   
   Para comenzar las lineas de comentario se colocan como:
   // para comentarios de una sola linea
   o como se encuentra este para varias lineas
   Para cerrar las lineas de código, se usa el ; y gralmente. es para finalizar
   la llamada a una función o asignacion de variables.
   La extensión de los archivos que contienen el código fuente por lo general
   llevan una extensión de .c o .cpp (dependiendo si se trata de ANSI-C o C++), 
   mientras que las librerias llevan extensión .h.
*/

/*
  Sección de librerias, aqui es en donde se colocan las librerias que C cuenta,
  La sintaxis puede ser de 2 formas:
  #include <libreria.h> para librerias que estan en el directorio del compilador (o que "vienen" incluídas con el compilador)
  #include "libreria.h" para aquellas librerias que no estan en el directorio del compilador, pero si en el mismo directorio
  del programa que se está desarrollando
*/
//En los primeros programas se hara un listado de las funciones de las librerias usadas
#include<stdio.h>
/*
   Listado de funciones
   1.-printf();			Enviar datos al dispositivo de salida estándar (stdout), en este caso la pantalla
*/
#include<conio.h>
/*
   1.-getch();			Esperar a recibir información del dispositivo de entrada estándar (stdin), en este caso el teclado
*/

/*
   Sección de Definiciones
   Aqui se pueden hacer definiciones de constantes, ya sea númericas o alfabeticas, la declaración es de la forma:
   #define NOMBRE valor
   Para el nombre de la definición es preferible colocarlo con mayúsculas y de longitud menor a 12.
   Las definiciones son como una especie de constante para los programas, son conocidas también con el nombre
   de MACROS y facilitan el hecho de modificar constantes recurrentes en los programas y que facilitan 
   el actualizar los códigos
*/
#define DEFINICION 50

// PUEDE OBSERVARSE EL USO DE # COMO OPERADOR DE DIRECTIVA, O DEL PRE-PROCESADOR

/*
  Variables Globales.
  Las variables son una especie de nombre que se le asigna a un espacio en memoria
  
  Las variables son nombres de valores que pueden ser utilizados dentro
  del programa, en este caso se creo una variable global que puede ser
  manipulada en todo el programa a diferencia de una variable local, que solo puede
  ser utilizada dentro de segmentos del programa conocidos como funciones.
  Se declaran como:
  tipo_dato nombre_variable;
  El tipo_dato puede ser:
  bool	-> Tipo booleano, solo puede tomar dos valores, 0 o 1, TRUE o FALSE (1 bit)
  char  -> Caracter, este es un solo caracter ASCII (de 0 a 255) (1 byte)
  int   -> entero con un rango de -32,768 a 32,767 (con signo) y 0 a 65,535 (sin signo) (2 bytes)
	   para declarar un entero con signo solo es necesario colocar el int
	   mientras que un entero sin signo debe de ser unsigned int
  long  -> es el tipo entero de formato largo, con un rango de -2147483648 a 2147483648 (4 bytes)
  float -> numeros con punto flotante, de rango 3.4E-38 a 3.4E+38 (4 bytes)
  double-> numeros con punto flotante de rango 3.4E-4932 a 1.1E+4932, mucho mas precisos que float (8 bytes)
  
  Estos son los mas comunes en caso de usar algun otro durante el curso
  se hara mencion de el.
  
  Los nombres de las variables no deben repetirse y pueden tener una longitud
  de 128 caracteres, pero por simplicidad se recomienda que no sean mayores a 8,
  además deben de tener solo caracteres alfanumericos y se puede incluir el símbolo _
  
  Nota C es sensible a las mayusculas por lo que "var" es diferente de "VAR"
  
*/
int var_glo;

// EXISTE UNA NOTACIÓN DE VARIABLES CONOCIDA COMO NOTACIÓN CAMELLO, PUES SE UTILIZA ALGO DE LA SIGUIENTE FORMA:
// miVariableNueva
// QUE COMO SE OBSERVA UNE PALABRAS Y SE COLOCA LA PRIMERA LETRA DE CADA NUEVA PALABRA CON MAYÚSCULA
// COMENZÓ A USARSE EN EL LENGUAJE DE PROGRAMACIÓN JAVA, PERO SE HA EXTENDIDO SU USO A OTROS LENGUAJES

/*
  Funcion principal main, el C es un lenguaje multiparadigma, mayormente estructurado, pero también
  puede trabajr algunos conceptos de la programación funcional, 
  esto es que se organiza mediante entidades llamadas funciones, estas son como declaraciones de
  ciertas partes en las que se compone un programa, segmentos de código, puede verse como una
  funcion matemática la cual recibe algun valor o valores, opera sobre esos valores y regresa uno y solo un resultado
  (aunque, a diferencia de las funciones matemáticas, existen algunos "trucos" que permiten regresar
  varios mas en lenguaje C).
  Las funciones se declaran como:
  valor_a_regresar nombre_función(valores_a_recibir)
  valor_a_regresar -> puede ser de cualquier tipo, pero también puede
		      declararse que no regrese nada mediante la palabra void
  nombre_funcion   -> aqui va el nombre de la función, siguiendo las reglas de las nomenclatura de variables, no se permiten
		      repeticiones de nombres (en C++ ya se permite, pero eso es parte de la Programación Orientada a Objetos)
*/
void main()
{
	// Las llaves { }, se utilizan para "encerrar" las instrucciones que corresponden con una función
	// ES UNA BUENA PRÁCTICA EL COLOCAR UN ESPACIO O TABULADOR (PREFERENTE) AL ABRIR UNA LLAVE 
	// (EL CASO DE LAS FUNCIONES O DE LAS SENTENCIAS DE CONTROL QUE SE VERÁN MÁS ADELANTE)
	// PARA HACER MÁS LEGIBLE EL PROGRAMA
	// (ADEMÁS DE ADQUIRIR LA COSTUMBRE QUE FACILITARÁ EL PROGRAMAR EN OTROS LENGUAJES)
	
	//Variable local esta solo es funcional dentro de esta sección del programa (main en este caso)
	int var_loc;

	//Asignacion de valores
	var_glo = 35;
	var_loc = 21;

	/*
		Uso de la función printf
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
		\uso       -> Este es para realizar alguna accion como:
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
	//... pero las operaciones se verán en la siguiente leccion
 getch();
}