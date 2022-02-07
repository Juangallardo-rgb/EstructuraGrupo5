#include <iostream>
#include <iomanip>
using namespace std;
 

const int tam=12;

int draw=38,nivel=0; int matriz[tam][tam+1];
 
	
	void triangulo_pascal()
	{
		for(int i=0;i<nivel;i++)
		{
			 matriz[i][0] = 1;matriz[i][i+1] = 1;
				cout << "\n\n" << setw(draw-i*2);
			for(int j=0;j<i+2;j++)
			{
				matriz[i+1][j+1] = matriz[i][j] + matriz[i][j+1];
					cout << matriz[i][j] << setw(4);
			}
		}
	}
