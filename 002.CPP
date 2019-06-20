/*
  Curso de Programación en C
  Leccion 2
*/

#include <stdio.h>
#include <conio.h>
/*
	putch(char var)
*/
#include <math.h>
/*
	La librería con funciones matemáticas
	double sin(double x)
	double cos(double x)
	double tan(double x)

	double asin(double x)
	double acos(double x)
	double atan(double x)
	
	double exp(double x)
	double log(double x)
	double log10(double x)
	double pow(double x, double y)
	double sqrt(double x)
	
	double ceil(double x)
	double floor(double x)
*/

#define PI 3.1415926539

void main()
{
	 // Función system(), permite ejecutar algunas funciones del sistema (como en el cmd)
	 // en este caso "cls" limpia la consola 
	 system("cls");

	 /*Variables a utilizar*/
	 int a=2, b=1, c=10, d, e, f;
	 /*las variables del mismo tipo pueden separarse con una coma
	   para declarar varias asi también se pueden asignar al declarar*/
	 float x, y=0.0;

	 //Operadores matemáticos
	 //Puede usarse cualquiera de los sigs: +,-,*,/,%
	 d=a+3; //suma
	 e=b-2; //resta
	 x=a*c; //multiplicación
	 y=1/3; //división
	 f=d%a; //residuo o módulo
	 printf("var d = %d\n",d);
	 printf("var e = %d\n",e);
	 printf("var x = %2.2f\n",x); //notar el %2.2f, con esto se puede truncar un número decimal a n dígitos
	 printf("var y = %.3f\n",y);
	 printf("var f = %d\n",f);

	 putch('\n'); 	//coloca un caracter en pantalla, puede colocarse una variable
					//tipo char o int, para este último se usa el codigo ASCII (*)
	 getch();
	 //Operadores Lógicos
	 //Se puede usar &&, ||, !
	 printf("0 && 0 -> %d\n",0&&0);		//AND -> 0 y 0 es 0
	 printf("0 || 1 -> %d\n",0||0);		//OR  -> 0 ó 1 es 1
	 printf("0! -> %d\n",!0);			//NOT -> no 0 es 1

	 putch('\n');
	 //Operadores Relacionales
	 /*
	   <  menor
	   >  mayor
	   <= menor o igual
	   >= mayor o iguak
	   == igual
	   != distinto
	   Regresan 1 si es verdad o 0 si es falso
	 */
	 getch();
	 printf("5 <  6 = %d\n", 5 < 6);
	 printf("5 >  6 = %d\n", 5 > 6);
	 printf("3 <= 1 = %d\n", 3 <= 1);
	 printf("2 <= 2 = %d\n", 2 <= 2);
	 printf("13 == 7 = %d\n", 13 == 7);
	 printf("5 != 6 = %d\n", 5 != 6);

	 /*
	   Operadores de asiganción
	   =,++,--,+=,-=,/=,*=
	   Estos asignan valores automaticamente
	 */
	 putch('\n');
	 getch();

	 //Primera asignación
	 a=1;
	 //suma en uno con ++ (también resta con --)
	 printf("a = %d\n",a);
	 printf("++a = %d\n",++a); //asigna primero
	 printf("a++ = %d\n",a++); //asigna después
	 printf("a = %d\n",a);
	 //Asignaciones
	 b+=3; //a b se le suman 3 (funciona igual con -,*,/
	 printf("b al sumarle 3 = %d\n",b);

	 /*
	   Operador condicional ?
	   op1 ? op2 : op3
	   si el operador op1 es verdadero (TRUE o 1) asigna op2, si no es op3
	 */
	 putch('\n');
	 getch();
	 int mayor = (a > b) ? a:b;
	 printf("%d > %d por tanto mayor es %d\n",a,b,mayor);
	 
	 /*
		Operadores matemáticos "avanzados" (disponibles en math.h)
		Funciones trigonométricas
		Funciones exponenciales
		Funciones de parte entera
	 */
	 printf("Funciones trigonometricas:\n");
	 printf("sen(60) = %.4f\n", sin( 60*PI/180 ));
	 printf("cos(60) = %.4f\n", cos( 60*PI/180 ));
	 printf("tan(60) = %.4f\n", tan( 60*PI/180 ));
	 printf("----------------------------------\n");
	 printf("e^1 = %.4f\n", exp(1));
	 printf("ln(4) = %.4f\n", log(4));
	 printf("log10(100) = %.4f\n", log10(100));
	 printf("raizcuadrada(81) = %.4f\n", sqrt(81));
	 printf("3^4 = %.4f\n", pow(3,4));
	 printf("ln(4) = %.4f\n", log(4));
	 printf("----------------------------------\n");
	 printf("¿Como se calificara? \n");
	 printf("con ceil(5.9) = %.2f \n", ceil(5.9));
	 printf("ó con floor(5.9) = %.2f \n", floor(5.9));
	 
	 /*
		Conversión de tipos de datos
		Para realizar operaciones C convierte datos de acuerdo a las siguientes reglas:
		1.-Cualquier operando del tipo float se convierte a double
		2.-Si un operando es de tipo long double, el otro se convierte a este tipo
		3.-Si uno es double el otro automaticamente se convierte en double
		4.-Cualquier operando char o short se transforma en int
		5.-En caso de que sea unsigned char o short se transforma en unsigned int
		6.-Se pasa un operando a tipo unsigned long si el otro lo es
		7.-Si un operando es de tipo long el otro se transforma a long
		8.-Si uno es unsigned int el otro se transforma a este tipo

		A pesar de esto, es posible realizar algunos cambios por medio de la
		conversion explicita, mediante una construcción conocida como cast, del tipo:
		(nombre_tipo)expresi¢n,
		p.ej.
		int y;
		double x;
		x=(double)y;
	 */
	 putch('\n');
	 getch();
	 long a1=2006;
	 unsigned char b1='a';
	 int c1=5;
	 float d1=3.3;
	 int f1;

	 f1=a1+b1*c1/d1;
	 /*
	   La secuencia que sigue es:
	   1. b se convierte a unsigned int (paso 5)
	   2. c se convierte a unsigned int (paso 8) y se hace la multiplicación y se halla u. int
	   3. d se convierte a double (paso 1)
	   4. b*c se convierte a double (paso 3) se ejecuta la division para obtener double
	   5. a se pasa a double (paso 3) se hace la suma y se obtiene un double
	   6. El resultado final se trunca para pasarlo a int
	 */
	 printf("Valor final de f = %d",f1);

	 getch();
}