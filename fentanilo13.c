// STanDard Input Output
#include <stdio.h>
// STanDard LIBrary
#include <stdlib.h>
// Manejo de cadenas de caracteres+
#include <string.h>
// STandard BOOLean
#include <stdbool.h>
// Esta librería ayuda a la configuración del entorno local
#include <locale.h>

/*
  Punteros a punteros
  Los punteros no solo pueden ser asignados a variables "estaticas", sino
  que tambi‚n es posible hacer punteros a punteros (y si fuera necesario
  es posible hacer punteros a punteros a punteros, a punteros ...)
  Este tipo de variables se usa en programas mas complejos en donde sea necesario
  mover direcciones de memoria de varias variables
*/

// Función principal
int main()
{
    //La declaración se realiza como tipo_variable **variable;
    char c='z';         //Un caracter
    char *pc=&c;		//Se asigna la dirección de c a pc
    char **ppc=&pc;     //Se asigna la dirección de pc a ppc
    char ***pppc=&ppc;	//Se asigna la dirección de ppc a pppc
    /*
    Esto implica que pppc tiene la dirección de ppc que tiene la dirección
    de pc que tiene la dirección de c, por lo tanto por medio de pppc puede
    accesarse a c
    */
    printf("c = %c en 0X%X\n",c,&c);
    printf("pc apunta a 0X%X que contiene %c, y pc tiene dirección 0X%X\n",pc,*pc,&pc);
    printf("ppc apunta a 0X%X que contiene 0X%X que contiene %c, dirección ppc es 0X%X\n",ppc,*ppc,**ppc,&ppc);
    printf("pppc apunta a 0X%X que contiene 0X%x que contiene 0X%X que contiene %c\n",pppc,*pppc,**pppc,***pppc);
    printf("Dirección pppc es 0X%X",&pppc);

    /*
    Ahora para crear una matriz mediante punteros
    */
    int **p, n, m[100], i, j;
    //Se pide el número de filas que tendrá la matriz siempre mayor a cero
    do
    { printf("\nNo. de filas: "); scanf("%d",&n);}
    while(n<=0);
    //Asignación dinámica de memoria para doble apuntador
    p=(int **)malloc(n*sizeof(int *));
    //Aceptar elementos de cada fila
    for(i=0; i<n; i++)
    {
        printf("No. de elementos de fila (<100) %d: ",i+1);
        scanf("%d",&m[i]);
        //Asigna memoria para cada vector
        p[i]=(int*)malloc(m[i]*sizeof(int));
        //Acepta los elementos
        for(j=0;j<m[i];j++)
        {
            printf("Elemento %d -> ",j);
            scanf("%d",&p[i][j]);
        }
    }

    int x, y;
    //Mostrar elementos
    //Filas
    for(i=0,y=2;i<n;i++,y++)
    {
        //Elementos de fila
        for(j=0,x=2;j<m[i];j++,x+=2)
        {
            printf(" %d ",p[i][j]);
        }
        printf("\n");
    }
    // Liberar la memoria
    for(i=0;i<n;i++)
    {
        // Liberar memoria de cada fila
        free(p[i]);
    }
    // Liberar memoria del puntero a punteros
    free(p);

    return 0;
}
