#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include "Sala.h"
#include "cola.cpp"

struct cola q;
int p=0;
int c=0;


void Marquesina(){
 char sign[50]="||BIENVENIDO AL SISTEMA ||SIN AGLOMERACIONES|| ";
    struct timespec d = { .tv_sec = 0.8, .tv_nsec = 1000000 };

    if (sign != NULL )
    {
        int t_len = strlen(sign);
        for (int i = 0; i < 10; i++)
        {
            for (int l_len = 0; l_len < t_len; l_len++)
            {
                int r_len = t_len - l_len;
                //GIRAR A LA DERECHA
                printf("\r[%*.*s%*.*s]", l_len, l_len, sign + r_len, r_len, r_len, sign);
                //GIRAR A LA IZQUIERDA
                //printf("\r[%*.*s%*.*s]", r_len, r_len, sign + l_len, l_len, l_len, sign);
                //fflush(stdout);
                nanosleep(&d, 0);
            }
        }
        putchar('\n');
    }
}


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

int AsignarAsientos(struct sala *Se, int e)
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
// e 1
				if ((e==1) && S.MATRIZ[F][C]==0)
        		{
				if ((S.MATRIZ[F][C+1]==0) && (S.MATRIZ[F-1][C+1]==0) && (S.MATRIZ[F-1][C]==0) && (S.MATRIZ[F-1][C-1]==0) && (S.MATRIZ[F][C-1]==0) && (S.MATRIZ[F+1][C-1]==0) && (S.MATRIZ[F+1][C]==0) && (S.MATRIZ[F+1][C+1]==0)  )
				{

					S.MATRIZ[F][C]=1;
        			*Se=S;
        			return 1;
				}
				}  // si e 1
// e 2

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
				}  // si e 2
// e 3

				if ((e==3) && S.MATRIZ[F][C]==0)
        		{
				if ((C<10) && (F<10) && (S.MATRIZ[F+1][C]==0) && (S.MATRIZ[F][C+1]==0)  && (S.MATRIZ[F][C+2]==0)&& (S.MATRIZ[F-1][C+2]==0) && (S.MATRIZ[F-1][C+1]==0) && (S.MATRIZ[F-1][C]==0) && (S.MATRIZ[F-1][C-1]==0) && (S.MATRIZ[F][C-1]==0) && (S.MATRIZ[F+1][C-1]==0) && (S.MATRIZ[F+2][C-1]==0) && (S.MATRIZ[F+2][C]==0) && (S.MATRIZ[F+2][C+1]==0) && (S.MATRIZ[F+1][C+1]==0) && (S.MATRIZ[F+1][C+2]==0) )
				{
					S.MATRIZ[F][C]=  1;
					S.MATRIZ[F+1][C]=  1;
					S.MATRIZ[F][C+1]=  1;
        			*Se=S; return 1;
				}
				else if((F<8) && (S.MATRIZ[F+1][C]==0)  && (S.MATRIZ[F+2][C]==0)  && (S.MATRIZ[F+2][C]==0) && (S.MATRIZ[F+1][C]==0) && (S.MATRIZ[F+2][C-1]==0) && (S.MATRIZ[F+1][C-1]==0) && (S.MATRIZ[F][C-1]==0) && (S.MATRIZ[F-1][C-1]==0) && (S.MATRIZ[F-1][C]==0) && (S.MATRIZ[F-1][C+1]==0)&& (S.MATRIZ[F][C+1]==0) && (S.MATRIZ[F+1][C+1]==0) && (S.MATRIZ[F+2][C+1]==0))
				{
					S.MATRIZ[F][C]=1;
					S.MATRIZ[F+1][C]=1;
					S.MATRIZ[F+2][C]=1;
        			*Se=S; return 1;
				}
				else if ((C<8) && (S.MATRIZ[F][C+1]==0) && (S.MATRIZ[F][C+2]==0)  && (S.MATRIZ[F][C+2]==0) && (S.MATRIZ[F-1][C+2]==0) && (S.MATRIZ[F-1][C+1]==0) && (S.MATRIZ[F-1][C]==0) && (S.MATRIZ[F-1][C-1]==0) && (S.MATRIZ[F][C-1]==0) && (S.MATRIZ[F+1][C-1]==0) && (S.MATRIZ[F+1][C]==0) && (S.MATRIZ[F+1][C+1]==0) && (S.MATRIZ[F+1][C+2]==0)  && (S.MATRIZ[F-1][C+1]==0) )
				{
					S.MATRIZ[F][C]=  1;
					S.MATRIZ[F][C+1]=  1;
					S.MATRIZ[F][C+2]=  1;
        			*Se=S; return 1;
				}
					else if ((C>9) && (F>8) && (S.MATRIZ[9][10]==0) && (S.MATRIZ[10][9]==0) && (S.MATRIZ[10][10]==0)  &&  (S.MATRIZ[8][10]==0) && (S.MATRIZ[8][9]==0) && (S.MATRIZ[9][9]==0) && (S.MATRIZ[9][8]==0) && (S.MATRIZ[10][8]==0)  )
				{
					S.MATRIZ[9][10]=  1;
					S.MATRIZ[10][9]=   1;
					S.MATRIZ[10][10]=  1;
        			*Se=S; return 1;
				}

				}  // si e 	3
