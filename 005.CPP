/*
   Curso de programaci¢n en C
   Leccion 5
*/

#include <stdio.h>
#include <conio.h>
#include <stdarg.h>
/*
  va_list puntero
  void va_start(puntero,ultimofijo);
  tipo va_arg(va_list puntero,tipo);
  void va_end(va_list puntero);
*/

/*
  Funciones en linea
  Cuando una función es llamada varias veces y su código es pequeño
  es posible colocarla como una definicion en la cabecera del código
  con la ventaja de que su ejecución será mas rápida que una función "normal"
*/
#define fesp(x) (x*x + 2*x - 1)

/*
   Declaracion de prototipo de funciones
   En programacion estructurada, se colocan antes de la función
   principal, el prototipo de las funciones que se piensa utilizar
   a lo largo de un prgrama, la forma de declarar esto es:

   tipo_valor_a_retornar nombre_funcion(variables_a_aceptar);
*/
void desplegar(int t);
void pasar();
int suma(int x, int y); //O puede ser suma(int x, int y);
void divide(int y);
void maximo(int n, ...); //Funcion sin numero de parametros definido
double factorial(int num); //Funcion recursiva

/*
  Declaracion de variables globales
*/
int xd;

void main()
{
	 //Variables locales
	 int a,b,c;
	 clrscr();

	 //Se manda a llamar la funcion para desplegar, con el valor
	 desplegar(1);
	 scanf("%d %d",&a,&b);
	 //Se llama a la funci¢n suma con sus par metros
	 //Ojo con los valores que se pasan a la funcion
	 printf("%d + %d = %d",a,b,suma(a,b));

	 //Ahora la division
	 desplegar(2);
	 scanf("%d",&c);
	 //Se manda a dividir
	 divide(c);

	 /*
	   Funciones sin un numero determinado de argumentos
	 */
	 pasar();
	 printf("Uso de funciones sin parametros definidos \n\n");
	 printf("\nN£meros: 4.0,6.0,1.2,10.0,45.9,102.5,98.5");
	 //Se manda primero el n£mero de datos que se va a mandar
	 maximo(7,4.0,6.0,1.2,10.0,45.9,102.5,98.5);
	 printf("\nN£meros: 7.0,0.01,666.0,23.0,12.0,3.141592,7.0,21.0,4.0,0.001");
	 maximo(10,7.0,0.01,666.0,23.0,12.0,3.141592,7.0,21.0,4.0,0.001);

	 /*
	   Funciones en linea o macros con argumentos
	 */
	 pasar();
	 float x1;
	 for(x1=0.0; x1 <= 6.5; x1+=0.3)
		printf("\n f(%.1f) = %6.2f",x1,fesp(x1));

	 /*
	   Un caso especial en las funciones: La Recursi¢n
	   La recursi¢n se trata de un caso en las funciones en donde una
	   funci¢n en lugar de llamar a otras se llama a si misma, como lo
	   muestra el ejemplo
	 */
	 //Se manda una nueva pantalla
	 pasar();
	 /*
	   El factorial se calcula n!= n * (n-1) * (n-2) * ... * 3 * 2 * 1
	   Esto es ideal para recursividad, pues se va haciendo decrementar el numero
	   y multiplicando, almacenando el resultado en memoria
	   Por ejemplo 5! = 120
	   5!= 5 * (5-1=4) * (5-2=3) * 2 * 1
	   o visto de otra forma
	   5! = 5 * 4!
	   4! = 4 * 3!
	   3! = 3 * 2!
	   2! = 2 * 1!
	   1! = 1
	   Que es nada mas y nada menos que la recursividad de esta funci¢n
	 */
	 int nf;
	 printf("Factorial de: "); scanf("%d", &nf);
	 printf("%d! = %.2lf",nf,factorial(nf));

	 getch();
}

/*
  Declaracion de las funciones.
  Despu‚s de la funcion principal, se colocan las funciones a utilizar
  aqui es donde se pone todo lo que van a hacer estas funciones al ser
  llamadas.
  Cuando se programa sin hacer uso de las funciones prototipo, se deben
  de colocar las declaraciones de funciones antes del main, pues el
  compilador de C puede no entender el nombre de la funcion y marcar error
*/

//No recibe nada, no regresa nada
void pasar()
{
	printf("\n\nPresiona una tecla-->"); getch(); clrscr();
}

//Recibe un argumento, no regresa nada
void desplegar(int t)
{
	 switch(t)
	 {
		  case 1:
			printf("Teclea dos numeros para sumar: ");
			break;
		  case 2:
			//Observar el trato que se le da a las variables globales
			printf("\nAhora dividamos\n");
			printf("Teclea el dividendo: "); scanf("%d",&xd);
			printf("Teclea el divisor  : ");
			break;
		  default:
			printf("Opci¢n Err¢nea");
			break;
	 }
}

//Recibe dos argumentos, regresa un entero
int suma(int x, int y)
{
	 int res=x+y;
	 return(res); //O colocar return res;
}

void divide(int y)
{
	 float resd;
	 resd=float(xd)/y;
	 printf("%d / %d = %.4f",xd,y,resd);
	 //No es necesario regresar nada
}

//Recibe numero indeterminado de parametros, no regresa nada
void maximo(int n,...)
{
	 double mx,actual;
	 //Declara un tipo va_list para manejar listas de datos pasadas a la funcion
	 va_list puntero;
	 int i;
	 //Inicia la va_list de tal forma que referencia a el primer par metro variable
	 va_start(puntero,n);
	 //Asignar al actual (como es el 1ero. tambi‚n el mayor) el argumento
	 mx=actual=va_arg(puntero,double);
	 printf("\nArgumento actual: %.2lf\n",actual); //Mostramos
	 for(i=2; i <= n; i++)  //Se hace hasta el n£mero de variables a partir de la 2da.
	 {
	  //Aqui se obtienen, consecutivamente, los sucesivos argumentos de la lista
	  actual=va_arg(puntero,double); //Se carga cada vez avance el for
	  printf("Argumento actual: %.2lf\n",actual);
	  //Se obitene el mayor
	  if(actual > mx)
	   mx=actual;
	 }
	 printf("Valor M ximo de la lista de %d n£meros es: %.2lf",n,mx);
	 //Finaliza con va_list y la prepara para las siguientes llamadas
	 va_end(puntero);
}

//Recibe un entero y regresa un doble
double factorial(int num)
{
	 //Mientras el numero sea mayor a 1 se llamara una y otra vez a si misma
	 if(num > 1)
	  return num * factorial(num - 1);
	 //En caso contrario regresa un uno
	 return 1;
}