/*
 * Programa que muestra la fecha y hora actuales del sistema del formato:
 * Hoy es DIASEMANA NUMERODÍA de MES de AÑO
 * La hora es: hh:mm:ss
 */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
// Librería básica para operaciones básicas con caracteres
#include <ctype.h>
//Librería que contiene la definición de macros, constantes y funciones para manejo de cadenas de caracteres
#include <string.h>
// Libreria que contiene funciones para manipular y formatear fecha y hora sel sistema
#include <time.h>

int main(int argc, char **argv)
{	
	/* Variables */
	// Para horas, minutos y segundos
	unsigned int hh, mm, ss;
	// Para días, meses, años
	unsigned int dd, me, aa;
	// Para días de la semana
	unsigned int ds;
	// Estrucutra para el manejo de la hora del sistema
	struct tm *fh;
	// Estructura con el tiempo del sistema en segundos
	// Tipo de dato especial para el almacenamiento de valores de
	// tiempo del sistema, definido en time.h
	// Esta definido como el número de segundos desde el inicio del
	// tiempo UNIX 1 de enero de 1970
	// Esto ocasionará el "problema del año 2038"
	time_t segundos;
	
	// Arreglo de caracteres para los nombres de
	// dias de la semana	
	static char dia[7][10] = {"Domingo", "Lunes",
		"Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};
	// meses del año
	static char mes [12][11] = {"Enero", "Febrero", "Marzo",
		"Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre",
		"Octubre", "Noviembre", "Diciembre"};
	/* Se usa static ya que no se piensa modificar estos datos que se iniciaron
	 * Recordar que se trata de un arreglo de dos dimensiones que indican:
	 * [número de filas][numero de columnas]
	 * Entonces se asignan espacios de memoria (de 8 bits para el caso de la variable char)
	 */
	
	// Obtener el valor del tiempo del sistema local
	time(&segundos);
	fh = localtime(&segundos);
	// Asignar los valores de horas, minutos y segundos
	hh = fh->tm_hour;	// hora [0, 23]
	mm = fh->tm_min;	// minuto [0, 59]
	ss = fh->tm_sec;	// segundo [0, 59]	
	
	// Asignar los valores de días, meses y años
	dd = fh->tm_mday;	// día del mes [1, 31]
	me = fh->tm_mon;	// mes del año [0, 11]
	aa = fh->tm_year;	// año (a partir de 1900)
	ds = fh->tm_wday;	// día de la semana [0, 6] 0 = domingo
	
	// Imprimir la fecha
	printf("Hoy es %s %d de %s de %d\n", dia[ds], dd, mes[me], aa+1900);
	printf("La hora es %d:%0d:%d", hh, mm, ss);
	return 0;
}