// e 4

				if ((e==4) && S.MATRIZ[F][C]==0)
        		{
				if ((C<10) && (S.MATRIZ[F+1][C]==0)  && (S.MATRIZ[F][C+1]==0)  && (S.MATRIZ[F+1][C+1]==0)  && (F<10)       && (S.MATRIZ[F+2][C]==0) && (S.MATRIZ[F][C+1]==0) && (S.MATRIZ[F][C+2]==0) && (S.MATRIZ[F-1][C+2]==0) && (S.MATRIZ[F-1][C+1]==0) && (S.MATRIZ[F-1][C]==0) && (S.MATRIZ[F-1][C-1]==0) && (S.MATRIZ[F][C-1]==0) && (S.MATRIZ[F+1][C-1]==0) && (S.MATRIZ[F+2][C-1]==0) && (S.MATRIZ[F+2][C]==0) && (S.MATRIZ[F+2][C+1]==0) && (S.MATRIZ[F+2][C+1]==0) && (S.MATRIZ[F+2][C+2]==0) )
				{
					S.MATRIZ[F][C]=  1;
					S.MATRIZ[F+1][C]=  1;
					S.MATRIZ[F][C+1]=  1;
					S.MATRIZ[F+1][C+1]=  1;
        			*Se=S; return 1;
				}
				else if((F<8) && (S.MATRIZ[F+3][C]==0)  && (S.MATRIZ[F+1][C]==0) && (S.MATRIZ[F+2][C]==0 ) && (S.MATRIZ[F+3][C]==0)  && (S.MATRIZ[F+4][C]==0)&& (S.MATRIZ[F+4][C+1]==0) && (S.MATRIZ[F+3][C+1]==0) && (S.MATRIZ[F+2][C+1]==0) && (S.MATRIZ[F+1][C+1]==0) && (S.MATRIZ[F][C+1]==0) && (S.MATRIZ[F-1][C+1]==0) && (S.MATRIZ[F-1][C]==0) && (S.MATRIZ[F-1][C-1]==0) && (S.MATRIZ[F][C-1]==0) && (S.MATRIZ[F+1][C-1]==0) && (S.MATRIZ[F+2][C-1]==0) && (S.MATRIZ[F+3][C-1]==0) && (S.MATRIZ[F+4][C-1]==0))
                {
                	S.MATRIZ[F][C]=  1;
					S.MATRIZ[F+1][C]=  1;
					S.MATRIZ[F+2][C]=  1;
					S.MATRIZ[F+3][C]=  1;
        			*Se=S; return 1;
				}
				else if((C<8) && (S.MATRIZ[F][C+1]==0) && (S.MATRIZ[F][C+2]==0 ) && (S.MATRIZ[F][C+3]==0)  && (S.MATRIZ[F][C+4]==0)&& (S.MATRIZ[F+1][C+4]==0) && (S.MATRIZ[F+1][C+3]==0) && (S.MATRIZ[F+1][C+2]==0) && (S.MATRIZ[F+1][C+1]==0) && (S.MATRIZ[F+1][C]==0) && (S.MATRIZ[F+1][C-1]==0) && (S.MATRIZ[F][C-1]==0) && (S.MATRIZ[F-1][C-1]==0) && (S.MATRIZ[F-1][C]==0) && (S.MATRIZ[F-1][C+1]==0) && (S.MATRIZ[F-1][C+2]==0) && (S.MATRIZ[F-1][C+3]==0) && (S.MATRIZ[F-1][C+4]==0))
                {
                	S.MATRIZ[F][C]=1;
					S.MATRIZ[F][C+1]=  1;
					S.MATRIZ[F][C+2]=  1;
					S.MATRIZ[F][C+3]=  1;
        			*Se=S; return 1;
				}
				}  // si e 4
