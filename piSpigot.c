/*
 * pi_spigot.c — Algoritmo "spigot" (gotero) de Rabinowitz–Wagon
 *
 * Saca los dígitos de pi de 4 en 4 (base 10000) sin necesidad de
 * guardar pi completo: solo un arreglo de "restos" de tamaño ~3.5*N.
 *
 * Se basa en escribir pi en una base "mixta":
 *   pi = 2 + 1/3*(2 + 2/5*(2 + 3/7*(2 + 4/9*(2 + ...))))
 *
 * En una base normal (decimal) cada posición vale 1/10 de la anterior;
 * aquí la posición b vale (b-1)/(2b-1) de la anterior: 1/3, 2/5, 3/7, ...
 * En esa base pi se escribe simplemente como "2.2222222..." y el arreglo
 * r[] guarda esos "dígitos". Para sacar dígitos decimales se multiplica
 * todo por 10000 y se normaliza de derecha a izquierda (como un acarreo):
 * lo que sale por la izquierda es la siguiente tanda de 4 dígitos de pi.
 *
 */
// printf, putchar, fprintf
#include <stdio.h>
// malloc, free, atoi
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Cuántos dígitos de pi se quieren (incluyendo el 3):
    // si se pasa un argumento (./pi_spigot 500) se usa ese; si no, 100
    int ndig = (argc > 1) ? atoi(argv[1]) : 100;
    // Si el argumento no es válido (menos de 4), usa 800
    if (ndig < 4) ndig = 800;
    // Grupos de 4 dígitos (se redondea hacia arriba: 10 dígitos -> 3 grupos)
    int bloques = (ndig + 3) / 4;
    // Términos de la serie: cada término aporta ~0.3 dígitos decimales
    // (cada fracción (b-1)/(2b-1) vale casi 1/2 y log10(2) = 0.301),
    // así que para 4 dígitos hacen falta 4/0.301 = 13.3 -> 14 términos
    int n = bloques * 14;

    // Arreglo de "dígitos" de la base mixta, posiciones 0..n
    // (long long = 64 bits, para que los productos no se desborden)
    long long *r = malloc((n + 1) * sizeof *r);
    // malloc devuelve NULL si no hay memoria: se avisa y se termina
    if (!r)
    {
        fprintf(stderr, "Sin memoria\n"); return 1;
    }
    // Cada posición arranca con el "2" de la fórmula, escalado por 1000
    // (2*1000 = 2000) para que la primera tanda salga como "3141"
    for (int i = 0; i < n; i++) r[i] = 2000;
    // La última posición en 0: ahí se trunca la serie infinita
    r[n] = 0;

    // Los 4 dígitos de la vuelta anterior, que todavía no se imprimen
    // porque podrían recibir un acarreo de la vuelta siguiente
    long long e = 0;
    // Cada vuelta produce 4 dígitos; después de cada vuelta las 14 posiciones
    // de la derecha ya no afectan los dígitos que faltan, así que se descartan
    // (c es la posición activa más a la derecha)
    for (int c = n; c > 0; c -= 14)
    {
        // Acarreo que viaja de derecha a izquierda
        long long d = 0;
        // Contador para el denominador: arranca en 2c y se le resta 1
        // justo antes de usarlo, para obtener 2b-1 en cada posición b
        long long g = 2LL * c;
        // Recorre las posiciones de derecha (b = c) a izquierda (b = 1);
        // el for no tiene condición: se sale con el break de abajo
        for (int b = c; ; )
        {
            // Multiplica la posición b por 10000 y le suma el acarreo
            // que llegó de la derecha
            d += r[b] * 10000;
            // g = 2b-1, el denominador de esta posición
            g--;
            // Lo que no completa un "entero" de esta posición se queda aquí
            // (es el nuevo dígito de la base mixta, siempre menor que 2b-1)
            r[b] = d % g;
            // Lo que sí completa pasa como acarreo a la izquierda
            d /= g;
            // Prepara g para la siguiente posición (quedará en 2(b-1)-1)
            g--;
            // Avanza a la izquierda; al llegar a la posición 0 terminamos.
            // Ojo: la posición 1 tiene denominador 1, así que todo su valor
            // pasa a d -> d queda con la parte "entera" de esta vuelta
            if (--b == 0) break;
            // El acarreo se multiplica por el numerador de la nueva posición
            // (la fracción de la posición b es (b-1)/(2b-1) y aquí b ya
            // bajó en 1, así que este b es el numerador de la anterior)
            d *= b;
        }
        // Imprime los 4 dígitos pendientes más el acarreo que acaba de
        // llegar; %04lld rellena con ceros a la izquierda (ej. 265 -> 0265)
        printf("%04lld", e + d / 10000);
        // Los 4 dígitos de abajo de esta vuelta quedan pendientes
        // para imprimirse en la siguiente
        e = d % 10000;
    }
    // Salto de línea final
    putchar('\n');
    // MUY IMPORTANTE: LIBERAR LA MEMORIA
    free(r);
    return 0;
}
