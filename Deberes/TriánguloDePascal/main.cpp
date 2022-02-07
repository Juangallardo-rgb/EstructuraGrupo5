#include <iostream>
#include <iomanip>
#include "Pascal.h"
using namespace std;
 


int main(int argc,char**argv){
	cout << "Ingrese un nivel del 1 al 12\n\n";
	while(cout << ("Ingrese Nivel: "),cin >> (nivel),nivel<1|nivel>tam);
	triangulo_pascal();
	cout << "\n\n";
	system("pause");
}
