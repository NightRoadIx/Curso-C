#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

void main()
{
    /*
    Apuntador void *, este es un apuntador genérico, esto es
    que puede asignarse a cualquier tipo de datos, pues si se declarase
    int *pint;
    pint solo puede apuntar a direcciones de memoria ocupadas por enteros
    sin embargo, con un void *pg, pg puede apuntar a cualquier dirección
    de memoria válida
    */
    void *p;
    int i;
    int m = 0;
    for(i = 1; ; i++)
    {
        p = malloc(1000);   // Asigna un bloque de 1000 bytes
        // Cuando ya no se pueda asignar mas espacio
        if(p==NULL)break;
        m += 1;
    }
    printf("\nTotal de memoria asignada %.2f Kb\n",(m*1000.0)/1024); getch();
}
