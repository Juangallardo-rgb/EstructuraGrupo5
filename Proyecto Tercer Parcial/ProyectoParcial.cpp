#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct sala{
char nombre[100];
int MATRIZ[12][12];
int Asistentes;
};

void mostrarSala(struct sala S)
{
    int i,j;
    printf("%s.\n",S.nombre);
    for(i=1;i<=10;i++)
    {
        for(j=1;j<=10;j++)
        {
            if (S.MATRIZ[i][j]==1)
    		{
                printf(" 1 ");
			}
			else
            {
                printf(" . ");
            }
        }
        printf("\n");
    }
    printf("Asistentes: %i.\n",S.Asistentes);
}

struct sala LeerSala(char nombre[100])
{
	system("cd c:/proyecto final/");
    struct sala S;
    FILE *myfile;
    int i,j;
    strcpy(S.nombre,nombre);
    char nombre2[100];
    strcpy(nombre2,nombre);
    strcat(nombre2,".txt");
    myfile = fopen(nombre2,"r");
    if(myfile!=NULL)
    {
        S.Asistentes=0;
        for(i=0;i<=11;i++)
        {
            for(j=0;j<=11;j++)
            {
                fscanf(myfile,"%i",&S.MATRIZ[i][j]);
                if(S.MATRIZ[i][j]==1)
                    S.Asistentes++;
            }
        }
    }
	else
	{
		printf("\nNo se ha encontrado la sala, revise los archivos.\n");
	}
    fclose(myfile);
    return S;
}

int Asignar(struct sala *Se, int e)
{
    int F,C;
    struct sala S=*Se;
    if (e>7)
    {
        return 0;
    }
	for(F=1;F<=10;F++)
    {
    	for(C=1;C<=10;C++)
    	{
				if ((e==1) && S.MATRIZ[F][C]==0)
        		{
				if ((S.MATRIZ[F][C+1]==0) && (S.MATRIZ[F-1][C+1]==0) && (S.MATRIZ[F-1][C]==0) && (S.MATRIZ[F-1][C-1]==0) && (S.MATRIZ[F][C-1]==0) && (S.MATRIZ[F+1][C-1]==0) && (S.MATRIZ[F+1][C]==0) && (S.MATRIZ[F+1][C+1]==0)  )
				{

					S.MATRIZ[F][C]=1;
        			*Se=S;
        			return 1;
				}
				}  

				if ((e==2) && S.MATRIZ[F][C]==0)
        		{
				if ((C<10) && (S.MATRIZ[F][C+1]==0) && (S.MATRIZ[F][C+2]==0) && (S.MATRIZ[F-1][C+2]==0) && (S.MATRIZ[F-1][C+1]==0) && (S.MATRIZ[F-1][C]==0) && (S.MATRIZ[F-1][C-1]==0) && (S.MATRIZ[F][C-1]==0) && (S.MATRIZ[F+1][C-1]==0) && (S.MATRIZ[F+1][C]==0) && (S.MATRIZ[F+1][C+1]==0) && (S.MATRIZ[F+1][C+2]==0)  )
				{
					S.MATRIZ[F][C]=  1;
					S.MATRIZ[F][C+1]=  1;
        			*Se=S; return 1;
				}
				else if((F<10) && (S.MATRIZ[F+1][C]==0) && (S.MATRIZ[F+2][C]==0) && (S.MATRIZ[F+2][C-1]==0) && (S.MATRIZ[F+1][C-1]==0) && (S.MATRIZ[F][C-1]==0) && (S.MATRIZ[F-1][C-1]==0) && (S.MATRIZ[F-1][C]==0) && (S.MATRIZ[F-1][C+1]==0)&& (S.MATRIZ[F][C+1]==0) && (S.MATRIZ[F+1][C+1]==0) && (S.MATRIZ[F+2][C+1]==0))
				{
					S.MATRIZ[F][C]=  1;
					S.MATRIZ[F+1][C]=  1;
        			*Se=S; return 1;
				}
				}  // 			
		}
 	}
 	return 0;
}

struct sala Anadir(struct sala S, int e)
{
    int posible=Asignar(&S,e);
    if(posible==0 && e>7)
    {
        printf("No es posible añadir más de 7 personas para evitar aglomeraciones.\nDivida el grupo y vuelva a intentarlo.\n");
    }
    else if(posible==0)
    {
        printf("No es posible añadir este número de personas para evitar aglomeraciones.\n");
    }
    else
    {
        S.Asistentes=S.Asistentes+e;
        mostrarSala(S);
    }
    return S;
}



void ActualizarSala(struct sala S)
{
    FILE *myfile;
    char nombre[100];
    strcpy(nombre,S.nombre);
    strcat(nombre,".txt");
    myfile = fopen(nombre,"w");
    int F,C;
    for(F=0;F<=11;F++)
    {
        for(C=0;C<=11;C++)
        {
            fprintf(myfile,"%i ",S.MATRIZ[F][C]);
        }
        fprintf(myfile,"\n");
    }
    fclose(myfile);
}

struct sala VaciarSala(struct sala S)
{
    S.Asistentes=0;
    int F,C;
    for(F=0;F<=11;F++)
    {
        for(C=0;C<=11;C++)
        {
            S.MATRIZ[F][C]=0;
        }
    }
    return S;
};

int main()
{
    char salas[8][100]={"Sala A1","Sala A2"};
    system ("COLOR 3");
    int sala_eleg=0,i;
    setlocale(LC_ALL, "");
    while(sala_eleg!=9)
    {
        system("cls");
        printf("BIENVENIDO AL SISTEMA ¡SIN AGLOMERACIONES!\n\nSeleccione una opción:\n");
        for(i=0;i<=1;i++)
        {
            printf("%i. Administar %s.\n",i+1,salas[i]);
        }
        printf("9. Salir del sistema.\nIgrese la opción: ");
        scanf("%i",&sala_eleg);
        if(sala_eleg>0 && sala_eleg<9)
        {
            int o=0;
            struct sala S=LeerSala(salas[sala_eleg-1]);
            while(o!=5)
            {
                system("cls");
                printf(" POR FAVOR SELECCIONE UNA OPCION DEL MENU:\n\n 1. VER ESPACIOS VACIOS.\n 2. DIGITAR PERSONAS QUE INGRESAN.\n 3. VACIAR LA SALA.\n 4. VOLVER AL MENÚ PRINCIPAL.\n " );
                printf("Ingrese la opción: ");
                scanf("%i",&o);
                switch (o)
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
                    S = VaciarSala(S);
                    ActualizarSala(S);
                    printf("La sala se ha vaciado. ");
                    system("pause");
                    break;
                }
                case 4:{printf("Volverá al menú principal. ");
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
        else if(sala_eleg==9)
        {
            system("color 4");
            printf("\n\nSaldrá del sistema.\n\n");
            system("pause");
        }
        else
        {
            printf("\nOpción mal ingresada.");
            system("pause");
        }
    }
    return 0;
}
