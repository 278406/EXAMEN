#include <iostream>
#include <string>
#include <cctype>
#include "../LIB/pamLoading.h"
#include "../LIB/pamColor.h"
const int FILAS = 4;
const int COLUMNAS = 1;
#define SLEEP 50000

const std::string CEDULA = "1752115418";
const std::string NOMBRE = "Anayomi Pamela Quishpe Tnadayamo";
const std::string CORREO = "anayomi.quishpe@epn.edu.ec";

bool ppLogin() 
{
    setTextColor(textColorCyan);
    const int MAX_INTENTOS = 3;
    int intentos = 0;
    
    std::cout << "Cedula: " << CEDULA << std::endl;
    setTextColor(textColorBlue);
    std::string nombreMayusculas = convertirMayusculas(NOMBRE);
    std::cout << "Nombre: " << nombreMayusculas << std::endl;
    setTextColor(textColorWhite);
    std::string correoMinusculas = convertirMinusculas(CORREO);
    std::cout << "Correo: " << correoMinusculas << std::endl;
    std::string usuario;
    std::string clave;
    
    while (intentos < MAX_INTENTOS) 
    {
        setTextColor(textColorGreen);
        std::cout << "Usuario: ";
        std::cin >> usuario;
        setTextColor(textColorRed);
        std::cout << "Clave: ";
        std::cin >> clave;
        
        if ((usuario == "<SuCorreoElectronico>" && clave == "<SuCedula>") || (usuario == "profe" && clave == "1234")) {
            std::cout << "¡:: Bienvenido " << std::toupper(usuario[0]) << usuario.substr(1) << "!" << std::endl;
            return true;
        } else {
            intentos++;
            int intentosRestantes = MAX_INTENTOS - intentos;
            setTextColor(textColorRed);
            std::cout << "Usuario o clave incorrectos. Intentos restantes: " << intentosRestantes << std::endl;
        }
    }
    
    std::cout << "Lo sentimos, tu usuario y clave son incorrectos..!" << std::endl;
    std::cout << "Gracias" << std::endl;
    
    return false;
}
void moverElementos(int matriz1[FILAS][COLUMNAS], int matriz2[FILAS][COLUMNAS], int indice_origen1, int indice_origen2, int indice_destino1, int indice_destino2) 
{
    setTextColor(textColorYellow);
    matriz2[indice_destino1][0] = matriz1[indice_origen1][0];
    matriz2[indice_destino2][0] = matriz1[indice_origen2][0];
    matriz1[indice_origen1][0] = 0;
    matriz1[indice_origen2][0] = 0;
}

int main() 
{
    if (ppLogin()) 
    {
        setTextColor(textColorYellow);
    std::cout << "\nSabiendo que:\n"
              << "Observador  = 1\n"
              << "Caperusita  = 2\n"
              << "Lobo        = 3\n"
              << "Uva         = 4\n";

    int matriz1[FILAS][COLUMNAS] = {{1},
                                    {2},
                                    {3},
                                    {4}};

    int matriz2[FILAS][COLUMNAS] = {{0},
                                    {0},
                                    {0},
                                    {0}};
                                    
    int indice_origen1;
    int indice_origen2;
    int indice_destino1;
    int indice_destino2;

    std::cout << "Ingrese el número del primer elemento de origen (1 a 4): ";
    std::cin >> indice_origen1;

    std::cout << "Ingrese el número del segundo elemento de origen (1 a 4): ";
    std::cin >> indice_origen2;

    std::cout << "Ingrese el número del primer elemento de destino (1 a 4): ";
    std::cin >> indice_destino1;

    std::cout << "Ingrese el número del segundo elemento de destino (1 a 4): ";
    std::cin >> indice_destino2; 

    moverElementos(matriz1, matriz2, indice_origen1 - 1, indice_origen2 - 1, indice_destino1 - 1, indice_destino2 - 1);
    
    std::cout << "\nMatriz 1:\n";
    for (int i = 0; i < FILAS; i++) 
    {
        std::cout << matriz1[i][0] << std::endl;
    }
    
    usleep(SLEEP); 

    for (int i = 0; i < 10; i++) 
    {
        system("clear"); 
        
        std::cout << "\nMatriz 1:\n";
        for (int j = 0; j < FILAS; j++) 
        {
            if (j == i)
                std::cout << "   "; 
            else
                std::cout << matriz1[j][0] << std::endl;
        }
        
        std::cout << "\nMatriz 2:\n";
        for (int j = 0; j < FILAS; j++) 
        {
            if (j == i)
                std::cout << matriz1[indice_origen1 - 1][0] << std::endl; 
            else
                std::cout << matriz2[j][0] << std::endl;
        }
        
        usleep(SLEEP); 
    }

    }
    
    return 0;
}

