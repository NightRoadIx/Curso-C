/*
 La sobrecarga de funciones consiste en declarar y definir varias funciones distintas que tienen un mismo nombre.
 Dichas funciones se definen en forma diferente. En el momento de la ejecución se llama a una uotra función
 dependiendo del número y/o tipo de los argumentos actuales de la llamada de la función. 
 
 La sobrecarga de funciones no admite funciones que difieran sólo en el tipo de valor de retorno, pero con el mismo
 número y tipo de argumentos. De hecho, el valor de retorno no influye en la determinación de la función que es llamada;
 sólo influyen el número y tipo de los argumentos. Tampoco se admite que la diferencia sea el que en una función un
 argumento se pasa por valor y en otra función ese argumento se pasa por referencia.
 
 
 En este programa se muestra la multiplicación de 2 numeros enteros, 2 mumeros flotantes, 3 numeros enteros, 3 numeros 
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
	cout<<"Introduce dos números enteros: "<<endl;
	cin>>ival1;
	cin>>ival2;
	//Se mandan solo 2 números enteros
	multi(ival1, ival2);
	cout<<"Introduce dos numeros flotantes: "<<endl;
	cin>>val1;
	cin>>val2;
	//Se mandan solo 2 números flotantes
	multi(val1, val2);

	cout<<"Introduce tres números enteros: "<<endl;
	cin>>ival1;
	cin>>ival2;
	cin>>ival3;
	//En esta se mandan los tres números enteros
	multi(ival1, ival2, ival3);
	cout<<"Introduce tres numeros flotantes: "<<endl;
	cin>>val1;
	cin>>val2;
	cin>>val3;
	//En esta se mandan los tres números flotantes
	multi(val1, val2, val3);

	getch();
	return 0;
}

/*Definición de las funciones*/
//En esta se define la función para multiplicar los números flotantes
void multi(float num1, float num2, float num3)
{
	float res;
	res=num1 * num2 * num3;
	cout<<"Resultado: "<<res<<endl;
}

//Y en este se define la función para multiplicar los números enteros
void multi(int num1, int num2, int num3)
{
	int res;
	res=num1 * num2 * num3;
	cout<<"Resultado: "<<res<<endl;
}