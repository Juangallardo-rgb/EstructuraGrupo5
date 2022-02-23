#include<iostream>
#include<string.h>
using namespace std;

//Al cambiar a la derecha, el bit alto debe llenarse con ceros, no el bit de signo
#define shift(x, n) (((x) << (n)) | ((x) >> (32-(n))))
#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))
#define A 0x67452301
#define B 0xefcdab89
#define C 0x98badcfe
#define D 0x10325476

//Longitud de strBaye
unsigned int strlength;

//Variables temporales: A,B,C,D 
unsigned int atemp;
unsigned int btemp;
unsigned int ctemp;
unsigned int dtemp;


//arreglo de caracteres hexadecimales 
const unsigned int k[]={
        0xd76aa478,0xe8c7b756,0x242070db,0xc1bdceee,
        0xf57c0faf,0x4787c62a,0xa8304613,0xfd469501,0x698098d8,
        0x8b44f7af,0xffff5bb1,0x895cd7be,0x6b901122,0xfd987193,
        0xa679438e,0x49b40821,0xf61e2562,0xc040b340,0x265e5a51,
        0xe9b6c7aa,0xd62f105d,0x02441453,0xd8a1e681,0xe7d3fbc8,
        0x21e1cde6,0xc33707d6,0xf4d50d87,0x455a14ed,0xa9e3e905,
        0xfcefa3f8,0x676f02d9,0x8d2a4c8a,0xfffa3942,0x8771f681,
        0x6d9d6122,0xfde5380c,0xa4beea44,0x4bdecfa9,0xf6bb4b60,
        0xbebfbc70,0x289b7ec6,0xeaa127fa,0xd4ef3085,0x04881d05,
        0xd9d4d039,0xe6db99e5,0x1fa27cf8,0xc4ac5665,0xf4292244,
        0x432aff97,0xab9423a7,0xfc93a039,0x655b59c3,0x8f0ccc92,
        0xffeff47d,0x85845dd1,0x6fa87e4f,0xfe2ce6e0,0xa3014314,
        0x4e0811a1,0xf7537e82,0xbd3af235,0x2ad7d2bb,0xeb86d391};
        
        
//N�mero de cambios a la izquierda.
const unsigned int s[]={7,12,17,22,7,12,17,22,7,12,17,22,7,
        12,17,22,5,9,14,20,5,9,14,20,5,9,14,20,5,9,14,20,
        4,11,16,23,4,11,16,23,4,11,16,23,4,11,16,23,6,10,
        15,21,6,10,15,21,6,10,15,21,6,10,15,21};
        
const char str16[]="0123456789abcdef";//cadena de de 16 car�cteres b�sicos hexadecimales


void mainLoop(unsigned int M[])//bucle principal para MD5
{
    unsigned int f,g;
    unsigned int a=atemp;
    unsigned int b=btemp;
    unsigned int c=ctemp;
    unsigned int d=dtemp;
    for (unsigned int i = 0; i < 64; i++){
        if(i<16){
            f=F(b,c,d);
            g=i;
        }else if (i<32)
        {
            f=G(b,c,d);
            g=(5*i+1)%16;
        }else if(i<48){
            f=H(b,c,d);
            g=(3*i+5)%16;
        }else{
            f=I(b,c,d);
            g=(7*i)%16;
        }
        unsigned int tmp=d;
        d=c;
        c=b;
        b=b+shift((a+f+k[i]+M[g]),s[i]);
        a=tmp;
    }
    atemp=a+atemp;
    btemp=b+btemp;
    ctemp=c+ctemp;
    dtemp=d+dtemp;
}
/*
*Funci�n de relleno 
*Despu�s del procesamiento, se deben cumplir los bits = 448 (mod512), y bytes = 56 (modo64)
*El m�todo de llenado es agregar un 1 primero y agregar ceros a otros bits
*Finalmente agregue la longitud original de 64 bits
*/
unsigned int* add(string str)
{
    unsigned int num=((str.length()+8)/64)+1;//Con 512 bits, 64 bytes como grupo
    unsigned int *strByte=new unsigned int[num*16];    //64/4=16, entonces hay 16 enteros
    strlength=num*16;
    for (unsigned int i = 0; i < num*16; i++)
        strByte[i]=0;
    for (unsigned int i=0; i <str.length(); i++)
    {
        strByte[i>>2]|=(str[i])<<((i%4)*8);//Un entero almacena cuatro bytes., i>>2 medio i/4 y un int sin signo corresponde a 4 Bytes, 
		//guardar 4 caracteres de informaci�n
    }
    strByte[str.length()>>2]|=0x80<<(((str.length()%4))*8);//Agregue 1 al final y un int sin cifrar, guarda 4 caracteres de informaci�n, 
	//as� que use 128, Mover a la izquierda 
    /*
    *Agregue la longitud original, la longitud se refiere a la longitud del bit, por lo que debe multiplicarse por 8, 
	y se coloca en el penultimo elemento, aqui la longitud es de solo 32 bits
    */
    strByte[num*16-2]=str.length()*8;
    return strByte;
}

//funci�n para manejar caracteres hexadecimales
string changeHex(int a)
{
    int b;
    string str1;
    string str="";
    for(int i=0;i<4;i++)
    {
        str1="";
        b=((a>>i*8)%(1<<8))&0xff;   //Procesar cada byte en orden inverso 
        for (int j = 0; j < 2; j++)
        {
            str1.insert(0,1,str16[b%16]);
            b=b/16;
        }
        str+=str1;
    }
    return str;
}

//funci�n para aplicar el algoritmo MD5
string getMD5(string source)
{
    atemp=A;    //inicializaci�n de las variables temporales
    btemp=B;
    ctemp=C;
    dtemp=D;
    unsigned int *strByte=add(source);
    for(unsigned int i=0;i<strlength/16;i++)
    {
        unsigned int num[16];
        for(unsigned int j=0;j<16;j++)
            num[j]=strByte[i*16+j];
        mainLoop(num);
    }
    return changeHex(atemp).append(changeHex(btemp)).append(changeHex(ctemp)).append(changeHex(dtemp));
}

