/*
	UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
	SUDOKU
	Autores: Gallardo Juan, Naspud Camila
	Fecha de Creación:		08/06/2021
	Fecha de modificacion:	08/06/2021
	Docente: 				Ing. Fernando Solis
	Carrera: 				Ingenieria de Software
	Asignatura:             Estructura de Datos
*/
#include <iostream>
#include "Sudoku.h"

using namespace std;


////////////////////////////////////////////////////////////////////////
// Name:       Sudoku::Sudoku()
// Purpose:    Implementation of Sudoku::Sudoku()
// Return:     
////////////////////////////////////////////////////////////////////////

Sudoku::Sudoku()
{
	matriz = new int *[9];
	for(int i=0;i<9;i++){
		matriz[i]=new int[9];
		for(int j=0;j<9;j++){
			matriz[i][j]=0;
		}
	}
	resto = 9*9;
}

////////////////////////////////////////////////////////////////////////
// Name:       Sudoku::~Sudoku()
// Purpose:    Implementation of Sudoku::~Sudoku()
// Return:     
////////////////////////////////////////////////////////////////////////

Sudoku::~Sudoku()
{
	for(int i=0;i<9;i++){
		delete[] matriz[i];
	}
	delete[] matriz;
}

////////////////////////////////////////////////////////////////////////
// Name:       Sudoku::jugar(int fila, int columna, int dato)
// Purpose:    Implementation of Sudoku::jugar()
// Parameters:
// - fila
// - columna
// - dato
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool Sudoku::jugar(int fila, int columna, int dato)
{
	fila+1;
	columna+1;
	//Borra un número ingresado
	if(dato==0){
		if(matriz[fila][columna] !=0){
			resto++;
			matriz[fila][columna] = 0;
			return true;
		}
	}
	//Verifica si el espacio esta ocupado
	if(matriz[fila][columna] !=0 ){
		return false;
	}
	//Verifica si existe en Fila/Colmuna
	for(int i=0;i<9;i++){
		if(dato == matriz[fila][i]){
			return false;
		}
		if(dato == matriz[i][columna]){
			return false;
		}
	}
	//Verifica si existe en el cuadrante
	int filaCuadrante = fila/3;
	int columnaCuadrante = columna/3;
	for(int i= filaCuadrante+3; i<3;i++){
		for(int j = columnaCuadrante; j<columnaCuadrante+3; j++){
			if(dato==matriz[i][j]){
				return false;
			}
		}
	}
	matriz[fila][columna] = dato;
	resto --;
	return true;
}

////////////////////////////////////////////////////////////////////////
// Name:       Sudoku::getResto()
// Purpose:    Implementation of Sudoku::getResto()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Sudoku::obtenerResto(void)
{
   return resto;
}

////////////////////////////////////////////////////////////////////////
// Name:       Sudoku::imprimir()
// Purpose:    Implementation of Sudoku::imprimir()
// Return:     void
///////////////////////////
/////////////////////////////////////////////
void Sudoku::imprimir(void)
{
	for(int i=0;  i<9; i++){
		if(i%3==0){
			for(int j=0;j<9;j++){
				if(j%3==0){
					cout<<"+-";
				}
				cout<<"--";
			}
			cout<<"+\n";
		}
		for(int j=0;j<9;j++){
			if(j%3==0){
				cout<<"| ";
			}
			if(matriz[i][j]==0){
				cout<<".";
			}
			else{
				cout<<matriz[i][j];
			}
			cout<<" ";
		}
		cout<<"|\n";
	}
	for(int j=0;j<9;j++){
		if(j%3==0){
			cout<<"+-";
		}
		cout<<"--";
	}
	cout<<"+\n";
}
