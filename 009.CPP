/*
  Curso de Programaci¢n en C
  Leccion 9
*/
#include <stdio.h>
/*
  struct FILE
  fopen(char *nombre_archivo,char *modo);
  NULL
  EOF
  int fclose(FILE *puntero_archivo);
*/
#include <conio.h>
#include <stdlib.h>
/*
  void exit(int status);
*/
#include <ctype.h>
/*
  int tolower(char car);
*/

/*
  Manejo de archivos en C
  El manejo de archivos en cualquier lenguaje de programaci¢n
  sigue 3 sencillos pasos:
  1.-Apertura del archivo
  2.-Obtenci¢n de datos del archivo (tratamiento)
  3.-Cierre del archivo
  Con esto es posible realizar cualquier tratamiento de datos que esten
  contenidos en un archivo.
  Para comenzar es necesario saber que para poder acceder a un archivo
  dentro de un programa en C, se debe de asiganr su direcci¢n de memoria
  (entre otras cosas mas) a un puntero especial que esta definido en
  la libreria stdio.h como una estructura.

  La estructura del puntero FILE:
  typedef struct {
   short          level;
   unsigned       flags;
   char           fd;
   unsigned char  hold;
   short          bsize;
   unsigned char *buffer, *curp;
   unsigned       istemp;
   short          token;
  }FILE;

  A pesar de la complejidad que pude mostrar, el manejo del puntero
  es sencillo pues solo se hace la declaraci¢n a una variable y mediante
  esta variable se puede abrir el archivo y extraer los datos.
*/

void main()
{
 char c, *cad;
 int entero;
 float flotante;
 /*Declaraci¢n del apuntador FILE*/
 FILE *pf;
 /*
   1.-Apertura del archivo
   fopen("nombre_archivo",modo);
   La funci¢n fopen recibe dos argumentos, una cadena que es el nombre del
   archivo, el cual se debe de especificar la ruta de acceso, si es que
   no se encuentra en donde esta el archivo ejecutable del programa
   y el modo de apertura, el cual puede ser:

   Modo   |  Significado
   "r"    |  Abre para la lectura
   "w"    |  Abre para crear un nuevo archivo (si ya existe pierde sus datos)
   "a"    |  Abre para a¤adir al final, si no existe se crea
   " +"   |  A¤adido a cualquiera de los anteriores, para lectura/escritura
   " b"   |  A¤adido a cualquiera de los anteriores, crea un archivo binario

   La funci¢n devuelve el puntero con la direcci¢n del archivo, en caso
   de que no se abriera regresar¡a NULL, por tanto se debe de colocar una
   rutina para evitar posibles errores en la ejecuci¢n del programa
 */
 if( (pf=fopen("archivo.txt","w+")) == NULL )
 {
  puts("Error al intentar abrir el archivo, presione una tecla para salir");
  //La funci¢n exit(-1); indica una terminaci¢n anormal de programa, por lo que
  //termina con la ejecuci¢n del programa
  getch(); exit(-1); //Puede colocarse exit(1); tambi‚n, pues exit(0); es una salida normal de programa
 }

 /*
   2.-Tratamiento de datos de archivos
   >> Escritura en archivos
   La escritura en archivos puede realizarse mediante la siguiente funci¢n:

   * fputc(char caracter, FILE *puntero_archivo);
     La cual coloca un caracter en el archivo deseado
   * fputs(char *cadena, FILE *puntero_archivo);
     La cual coloca una cadena completa en el archivo
   * fprintf(puntero_archivo,"caracteres", variables);
     Esta funci¢n escribe en el archivo como lo hace la funci¢n printf
     en la salida est ndar (monitor)
   * fwrite(const void *buffer, int tama¤o, int num_elem, FILE *ptr_arch);
     Esta es una funci¢n para archivos binarios, lo que escribe en el
     archivo es la direcci¢n de lo que se desea escribir en const void *buffer
     de cierto tama¤o, con un numero de elementos, en el archivo al que apunta FILE *pf
 */
 printf("<<Escritura caracter por caracter [Presiona 's' para salir]>>\n");
 /*
   Aqui se espera un caracter convirtiendo cualquiera que se presione en
   minusculas mediante la funci¢n tolower, y se compara si es diferente a 's'
 */
 while( (tolower(c=getche())) != 's' )
 {
  putc(c,pf); //Se escribe en el archivo
 }
 //se puede escribir el caracter que uno desee, por ejemplo salto de linea
 putc('\n',pf);

 /*Ahora podemos probar con otra cadena*/
 printf("\n\n<<Escritura por cadena, teclea una cadena>>\n");
 gets(cad);
 //Escribimos en archivo
 fputs(cad,pf);
 //Escribimos un nuevo retorno de carro
 putc('\n',pf);

 /*Luego colocaremos varios tipos de datos*/
 printf("\n\n<<Escritura con formato>>\n");
 printf("Escribe un entero  : "); scanf("%d",&entero);
 printf("Escribe un flotante: "); scanf("%f",&flotante);
 /*Colocamos todo para ver como se ver  en el archivo*/
 printf("Entero  : %d\nFlotante: %.2f\nCaracter: %c\nCadena  : %s\n",entero,flotante,c,cad);
 //Y ahora en el archivo
 fprintf(pf,"Entero  : %d\nFlotante: %.2f\nCaracter: %c\nCadena  : %s\n",entero,flotante,c,cad);
 printf("{{Presiona una tecla para seguir}}"); getch(); clrscr();
 /*
   2.-Tratamiento de datos de archivos
   >> Lectura de archivos
   Ya que logramos escribir en el archivo o que deseamos leer lo que
   tenga un archivo, se pueden usar las funciones:

   * int fgetc(*FILE puntero_archivo);
     La cual lee caracter por caracter del archivo
   * char *fgets(char *cad, int num, FILE *ptr_arch);
     La cual lee una cadena de caracteres del archivo, la cual puede tener una longitud num
   * fscanf(*FILE *ptr_arch, "cadena_ctrl", variables);
     Funciona de la misma manera que el scanf();
   * size_t fread(void *ptr, size_t tam, size_t n, FILE *ptr_arch);
     Para archivos binarios, la funci¢n devuelve el numero de bloques que lee
     el cual debe coincidir con el tama¤o n, los valores quedan en el
     apuntador *ptr, el cual debe tener el tama¤o tam, del archivo FILE *ptr_arch
 */
 /*
   En este punto del programa el apuntador FILE *pf, esta al final del
   archivo, por lo que si lo leyeramos marcar¡a EOF, provocandonos errores
   por lo que se debe de rebobinar el puntero para que apunte al inicio del
   archivo, esto se logra mediante la funci¢n rewind:
   void rewind(FILE *ptr_arch);
 */
 rewind(pf);
 //Ahora si es posible leer el archivo
 //Se leera todo el archivo
 char c1, *cad1;
 while(!feof(pf)) //La funci¢n feof() detecta si se ha llegado al fin del archivo
 {
  c1=fgetc(pf); //Se lee el caracter
  putchar(c1);    //Se escribe en pantalla
 }

 /*
   3.-Cierre de archivos
   ESTO ES MUUY IMPORTANTE, PARA EVITAR QUE LA MEMORIA DE LA COMPUTADORA
   SE VAYA LLENANDO DE BASURA CADA QUE SE TRABAJE CON ARCHIVOS EN C, SE DEBE
   DE CERRAR EL APUNTADOR QUE CONTIENE AL ARCHIVO
   esto se realiza con la funci¢n fclose
   int fclose(FILE *puntero);
   Regresando 0 cuando es correcto el cierre o EOF cuando falla
 */
 fclose(pf);
 getch();
}