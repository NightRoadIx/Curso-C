/** PREPROCESADOR **/
/* LIBRERIAS */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
// Si se usa una librería creada por el programador
// se coloca en la carpeta junto con este código fuente
// y se llama de la siguiente forma:
// #include "libreriapersonal.h"

/* DEFINICIONES */
#define MAXIMAVELOCIDAD 80

/** DECLARACIONES **/
/* Declaración de funciones */
/* también llamada "Prototipo de función"*/
// void miFuncion(int argumento);      // "void" indica que la función no regresa NADA
//             ^Esto es un argumento de los muchos que puede tener la función
// int miFuncionInt(int otroArgumento);// regresan cosas (en este caso un número entero)
// MUCHO OJO, LAS FUNCIONES SOLO REGRESAN UNO Y SOLO UN VALOR
float suma(float a, float b);
float resta(float a, float b);
float multiplica(float a, float b);
float divide(float a, float b);
float potencia(float base, float exponente);

/* Variables globales */
// Estas pueden ser operadas en TODO el programa (incluídas las funciones adicionales)
// int miVariableGlobal;

// int main recibe como argumentos el nombre del mismo programa al ser llamado
// más texto adicional con el que se ejecute el programa
int main(int argc, char *argv[])
{
	// Variables locales
    float a, b, c;
	char operar;
	
	// Cuerpo del programa
    printf("Ingresa a: "); scanf("%f", &a);
    printf("Ingresa b: "); scanf("%f", &b);
	
	// Esta sección de código permite solo ingresar cualquiera de los 5 caracteres +, -, *, /, p
    printf("( + - * / p)>>");
    while(1)
    {
        operar = getch();
        if( (operar == '+')||(operar == '-')||(operar == '*')||(operar == '/')||(operar == 'p') )
            break;
    }
    putch(operar);
    
	// Seleccionar entre alguno de las operaciones
    switch(operar)
    {
        case '+':
            c = suma(a,b);
            break;
        case '-':
            c = resta(a,b);
            break;
        case '*':
            c = multiplica(a, b);
            break;
        case '/':
            c = divide(a,b);
            break;
        case 'p':
            c = potencia(a,b);
            break;
    }
	
	printf("\n Resultado: %.2f\n", c);
    return 0; // Programa termino OK
    // return 1; // Programa termino con error en el caso de main, regresa el valor al programa que lo mando a llamar
}

/* Definción de funciones */
float suma(float a, float b)
{
    float c;
    c = a + b;
    return c;	// SUPER DUPER ULTRA IMPORTANTE, al tratarse de una función que retorna un valor se debe usar "return valor"
}

float resta(float a, float b)
{
    float c;
    c = a - b;
    return c;    
}

float multiplica(float a, float b)
{
    float c;
    int i;
	// No se usa la operación "*", supongamos no está definida
	// Una multiplicación es una sucesión de sumas
	// por tanto se puede ejecutar con un ciclo for, dado que 
	// el número de sumas está dada por uno de los multiplicandos
    for(i=0, c=0.0; i < b; i++, c+=a);
	
	// SIN EMBARGO LA MULTIPLICACIÓN ASÍ NO ESTÁ DEFINIDA PARA SIGNOS NEGATIVOS...
	// ¿QUÉ MÁS HARÍA FALTA AGREGAR PARA QUE SE PUDERIA REALIZAR?
	
    return c;
}

float divide(float a, float b)
{
    // Variables locales
    float c;
    
	// Hay que considerar el caso cuando se indetermina la división (denominador es 0)
    if(b != 0)
    {
        c = (a) / (b);
        
        // Regresar el resultado
        return c;        
    }
    else
    {
        printf("\nEl usuario anda borracho\n");
        return -1.0;
    }
}

float potencia(float base, float exponente)
{
    float c;
    int i;
    
	// En este caso la potencia es una serie de multiplicaciones sucesivas
    for(i=0, c=1.0; i < exponente; i++, c *= base);
	
	// ¿ESTE CÓDIGO ES SUFICIENTE PARA ACEPTAR CUALQUIER POTENCIA? ¿INCLUSO NEGATIVAS Y FRACCIONADAS?
	
    return c;
}