// e 5

				if ((e==5) && S.MATRIZ[F][C]==0)
        		{
				if ((C<9) && (F<9) && (S.MATRIZ[F+1][C]==0) && (S.MATRIZ[F+1][C+1]==0) && (S.MATRIZ[F][C+1]==0) && (S.MATRIZ[F][C+2]==0)       && (S.MATRIZ[F][C+2]==0)  && (S.MATRIZ[F][C+3]==0)  && (S.MATRIZ[F-1][C+3]==0) && (S.MATRIZ[F-1][C+2]==0) && (S.MATRIZ[F-1][C+1]==0)  && (S.MATRIZ[F-1][C+0]==0)  && (S.MATRIZ[F-1][C-1]==0) && (S.MATRIZ[F][C-1]==0) && (S.MATRIZ[F+1][C-1]==0)  && (S.MATRIZ[F+2][C-1]==0) && (S.MATRIZ[F+2][C]==0)  && (S.MATRIZ[F+2][C+1]==0) && (S.MATRIZ[F+2][C+2]==0)  && (S.MATRIZ[F+1][C+2]==0)  && (S.MATRIZ[F+1][C+3]==0)    )
				{
					S.MATRIZ[F][C]=1;
					S.MATRIZ[F+1][C]=  1;
					S.MATRIZ[F][C+1]=  1;
					S.MATRIZ[F+1][C+1]=  1;
					S.MATRIZ[F][C+2]=  1;
        			*Se=S; return 1;
				}
				else if ((C<10) && (F<9) && (S.MATRIZ[F-1][C-1]==0) && (S.MATRIZ[F-1][C]==0) && (S.MATRIZ[F-1][C+1]==0) && (S.MATRIZ[F-1][C+2]==0) && (S.MATRIZ[F][C-1]==0) && (S.MATRIZ[F][C]==0) && (S.MATRIZ[F][C+1]==0) && (S.MATRIZ[F][C+2]==0) && (S.MATRIZ[F+1][C-1]==0) && (S.MATRIZ[F+1][C]==0) && (S.MATRIZ[F+1][C+1]==0) && (S.MATRIZ[F+1][C+2]==0) && (S.MATRIZ[F+2][C-1]==0) && (S.MATRIZ[F+2][C]==0) && (S.MATRIZ[F+2][C+1]==0) && (S.MATRIZ[F+2][C+2]==0) && (S.MATRIZ[F+3][C-1]==0) && (S.MATRIZ[F+3][C]==0) && (S.MATRIZ[F+3][C+1]==0) && (S.MATRIZ[F+3][C+2]==0))
                {
                    S.MATRIZ[F][C]=1;
					S.MATRIZ[F+1][C]=  1;
					S.MATRIZ[F][C+1]=  1;
					S.MATRIZ[F+1][C+1]=  1;
					S.MATRIZ[F+2][C]=  1;
        			*Se=S; return 1;
                }
				//5v
				else if((F<7) && (S.MATRIZ[F+1][C]==0) && (S.MATRIZ[F+2][C]==0 ) && (S.MATRIZ[F+3][C]==0)  && (S.MATRIZ[F+4][C]==0)          && (S.MATRIZ[F+5][C]==0) && (S.MATRIZ[F+5][C+1]==0)&& (S.MATRIZ[F+4][C+1]==0) && (S.MATRIZ[F+3][C+1]==0) && (S.MATRIZ[F+2][C+1]==0) && (S.MATRIZ[F+1][C+1]==0) && (S.MATRIZ[F][C+1]==0) && (S.MATRIZ[F-1][C+1]==0) && (S.MATRIZ[F-1][C]==0) && (S.MATRIZ[F-1][C-1]==0) && (S.MATRIZ[F][C-1]==0) && (S.MATRIZ[F+1][C-1]==0) && (S.MATRIZ[F+2][C-1]==0) && (S.MATRIZ[F+3][C-1]==0) && (S.MATRIZ[F+4][C-1]==0) && (S.MATRIZ[F+5][C-1]==0))
                {
                	S.MATRIZ[F][C]=  1;
					S.MATRIZ[F+1][C]=  1;
					S.MATRIZ[F+2][C]=  1;
					S.MATRIZ[F+3][C]=  1;
					S.MATRIZ[F+4][C]=  1;
        			*Se=S; return 1;
				}//5h
				else if( (S.MATRIZ[F][C+1]==0) && (S.MATRIZ[F][C+2]==0) && (S.MATRIZ[F][C+3]==0) && (S.MATRIZ[F][C+4]==0) &&           (C<7) && (S.MATRIZ[F][C+1]==0) && (S.MATRIZ[F][C+2]==0 ) && (S.MATRIZ[F][C+3]==0)  && (S.MATRIZ[F][C+4]==0) && (S.MATRIZ[F][C+5]==0)  && (S.MATRIZ[F+1][C+5]==0) && (S.MATRIZ[F+1][C+4]==0) && (S.MATRIZ[F+1][C+3]==0) && (S.MATRIZ[F+1][C+2]==0) && (S.MATRIZ[F+1][C+1]==0) && (S.MATRIZ[F+1][C]==0) && (S.MATRIZ[F+1][C-1]==0) && (S.MATRIZ[F][C-1]==0) && (S.MATRIZ[F-1][C-1]==0) && (S.MATRIZ[F-1][C]==0) && (S.MATRIZ[F-1][C+1]==0) && (S.MATRIZ[F-1][C+2]==0) && (S.MATRIZ[F-1][C+3]==0) && (S.MATRIZ[F-1][C+4]==0)  && (S.MATRIZ[F-1][C+5]==0))
                {
                	S.MATRIZ[F][C]=  1;
					S.MATRIZ[F][C+1]=  1;
					S.MATRIZ[F][C+2]=  1;
					S.MATRIZ[F][C+3]=  1;
					S.MATRIZ[F][C+4]=  1;
        			*Se=S; return 1;
				}
				}  // si e 5
