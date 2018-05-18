/*
  Programa ejemplo de listas
  
  La forma mas simple de relacionar o enalzar  un conjunto de elementos es alinearlos
  formando una unica lista, ya que en este caso solo se requerira de apuntador por 
  elemento, para poder hacer referencia a su sucesor.
  
  Esto puede verse de la forma:
  
  p--> ┌──────┐ ┌-> ┌──────┐ ┌-> ┌──────┐
       ├──────┤ │   ├──────┤ │   ├──────┤
	   ├──────┤ │   ├──────┤ │   ├──────┤
	   └─────*┘-┘   └─────*┘-┘   └──NULL┘
	   
  Esto es que el apuntador del elemento "apunta" hacia el inicio del siguiente elemento.
  
  Las operaciones básicas que se realizan en una lista son:
  Iniciando el puntero p a NULL
  1.- Insertar un elemento, donde al crearse el elemento se reasignan los punteros, esto es
   q = nuevo_elemento();
   Se asignan los valores de los elementos de q
   Se reasignan los punteros en q: q-> siguiente = p;
   p = q;
   
  >>Ahora en el caso de insertar un elemento en general lo que se requiere es reasignar los punteros
    en el elemento insertado de la forma:
   q->siguiente = p->siguiente,
   p->siguiente = q;
   
   Lo que inserta el elemento nuevo 
  
  2.-Borrar un elemento de la lista, para borrar el sucesor de un elemento apuntado por p, las
  operaciones a realizar son:
   q = p->siguiente;
   p->siguiente = q->siguiente;
   liberar q
   
  En caso de borrar un elemento apuntado por p, las operaciones a realizar son las siguientes:
   q = p->siguiente;
   *p = *q;
   liberar q
   
  
  El programa es una implementaci¢n de la estructura de listas
  Se aceptan un numero de control y una cadena
  A partir de esos campos es posible buscar y borrar elementos
  
  */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
#include <string.h>
#include <ctype.h>

/*Estructura principal*/
typedef struct dat{
 char cad[9];		//Cadena de datos
 int num;			//Numero entero de control
 //Importante, se requiere un puntero del tipo struct dentro
 //de la misma estructura para el recorrido de datos
 struct dat *sig;	
}nodo;	//Nombre del tipo de datos "struct dat"

//Se inicia el primer elemento del tipo nodo como NULL
nodo *primero=NULL;

/* Prototipos de Funciones */
nodo *aceptar();	//Función para aceptar datos
agregar(nodo *item);	//Función para agregar un elemento
insertar(nodo *item);	//Función para insertar un elemento
void buscar(char x);	//Función para buscar un elemento
void recorrer();	//Función para recorrer entre elementos
void mostrar(nodo *tmp);	//Función para mostrar elementos
void borrar();	//Función para borrar elementos
void liberar();	//Función para liberar espacio en memoria

