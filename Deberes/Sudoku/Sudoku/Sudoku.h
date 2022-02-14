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
#if !defined(__Sudoku_Sudoku_h)
#define __Sudoku_Sudoku_h

class Sudoku
{
public:
   Sudoku();
   ~Sudoku();
   bool jugar(int fila, int columna, int dato);
   int obtenerResto(void);
   void imprimir(void);

protected:
private:
   int resto;
   int **matriz;


};

#endif