//e 6

				if ((e==6) && S.MATRIZ[F][C]==0)
        		{
				if ((C<9) && (F<10) && (S.MATRIZ[F+1][C]==0) && (S.MATRIZ[F+1][C+2]==0) && (S.MATRIZ[F][C+2]==0) && (S.MATRIZ[F+1][C+1]==0)  && (S.MATRIZ[F][C+1]==0) && (S.MATRIZ[F][C+2]==0)&& (S.MATRIZ[F][C+1]==0)  && (S.MATRIZ[F][C+2]==0)  && (S.MATRIZ[F][C+3]==0)  && (S.MATRIZ[F-1][C+3]==0) && (S.MATRIZ[F-1][C+2]==0) && (S.MATRIZ[F-1][C+1]==0)  && (S.MATRIZ[F-1][C+0]==0)  && (S.MATRIZ[F-1][C-1]==0) && (S.MATRIZ[F][C-1]==0) && (S.MATRIZ[F+1][C-1]==0)  && (S.MATRIZ[F+2][C-1]==0) && (S.MATRIZ[F+2][C]==0)  && (S.MATRIZ[F+2][C+1]==0) && (S.MATRIZ[F+2][C+2]==0) && (S.MATRIZ[F+2][C+3]==0)  && (S.MATRIZ[F+1][C+3]==0)    )
				{
					S.MATRIZ[F][C]=  1;
					S.MATRIZ[F+1][C]=  1;
					S.MATRIZ[F][C+1]=1   ;
					S.MATRIZ[F+1][C+1]=  1;
					S.MATRIZ[F][C+2]=  1;
					S.MATRIZ[F+1][C+2]=  1;
        			*Se=S; return 1;
				}
				else if ((C<10) && (F<9) && (S.MATRIZ[F-1][C-1]==0) && (S.MATRIZ[F-1][C]==0) && (S.MATRIZ[F-1][C+1]==0) && (S.MATRIZ[F-1][C+2]==0) && (S.MATRIZ[F][C-1]==0) && (S.MATRIZ[F][C]==0) && (S.MATRIZ[F][C+1]==0) && (S.MATRIZ[F][C+2]==0) && (S.MATRIZ[F+1][C-1]==0) && (S.MATRIZ[F+1][C]==0) && (S.MATRIZ[F+1][C+1]==0) && (S.MATRIZ[F+1][C+2]==0) && (S.MATRIZ[F+2][C-1]==0) && (S.MATRIZ[F+2][C]==0) && (S.MATRIZ[F+2][C+1]==0) && (S.MATRIZ[F+2][C+2]==0) && (S.MATRIZ[F+3][C-1]==0) && (S.MATRIZ[F+3][C]==0) && (S.MATRIZ[F+3][C+1]==0) && (S.MATRIZ[F+3][C+2]==0))
                {
                    S.MATRIZ[F][C]=1;
					S.MATRIZ[F+1][C]=  1;
					S.MATRIZ[F][C+1]=  1;
					S.MATRIZ[F+1][C+1]=  1;
					S.MATRIZ[F+2][C]=  1;
					S.MATRIZ[F+2][C+1]=  1;
        			*Se=S; return 1;
                }
				//6v
				else if((S.MATRIZ[F+1][C]==0)  && (S.MATRIZ[F+2][C]==0)  && (S.MATRIZ[F+3][C]==0)  && (S.MATRIZ[F+4][C]==0)   && (S.MATRIZ[F+6][C]==0)     &&        (F<6) && (S.MATRIZ[F+1][C]==0) && (S.MATRIZ[F+2][C]==0 ) && (S.MATRIZ[F+3][C]==0)  && (S.MATRIZ[F+4][C]==0) && (S.MATRIZ[F+5][C]==0) && (S.MATRIZ[F+6][C]==0) && (S.MATRIZ[F+6][C+1]==0) && (S.MATRIZ[F+5][C+1]==0)&& (S.MATRIZ[F+4][C+1]==0) && (S.MATRIZ[F+3][C+1]==0) && (S.MATRIZ[F+2][C+1]==0) && (S.MATRIZ[F+1][C+1]==0) && (S.MATRIZ[F][C+1]==0) && (S.MATRIZ[F-1][C+1]==0) && (S.MATRIZ[F-1][C]==0) && (S.MATRIZ[F-1][C-1]==0) && (S.MATRIZ[F][C-1]==0) && (S.MATRIZ[F+1][C-1]==0) && (S.MATRIZ[F+2][C-1]==0) && (S.MATRIZ[F+3][C-1]==0) && (S.MATRIZ[F+4][C-1]==0) && (S.MATRIZ[F+5][C-1]==0) && (S.MATRIZ[F+6][C-1]==0))
                {
                	S.MATRIZ[F][C]=  1;
					S.MATRIZ[F+1][C]=  1;
					S.MATRIZ[F+2][C]=  1;
					S.MATRIZ[F+3][C]=  1;
					S.MATRIZ[F+4][C]=  1;
					S.MATRIZ[F+5][C]=  1;
        			*Se=S; return 1;
				}//6h
				else if((C<6) && (S.MATRIZ[F][C+1]==0) && (S.MATRIZ[F][C+2]==0) && (S.MATRIZ[F][C+3]==0) && (S.MATRIZ[F][C+4]==0)  && (S.MATRIZ[F][C+5]==0)     && (S.MATRIZ[F][C+1]==0) && (S.MATRIZ[F][C+2]==0 ) && (S.MATRIZ[F][C+3]==0)  && (S.MATRIZ[F][C+4]==0) && (S.MATRIZ[F][C+5]==0) && (S.MATRIZ[F][C+6]==0)&& (S.MATRIZ[F+1][C+6]==0) && (S.MATRIZ[F+1][C+5]==0) && (S.MATRIZ[F+1][C+4]==0) && (S.MATRIZ[F+1][C+3]==0) && (S.MATRIZ[F+1][C+2]==0) && (S.MATRIZ[F+1][C+1]==0) && (S.MATRIZ[F+1][C]==0) && (S.MATRIZ[F+1][C-1]==0) && (S.MATRIZ[F][C-1]==0) && (S.MATRIZ[F-1][C-1]==0) && (S.MATRIZ[F-1][C]==0) && (S.MATRIZ[F-1][C+1]==0) && (S.MATRIZ[F-1][C+2]==0) && (S.MATRIZ[F-1][C+3]==0) && (S.MATRIZ[F-1][C+4]==0)  && (S.MATRIZ[F-1][C+5]==0)&& (S.MATRIZ[F-1][C+6]==0))
                {
                	S.MATRIZ[F][C]=1;
					S.MATRIZ[F][C+1]=  1;
					S.MATRIZ[F][C+2]=  1;
					S.MATRIZ[F][C+3]=  1;
					S.MATRIZ[F][C+4]=1;
					S.MATRIZ[F][C+5]=1;
        			*Se=S; return 1;
				}
				}  // si e 6
