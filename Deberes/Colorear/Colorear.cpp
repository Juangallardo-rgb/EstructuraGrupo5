#include <iostream> 
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#define dimension 10

using namespace std;

vector<vector<int> > file(const char*); 

class Sudoku
{
private:
    struct nodo
    {
        int data; 
        nodo *vecinos_fila[dimension]; 
        nodo *vecinos_columna[dimension];
        nodo *vecinos_zona[((dimension/2) * (dimension/2) - (dimension-1))]; 
        bool modificado; 
        bool borde; 
    };
    vector<vector<nodo> > tablero;  
    int colores[dimension]; 
    void cargarColores() 
    {
        for (int i = 1; i <= dimension; i++)
        {
            colores[i - 1] = i;
        }
    }

    void cargarFila(nodo *temp, int fila, int columna)
    {
        
        for (int i=0,j = 0; i < dimension; i++)
        {
            if(columna != i)
              temp->vecinos_fila[j++] = &tablero[fila][i];
             
        }
        
    }
    
    void cargarColum(nodo *temp, int fila, int columna){
        
        for (int i=0, j = 0; i < dimension; i++)
        {
            if(fila != i){
                temp->vecinos_columna[j++] = &tablero[i][columna];
            } 
        }
        
    }
    void cargarZona(nodo *temp, int fila, int columna){
        if (columna != dimension-1 && fila != dimension-1)
        {
            if(fila %2 == 0){
                if (columna%2 == 0)
                {
                    temp->vecinos_zona[0] = &tablero[fila+1][columna+1];    
                }else
                {
                    temp->vecinos_zona[0] = &tablero[fila+1][columna-1];
                }
            }else
            {
                if (columna %2 == 0)
                {
                    temp->vecinos_zona[0] = &tablero[fila-1][columna+1];        
                }else
                {
                    temp->vecinos_zona[0] = &tablero[fila-1][columna-1];
                }
                
                
                
            }
            
        }else{
            temp->borde = true;
            if(fila %2 == 0){
                temp->vecinos_zona[0] = &tablero[fila+1][columna-1];    
            }else
            {
                temp->vecinos_zona[0] = &tablero[fila-1][columna-1];    
            }
        }
        
    }
    void imprimir_tablero(vector<vector<nodo> > Matriz_Tablero){
        for (int i = 0; i < dimension; i++)
        {
            for (int j = 0; j < dimension; j++)
            {
                cout << Matriz_Tablero[i][j].data << "\t";
            }
            cout << endl;
        }
    }
    
    int colorear(nodo aColorear, int indColor){
        
        if(indColor > dimension-1 ){ 
            return -1; 
        }else
        {
            int color = colores[indColor]; 
            int bandFila = 0,bandColum = 0,bandZona = 0; 
            if (aColorear.borde == true ) 
            {
                bandZona = dimension-1; 
            }else
            {
                if (aColorear.vecinos_zona[0]->data != color) 
                { 
                    bandZona = dimension-1; 
                }else
                    bandZona = -1;
            }

            if (bandZona != -1) 
            {
                for (int i = 0; i < dimension - 1; i++)
                {
                    if (aColorear.vecinos_fila[i]->data != color) 
                    {
                        bandFila++; 
                    }
                    else
                    {
                        break; 
                    }

                    if (aColorear.vecinos_columna[i]->data != color) 
                    {
                        bandColum++;
                    }
                    else
                    {
                        break; 
                    }
                }  
            }
            if (bandFila == dimension - 1 && bandColum == dimension - 1 && bandZona == dimension - 1)
            {
                return color; 
            }
            else
            {
                indColor++;
                return colorear(aColorear, indColor); 
            }
        } 
    }
public:
    Sudoku(vector<vector<int> > );
    void cargarDatos(){
        
        for (int i = 0; i < dimension; i++)
        {
            for (int j = 0; j < dimension; j++)
            {
                cargarFila(&tablero[i][j],i,j);
                cargarColum(&tablero[i][j],i,j);
                cargarZona(&tablero[i][j],i,j);
            }
        }
       
    }
    int resolver(){
        bool band=0;
       for (int i = 0; i < dimension; i++)
       {
           for (int j = 0; j < dimension; j++)
           {
               if (tablero[i][j].data == 0)
               {
                   tablero[i][j].data = colorear(tablero[i][j],0);
                   if (tablero[i][j].data == -1)
                   {
                       band = 1;
                       break;
                   }
                   
               }
           }
           if(band == 1){
               break;
           }
       }
       if (band == 1)
       {
           cout << "No se pudo resolver el SUDOKU" << endl;
       }
       else
       {
           cout << "Tablero Resuelto" << endl;
           imprimir_tablero(tablero);
       }
   }
    ~Sudoku();
};

Sudoku::Sudoku(vector<vector<int> > Matriz_Tablero)
{
    cargarColores(); 
    tablero.resize(dimension); 
    for (int i = 0; i < dimension; ++i)
        tablero[i].resize(dimension);
    
    for (int i = 0; i < dimension; i++) 
    {
        for (int j = 0; j < dimension; j++)
        {
            tablero[i][j].data = Matriz_Tablero[i][j];
            
        } 
        cout<<endl;
    }
    
    cout<<endl<<"Tablero Orgininal (cero representa celdas vacias)"<<endl;
    imprimir_tablero(tablero);
}

Sudoku::~Sudoku(){
    
}

int main(){
    
    
    vector<vector<int> > Matriz_Tablero;           
    Matriz_Tablero.resize(dimension); 
    for (int i = 0; i < dimension; ++i)
        Matriz_Tablero[i].resize(dimension); 

    Matriz_Tablero = file("puntos.txt"); 
    Sudoku juego(Matriz_Tablero); 
    juego.cargarDatos(); 
    juego.resolver();
return 0;
}

vector<vector<int> > file(const char* name_file){
    
    ifstream fs;
    fs.open(name_file); 
    int numero;
    vector<vector<int> > Matriz_Tablero;        
    Matriz_Tablero.resize(dimension); 
    for (int i = 0; i < dimension; ++i)
        Matriz_Tablero[i].resize(dimension); 

    string line,line2;
    
    if (fs.is_open()) 
    {
        cout<<"El archivo esta abierto"<<endl;
        int j=0;
        while (!fs.eof())
        {
            getline(fs, line); 
            istringstream iss(line);
            for (int i = 0; i < dimension; i++)
            {
                if (iss >> numero)
                {
                    Matriz_Tablero[j][i] = numero;
                }
            }
            j++;
        }
        for (int i = 0; i < dimension; i++)
        {
            for (int j = 0; j < dimension; j++)
            {
                cout << Matriz_Tablero[i][j] << "\t";
            }
            cout << endl;
        }
        
        fs.close();
    }else{
        cout<<"Error al abrir el archivo"<<endl;
    }

    return Matriz_Tablero;
    
}


