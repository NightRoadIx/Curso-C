/* LIBRERIAS */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

/* DEFINICIONES */
#define MAXGRADO 11
#define MAXP 10
#define MAXIT 100

/* PROTOTIPOS DE FUNCIONES */
float evaluarFuncion(float coefic[], int grado, float x);

/* VARIABLES GLOBALES */

/* FUNCIÓN PRINCIPAL */
int main(int argc, char **argv)
{
    float coef[MAXGRADO], a, b, m, h, f_m, f_a, errMin = 0.0;
    unsigned int grado, i, prec;
	char res[MAXP+2], rorre[MAXP+2];
    
    /* Ingresar grado del polinomio */
    while(1) {
        printf("Grado polinomio [MAX %d]: ", MAXGRADO-1);
        scanf("%d", &grado);
        if( (grado > 0)&&(grado < MAXGRADO) ) break;
        printf("Error en el intervalo\n");
    }
    
    /* Ingresar los coeficientes */
    for(i = grado+1; i > 0; i--)
    {
        printf("Coeficiente x^%d: ", i-1);
        scanf("%f", &coef[i-1]);
    }
        
    /* INTERVALO DE CALCULO */
    while(1)
    {
        printf("Ingresar intervalo de calculo [a,b]\n");
        printf("a: "); scanf("%f",&a);
        printf("b: "); scanf("%f",&b);
        if( (a < b)&&( evaluarFuncion(coef, grado, a)*evaluarFuncion(coef, grado, b) < 0 ) ) break;
        printf("Error en intervalo\n");
    }
    
    /* DIGITOS DE PRECISION */
    while(1)
    {
        printf("Digitos de precision [1, %d]: ", MAXP);
        scanf("%d", &prec);
		if( (prec > 1)&&(prec <= MAXP) ) break;
		printf("Error en el intervalo\n");
    }
	errMin = 1.0/pow(10,prec);			// Calcular el valor del error a partir de los dígitos de precisión
	gcvt(errMin, prec, rorre);
	
	/* ENCABEZADO CON LOS DATOS PARA OBTENER LOS VALORES */
    /* Mostrar el polinomio en pantalla*/
    printf("\nf(x) = ");
    for(i = grado+1; i > 0; i--)
    {
        printf("%.2fx^%d ", coef[i-1], i-1);
        if(i != 1) printf("+ ");
    }
    printf(" = 0\n");
	printf("Intervalo:  [%.2f, %.2f]\n", a, b);
	printf("Error:\t%s\n\n", rorre);
	
	/* SECCIÓN DEL MÉTODO DE BISECCIÓN */
	printf("i\ta       \tb       \tm       \th       \n");
	i = 0;
	while(1)
	{
		m = (a + b)/2;
		f_m = evaluarFuncion(coef, grado, m);		// f(m)
		if( f_m == 0 ) break;		// Condición para romper el ciclo, si f(m) = 0
		h = (b - a)/2;
		f_a = evaluarFuncion(coef, grado, a);		// f(a)
		printf("%d\t%.10f\t%.10f\t%.10f\t%.10f\n",i, a, b, m, h); i++;
		
		// Reasignaciones
		if( (f_a * f_m) < 0 )
		{ a = a; b = m; }
		else
		{ a = m; b = b; }
		if(h < errMin) break;		// Condición de error para romper el ciclo
		
		if(i > MAXIT) break;		// Si el número de iteraciones sobrepasa un límite
	}
	gcvt(m, prec, res);				// Convertir el resultado en una cadena con "prec" dígitos de precisión
	printf("Solucion a %d digitos de precision: %s", prec, res);
    
    return 0;
}

/* FUNCIONES DE PROGRAMA */
/* Evaluar la función polinomial
 * RECIBE:
 * coefic[]		Arreglo con los coeficientes del polinomio
 * grado		Grado máximo del polinomio
 * x			Valor a evaluar en el polinomio
 * REGRESA:
 * Valor del polinomio evaluado en x
 */
float evaluarFuncion(float coefic[], int grado, float x)
{
    int i;
    float total;
    for(i=0, total = 0.0; i <= grado; i++)
        total += coefic[i] * pow(x, i);
        
	// El return es una especie de goto, pero con "premio" pues regresa el control del programa
	// y un valor
    return total;
}