// e 7

				if ((e==7) && S.MATRIZ[F][C]==0)
        		{
				if ((C<7) && (S.MATRIZ[F+1][C]==0) && (S.MATRIZ[F+1][C+1]==0) && (S.MATRIZ[F+1][C+2]==0)    && (F<9) && (S.MATRIZ[F][C+1]==0)  && (S.MATRIZ[F][C+2]==0)  && (S.MATRIZ[F][C+3]==0)  && (S.MATRIZ[F][C+4]==0)  && (S.MATRIZ[F-1][C+4]==0)   && (S.MATRIZ[F-1][C+3]==0) && (S.MATRIZ[F-1][C+2]==0) && (S.MATRIZ[F-1][C+1]==0)  && (S.MATRIZ[F-1][C+0]==0)  && (S.MATRIZ[F-1][C-1]==0) && (S.MATRIZ[F][C-1]==0) && (S.MATRIZ[F+1][C-1]==0)  && (S.MATRIZ[F+2][C-1]==0) && (S.MATRIZ[F+2][C]==0)  && (S.MATRIZ[F+2][C+1]==0) && (S.MATRIZ[F+2][C+2]==0) && (S.MATRIZ[F+2][C+3]==0)  && (S.MATRIZ[F+1][C+3]==0)  && (S.MATRIZ[F+1][C+4]==0)     )
				{
					S.MATRIZ[F][C]=1;
					S.MATRIZ[F+1][C]=  1;
					S.MATRIZ[F][C+1]=  1;
					S.MATRIZ[F][C+3]=  1;
					S.MATRIZ[F+1][C+1]=  1;
					S.MATRIZ[F][C+2]=  1;
					S.MATRIZ[F+1][C+2]=  1;
        			*Se=S; return 1;
				}
				else if( C<9 && F<9 && (S.MATRIZ[F-1][C-1]==0) && (S.MATRIZ[F-1][C]==0) && (S.MATRIZ[F-1][C+1]==0) && (S.MATRIZ[F-1][C+2]==0) && (S.MATRIZ[F-1][C+3]==0) && (S.MATRIZ[F][C-1]==0) && (S.MATRIZ[F][C]==0) && (S.MATRIZ[F][C+1]==0) && (S.MATRIZ[F][C+2]==0) && (S.MATRIZ[F][C+3]==0) && (S.MATRIZ[F+1][C-1]==0) && (S.MATRIZ[F+1][C]==0) && (S.MATRIZ[F+1][C+1]==0) && (S.MATRIZ[F+1][C+2]==0) && (S.MATRIZ[F+1][C+3]==0) && (S.MATRIZ[F+2][C-1]==0) && (S.MATRIZ[F+2][C]==0) && (S.MATRIZ[F+2][C+1]==0) && (S.MATRIZ[F+2][C+2]==0) && (S.MATRIZ[F+2][C+3]==0) && (S.MATRIZ[F+3][C-1]==0) && (S.MATRIZ[F+3][C]==0) && (S.MATRIZ[F+3][C+1]==0) && (S.MATRIZ[F+3][C+2]==0) && (S.MATRIZ[F+3][C+3]==0))
                {
                    S.MATRIZ[F][C]=1;
                    S.MATRIZ[F][C+1]=1;
                    S.MATRIZ[F][C+2]=1;
                    S.MATRIZ[F+1][C]=1;
                    S.MATRIZ[F+1][C+1]=1;
                    S.MATRIZ[F+1][C+2]=1;
                    S.MATRIZ[F+2][C]=1;
                    *Se=S; return 1;
                }
				else if( C<10 && F<8 && (S.MATRIZ[F-1][C-1]==0) && (S.MATRIZ[F-1][C]==0) && (S.MATRIZ[F-1][C+1]==0) && (S.MATRIZ[F-1][C+2]==0) && (S.MATRIZ[F][C-1]==0) && (S.MATRIZ[F][C]==0) && (S.MATRIZ[F][C+1]==0) && (S.MATRIZ[F][C+2]==0) && (S.MATRIZ[F+1][C-1]==0) && (S.MATRIZ[F+1][C]==0) && (S.MATRIZ[F+1][C+1]==0) && (S.MATRIZ[F+1][C+2]==0) && (S.MATRIZ[F+2][C-1]==0) && (S.MATRIZ[F+2][C]==0) && (S.MATRIZ[F+2][C+1]==0) && (S.MATRIZ[F+2][C+2]==0) && (S.MATRIZ[F+3][C-1]==0) && (S.MATRIZ[F+3][C]==0) && (S.MATRIZ[F+3][C+1]==0) && (S.MATRIZ[F+3][C+2]==0) && (S.MATRIZ[F+4][C-1]==0) && (S.MATRIZ[F+4][C]==0) && (S.MATRIZ[F+4][C+1]==0) && (S.MATRIZ[F+4][C+2]==0) )
                {
                    S.MATRIZ[F][C]=1;
                    S.MATRIZ[F][C+1]=1;
                    S.MATRIZ[F+1][C]=1;
                    S.MATRIZ[F+1][C+1]=1;
                    S.MATRIZ[F+2][C]=1;
                    S.MATRIZ[F+2][C+1]=1;
                    S.MATRIZ[F+3][C]=1;
        			*Se=S; return 1;
                }
				//7v
				else if((F<6) && (S.MATRIZ[F+6][C]==0) && (S.MATRIZ[F+1][C]==0) && (S.MATRIZ[F+2][C]==0 ) && (S.MATRIZ[F+3][C]==0)  && (S.MATRIZ[F+4][C]==0) && (S.MATRIZ[F+5][C]==0) && (S.MATRIZ[F+6][C]==0) && (S.MATRIZ[F+6][C+1]==0) && (S.MATRIZ[F+5][C+1]==0)&& (S.MATRIZ[F+4][C+1]==0) && (S.MATRIZ[F+3][C+1]==0) && (S.MATRIZ[F+2][C+1]==0) && (S.MATRIZ[F+1][C+1]==0) && (S.MATRIZ[F][C+1]==0) && (S.MATRIZ[F-1][C+1]==0) && (S.MATRIZ[F-1][C]==0) && (S.MATRIZ[F-1][C-1]==0) && (S.MATRIZ[F][C-1]==0) && (S.MATRIZ[F+1][C-1]==0) && (S.MATRIZ[F+2][C-1]==0) && (S.MATRIZ[F+3][C-1]==0) && (S.MATRIZ[F+4][C-1]==0) && (S.MATRIZ[F+5][C-1]==0) && (S.MATRIZ[F+6][C-1]==0))
                {
                	S.MATRIZ[F][C]=1;
					S.MATRIZ[F+1][C]=1;
					S.MATRIZ[F+2][C]=1;
					S.MATRIZ[F+3][C]=1;
					S.MATRIZ[F+4][C]=1;
					S.MATRIZ[F+5][C]=1;
					S.MATRIZ[F+6][C]=1;
        			*Se=S; return 1;
				}//7h
				else if((C<6) && (S.MATRIZ[F][C+6]==0) && (S.MATRIZ[F][C+1]==0) && (S.MATRIZ[F][C+2]==0 ) && (S.MATRIZ[F][C+3]==0)  && (S.MATRIZ[F][C+4]==0) && (S.MATRIZ[F][C+5]==0) && (S.MATRIZ[F][C+6]==0)&& (S.MATRIZ[F+1][C+6]==0) && (S.MATRIZ[F+1][C+5]==0) && (S.MATRIZ[F+1][C+4]==0) && (S.MATRIZ[F+1][C+3]==0) && (S.MATRIZ[F+1][C+2]==0) && (S.MATRIZ[F+1][C+1]==0) && (S.MATRIZ[F+1][C]==0) && (S.MATRIZ[F+1][C-1]==0) && (S.MATRIZ[F][C-1]==0) && (S.MATRIZ[F-1][C-1]==0) && (S.MATRIZ[F-1][C]==0) && (S.MATRIZ[F-1][C+1]==0) && (S.MATRIZ[F-1][C+2]==0) && (S.MATRIZ[F-1][C+3]==0) && (S.MATRIZ[F-1][C+4]==0)  && (S.MATRIZ[F-1][C+5]==0)&& (S.MATRIZ[F-1][C+6]==0))
                {
                	S.MATRIZ[F][C]=1;
					S.MATRIZ[F][C+1]=1;
					S.MATRIZ[F][C+2]=1;
					S.MATRIZ[F][C+3]=1;
					S.MATRIZ[F][C+4]=1;
					S.MATRIZ[F][C+5]=1;
					S.MATRIZ[F][C+6]=1;
        			*Se=S; return 1;
				}
				}  // si e 7
		}
 	}
 	return 0;
}

