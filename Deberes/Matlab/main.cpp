#include <iostream> //comandos de entrada y salida
#include<fstream> // gestionar archivos
#include<math.h> //operaciones matematicas
#include <time.h>  
#include <math.h> 
#include <ctime> 


using namespace std;

int main(int argc, char** argv) 
{
	//array unidimensional 
	float valorx[1000];
	//generar variable para rchivo
	ofstream file;
	//abrir y nombrar el archivo de texto
	file.open("TiempoDeEjecucion.txt");
	//evaluar la funcion x
	//declarar un ciclo for con el rango para evaluar la funcion 
	for(int i = 0; i<1000; i++)
	{
		valorx[i]=i;
		cout<<i<<"\t"<<valorx[i]<<endl;
		file<<i<<"\t"<<valorx[i]<<endl;
	}
	file.close(); 
	
	//return 0;
}
