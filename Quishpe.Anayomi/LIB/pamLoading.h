#include <iomanip>
#include <unistd.h>
#include <iostream>

using namespace std;
#define SLEEP 50000

string setBar(string c, int size)
{
    string str=""; 
    for (int i = 0; i < size; i++)
        str += c;
    return str;
}

void showFace()
{
     for (int i = 0; i < 15; i++)
     {
        cout << "\x1B[2J\x1B[H";
        string desplazar = setBar("  ",i);
        cout << "\r" << desplazar << "   \\|||/  " << endl;
        cout << "\r" << desplazar << "   (> <)   " << endl;
        cout << "\r" << desplazar << "ooO-(*)-Ooo" << endl;
        usleep(SLEEP*5);
     }
}

void showWaitingporcentaje()
{
    for (int i = 0; i <= 30; i++)
    {
    std::string str = "ooo";
        std::cout << "\r" << str.replace(i%3,1, "O") << " " << std::setw(3) << i << " % ";
        std::cout.flush();
        usleep(SLEEP*5);
    }
}

void showWaiting()  // *.*
{
    for (int i = 0; i <= 30; i++)
    {
        string str ="ooo"; 
        cout << "\r" << str.replace(i%3,1,"O") << " " ;
        usleep(SLEEP*5);
    }
}

void showLoadingSpinner()
{
    char c[] ="\\|/- ";
    for (int i = 0; i <= 100; i++)
    {   //<<fixed<<setprecision(3)    <<setfill('0') 
        cout << "\r" << c[i%5] << " " <<setw(3) <<i << " % ";
        usleep(SLEEP);
    }
}

void showBarLoading(int size)
{
    for (int i = 0; i <= 100; i++)
    {   
        cout << "\r[" << setBar("=", size).replace(i%size,1,"-") << "] " <<setw(3) <<i << " % ";
        usleep(SLEEP);
    }
}

void showWaitingLoading(int size)
{
    bool avanzar=false;
    for (int i = 0; i <= 100; i++)
    {   
        if(i%size==0)
            avanzar =!avanzar;
        int ix = (avanzar)? i%size: (size - i%size);
        cout << "\r[" << setBar(" ", size).replace(ix,0,"<>") << "] " <<setw(3) <<i << " % ";
        usleep(SLEEP);
    }
}

void showloadingName(char* nombre)
{
    int longitud = strlen(nombre);
    char imprimir[longitud + 1];
    
    for (int i = 0; i <= 100; i++)
    {
        int wordSize = (longitud * i) / 100;
        strncpy(imprimir, nombre, wordSize);
        imprimir[wordSize] = '\0';
        
        std::cout << imprimir << " " << i << "%\r";
        std::cout.flush();
        usleep(SLEEP);
    }
    std::cout << nombre << " 100%" << std::endl;
}

std::string convertirMayusculas(const std::string& texto) 
{
    std::string resultado = texto;
    for (char& c : resultado) 
    {
        c = std::toupper(c);
    }
    return resultado;
}

std::string convertirMinusculas(const std::string& texto) 
{
    std::string resultado = texto;
    for (char& c : resultado) 
    {
        c = std::tolower(c);
    }
    return resultado;
}

void moverElementos(int FILAS = 4, int COLUMNAS = 1) 
{
    int matriz1[FILAS][COLUMNAS];
    int matriz2[FILAS][COLUMNAS];
    int indice_origen1;
    int indice_origen2;
    int indice_destino1;
    int indice_destino2;
    matriz2[indice_destino1][0] = matriz1[indice_origen1][0];
    matriz2[indice_destino2][0] = matriz1[indice_origen2][0];
    matriz1[indice_origen1][0] = 0;
    matriz1[indice_origen2][0] = 0;
}