struct sala Anadir(struct sala S, int e)
{
    int posible=AsignarAsientos(&S,e);
    if(posible==0 && e>7)
    {
    	c=0;
        printf("No es posible añadir más de 7 personas para evitar aglomeraciones.\nDivida el grupo y vuelva a intentarlo.\n");
        printf("\nPersonas en cola de espera: %d \n", e);
           for(int cola=c;cola<e;cola++){//llenar cola de espera
        	   encolar(q, cola);
        	   c=c+1;
	       	}
          if(q.delante!=NULL) mostrarCola(q);
          printf("\n");
          printf("\n%d",c);
          p=c;
    }
    
    
    else if(posible==0)
    {
        printf("No es posible añadir este número de personas para evitar aglomeraciones.\n");
    }
    
    else if(p<=0){//validacion cuando no existan personas en cola
	
	printf("\nPersonas en cola de espera: %d\n",0);
	S.Asistentes=S.Asistentes+e;
    mostrarSala(S);
    	  
	}
    
    else if(c>0 && e<=7){//controlar ingreso de personas cuando estan en cola

	   printf("\nPersonas en cola de espera: %d\n",p-e);
	   p=e;
	   
	      if(p-e<0){//validar personas que entran menos salen negativo
	
	         printf("\nPersonas en cola de espera: %d\n",0);
             vaciarCola(q);
             if(q.delante!=NULL) mostrarCola(q);
		  	}
    
	  for(int cola=0;cola<c;cola++){
         cola = desencolar(q);
         p=p-1;//decremento personas que entran
	  }
	
	  printf("\nPersonas que entran: %d\n",e);

	 if(q.delante!=NULL) mostrarCola(q);
     printf("\n");
    
     AsignarAsientos(&S,p);
     S.Asistentes=S.Asistentes+e;
     mostrarSala(S);
     
     if(q.delante==NULL) vaciarCola(q);//controlar vaciado de cola
     
     }
     
