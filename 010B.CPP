/*
  Programa ejemplo de pilas
  
  Una pila es una lista lineal en la que todos los datos que se insertan o se eliminan
  se hacen en un extremo de la lista, esto es, como una pila de objetos en que el añadir
  o quitar objetos se hace siempre por la parte superior de la pila. A esto se le conoce
  como listas LIFO (Last In - First Out)
  
  Lo que se hace es:
  
  *p->Datos03*---+
  +--------------|
  |            
  +->Datos02*---+
			    |
     Datos01<---+
  
  Y cada nuevo elemento se va añadiendo por encima de los anteriores
  El algoritmo es:
  
  1.-Un apuntador general *p fue asignado al último elemento añadido
  2.-Se asigan un apuntador temporal *tmp al último elemento añadido
  3.-El apuntador siguiente del elemento nuevo se asigna al elemento al que apunta el apuntador *tmp
  4.-Se reasigna el apuntador *tmp al nuevo elemento añadido
  5.-Se reasigna el apuntador *p al apuntador *tmp
  
  En el programa se implemeta la estructura de pila
  Recibe un número y una cadena y las ordena en forma de
  pila (LIFO).
  */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
/*Estructura de los datos a utilizar*/
typedef struct dat{
	       int num;		//Un número entero
	       char cad[20];	//Un arreglo de caracteres
	       struct dat *sig;	//El apuntador al dato siguiente
}nodo;	//Nombre de la estrcutura

nodo *p=NULL;	//Un apuntador a la estrcutura nodo

/*Función principal*/
void main()
{
	char opc;
	int num_aux;
	nodo *q=NULL,*r=NULL;
	
	/*Ciclo principal*/
	do
	{
		//Limpiar la pantalla
		clrscr();
		printf("Menu\n");
		printf("1.Agregar\n");
		printf("2.Mostrar\n");
		printf("3.Borrar elemento\n");
		printf("4.Salir\n");
		opc=getche();	//Obtener la opción
		/*Opción de Agregar elemento*/
		if(opc=='1')
		{
			//Limpiar la pantalla
			clrscr();
			//Pedir un número para ingresar
			printf("\nTeclea un Numero:  -->");
			scanf("%d",&num_aux);
			//De la misma forma que en las listas, evitar que se agreguen elementos nulos
			if(num_aux==NULL) break;
			//En caso de que exista un dato a agregar, asignar espacio en memoria para la estrucutra
			q=(nodo*)malloc(sizeof(nodo));
			//En caso de que no se pueda asignar memoria, mostrar mensaje de error y salir del ingreso de datos
			if(q==NULL)
			{
				printf("Error al Aasigner Memoria\n"); break;
			}
			q->num=num_aux;	//Asignar valor al valor de la estructura
			//Ingresar ahora una cadena
			fflush(stdin);
			printf("\nTeclea una Cadena: -->");
			gets(q->cad);
			//Se realizan las asignaciones(esto es que se va a comenzar a apilar los datos)
			r=p;		//Se igualan los punteros r & p
			q->sig=r;	//El valor del apuntador sig en q va a apuntar a r
			r=q;		//Ahora el apuntador r es igual al apuntador q
			p=r;		//Y el apuntador p toma el valor de r
		}
		/*Opción para mostrar los elementos*/
		else if(opc=='2')
		{
			clrscr();
			nodo *s=NULL;	//Apuntador auxiliar que se inicia a NULL
			s=p;			//Se asigna el apuntador *p al apuntador temporal *s
			//En caso de que no haya elementos
			if(s==NULL)
			{
				printf("No existe elemento\n"); getche(); clrscr(); break;
			}
			
			//Ahora en caso de que existan elementos, mostrar los datos
			//Hay que observar que los elementos se muestran del último añadido al primero que se añadió
			while(s != NULL)
			{
				clrscr();
				printf("Numero %d \n",s->num);
				printf("cadena %s \n",s->cad);
				printf("----------------------------\n");
				getch();
				s=s->sig;
			}
		}
		/*Opción para eleminar los elementos*/
		else if(opc == '3')
		{
			nodo *fx; char borrar;
			clrscr();
			//Mientras el apuntador *p sea diferente a NULL
			if(p != NULL)
			{
				do
				{
					//Mostrar que elemento es
					printf("Elemento -->%d", p->num);
					//Preguntar si se desea eliminar
					printf("\n\nDeseas eliminarlo [s/n] -->");
					borrar=getche();
					//En caso de que así sea
					if(borrar == 's')
					{
						fx=p;	//El apuntador *p se asigna al apuntador temporal *fx
						p=p->sig;	//Se reasigna el apuntador p al dato que apunta, esto es el que está "debajo"" en la pila
						free(fx);	//Se libera la memoria
						printf("\nDatos eliminados\n");
						getch();
					}
					else if(borrar == 'n')
					{ printf("\nNo lo borre"); getch(); }
					else
					{ printf("Esa tecla no es v lida");  getch(); }
				}
				while(borrar != 'n');	//Mientras la opción de borrar no sea 'n'
			}
		}
		else if(opc=='4')
		{
			printf("Programa Finalizado\n");   getch();
			break;
		}
		else
			printf("Tecla Erronea");
	}
	while(opc!='4');
	nodo *l=NULL,*l2=NULL;
	l=p;
	//Importante liberar la memoria que se utilizó
	while(l!=NULL)
	{
		l2=l;
		l=l->sig;
		free(l2);
	}
	printf("Memoria Liberada");
	getch();
}