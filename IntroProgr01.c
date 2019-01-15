//---------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

//---------------------------------------------------------------------------

/* Estructura a manejar */
typedef struct {
        char nombre[20];
        char apellido[20];
        int edad;
        char curp[20];
        char sexo;
} persona;      // Definir estructura como "persona"

/* Función Principal */
int main(int argc, char* argv[])
{
        persona alumno; // Declarar alumno como "persona"
        persona *ptr_persona;   // Apuntador a estructura

        /* Llenar la estructura */
        strcpy(alumno.nombre, "Juan");
        strcpy(alumno.apellido, "Perez");
        alumno.edad = 20;
        strcpy(alumno.curp,"XEXX010101HNEXXXA4");
        alumno.sexo = 'M';

        /* Mostrar los datos en la estructura */
        printf("Nombre:  \t%s\n",alumno.nombre);
        printf("Apellido:\t%s\n",alumno.apellido);
        printf("Edad:    \t%d\n",alumno.edad);
        printf("CURP:    \t%s\n",alumno.curp);
        printf("Sexo:    \t%c\n",alumno.sexo);

        printf("Presione una tecla para continuar--> ");
        getch();        // Pausa para una tecla

        ptr_persona = &alumno;  // Hacer que apunte a la estructura
        /* Llenar la estructura (apuntadores) */
        // Podría ocuparse la siguiente notación
        // (*ptr_persona).edad = 20;
        // pero se tiene para ese caso el operador ->
        strcpy(ptr_persona -> nombre, "Juana");
        strcpy(ptr_persona -> apellido, "Perez");
        ptr_persona -> edad = 22;
        strcpy(ptr_persona -> curp,"XEXX010101MNEXXXA8");
        ptr_persona -> sexo = 'F';

        /* Mostrar los datos en la estructura (apuntadores) */
        printf("\nNombre:  \t%s\n",alumno.nombre);
        printf("Apellido:\t%s\n",alumno.apellido);
        printf("Edad:    \t%d\n",alumno.edad);
        printf("CURP:    \t%s\n",alumno.curp);
        printf("Sexo:    \t%c\n",alumno.sexo);
        getch();        // Esperar una tecla antes de terminar
        return 0;
}
//---------------------------------------------------------------------------