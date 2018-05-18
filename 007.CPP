/*
  Curso de Programaci¢n en C
  Leccion 7
*/
#include <stdio.h>
#include <conio.h>

/*
   Estructuras, uniones y enumeraciones
   Las estructuras es un tipo de datos de C, en el que se pueden tener
   diferentes tipos de variables dentro de una misma a diferencia de los
   arreglos que solo pueden contener un solo tipo de datos
   Declaraci¢n:
   struct nombre_estuctura
   {
    tipo_dato var1;
    tipo_dato var2;
    ...
    tipo_dato varn;
   };
   Pero despues de haber declarado la estructra (o definido), se le debe de poner
   otro nombre para definir a la varible con la que se piensa trabajar:
   struct nombre_estructura nombre_variable_estructura
   o para evitar el volver a colocar la palabra struct se realiza de esta otra forma:
   struct nombre_estuctura
   {
    tipo_dato var1;
    tipo_dato var2;
    ...
    tipo_dato varn;
   }nombre_var_estruct1, nombre_var_estruct2;

   Las uniones son muy similares a las estrcutras, pero la forma en que se
   almacenan en memoria es diferente, pues mientras una estructura permite
   almacenar variables relacionadas juntas y en posiciones contiguas de la memoria
   (esto es una al lado de otra), las uniones almacenan todos los miembros en la
   misma posici¢n (esto es todas las variables se solapan) y el tama¤o de la uni¢n
   ser  igual al de la variable miembro de la uni¢n mas grande
   La declaraci¢n es:
   union nombre_union
   {
    tipo_dato var1;
    tipo_dato var2;
    ...
    tipo_dato varn;
   }nombre_var_union;

   Las enumeraciones es un tipo definido por el usuario con constantes de nombre
   tipo entero. En la declraci¢n de un tipo enum se escribbe una lista de identificadores
   que internamente se asocian a constantes enteras 0,1,2,...
   Declaraci¢n:
   enum
   {
    enumerador1, enumerador2, ..., enumeradorn
   };
   O de la forma:
   enum nombre_enumerador
   {
    enumerador1, enumerador2, ..., enumeradorn
   };
   O bien si no se desea que se asocien con los valores default (0,1,2...):
   enum nombre_enumerador
   {
    enumerador1=expresion_cte,
    enumerador2=expresion_cte,
    ...
    enumeradorn=expresion_cte,
   };
   De igual forma que las estrucutras y uniones debe de declararse despues
   la variable de tipo nombre_enumerador
*/

struct disco  //Declaramos la estructura
{
 //Variables miembro de la estructura
 char *titulo;
 char *interprete;
 int no_pistas;
 float duracion;
}Cd; //Nombre de la variable de la estructura

union discou  //Declaramos la union
{
 //Variables miembro de la union
 char *titulou;
 char *interpreteu;
 int no_pistasu;
 float duracionu;
}Cdu; //Nombre de la variable de la union

enum dias_semana //Declaramos la enumeraci¢n
{
 //Variables constantes toman valores 0,1,2,3,4,5,6
 LUNES, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO, DOMINGO
};

/*
   El operador typedef puede usarse para definir un tipo de datos al que
   se desea acceder varias veces por medio de variables por ejemplo, en
   el caso de la estructura disco, si se va a declarar varias veces esta
   estructura a lo largo del programa, entonces se puede hacer la declaraci¢n como:
typedef struct disco
{
 char *titulo;
 char *interprete;
 int no_pistas;
 float duracion;
}Cd;

Cd disco_nuevo; //Ser¡a el sustituto a:  struct disco disco_nuevo
*/

//Inicializaci¢n de estructuras
struct disco Cd1={
"T¡tulo del disco",
"Interprete_del_disco",
5,
1.5
};

/*PROTOTIPOS FUNCIONES*/
void ver_info(struct disco reg, int);

void main()
{
 clrscr();
 //Manejo de las estructuras
 //Puede declararse otra estructura como variable local
 struct disco Cd_local;
 //Al igual que una union
 union discou Cd_localu;

 /*
   El tama¤o de las estructruas
   Puede determinarse el tama¤o de las estructuras mediante el operador
   sizeof(variable_estructura); <- devuelve el tama¤o en bytes (ver OO1.cpp)
   y el tama¤o es la suma de los tama¤os de sus variables miembro
   en este caso ser  de
   sizeof(char *titulo) = asigna 2 (char es 1, + el nulo)
   sizeof(char *int‚rprete) = asigna 2 (char es 1, + el nulo)
   sizeof(int no_pistas) = 2
   sizeof(float duracion) = 4
 */
 printf("Tama¤o de Cd1 [Estructura] -> %d\n\n",sizeof(Cd_local));
 printf("Tama¤o de Cd1 [Uni¢n]      -> %d\n\n",sizeof(Cd_localu));

 /*
   Acceso a estructuras
   Para acceder a las estructuras se debe usar el operador punto:
   variable_estructura.variable_miembro
 */
 /*LECTURA*/
 printf("Disco 1 \n");
 printf("T¡tulo      : %s\n",Cd1.titulo);
 printf("Int‚rprete  : %s\n",Cd1.interprete);
 printf("No_canciones: %d\n",Cd1.no_pistas);
 printf("Duraci¢n    : %.2f\n",Cd1.duracion);
 /*ESCRITURA*/
 printf("\n\nNuevo disco\n");
 printf("Escribe el t¡tulo    : "); gets(Cd_local.titulo);
 printf("Escribe el interprete: "); gets(Cd_local.interprete);
 printf("Cuantas canciones    : "); scanf("%d",&Cd_local.no_pistas);
 printf("Duracion del disco   : "); scanf("%f",&Cd_local.duracion);
 //Las estructuras pasan a una funci¢n igual que cualquier otra variable
 ver_info(Cd_local,2);

 getch();
 printf("\nEnumeraci¢n\n");
 enum dias_semana dia;
 for(dia=LUNES; dia <= DOMINGO; dia++)
  printf("Dia -> %d\n",dia);

 getch();
}

void ver_info(struct disco reg,int num)
{
 printf("\nDisco %d \n",num);
 printf("T¡tulo      : %s\n",reg.titulo);
 printf("Int‚rprete  : %s\n",reg.interprete);
 printf("No_canciones: %d\n",reg.no_pistas);
 printf("Duraci¢n    : %.2f\n",reg.duracion);
}