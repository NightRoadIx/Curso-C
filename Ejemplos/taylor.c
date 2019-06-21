/*
 * Programa que realizar el método numérico de
 * Serie de Taylor para calcular el coseno de un ángulo
 * 
 * EL PROGRAMA NO VIENE COMENTADO
 * ¿SERÍA CAPAZ DE COMENTAR LAS PARTES IMPORTANTES DEL PROGRAMA
 * PARA DESCRIBIR SU FUNCIONAMIENTO?
 * 
 * THE MATRIX NEEDS YOU!!!
 * 
 * */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

#define PI 3.14159265358979323846

float factorial(float n);

int main(int argc, char **argv)
{
	float ang_deg=0.0, ang_rad=0.0, Err, an, S, Sant;
	int n;
		
	do {
		printf("Angulo a calcular coseno [0, 360]: ");
		scanf("%f", &ang_deg);
	} while( (ang_deg < 0.0)||(ang_deg > 360.0) );
	ang_rad = ang_deg * PI / 180.0;
	
	printf("n\tan\tS\tSn-1\tError\n");
	n = 0; S = 0; Err = 1.0;
	do { 
		Sant = S;
		an = ( pow(-1, n)/factorial(2*n) )*(pow(ang_rad, 2*n) );
		S = S + an;
		if(n != 0) Err = fabs( (S-Sant)/Sant );
		printf("%d\t%.2f\t%.2f\t%.2f\t%.6f\n", n,an, S, Sant, Err);
		n++;
	}while(Err > 1e-6);
	
	printf("El valor tras %d iteraciones de cos(%.2f) = %.6f ", n-1, ang_deg, S);
	
	return 0;
}

float factorial(float n)
{
	if(n == 0)
		return 1;
	else
		return(factorial(n-1)*n);
}

/*
 * CORRECTO, AHORA, ¿¿¿PODRÍA INCRMENTAR EL PROGRAMA PARA QUE ESTE CALCULE 
 * TAMBIÉN LA SERIE DE TAYLOR DEL SENO, COLOCANDO AMBAS COMO FUNCIONES???
 * 
 * LA SERIE DE TAYLOR DEL SENO ES IGUAL A:
 * suma de 0 a infinito del término
 * an = ( pow(-1, n)/factorial(2*n+1) )*(pow(ang_rad, 2*n+1) )
 */ 
