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
// Esta librería ayuda a la manipulación de caracteres
#include <ctype.h>

#define N 4

/*
  Los apuntadores y las funciones
  A veces se desea que una función regrese mas de un valor, y esto es
  posible con el uso de apuntadores, ya que cuando se pasa una variable
  a una función, solo se pasa el valor de esta variable, pero cuando
  se pasa un apuntador a una función se pasa su dirección en memoria
*/

// Prototipos de funciones
void salida(char*[], int *);
void entrada(char*[]);
int vocales(char*);

// Función principal
int main()
{
    //Arreglo de apuntadores
    char *cad[N];
    int j,voc[N];

    //Se pasa el arreglo de apuntadores cad, esto es se pasa la dirección de
    //este espacio en memoria
    entrada(cad);
    //En este punto del programa cad ya está modificado
    for(j=0;j<N;j++)
        //Se manda cada elemento del arreglo de punteros
        voc[j]=vocales(cad[j]);
    //Se muestra por último, mandando todo el arreglo de punteros y el de enteros
    salida(cad,voc);
    return 0;
}

void entrada(char *cd[])
{
    char B[121];
    int j,tam;
    printf("\n\tEscribe %d líneas de texto\n",N);
    for(j=0;j<N;j++)
    {
        //Se obtiene una cadena que se guarda en el arreglo B
        fgets(B,121,stdin);
        //Se realiza la asignación de memoria
        tam=(strlen(B)+1)*sizeof(char);
        cd[j]=(char*)malloc(tam);
        //Se copia la cadena B a cd[j] que no es más que la dirección en memoria
        //del arreglo de apuntadores *cad[N] que se encuentra en main
        strcpy(cd[j],B);
    }
}

//Se recibe una cadena
int vocales(char *c)
{
    int k,j;
    //Se revisará toda la cadena letra por letra
    for(j=k=0;j<strlen(c);j++)
        //Cuando ocurra una vocal se suma la variable k
        switch(tolower(*(c+j)))
        {
            case 'a':;
            case 'e':;
            case 'i':;
            case 'o':;
            case 'u': k++;
        }
    return k;
}

//Aquí se recibe el arreglo de apuntadores y el arreglo de enteros, pero este
//último se recibe en forma de apuntador
void salida(char *cd[], int *v)
{
    int j;
    puts("\n\tSalida de las líneas junto al número de vocales\n");
    for(j=0;j<N;j++)
        printf("%s : %2d\n",cd[j],v[j]);
}
