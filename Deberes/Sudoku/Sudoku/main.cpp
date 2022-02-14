/*
	UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
	SUDOKU
	Autores: Gallardo Juan, Naspud Camila
	Fecha de Creación:		13/02/2021
	Fecha de modificacion:	14/02/2021
	Docente: 				Ing. Fernando Solis
	Carrera: 				Ingenieria de Software
	Asignatura:             Estructura de Datos
*/

#include <iostream>
#include "Sudoku.h"

using namespace std;

int main() {
	Sudoku* s1 = new Sudoku();
	int fila, columna, dato;
	while(s1->obtenerResto()>0){
		s1->imprimir();
		cout<<"Ingrese el numero de la fila, columna y dato (entre el 1 y 9)";
		cin>>fila>>columna>>dato;
		if(fila>=1 && fila <=9 && columna>=1 && columna <=9){
			if(!s1->jugar(fila-1,columna-1,dato)){
				cout<<"Jugada incorrecta"<<endl;
			}
		}
		else{
			cout<<"Jugada Ilegal"<<endl;
		}
	}
	
	return 0;
}