/* Funcion principal */
void main()
{
 /* Variables locales */
 // Se coloca una variable del tipo nodo para su manejo y se inicia a NULL, esto es muy 
 // importante pues es posible que sino se inicia a un valor NULL el apuntador inicie "apuntando"
 // a algún dato "basura"
 nodo *tmp=NULL;
 char opc, opc1, opc2, opc3;
 clrscr();
 
 // Ciclo principal
 while(1)
 {
	//Se inicia limpiando la pantalla
	clrscr();
	// Se mostrará un menú para ver las posibles opciones a realizar con las listas
	printf("*****Menu de Listas*****\n");
	printf("1.-Agregar elemento\n");
	printf("2.-Buscar\n");
	printf("3.-Recorrer\n");
	printf("4.-Borrar\n");
	printf("5.-Salir\n");
	printf("-> ");
	//En caso de encontrar la opción '5' salir del ciclo
	if((opc=getch()) == '5')
		break;
	//Revisar cada una de las opciones
	switch(opc)
	{
		case '1':	//Agregar elemento
		{
			//Limpiar la pantalla
			clrscr();
			printf(" < Como se realizara la inserción > \n");
			printf("1.-Agregando al final\n");
			printf("2.-Insertando un elemento\n");
			printf("--> ");
			//Aceptar la opción y mostrar el eco en pantalla
			opc1=getche();
			if(opc1 == '1')	//Opción de agregar al final
			{
				clrscr();
				tmp=aceptar();	//Aceptar los valores
				agregar(tmp);	//Agregar los nuevos datos
				break;
			}
			else if(opc1 == '2')	//Opción de insertar un elemento
			{
				//Limpiar la pantalla
				clrscr();
				//Asignar el valor del apuntador primero a un apuntador temporal tmp
				tmp=primero;
				if(tmp == NULL)	//Si el apuntador tmp es NULL
				{
					//Esto quiere decir que no hay ningún elemento en la lista
					printf("\nNo hay elementos en la lista");
					getche();
					break;
				}
				//En caso de que exista al menos un elemento en la lista se ingresan los valores
				tmp=aceptar();
				// Se manda a llamar a la función de insertar un dato
				insertar(tmp);
				break;
			}
			else //En caso de ingresar una opción no válida
			{
				printf("Opción incorrecta -->");
				getch();
				break;
			}
		}
		case '2':	//Buscar elemento
		{
			clrscr();
			printf("<Como deseas buscar el elemento>\n");
			printf("1.-Por la clave\n");
			printf("2.-Por la cadena\n");
			printf("--> ");
			opc2=getche();
			if(opc2 == '1' || opc2 == '2')
			{
				clrscr();
				// Evitar problemas y verificar si el apuntador primero "apunta" a un valor
				if(primero == NULL)
				{
					printf("No hay elementos en la lista\n");
					getch();
					break;
				}
				buscar(opc2);	//Buscar los valores, enviando el tipo de busqueda
				break;
			}
			else
			{
				printf("Opción incorrecta -->");
				getch();
				break;
			}
		}
		case '3':	//Recorrer los elementos
		{
			clrscr();
			if(primero == NULL)	//Volver a verificar si hay elementos
			{
				printf("\n <<<No existen aun elementos>>> ");
				getch();
				break;
			}
			printf("<Elemento Desplegado>");
			recorrer();
			break;
		}
		case '4':	//Borrar elementos
		{
			clrscr();
			printf("\n<Como deseas borrar>\n");
			printf("1.-Un elemento\n");
			printf("2.-Formatear todo\n");
			printf("--> ");
			opc3=getche();
			if(opc3 == '1')
			{
				clrscr();
				tmp=primero;
				if(tmp == NULL)
				{
					printf("\nLa lista no tiene elementos");
					getch();
					break;
				}
				borrar();
				break;
			}
			else if(opc3 == '2')
			{
				tmp=primero;
				if(tmp == NULL)
				{
					printf("\nAun no hay elementos que eliminar");
					getch();
					break;
				}
				liberar();	// Liberar la memoria, esto es quitar todos los elementos
				printf("\n\nSe elimino todo...");
				getche();
				break;
			}
			else
			{
				printf("Opción incorrecta -->");
				getch();
				break;
			}
		}
		default:
		{
			printf("Opción incorrecta -->");
			getch();
			break;
		}
	}
 }
 printf("Programa terminado");
 liberar();		//IMPORTANTE, HAY QUE LIBERAR LA MEMORIA
 printf("Memoria Liberada");
 getch();
}

/* Función Aceptar */
// Regresa un apuntador al elemento del tipo nodo
nodo *aceptar()
{
	//Variables locales
	char numaux[10];
	char cadaux[10];
	nodo *tmp=NULL;
	
	// Pedir un número a agregar
	printf("\n Inserta el numero -->");
	// Obtener la cadena
	gets(numaux);
	// Las siguientes instrucciones son muy importantes pues con estas se evitan
	// problemas en la asiganción de memoria
	// Si lo ingresado es igual a NULL, esto es que no se agrego ningún dato o 
	// existió algún error en la asiganción de los datos, se regresa un valor NULL
	// para evitar agregar datos nulos
	if(*numaux == NULL) return(NULL);
	// En caso de tener un dato a agregar, se realiza la asiganción de la memoria:
	// en un apuntador temporal del tipo "nodo" se realiza la asignación de memoria mediante la
	// función malloc(size_t size), esta función permite asignar un espacio en memoria del tamaño size en bytes
	// en este caso el tamaño es el del tipo "nodo" que se obtiene con la función sizeof() y además se hace un
	// cast para asegurar el tipo "nodo" mediante (nodo *)
	tmp=(nodo *)malloc(sizeof(nodo));
	// En caso de que falle la asignación de memoria, malloc() regresa un valor NULL, y en este caso se muestra un
	// mensaje de error y se sale de la función regresando un valor NULL
	if(tmp == NULL)
	{
		cprintf("ERROR MORTAL");
		cprintf("Error al asignar memoria");
		return(NULL);
	}
	// En el caso de que se haya asignado el espacio en memoria se continua
	// Se inician los valores a los que apunta el nodo tmp
	tmp->num=0;
	tmp->cad[0]=0;
	// Asigna el valor numérico tecleado, convirtiendo a entero la cadena
	tmp->num=atoi(numaux);
	// Limpiar el buffer de entrada
	fflush(stdin);
	// Se ingresa el valor de la cadena de la estructura nodo
	cprintf("Teclea la cadena  -->");
	gets(cadaux);
	fflush(stdin);
	strcpy(tmp->cad, cadaux);	//Copiar la cadena ingresada
	return(tmp);	//Regresar el nodo temporal para asignar
}

