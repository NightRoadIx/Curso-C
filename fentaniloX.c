// STanDard Input Output
#include <stdio.h>
// STanDard LIBrary
#include <stdlib.h>
// STandard BOOLean
#include <stdbool.h>
// Esta librería ayuda a la configuración del entorno local
#include <locale.h>

/* --- Reset y estilos --- */
#define A_RESET      "\x1b[0m"
#define A_BOLD       "\x1b[1m"
#define A_DIM        "\x1b[2m"
#define A_UNDERLINE  "\x1b[4m"
#define A_BLINK      "\x1b[5m"
#define A_REVERSE    "\x1b[7m"

/* --- Colores de texto (foreground) --- */
#define A_FG_BLACK   "\x1b[30m"
#define A_FG_RED     "\x1b[31m"
#define A_FG_GREEN   "\x1b[32m"
#define A_FG_YELLOW  "\x1b[33m"
#define A_FG_BLUE    "\x1b[34m"
#define A_FG_MAGENTA "\x1b[35m"
#define A_FG_CYAN    "\x1b[36m"
#define A_FG_WHITE   "\x1b[37m"

/* --- Colores de texto brillantes --- */
#define A_FG_BBLACK  "\x1b[90m"
#define A_FG_BRED    "\x1b[91m"
#define A_FG_BGREEN  "\x1b[92m"
#define A_FG_BYELLOW "\x1b[93m"
#define A_FG_BBLUE   "\x1b[94m"
#define A_FG_BMAGENTA "\x1b[95m"
#define A_FG_BCYAN   "\x1b[96m"
#define A_FG_BWHITE  "\x1b[97m"

/* --- Colores de fondo (background) --- */
#define A_BG_BLACK   "\x1b[40m"
#define A_BG_RED     "\x1b[41m"
#define A_BG_GREEN   "\x1b[42m"
#define A_BG_YELLOW  "\x1b[43m"
#define A_BG_BLUE    "\x1b[44m"
#define A_BG_MAGENTA "\x1b[45m"
#define A_BG_CYAN    "\x1b[46m"
#define A_BG_WHITE   "\x1b[47m"

/* --- Control de pantalla / cursor --- */
#define A_CLEAR      "\x1b[2J"        /* borra toda la pantalla        */
#define A_HOME       "\x1b[H"         /* cursor a (1,1)                */
#define A_CLEAR_ALL  "\x1b[2J\x1b[H"  /* borra + home                  */
#define A_HIDE_CUR   "\x1b[?25l"
#define A_SHOW_CUR   "\x1b[?25h"

/* Posiciona el cursor en (fila, col) 1-indexado */
static inline void a_gotoxy(int fila, int col) {
    printf("\x1b[%d;%dH", fila, col);
}

/* Color RGB de 24 bits */
static inline void a_fg_rgb(int r, int g, int b) {
    printf("\x1b[38;2;%d;%d;%dm", r, g, b);
}
static inline void a_bg_rgb(int r, int g, int b) {
    printf("\x1b[48;2;%d;%d;%dm", r, g, b);
}

// Función principal
int main()
{
    printf(A_CLEAR_ALL);      /* limpia pantalla          */
    printf(A_HIDE_CUR);       /* oculta el cursor         */

    /* --- Colores básicos --- */
    printf(A_FG_RED     "Este es el color rojo\n"     A_RESET);
    printf(A_FG_GREEN   "Este es el color verde\n"    A_RESET);
    printf(A_FG_YELLOW  "Este es el color amarillo\n" A_RESET);
    printf(A_FG_BLUE    "Este es el color azul\n"     A_RESET);
    printf(A_FG_MAGENTA "Este es el color magenta\n"  A_RESET);
    printf(A_FG_CYAN    "Este es el color cian\n"     A_RESET);
    printf(A_FG_WHITE   "Este es el color blanco\n"   A_RESET);

    printf("\n");

    /* --- Colores brillantes --- */
    printf(A_FG_BRED    "Este es el rojo brillante\n"    A_RESET);
    printf(A_FG_BGREEN  "Este es el verde brillante\n"   A_RESET);
    printf(A_FG_BYELLOW "Este es el amarillo brillante\n"A_RESET);
    printf(A_FG_BBLUE   "Este es el azul brillante\n"    A_RESET);

    printf("\n");

    /* --- Combinaciones: color + fondo --- */
    printf(A_FG_BLACK A_BG_YELLOW " Negro sobre amarillo " A_RESET "\n");
    printf(A_FG_WHITE A_BG_RED    " Blanco sobre rojo    " A_RESET "\n");
    printf(A_FG_BLACK A_BG_CYAN   " Negro sobre cian     " A_RESET "\n");

    printf("\n");

    /* --- Estilos --- */
    printf(A_BOLD      A_FG_RED "Negrita roja\n"      A_RESET);
    printf(A_UNDERLINE A_FG_BLUE "Azul subrayado\n"    A_RESET);
    printf(A_REVERSE   "Texto invertido (fg/bg swap)\n" A_RESET);

    printf("\n");

    /* --- 256 colores --- */
    printf("\x1b[38;5;208mNaranja de la paleta 256\x1b[0m\n");
    printf("\x1b[38;5;99m  Violeta de la paleta 256\x1b[0m\n");

    /* --- Truecolor RGB (24-bit) --- */
    a_fg_rgb(255, 128, 0);
    printf("Naranja RGB (255,128,0)\n");
    printf(A_RESET);

    a_fg_rgb(0, 200, 255);
    printf("Cian personalizado (0,200,255)\n");
    printf(A_RESET);

    return 0;
}
