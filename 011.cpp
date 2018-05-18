/*
* Cambios en el lenguaje C++ con respecto a C
* En principio la estrcutura del lenguaje C++ con respecto a C es muy similar, sin embargo existen
* algunos cambios importantes a señalar que permiten la programación orientada a objetos
*/

void main()
{
	/*
	* 1.- Flexibilidad en la declaración de variables
	* La declaración de variables en C++ es igual que en ANSI C, pero con una diferencia importante,
	* en C las variables debían delcararse al comienzo de un bloque, antes de que se escribiera la
	* primera sentencia del bloque, mientras que en C++ las variables se pueden declarar en cualquier lugar
	* del bloque.
	* Por ejemplo en el caso de la sentencia for, considerando que se sumar los elementos de un arreglo
	*/
	double a[10] = {1,2,3,4,5,6,7,8,9,10};	//Se declara el arreglo y se inicia
	int n=10;
	// Se pueden colocar más sentencias en este punto
	// Después se quiere sumar los valores del arreglo, se observa que se inicia la variable suma
	// donde se vacía el valor de la suma de los números y el entero i como contador 
	for(double suma = 0.0, int i=0; i<n; i++)
		suma += a[i];
	/*
	* 2.-Especificador const para variables
	* En C++ el especificador const se puede utilizar con variables y punteros. si una variable se define como
	* const, se tiene la garantía que su valor no va a cambiar durante toda la ejecución del programa.
	* Si en alguna sentencia del programa se intenta variar el valor de una variable definida como const, el
	* compilador produce un mensaje de error. Esto permite detectar errores durante la compilación del programa.
	* Este tipo de variables es muy similar al #define del preprocesador.
	* Puede utilizarse para definir el tamaño de arreglos, cosa que no estaba permitida en ANSI C
	*/
	const int SIZE = 5;
	char cs[SIZE];
	
	/*
	* En el caso de apuntadores hay dos formas de aplicar el especificador const:
	* 1. Un puntero variable apuntando a una variable constante, en este caso el puntero no permite modificar el valor
	*	de la variable, pero el puntero no tiene por que apuntar siempre a la misma dirección de memoria
	* 2. Un puntero constante apuntando a una variable cualquiera, en este caso el apuntador siempre apunta hacia la
	*	la misma dirección de memoria, pero el valor de la variable puede cambiar sin problemas
	*/
	//Un puntero a la variable const
	const char *nombre1 = "Nombre1";	//No se puede modificar el valor de la variable
	
	//Un puntero const a una variable cualquiera
	char* const nombre2 = "Nombre2";	//No se puede modificar la dirección donde apunta el apuntador, pero sí el valor
	
	
}