    else
    {
        S.Asistentes=S.Asistentes+e;
        mostrarSala(S);
    }
    return S;
}



struct sala Quitar(struct sala S, int s)
{
    int F,C;
    S.Asistentes=S.Asistentes-s;
    
    if(p==0 || p-s<0){
	printf("\nPersonas en cola de espera: %d\n",0);
    vaciarCola(q);//controlar vaciado de cola
    if(q.delante!=NULL) mostrarCola(q);
		  
	}
	
	
	else if(p-s==0 && p>7){
		printf("No es posible añadir más de 7 personas para evitar aglomeraciones.\nDivida el grupo y vuelva a intentarlo.\n");	
     }
     
     
    else if(p-s>=7){
	 printf("No es posible añadir más de 7 personas para evitar aglomeraciones.\nDivida el grupo y vuelva a intentarlo.\n");	
	}
	
	
	else{

	   printf("\nPersonas en cola de espera: %d\n",p-s);
       printf("\nPersonas que salen: %d\n",s);
	 
	  for(int cola=0;cola<s;cola++){
         cola = desencolar(q);
         p=p-1;
	  }
	
	  printf("\nPersonas que entran: %d\n",s);

      printf("\n");
    
     AsignarAsientos(&S,s);
     S.Asistentes=S.Asistentes+s;
     
     }
	
	if (0>S.Asistentes)
	{
		S.Asistentes=0;
	}
	for(F=0;F<=10;F++)
    {
    	for(C=0;C<=10;C++)
    	{
            if ( s>0 && S.MATRIZ[F][C]==1){
                S.MATRIZ[F][C]=0;
                s--;
            }
            if(s==0){
                return S;
            }
    	}
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
    vaciarCola(q);
    return S;
};
