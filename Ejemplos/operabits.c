#include <stdio.h>
#include <stdlib.h>

void binario(int num);

int main(int argc, char **argv)
{
	int a = 36;
	
	printf("<<Operaciones aniveles de bits>>\n");
	printf("Estas permiten crear las tablas de verdad\n");
	
	printf("\nTabla AND\n");
	printf("0 AND 0 = %d\n", 0&0);
	printf("0 AND 1 = %d\n", 0&1);
	printf("1 AND 0 = %d\n", 1&0);
	printf("1 AND 1 = %d\n", 1&1);
	
	printf("\nTabla OR\n");
	printf("0 OR 0 = %d\n", 0|0);
	printf("0 OR 1 = %d\n", 0|1);
	printf("1 OR 0 = %d\n", 1|0);
	printf("1 OR 1 = %d\n", 1|1);
	
	printf("\nTabla XOR\n");
	printf("0 XOR 0 = %d\n", 0^0);
	printf("0 XOR 1 = %d\n", 0^1);
	printf("1 XOR 0 = %d\n", 1^0);
	printf("1 XOR 1 = %d\n", 1^1);
	
	printf("\nTabla NOT\n");
	printf("NOT 0 = %d\n", !0);
	printf("NOT 1 = %d\n", !1);
	
	// Cuando se aplica a un valor numérico entero, por ejemplo,
	// lo que se hace es convertir el valor a binario
	// y aplicar la operación bit a bit
	printf("\n\n%d decimal es %x heaxadecimal y binario ", a, a);
	binario(a);
	
	// Si se aplica la operación AND para un valor de 000111
	// es hacer bit por bit 00100100 AND 00000111
	// Lo que dará 00000100
	// A esto se le llama enmascaramiento y mantiene todo lo que 
	// se le aplica la operación AND con 1's
	// OJO SE TOMAN DE 4 BITS (llamado nibble) PARA FACILITAR LAS COSAS
	// Y VER ESTOS RESULTADOS EN SISTEMA HEXADECIMAL
	printf("\n\%d AND %d = %d\n", a, 7, a&7);
	printf("%X AND %X = %X\n\n", a, 7, a&7);
	// Para el caso de OR
	// es otra clase de enmascaramiento puesto que
	// 00100100 OR 00000111 = 00100111
	printf("\%d OR %d = %d\n", a, 7, a|7);
	printf("%X OR %X = %X\n", a, 7, a|7);
	
	// Desplazamiento de bits              -Notar que se asigna y muestra al mismo tiempo
	printf("\n\nConsiderando un valor a = %d\n", a=2);
	printf("Las oepraciones de desplazamiento de bits \"mueven\" los bits de un numero\n");
	printf("ya sea a la derecha >> o a la izquierda <<\n");
	printf("Por ejemplo aplicando la operacion a << 2 = %d\n", a = a << 2);
	printf("Que es lo que esta pasando... por ejemplo 2 = "); binario(2);
	printf("  mientras 8 = "); binario(8);
	printf("\nEsto es que se movieron los bits existentes 2 posiciones a la izquierda\n\n");
	printf("...y que pasa si se aplica a >> 3 = %d ", a >> 3);
	return 0;
}

// Definición de la función para obtener el número en binario
void binario(int num)
{
	int aux;
	if(num == 0)
		return;
	aux = num % 2;
	num = num / 2;
	binario(num);
	printf("%d", aux);
}

// ¿EXISTIRÁ ALGUNA FORMA DE MOSTRAR UN NÚMERO ENTERO EN BASE BINARIA?