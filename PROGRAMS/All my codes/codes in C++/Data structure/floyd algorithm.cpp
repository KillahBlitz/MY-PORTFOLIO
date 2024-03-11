#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <windows.h>

using namespace std;

const int MAX_NODOS = 50;

void floyds(int m, int MatrizA[MAX_NODOS][MAX_NODOS], char MatrizD[MAX_NODOS][MAX_NODOS], char Nom[MAX_NODOS]) {
    for (int k = 0; k < m; k++) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (MatrizA[i][k] + MatrizA[k][j] < MatrizA[i][j]) {
                    MatrizA[i][j] = MatrizA[i][k] + MatrizA[k][j];
                    MatrizD[i][j] = Nom[k];
                }
            }
        }
    }
}

void mostrarCamino(int origen, int destino, char MatrizD[MAX_NODOS][MAX_NODOS], char Nom[MAX_NODOS], int MatrizA[MAX_NODOS][MAX_NODOS]) {
    if (MatrizD[origen][destino] == '*') {
        cout << "No hay camino entre " << Nom[origen] << " y " << Nom[destino] << endl;
    } else {
        vector<char> camino;
        int i = origen;
        int j = destino;

        while (i != j) {
            camino.push_back(Nom[j]);
            j = find(Nom, Nom + MAX_NODOS, MatrizD[i][j]) - Nom;
            i = j;  // Agrega esta línea para actualizar el valor de i
        }

        camino.push_back(Nom[i]);
        reverse(camino.begin(), camino.end());

        cout << "El camino más corto entre " << Nom[origen] << " y " << Nom[destino] << " es: ";
        for (size_t k = 0; k < camino.size(); k++) {
            cout << camino[k] << " ";
        }
        cout << "\nLa distancia es: " << MatrizA[origen][destino] << endl;
    }
}







void gotoxy(int x, int y){
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

void escribir(){
    gotoxy(45,11);cout<<"Instituto Politecnico Nacional";
    gotoxy(27,12);cout<<"Escuela Superior De Ingeneria Mecanica y Electrica UNIDAD CULHUACAN";
    gotoxy(47,13);cout<<"Cruz Hernandez William";
    gotoxy(44,14);cout<<"Monroy Cortines Jacobo Emiliano";
    gotoxy(44,15);cout<<"San Pedro Texis Emanuel Tristan";
    gotoxy(50,16);cout<<"Estructura de Datos";
    gotoxy(46,17);cout<<"PROYECTO: CONSULTA DE RUTAS ";
    gotoxy(51,18);cout<<"  Grupo 2CV35 \n\n";
}

void instrucciones(){
    gotoxy(45,11);cout<<"Instrucciones";
    gotoxy(37,12);cout<<"Abreviar los puntos de interes con maximo 3 letras";
    gotoxy(37,13);cout<<"Si no hay conexion marcarlo con 999";
    gotoxy(37,14);cout<<"Se pueden realizar varias consultas";
}






int main() {
    char continuar = 'S';
        int m, MatrizA[MAX_NODOS][MAX_NODOS];
        char MatrizB[MAX_NODOS][MAX_NODOS] = {}, MatrizD[MAX_NODOS][MAX_NODOS];
        char Nom[MAX_NODOS] = {};

		system("Title DISTANCIA DE RUTAS");
		system("COLOR 0D");
    	escribir();
    	getch();
    	system("cls");
    	instrucciones();
    	getch();
    	system("cls");
    	
    	
        cout << "\t\tMatrices de Floyd:\n\n";
        cout << "Cuantos rutas de interes desea ingresar? ";
        cin >> m;

        cout << "\tNombrar las rutas de interes con Abreviaciones: \n";
        for (int i = 0; i < m; i++) {
            cout << "\trutas de interes numero " << i + 1 << " es: ";
            cin >> Nom[i];
        }

        cout << "Define las distancias: \n";
        cout << "Si no hay conexion en la ruta, coloca 999 \n\n";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (i == j)
                    MatrizA[i][j] = 0;
                else {
                    cout << "Ingresa la distancia en el punto " << Nom[i] << " y " << Nom[j] << ": ";
                    cin >> MatrizA[i][j];
                }
            }
            printf("\n\n");
        }

        cout << "La matriz de distancias es \n";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                cout << "[" << setw(3) << MatrizA[i][j] << " ]";
            }
            cout << "\n";
        }

        // Inicializar la matriz D con las letras correspondientes y poner asteriscos en la diagonal principal
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (i == j) {
                    MatrizD[i][j] = '*';
                } else {
                    MatrizD[i][j] = Nom[j]; // Inicializar con las letras de la columna correspondiente
                }
            }
        }

        // La matriz B
        cout << "La matriz de recorrido es: \n";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                cout << "[" << setw(3) << Nom[j] << " ]";
            }
            cout << endl;
        }

        // La matriz C
        cout << "La matriz con algoritmo de Floyd es: \n";
        floyds(m, MatrizA, MatrizD, Nom);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                cout << "[ " << setw(3) << MatrizA[i][j] << " ]";
            }
            cout << "\n";
        }

        // Matriz de letras
        cout << "La matriz las rutas de interes es: \n";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                cout << "[ " << setw(3) << MatrizD[i][j] << " ]";
            }
            cout << "\n";
        }
        
		while (continuar == 'S' || continuar == 's') {
        // Solicitar camino
        int origen, destino;
        cout << "Ingrese las ruta de interes de origen (1-" << m << "): ";
        cin >> origen;
        cout << "Ingrese las ruta de interes destino (1-" << m << "): ";
        cin >> destino;

        mostrarCamino(origen - 1, destino - 1, MatrizD, Nom, MatrizA);

        // Preguntar al usuario si desea realizar otra consulta
        cout << "Â¿Desea realizar otra consulta? (S/N): ";
        cin >> continuar;
        
    }

    return 0;
}
