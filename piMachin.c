/*
 * pi_machin.c — Calcula N dígitos de pi con precisión arbitraria.
 *
 * Idea: un número "grande" se guarda como un ARREGLO de dígitos decimales
 * (memoria dinámica con malloc), y hacemos la aritmética "a mano", como en
 * la primaria: suma, resta y división larga entre un entero pequeño.
 *
 * Fórmula de Machin (1706):
 *     pi = 16*arctan(1/5) - 4*arctan(1/239)
 * con la serie de Taylor:
 *     arctan(1/m) = 1/m - 1/(3 m^3) + 1/(5 m^5) - 1/(7 m^7) + ...
 *
 * Representación: x[0] es la parte entera, x[1], x[2], ... son los
 * decimales. Ej. 3.1415 -> {3, 1, 4, 1, 5, 0, 0, ...}
 *
 */
// printf, putchar, fprintf
#include <stdio.h>
// malloc, free, atoi
#include <stdlib.h>
// memset, memcpy
#include <string.h>

// Dígitos extra al final del arreglo: ahí se acumulan los errores de
// truncamiento de las divisiones, lejos de los dígitos que sí imprimimos
#define GUARDA 10

// Longitud total de cada número (cuántas casillas tiene cada arreglo).
// Es global porque todas las funciones la necesitan
int LEN;

/* x = n (entero pequeño) */
void asignar(int *x, int n) {
    // Pone en cero todas las casillas del arreglo (LEN enteros en bytes)
    // void *memset(void *ptr, int value, size_t num);
    memset(x, 0, LEN * sizeof *x);
    // La parte entera queda en n; todos los decimales en 0 -> x = n.000...
    x[0] = n;
}

/* x = x / d   (división larga, de izquierda a derecha) */
void dividir(int *x, int d) {
    // Lo que "sobra" de la casilla anterior (como en la división de primaria)
    long resto = 0;
    // Recorre desde la parte entera hacia los decimales
    for (int i = 0; i < LEN; i++) {
        // "Bajamos" el siguiente dígito: resto*10 + dígito actual
        long v = resto * 10 + x[i];
        // Cuántas veces cabe d -> ese es el dígito del cociente
        x[i]  = (int)(v / d);
        // Lo que no alcanzó a dividirse pasa a la siguiente casilla
        resto = v % d;
    }
}

/* a = a + b   (de derecha a izquierda, propagando el acarreo) */
void sumar(int *a, const int *b) {
    // "Lo que se lleva" de una columna a la siguiente
    int acarreo = 0;
    // Empieza por el último decimal (derecha) y avanza a la izquierda
    for (int i = LEN - 1; i >= 0; i--) {
        // Suma de la columna: dígito de a + dígito de b + lo que se llevaba
        int v = a[i] + b[i] + acarreo;
        // Se queda solo la unidad (0..9) en esta casilla
        a[i] = v % 10;
        // La decena (0 o 1) se lleva a la columna de la izquierda
        acarreo = v / 10;
    }
}

/* a = a - b   (suponemos a >= b; propagamos el "préstamo") */
void restar(int *a, const int *b) {
    // 1 si la columna anterior tuvo que "pedir prestado"
    int prestamo = 0;
    // De derecha a izquierda, como la resta en papel
    for (int i = LEN - 1; i >= 0; i--) {
        // Resta de la columna, descontando el préstamo pendiente
        int v = a[i] - b[i] - prestamo;
        // Si quedó negativo, pedimos 10 a la izquierda y marcamos el préstamo;
        // si no, no se debe nada a la siguiente columna
        if (v < 0) { v += 10; prestamo = 1; } else prestamo = 0;
        // Guarda el dígito resultante (0..9)
        a[i] = v;
    }
}

