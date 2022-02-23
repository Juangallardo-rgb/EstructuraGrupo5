#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include "Sala.cpp"
#include "Sala.h"
 
#define ARRIBA 'w'
#define ABAJO 's'
#define ENTER 13

int menu(const char titulo[], const char *opciones[], int n);
void menu_principal();
void menu_salas();

struct sala S;
int opcion;
int sala_eleg=0;


//metodo principal del Menu.cpp
void Menu()
{
    Marquesina();
	menu_principal();
}


//menu principal para la administracion de salas de cine
void menu_principal()
{
   bool repite = true;   
   // Titulo del menÃº y nombres de las opciones
   const char *titulo = "MENU PRINCIPAL";
   const char *opciones[] = {"Administar Sala A1","Administar Sala A2","Administar Sala A3","Administar Sala B1","Administar Sala B2",
   "Administar Sala B3","Administar Sala C1","Administar Sala C2","Salir del Sistema"};
   int n = 9;  // Numero de opciones
   
   system("cls");
   setlocale(LC_ALL, "");
   do {
      opcion = menu(titulo, opciones, n);
      sala_eleg=opcion;
       
      switch (opcion) {
         case 1:
            menu_salas();
            break;
 
 
         case 2:
            menu_salas();
            break;
 
         case 3:
            menu_salas();
            break;
 
         case 4:
            menu_salas();
            break;
            
        case 5:
            menu_salas();
            break;
            
        case 6:
            menu_salas();
            break;
        
		case 7:
            menu_salas();
            break;
            
        case 8:
            menu_salas();
            break;
			    
  
        case 9:
            system("color 4");
            printf("\n\nEsta abandonando el sistema.\n\n");
            system("pause");	
            repite = false;
            break;
        
		default:
            printf("\nOpción mal ingresada.");
			system("pause");
			break;
      }
 
   } while(repite);
}


//menu auxiliar para las salas de cine
//con ingreso de teclado
void menu_salas(){
	system("cls");
    system ("COLOR 3");
    Marquesina();
    	
    int opc=0;
	int n = 5;  // Numero de opciones
	
	//salas
	char salas[8][100]={"Sala A1","Sala A2","Sala A3","Sala B1","Sala B2","Sala B3","Sala C1","Sala C2"};
 
   // Titulo del menÃº y nombres de las opciones
   const char *titulo = "POR FAVOR SELECCIONE UNA OPCION:\n\n";
   const char *opciones[] = {"VER SALA.\n","DIGITAR PERSONAS QUE INGRESAN.\n","DIGITAR PERSONAS QUE SALEN.\n",
   "VACIAR LA SALA.\n","VOLVER AL MENU PRINCIPAL.\n"};
   
      
        struct sala S=LeerSala(salas[sala_eleg-1]);
        while(opc!=5){
                system("cls");
                printf("%s\n",titulo);
   
               for (int i = 0; i < n; ++i) {
                    printf("%i. %s\n",i+1,opciones[i]);
                }
                //printf(" POR FAVOR SELECCIONE UNA OPCION DEL MENU:\n\n 1. VER ESPACIOS VACIOS.\n 2. DIGITAR PERSONAS QUE INGRESAN.\n 3. DIGITAR PERSONAS QUE SALEN.\n 4. VACIAR LA SALA.\n 5. VOLVER AL MENÃš PRINCIPAL.\n " );
                printf("Ingrese la opción: ");
                scanf("%i",&opc);
                switch (opc)
                {
                case 1:
                    mostrarSala(S);
                    system("pause");
                    break;
                case 2:{
                    int ingresan;
                    printf("\nDigite el número de personas que ingresan: ");
                    scanf("%d",&ingresan);
                    S = Anadir(S,ingresan);
                    ActualizarSala(S);
                    system("pause");
                    break;
                }
                case 3:{
                    int salen;
                    printf("\nDigite el número de personas que salen: ");
                    scanf("%d",&salen);
                    S = Quitar(S,salen);
                    mostrarSala(S);
                    ActualizarSala(S);
                    system("pause");
                    break;
                }
                case 4:{
                    S = VaciarSala(S);
                    ActualizarSala(S);
                    printf("La sala se ha vaciado. ");
                    system("pause");
                    break;
                }
                case 5:{printf("Volverá al menú principal. ");
                    system("pause");
                    break;
                }
                default:{
                    printf("Opción incorrecta. ");
                    system("pause");
                    break;
                }
                }
            }
	
}
        
//funcion para deshabilitar la escritura en consola y permitir
//únicamente el movimiento de las teclas "w" para arriba y "s" para abajo

char getch2 ()
{
   char c=0;
   DWORD modo, contador;
   HANDLE ih = GetStdHandle(STD_INPUT_HANDLE);
 
   // Desactivamos escritura en terminal
   SetConsoleMode (ih, modo & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));
 
   ReadConsoleA (ih, &c, 1, &contador, NULL);
 
   if (c == 0) {
      ReadConsoleA (ih, &c, 1, &contador, NULL);
   }
 
   SetConsoleMode (ih, modo); // Devolvemos control normal
 
   return c;
}

 
//funcion para utilizar el cursor como posicion
int gotoxy(USHORT x,USHORT y) {
   COORD cp = {x,y};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cp);
 }
 
 
//función auxiliar para el menú de opciones y moverse con las teclas
int menu(const char titulo[], const char *opciones[], int n){
   int opcionSeleccionada = 1;  // Indica la opcionSeleccionada
   int tecla; //variable para las teclas "w" y "s"
   bool repite = true; // controla el bucle para regresar a la rutina que lo llamo, al presionar ENTER
       
   do {
      system("cls");
      system("color 1e"); //poner consola en azul
      //system("color 2");
      printf("[||BIENVENIDO AL SISTEMA ||SIN AGLOMERACIONES||]\n");
      gotoxy(5, 3 + opcionSeleccionada); printf("==>");
 
      // Imprime el titulo del menu
      gotoxy(15, 2); printf("%s.\n",titulo);
 
      // Imprime las opciones del menu
      for (int i = 0; i < n; ++i) {
         gotoxy(10, 4 + i);
         printf("%i. %s.\n",i+1,opciones[i]);
      }
 
      // Solo permite que se ingrese ARRIBA, ABAJO o ENTER
 
      do {
         tecla = getch2();
      } while (tecla != ARRIBA && tecla != ABAJO && tecla != ENTER);
 
      switch (tecla) {
 
         case ARRIBA:   // En caso que se presione ARRIBA
 
            opcionSeleccionada--;
 
            if (opcionSeleccionada < 1) {
               opcionSeleccionada = n; //cuando se va a la primera posición -1
            }
 
            break;
 
         case ABAJO:   // En caso que se presione ABAJO
            opcionSeleccionada++;
 
            if (opcionSeleccionada > n) {
               opcionSeleccionada = 1; //cuando se va a la última posición +1
            }
 
            break;
 
         case ENTER:
            repite = false;
            break;
      }
 
   } while (repite);
 
   return opcionSeleccionada;
}