/*Función de agregar datos, se recibe un apuntador del tipo nodo*/
agregar(nodo *item)
{
	// Estos son los pasos a seguir para ingresar un elemento en la lista
	// Se crea un apuntador del tipo nodo, iniciado a NULL
	nodo *ptr=NULL;
	// Posteriormente se revisa si el apuntador tipo nodo primero es o no igual a NULL
	// Esto indica que no hay elementos aún almacenados
	if(primero == NULL)
	{
		// El apuntador tipo nodo que se recibe como argumento se asigna al apuntador primero
		primero=item;
		// Posteriormente el apuntador sig dentro de la estructura se asigana NULL indicando que no hay elementos
		// después de este
		item->sig=NULL;
		// Se termina la función con un return(0)
		return(0);
	}
	// En caso de la existencia de otros datos en memoria
	// Se asigna el apuntador primero al temporal ptr
	ptr=primero;
	// Realizar lo siguiente mientras el apuntador sig sea diferente a NULL
	// Con esto se recorre desde el primer elemento hasta el último
	while(ptr->sig != NULL)
		ptr=ptr->sig;
	// Finalmente el apuntador del último elemento (que esta apuntando a NULL) se asigna a los
	// nuevos datos
	ptr->sig=item;
	// Y el apuntador de los nuevos datos se asigna a un valor NULL, convirtiendo a estos datos como los últimos
	item->sig=NULL;
	return(0);
}

/*Función de insertar entre elementos*/
insertar(nodo *item)
{
	nodo *aux=NULL;
	int num;
	aux=primero;	//Asignar el apuntador primero a un valor temporal
	// En caso de que este apunte a un alor NULL, indica que no hay elementos en la lista
	if(aux == NULL)
	{
		printf("\nLa lista no contiene elementos");
		getch();
		return(NULL); ///Regresa un valor NULL
	}
	//Preguntar en donde se va a insertar el elemento
	printf("Despu‚s de que tarea deseas insertar el elemento -->");
	scanf("%d", &num);
	// Buscar el elemento de la siguiente manera, se reasigan el apuntador primero a aux
	// & realizar mientras este no sea NULL o en caso de que el valor numérico sea igual al que se
	// está buscando e ir recorriendo entre los datos mediante aux->sig
	for(aux=primero; (aux != NULL)&&(aux->num != num); aux=aux->sig)
	// Si aux llegó a NULL, enbtonces se recorrieron todos los datos y no se halló el elemento
	if(aux == NULL)
	{
		printf("\nEl elemento no ha sido encontrado");
		printf("\nNo se pudo realizar la inserción");
		getch();
		return(NULL);
	}
	else //En caso de que si se encuentre el elemento
	{
		// Se realiza la inserción de la siguiente forma:
		// El apuntador sig del elemento nuevo (item) se le asignará el elemento al que apunta el nodo aux que fue localizado
		// De esta forma se "sustituye" temporalmente a  los datos contenidos en aux
		item->sig=aux->sig;
		// Y finalmente se reasigna el valor de aux->sig como item, esto es que el apuntador siguiente de aux ve al nuevo elemento
		aux->sig=item;
		cprintf("\nElemento insertado");
		getch();
	}
	return(0);
}

