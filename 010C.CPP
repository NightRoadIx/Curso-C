/*Esto es un programa muy perfecto
  sobre las colas
  Su objetivo es la creaci¢n, despliegue y destrucciones de estructuras*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define ENTER 13
#define MAX 30

//Structuras y variables globales imperfectas
typedef struct item {
	char cve_p [5];
	char des_mov [MAX];
	struct item *sig_tarea;
	}NODO;
NODO *primero = NULL;

//Prosstotipos
NODO *acepta(void);
void recorre_item(void);
void libera_item(void);
void muestra_item(NODO *tmp);
void borrar_inicio();
agrega_item(NODO *item);

//MAIN no perfecto
void main()
{
 NODO *tmp=NULL;
 char key;
 clrscr();
 do
 {
  clrscr();
  printf("\n\t\t*********BANCO*********");
  printf("\n\t\t\t <---Menu---> \n");
  printf("\n\t\t1.- Agregar (PUSH)");
  printf("\n\t\t2.- Recorrer ");
  printf("\n\t\t3.- Borrar (POP)");
  printf("\n\t\t4.- Salir");
  printf("\n\tSu opci¢n es...");
  key=getche();
   if(key == '1') {
		clrscr();
		printf("\n\n\t-----AGREGAR AL FINAL-----");
		tmp=acepta();
		agrega_item(tmp);
		break;
		}
   else if(key == '2') {
		clrscr();
		printf("\n\n\t-----DESPLEGAR-----");
		recorre_item();
		break;
		}
   else if(key == '3') {
		clrscr();
		printf("\n\n\t-----BORRAR-----");
		borrar_inicio();
		break;
		}
   else if(key == '4') {
		break;
		}
   else {
		printf("\n\n\tLA OPCION NO EXISTE");
		getch();
		}
 }
 while(key != '4');
 libera_item();
 printf("\n\a\aPrograma terminado...");
 getch();
}

//Funciones no perfectas
//ACEPTAR
NODO *acepta(void)
{
 char id_p[10];
 NODO *tmp = (NODO *) NULL;
 printf("\n\nNumero de Tarea: [TECLEE ENTER PARA SALIR]\T"); gets(id_p);
 if(*id_p == NULL) return((NODO *)NULL);
  tmp=(NODO *)malloc(sizeof(NODO));
 if(tmp == (NODO *)NULL)
 {
  printf("\nError al asignar memoria");
  printf("\nImposible continuar");
  for(int x=0; x <= 80; x++)
   printf("erroreroeoreoreroerror");
  exit(1);
 }
 strcpy(tmp->cve_p, id_p);
 gotoxy(15, 10);
 printf("Descripci¢n: ");
 gotoxy(35, 11);
 printf("		");
 gotoxy(35, 11);
 fflush(stdin);
 gets(tmp->des_mov);
 return(tmp);
}

//AGREGA AL FINAL (IMPERFECTO)
agrega_item(NODO *item)
{
 NODO *ptr=NULL;
 if(primero == NULL) //primer elemento en la lista
 {
  primero=item;
  item->sig_tarea=NULL;
  return(0);
 }
 ptr=primero;
 while(ptr->sig_tarea != NULL)
  ptr=ptr->sig_tarea;
 ptr->sig_tarea=item;
 item->sig_tarea=NULL;
 return(0);
}

//RECORRE Y MUESTRA LOS OBJETOS (ESTO ES MAS QUE PERFECTO)
void recorre_item(void)
{
 NODO *ptr=NULL;
 ptr=primero;
 if(ptr == NULL)
 {
  printf("\n\n\tNo existe lista ...[FUCK FUCK FUCK]");
  getch();
 }
 while(ptr != NULL)
 {
  muestra_item(ptr);
  ptr=ptr->sig_tarea;
 }
}

//DESPLEGAR (YA ESTO ES MAS QUE PERFECTO)
void muestra_item(NODO *tmp)
{
 printf("\n\n\t < Elemento Recuperado > \n");
 printf("\n  Clave del cliente : %d", tmp->cve_p);
 printf("\n  Descripci¢n del movimiento : %s", tmp->des_mov);
 printf("(-Presione cualquier tecla-)"); getch();
}

//LIBERA MEMORIA
void libera_item()
{
 NODO *ptr=(NODO *)NULL, *tmp = (NODO *)NULL;
 ptr=primero;

 while(ptr != NULL)
 {
  tmp=ptr;
  ptr=ptr->sig_tarea;
  free(tmp);
 }
 printf("\nPerfecto se ha liberado la memoria");
}

//COMO BORRAR LO MAS PERFECTO DEL PROGRAMA
void borrar_inicio()
{
 NODO *p;
 if(primero != NULL)
 {
  printf("\n\t %s \n\t %s", primero->cve_p, primero->des_mov);
  printf("\nEsta seguro de borrar este elemento [DIGA QUE SI]...");
  if(getch() == ENTER)
  {
   p=primero;
   primero=primero->sig_tarea;
   free(p);
  }
  else
  {
   printf("No #$%! EXISTE COLA !!!!");
   getch();
  }
 }
}
//Fin del programa