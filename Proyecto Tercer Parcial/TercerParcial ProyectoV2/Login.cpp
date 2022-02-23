#include <stdio.h> 
#include <stdlib.h> 
#include <conio.h> 
#include "md5.cpp"
#include <string.h>
#include <time.h>


#define TECLA_ENTER 13
#define TECLA_BACKSPACE 8
#define LONGITUD 5
#define MAX_INTENTOS 3

#define NUMERO_USUARIOS 5

//función principal para Login de Usuario

void Login() {
	char usuario[LONGITUD + 1];
	char clave[LONGITUD + 1];
	int intento = 0;
	int ingresa = 0;
	char caracter;
	int i = 0;
    int j = 0;

    /* Declaración e inicialización de arreglos de usuarios y claves */
    char usuarios[NUMERO_USUARIOS][LONGITUD + 1] = {"juan", "jorge", "edy", "johan", "kevin"};
    char claves[NUMERO_USUARIOS][LONGITUD + 1] = {"1234", "4567", "78910", "abcd", "efgh"};
	
	do {
		i = 0;
		system("cls");
		printf("\n\t\t\tINICIO DE SESION\n");
		printf("\t\t\t---------------\n");
		printf("\n\tUSUARIO: ");
		gets(usuario);
		printf("\tCLAVE: ");
		while (caracter = getch()) {
			if (caracter == TECLA_ENTER) {
				clave[i] = '\0';
				break;
				
			} else if (caracter == TECLA_BACKSPACE) {
				if (i > 0) {
					i--;
					printf("\b \b");
				}
				
			} else {
				if (i < LONGITUD) {
					printf("*");
					clave[i] = caracter;
					i++;
				}
			}
		}
		
        /* El usuario y clave debe coincidir con alguno de los que se encuentran en el array */
        for (j = 0; j < NUMERO_USUARIOS; ++j) {
            if (strcmp(usuario, usuarios[j]) == 0 && strcmp(clave, claves[j]) == 0) {
                ingresa = 1;
                break;
                
            }
        }

        if (ingresa == 0) { //mensaje de error en caso de ingresar las credenciales incorrectas
            printf("\n\tUsuario y/o clave son incorrectos\n");
            intento++;
            getchar();
        }
		
		
	} while (intento < MAX_INTENTOS && ingresa == 0);
	
	  /* Aquí va el código del programa cuando el usuario ingresa sus credenciales correctas */
	
	if (ingresa == 1) {
		string s=getMD5(clave);
		printf("\n\n\tClave Encriptada con MD5");
		struct timespec d = { .tv_sec = 0.8, .tv_nsec = 1000000 };
		printf("\n\n\t%s",s.c_str());
		nanosleep(&d, 0);
		printf("\n\n\t[||BIENVENIDO AL SISTEMA ||SIN AGLOMERACIONES||]\n");
		

	} else {
		printf("\n\n\tHa sobrepasado el numero maximo de intentos permitidos\n");
		printf("\n\n\tSe procedera a cerrar el sistema por seguridad.\n\n");
		exit(-1);
	}
}
