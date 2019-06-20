/*
  Curso de Programaci¢n en C
  Leccion 6
*/
#include <stdio.h>
#include <conio.h>
#define L 100

/*
  Los arreglos cuando son parámetros de funciones pueden cambiar su valor
  si se modifican dentro de la misma como en el ejemplo, debido a que
  lo que se env¡a es la direcci¢n del arreglo, esto es que se manda:
  &arreglo, y entonces es posible cambiar el valor dentro de la direcci¢n
*/
void LeerArray(double a[], int *);
//Puede no declararse el nombre de la varible en la función
void imprimir(const double [], int);

void main()
{
	 double a[L];
	 int n;

	 clrscr();
	 LeerArray(a,&n); //Se manda el arreglo y el valor de la direcci¢n de n
	 printf("El arreglo tiene %d elementos, estos son: \n",n);
	 imprimir(a,n);
	 getch();
}

/*
  En la declaraci¢n de la funci¢n debe de ponerse el nombre de cada variable
  Adem s cuando se pasa un arreglo a una funci¢n, esta no conoce cuantos
  elementos tiene este y por lo tanto debe de mandarse a la funci¢n
  el numero de estos elementos o poner un "identificador" o valor dentro
  del arreglo que sea el que determine donde termina el arreglo
*/
void LeerArray(double a[], int *num)
{
	 int n=0;
	 puts("Introduzca sus datos. Para terminar presione 0.\n");
	 //Observar que si se inicializa antes la variable contador, puede omitirse en el for
	 for(; n < L; n++)
	 {
		printf("%d: ",n);
		//Se modifica el valor del arreglo
		scanf("%lf",&a[n]);
		if(a[n] == 0) break;
	 }
	 //Asigna n al valor de num
	 *num=n;
}

//Si se desea que una varible no cambie en una funci¢n, se le coloca
//identificador const
void imprimir(const double a[], int n)
{
	 //Inicializar variables dentro del for
	 for(int i=0; i < n; i++)
		printf("\t%d: %lf\n",i,a[i]);
}