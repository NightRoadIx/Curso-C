// STanDard Input Output
#include <stdio.h>
// STanDard LIBrary
#include <stdlib.h>
// STandard BOOLean
#include <stdbool.h>
// Esta librería ayuda a la configuración del entorno local
#include <locale.h>

/*
	Los apuntadores son un tipo de variable especial en el lenguaje de programación C,
	Se trata de variables que no guardan exactamente un dato en memoria, sino que almacena
	la dirección de memoria ya sea de otra variable o segmento de código.
	
	Para el caso de las computadoras, la memoria del programa (memoria volátil o de acceso aleatorio, RAM)
	está "mezclada" con la memoria de datos, a esto se le conoce como arquitectura Von Neumann.
	Cuando el programa es cargado en dicha memoria, cada parte del mismo programa y de los datos que utiliza
	se almacenan en localidades de memoria que pueden ser vistas como cajas o compartimentos, identificados por
	un número, el cual es su dirección, es ahí donde los apuntadores entran en juego al tener la capacidad de
	almacenar dichos valores y poder "acceder" de manera indirecta al contenido de esos espacios.
	
*/

// Función principal
int main()
{
    // Establece la región a español para mostrar acentos y la ñ
    setlocale(LC_ALL, "spanish");


    int chernobyl[6] = {4, 6, 69, 42, 67, 13};     // Esto es para iniciarlos
    // Los índices son solamente del tipo entero
    int indice = 3;

    // Apuntadores
    // Se declaran de la siguiente forma:
    // tipo_de_memoria *apuntador = direccion_a_apuntar;
    int *p = chernobyl;     // El nombre de un arreglo es la dirección de memoria del primer elemento


    // Se recorren los elementos para mostrarlos
    for(indice = 0; indice < 6; indice++)
    {
        // Por nombre de arreglo
        printf("o %X - %d \n", chernobyl+indice, *(chernobyl+indice));
        // Por apuntador
        printf("p %X - %d \n", p+indice, *(p+indice));
    }

    // Al apuntar en otro espacio de memoria que no sea el "asigando"
    // al arreglo
    printf("\n\n Saliendo del arreglo %X  -  %d", p + indice + 1, *(p + indice + 1));

    return 0;
}
