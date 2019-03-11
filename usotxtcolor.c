/*
 * Programa ejemplo para el uso de la librería txtcolor.h
 */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* 
 * SE TIENE QUE AÑADIR ESTA LIBRERÍA PARA QUE FUNCIONE
 * LA LIBRERÍA TIENE QUE COLOCARSE EN LA MISMA CARPETA DONDE
 * SE TENGA EL CÓDIGO FUENTE
 */
#include "txtcolor.h"

int main(int argc, char **argv)
{
	// Función para limpiar la pantalla
	clrscr();
	
	// Función para el cambio del tipo de cursor
	// _setcursortype(int tipo)
	// tipo:
	// 0	->	Sin cursor
	// 1	->	Cursor normal (_)
	// 2	->	Cursor medio (▄)
	// 3	->	Cursor completo (█)
	_setcursortype(3);
	
	// Función para imprimir en una posición de la pantalla
	// Se debe colocar la posición tanto en x, como en y
	// el punto inicial es la esquina superior izquierda (1,1)
	// gotoxy(int x, int y)
	gotoxy(5,4);
	printf("Se coloca en la posicion de la pantalla (5,5)");
	
	// Función para cambio de color de texto
	// textcolor(int color)
	// color:
	// 0	->	negro
	// 1	->	azul
	// 2	->	verde
	// 3	->	cian
	// 4	->	rojo
	// 5	->	magenta
	// 6	->	amarillo ocre
	// 7	->	gris
	// 8	->	azul intenso
	// 9	->	verde intenso
	// 10	->	cian intenso
	// 11	->	rojo intenso
	// 12	->	magenta intenso
	// 13	->	amarillo intenso
	// 14	->	blanco
	gotoxy(1,5);
	textcolor(11);
	printf("Texto en color rojo intenso");
	
	// Función para cambio de color de fondo del texto
	// textbackgroun(int color)
	// color:
	// 0	->	negro
	// 1	->	azul
	// 2	->	verde
	// 3	->	cian
	// 4	->	rojo
	// 5	->	magenta
	// 6	->	amarillo ocre
	// 7	->	gris
	// 8	->	azul intenso
	// 9	->	verde intenso
	// 10	->	cian intenso
	// 11	->	rojo intenso
	// 12	->	magenta intenso
	// 13	->	amarillo intenso
	// 14	->	blanco
	gotoxy(1,6);
	// Tener cuidado en como se colocan el color del texto y el fondo
	textcolor(11); textbackground(14);
	printf("Texto en color rojo intenso con fondo blanco");
	
	getch();
	 textbackground(0); textcolor(7); _setcursortype(1);
	// Regresar todo a la normalidad
	
	return 0;
}
