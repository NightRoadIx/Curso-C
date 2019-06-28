/*
	Programa ejemplo de árboles
	Los árboles son de las estructuras de datos más utilizadas, sin embargo
	son de las más complejas. Los árboles se caracterizan por estructurar
	los nodos en forma jerárquica y no lineal como las listas, pilas o colas.
	
	Su estrcutura es como la siguiente:
			┌─────┐
			│Raíz │						Solo puede haber una raíz por árbol
			└─────┘
		  ┌────┴────┐
		  │         │
       ┌─────┐   ┌─────┐
       │Rama │   │Rama │				Ramas o nodos, de la que se puede mover hacia otras, en caso de 
	   └─────┘   └─────┘				que provenga de otra se le llama nodo hijo, mientras que la de jerarquía
	 ┌────┴────┐    └────┐				superior es el nodo padre.
					  ┌─────┐
					  │Hoja │			Las hojas son aquellos nodos que son extremos de la estructura
					  └─────┘
					  
	Niveles: Se refiere a cada generación dentro de un árbol. Un árbol vacío tiene 0 niveles, mientras que el nodo
	raíz es nivel 1; la altura es el número máximo de niveles de un árbol.
	
	Peso: Se refiere al número de nodos que tiene un árbol.
	
	Orden: Se refiere a la cantidad de nodos hijos que puede tener cada nodo padre.
	
	
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct nodo {
    int info;
    struct nodo *izq;
    struct nodo *der;
};

struct nodo *raiz=NULL;


int main()
{
    insertar(100);
    insertar(50);
    insertar(25);
    insertar(75);
    insertar(150);
    printf("Impresion preorden: ");
    imprimirPre(raiz);
    printf("\n\n");
    printf("Impresion entreorden: ");
    imprimirEntre(raiz);
    printf("\n\n");
    printf("Impresion postorden: ");
    imprimirPost(raiz);
    borrar(raiz);
    getch();
    return 0;
}


void insertar(int x)
{
    struct nodo *nuevo;
    nuevo = malloc(sizeof(struct nodo));
    nuevo->info = x;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    if (raiz == NULL)
        raiz = nuevo;
    else
    {
        struct nodo *anterior, *reco;
        anterior = NULL;
        reco = raiz;
        while (reco != NULL)
        {
            anterior = reco;
            if (x < reco->info)
                reco = reco->izq;
            else
                reco = reco->der;
        }
        if (x < anterior->info)
            anterior->izq = nuevo;
        else
            anterior->der = nuevo;
    }
}

void imprimirPre(struct nodo *reco)
{
    if (reco != NULL)
    {
        printf("%i-",reco->info);
        imprimirPre(reco->izq);
        imprimirPre(reco->der);
    }
}


void imprimirEntre(struct nodo *reco)
{
    if (reco != NULL)
    {
        imprimirEntre(reco->izq);
        printf("%i-",reco->info);
        imprimirEntre(reco->der);
    }
}

void imprimirPost(struct nodo *reco)
{
    if (reco != NULL)
    {
        imprimirPost(reco->izq);
        imprimirPost(reco->der);
        printf("%i-",reco->info);
    }
}

void borrar(struct nodo *reco)
{
    if (reco != NULL)
    {
        borrar(reco->izq);
        borrar(reco->der);
        free(reco);
    }
}