/*Función de buscar(llevandose como buscar)*/
void buscar(char x)
{
	nodo *ps=NULL; int sea=0;
	char busq[10];
	/*Buscar por numero*/
	if(x == '1')
	{
		//Asignar al apuntador primero a ps
		ps=primero;
		// En caso de que no exista ningun elemento, esto se realiza de forma repetitiva para evitar
		// algún problema de desbordamiento de memoria o ingresar a valores de memoria no permitidos
		if(ps == NULL)
		{
			printf("\nNo existe ningun campo-->");
			getch();
		}
		else
		{
			printf("\nTeclea la tarea a buscar : >");
			scanf("%d", &sea);
			while(ps != NULL) //Mientras ps sea diferente de NULL
			{
				if(ps->num == sea)	//En el momento en que se encuentre la coincidencia, mostrar los valores
				{ mostrar(ps); getch(); break; }
				else	//En otro caso seguir avanzando entre los elementos guardados
					ps=ps->sig;
			}
		}
		if(ps == NULL)
		{
			printf("\nTarea no encontrada");
			getch();
		}
		else
		{
			printf("\n\nRegresar al menu -->");
			getch();
		}
	}
	/*Buscar por cadena*/
	else if(x == '2')
	{
		ps=primero;
		if(ps == NULL)
		{
			printf("\nNo existe ningun campo");
			getch();
		}
		else
		{
			printf("\nTeclea la cadena de la tarea a buscar : >");
			gets(busq);
			while(ps != NULL)
			{
				// Se realiza lo mismo que en el caso de busqueda por numero, solo que en este caso
				// se realiza la comparación de cadenas mediante stricmp(string cad1, string cad2)
				if((stricmp(ps->cad, busq)) == 0)
				{ mostrar(ps); getch(); break; }
				else
					ps=ps->sig;
			}
		}
		if(ps == NULL)
		{
			printf("\nTarea no encontrada");
			getch();
		}
		else
		{
			printf("\nRegresar al menu -->");
			getch();
		}
	}
}

/*Función recorrer los elementos*/
void recorrer()
{
	char cqw;
	nodo *ptrr=NULL;
	ptrr=primero;
	if(ptrr == NULL)
	{
		clrscr();
		printf("\nNo existe ningun elemento");
		getch();
	}
	else
	{
		while(ptrr != NULL) //Realizar mientras el apuntador sea diferente a NULL
		{
			mostrar(ptrr);
			printf("\n\nDeseas ver los siguientes registros...[s/n]");
			cqw=getche();
			if(cqw == 's')
				ptrr=ptrr->sig;	//Recorrer entre los datos almacenados en memoria
			else
				break;
		}
	}
	printf("\n*****Datos Finalizados*****");
	getch();
}

/*Función de mostrar*/
void mostrar(nodo *tmp)
{
	char conty;
	fflush(stdin);	//Limpiar valores que esten el buffer
	//clrscr();
	printf("\nClave  --> %d", tmp->num);
	printf("\nCadena --> %s", tmp->cad);
}

/*Función de borrar*/
void borrar()
{
	nodo *aux=NULL, *p=NULL;
	int k=0;
	
	printf("Teclea la tarea que vas a eliminar -> ");
	scanf("%d", &k);
	// Buscar entre los datos 
	for(aux=primero; aux != NULL && aux->num != k; aux=aux->sig);
	if(aux == NULL)
	{
		cprintf("Elemento no encontrado");
		getch();
	}
	else
	{
		// Cuando se va a eliminar un elemento almacenado en la lista, lo que se requiere revisar es
		// si este elemento es el primero o no
		if(aux == primero)
		{
			// En caso de que sea el primero se debe de reasignar unicamente el valor del apuntador sig
			// al elemento siguiente, convirtiendo al segundo elemento en el primero
			p=primero->sig;
			// La función free(void *ptr) libera bloques de memoria a los que apunte *ptr
			// asignados por la función malloc()			
			free(primero);
			primero=p;
			cprintf("\nElemento eliminado");
			getch();
		}
		//En caso de que no sea el primero
		else
		{
			// Se encuentra el valor anterior al que se pretende borrar
			for(p=primero; p->sig!=aux; p=p->sig);
			// Para reasignar el apuntador sig al elemento que continua del que se va a eliminar
			p->sig=aux->sig;
			free(aux);
			printf("\nElemento eliminado");
			getch();
		}
	}
}

/*Función liberar memoria*/
void liberar()
{
	nodo *ptr=NULL, *tmp=NULL;
	ptr=primero;
	// Recorrer todos los datos guardados
	while(ptr != NULL)
	{
		tmp=ptr;
		ptr=ptr->sig;
		// La función free(void *ptr) libera bloques de memoria a los que apunte *ptr
		// asignados por la función malloc()
		free(tmp); fflush(stdin);
	}
	printf("\nLa memoria se libero completamente");
}