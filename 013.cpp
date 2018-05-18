/*
 La sobrecarga de funciones consiste en declarar y definir varias funciones distintas que tienen un mismo nombre.
 Dichas funciones se definen en forma diferente. En el momento de la ejecuci�n se llama a una uotra funci�n
 dependiendo del n�mero y/o tipo de los argumentos actuales de la llamada de la funci�n. 
 
 La sobrecarga de funciones no admite funciones que difieran s�lo en el tipo de valor de retorno, pero con el mismo
 n�mero y tipo de argumentos. De hecho, el valor de retorno no influye en la determinaci�n de la funci�n que es llamada;
 s�lo influyen el n�mero y tipo de los argumentos. Tampoco se admite que la diferencia sea el que en una funci�n un
 argumento se pasa por valor y en otra funci�n ese argumento se pasa por referencia.
 
 
 En este programa se muestra la multiplicaci�n de 2 numeros enteros, 2 mumeros flotantes, 3 numeros enteros, 3 numeros 
 flotantes, Utilizando Sobrecarga de Funciones
*/

#include<iostream.h>
#include<conio.h>

//Se definen los prototipos de las funciones  que se van a sobrecargar
//Se observa el mismo nombre "multi", pero las dos funciones reciben datos diferentes:
//flotantes
void multi(float num1, float num2, float num3=1.0);
//enteros
void multi(int num1, int num2, int num3=1);

int main()
{
	int ival1, ival2, ival3;
	float val1, val2, val3;
	
	cout<<"Programa Multiplicador"<<endl;
	cout<<endl;
	cout<<"Introduce dos n�meros enteros: "<<endl;
	cin>>ival1;
	cin>>ival2;
	//Se mandan solo 2 n�meros enteros
	multi(ival1, ival2);
	cout<<"Introduce dos numeros flotantes: "<<endl;
	cin>>val1;
	cin>>val2;
	//Se mandan solo 2 n�meros flotantes
	multi(val1, val2);

	cout<<"Introduce tres n�meros enteros: "<<endl;
	cin>>ival1;
	cin>>ival2;
	cin>>ival3;
	//En esta se mandan los tres n�meros enteros
	multi(ival1, ival2, ival3);
	cout<<"Introduce tres numeros flotantes: "<<endl;
	cin>>val1;
	cin>>val2;
	cin>>val3;
	//En esta se mandan los tres n�meros flotantes
	multi(val1, val2, val3);

	getch();
	return 0;
}

/*Definici�n de las funciones*/
//En esta se define la funci�n para multiplicar los n�meros flotantes
void multi(float num1, float num2, float num3)
{
	float res;
	res=num1 * num2 * num3;
	cout<<"Resultado: "<<res<<endl;
}

//Y en este se define la funci�n para multiplicar los n�meros enteros
void multi(int num1, int num2, int num3)
{
	int res;
	res=num1 * num2 * num3;
	cout<<"Resultado: "<<res<<endl;
}