/* a = a * n   (n entero pequeño) */
void multiplicar(int *a, int n) {
    // Lo que se lleva (aquí puede ser mayor que 1, p. ej. 9*16 = 144)
    int acarreo = 0;
    // De derecha a izquierda
    for (int i = LEN - 1; i >= 0; i--) {
        // Producto de la casilla más lo que se llevaba
        int v = a[i] * n + acarreo;
        // Se queda la unidad
        a[i] = v % 10;
        // El resto (decenas, centenas...) pasa a la izquierda
        acarreo = v / 10;
    }
}

/* Devuelve 1 si todo el arreglo vale cero, 0 en otro caso */
int es_cero(const int *x) {
    // En cuanto encuentra un dígito distinto de cero, ya no es cero
    for (int i = 0; i < LEN; i++) if (x[i]) return 0;
    // Recorrió todo y no encontró nada: el número es 0
    return 1;
}

/* res = arctan(1/m) por su serie de Taylor */
void arctan_inv(int *res, int m) {
    // Potencia actual: 1/m^(2k+1)
    int *pot  = malloc(LEN * sizeof *pot);
    // Término actual de la serie: 1/((2k+1) m^(2k+1))
    int *term = malloc(LEN * sizeof *term);

    // pot = 1
    asignar(pot, 1);
    // pot = 1/m  (primer término de la serie, k = 0)
    dividir(pot, m);
    // res = 1/m  (copia el arreglo pot completo en res)
    // void *memcpy(void *restrict dest, const void *restrict src, size_t count);
    memcpy(res, pot, LEN * sizeof *res);

    // Sin condición de paro en el for: se sale con el break de abajo
    for (int k = 1; ; k++) {
        // Dividir dos veces entre m equivale a dividir entre m^2
        // (así evitamos que m*m sea grande y desborde)
        dividir(pot, m);
        // pot = 1/m^(2k+1)
        dividir(pot, m);
        // term = copia de pot
        memcpy(term, pot, LEN * sizeof *term);
        // term = pot/(2k+1)  -> 1/3, 1/5, 1/7, ...
        dividir(term, 2 * k + 1);
        // Si el término ya es 0 en todas las casillas, ya no aporta nada
        if (es_cero(term)) break;
        // Signos alternados: k impar resta (-1/3m^3), k par suma (+1/5m^5)
        if (k % 2) restar(res, term);
        else       sumar(res, term);
    }
    // Libera los arreglos temporales de esta función
    free(pot);
    free(term);
}

int main(int argc, char *argv[])
{
    // Ajustar cuantos decimales de pi se requieren:
    // si se pasa un argumento (./inin02 500) se usa ese; si no, 10
    int n = (argc > 1) ? atoi(argv[1]) : 10;
    // Si el argumento no es válido (0 o negativo), usa 100
    if (n < 1) n = 100;
    // parte entera + decimales + guarda
    LEN = n + 1 + GUARDA;

    // Se asigna espacio en memoria para pi y para el número auxiliar b
    int *pi = malloc(LEN * sizeof *pi);
    int *b  = malloc(LEN * sizeof *b);
    // malloc devuelve NULL si no hay memoria: se avisa y se termina
    if (!pi || !b) { fprintf(stderr, "Sin memoria\n"); return 1; }

    // 16*arctan(1/5)
    arctan_inv(pi, 5);    multiplicar(pi, 16);
    // 4*arctan(1/239)
    arctan_inv(b, 239);   multiplicar(b, 4);
    // pi = diferencia
    restar(pi, b);

    // Imprimir el número entero
    printf("%d.", pi[0]);
    // Y los decimales (solo hasta n; los dígitos de guarda no se imprimen)
    for (int i = 1; i <= n; i++)
    {
        // Convierte el dígito (0..9) a su carácter ASCII ('0'..'9') y lo imprime
        putchar('0' + pi[i]);
        // Para imprimir de 50 en 50 dígitos
        if (i % 50 == 0 && i < n) printf("\n  ");
    }
    // Salto de línea final
    putchar('\n');

    // MUY IMPORTANTE: LIBERAR LA MEMORIA
    free(pi);
    free(b);
    return 0;
}
