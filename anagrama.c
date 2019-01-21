//---------------------------------------------------------------------------

#pragma hdrstop
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


//Aqui esta la funcion de ordenacion
int sort_function( const void *a, const void *b);
void permuta(char vec[], int k, int n);

//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
	char cad1[50], cad2[50], cad3[50], cad4[50];
	unsigned int abcd01[26], abcd02[26];
	int len01 = 0, len02 = 0;
	int i, j, cont;

	printf("Cadena 01: ");
	gets(cad1);
	fflush(stdin);
	printf("Cadena 02: ");
	gets(cad2);

	printf("\nSe ingresaron:\n1.-%s\n2.-%s\n\n", cad1, cad2);
	
	// Longitudes de las cadenas ingresadas
	len01 = strlen(cad1);
	len02 = strlen(cad2);	
	cont = 0;

	/* Verificar si se tratan de anagramas */
	// 1.- Prueba letra a letra
	// Primero revisar si las longitudes de las cadenas son iguales
	if(len01 == len02)
	{
		strcpy(cad3, cad2);
		for(i=0; i < len01; i++)
		{
			for(j=0; j < len02; j++)
			{
				if(cad1[i] == cad3[j])
				{
					// Sustituir el caracter hallado por '#'
					cad3[j] = '#';
					// Incrementar un contador
					cont++;
					printf("\n(%d ^ %d) - %s | %d", i, j, cad3, cont);
					break;
				}
			}
		}
		// Verificar entonces si es anagrama
		printf("\nLas cadenas %s y %s ", cad1, cad2);
		if(cont == len01)
			printf("son anagramas\n");
		else
			printf("no son anagramas\n");
	}
	else
		printf("\nLongitud de cadenas diferente, no puede ser un anagrama\n");
	
	// 2.- Ordenar y comparar
	// La primera revisión es siempre si son de la misma longitud
	if(len01 == len02)
	{
		strcpy(cad3, cad1);
		strcpy(cad4, cad2);
		// Ordenar la primer cadena
		qsort((void *)cad3, len01, sizeof(cad3[0]), sort_function);
		// Ordenar la segunda cadena
		qsort((void *)cad4, len01, sizeof(cad4[0]), sort_function);
		
		printf("\ncad1 : %s", cad3);
		printf("\ncad2 : %s", cad4);
		
		// Verificar si ambas son iguales y entonces si es que son anagramas
		printf("\nLas cadenas %s y %s ", cad1, cad2);
		if(strcmp(cad3,cad4) == 0)
			printf("son anagramas\n");
		else
			printf("no son anagramas\n");		
		
	}
	else
		printf("\nLongitud de cadenas diferente, no puede ser un anagrama\n");	
	
	// 3.- Fuerza bruta
	// Una vez más revisar si son de la misma longitud
	if(len01 == len02)
	{
		permuta(cad1, 0, len01);
	}
	else
		printf("\nLongitud de cadenas diferente, no puede ser un anagrama\n");	
	
	// 4.- Contar y comparar
	// Revisar cuantas veces se presentan las mismas letras en ambas cadenas
	// Usaremos la comparación con el codigo ASCII
	// Una vez más revisar si son de la misma longitud
	if(len01 == len02)
	{
		// Rellenar de 0's los arreglos
		for(i=0; i < 26; i++)
		{
			abcd01[i] = 0; abcd02[i] = 0;
		}
		cont = 0;
		
		// Recorrer las cadenas (ambas son de la misma longitud)
		for(i=0; i < len01; i++)
		{
			// Sobre las 26 letras
			for(j =0; j < 26; j++)
			{
				// Primera cadena
				if(cad1[i] == (j+97))
					abcd01[j]++;
				//Segunda cadena
				if(cad2[i] == (j+97))
					abcd02[j]++;				
			}
		}
		// Ahora revisar si los contadores son iguales
		for(i=0; i < 26; i++)
		{
			// Con una sola diferencia, no son anagramas
			if(abcd01[i] != abcd02[i])
			{
				cont = 1; break;
			}
		}
		printf("\nLas cadenas %s y %s ", cad1, cad2);
		if(cont)
			printf("no son anagramas\n");
		else
			printf("son anagramas\n");
		
	}
	else
		printf("\nLongitud de cadenas diferente, no puede ser un anagrama\n");

	getch();

    return 0;
}
//---------------------------------------------------------------------------

//Funci¢n ordenar te llevas 2 punteros constantes
int sort_function( const void *a, const void *b)
{
   //Estos se comparan en forma de cadena (es a partir del c¢digo ASCII)
   return( strcmp((char *)a,(char *)b) );
}

void permuta(char vec[], int k, int n)
{
	int i, aux;
	
	if (k < n)
	{
		for(i = k; i < n; i++)
		{
			aux = vec[k];
			vec[k] = vec[i];
			vec[i] = aux;
			permuta(vec, k+1, n);
			aux = vec[k];
			vec[k] = vec[i];
			vec[i] = aux;
		}
	}
	else
	{
		printf("\n");
		for(i=0; i < n; i++)
			printf(" %c ", vec[i]);
	}
	
}