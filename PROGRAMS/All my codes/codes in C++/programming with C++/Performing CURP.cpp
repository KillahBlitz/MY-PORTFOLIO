#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <windows.h>


struct Alumno {
    string nombre;
    string apellidoPaterno;
    string apellidoMaterno;
    float calificacion1;
    float calificacion2;
    float calificacion3;
    string entidadFederativa;
    char sexo;
    string fechaNacimiento;
    string curp;
    float promedio;
    Alumno* siguiente;
    Alumno* anterior;
};

struct Nodo {
    int dato;
    Nodo* siguiente;
    Nodo* anterior;
};



void gotoxy(int x, int y);
void escribir();




using namespace std;


int main() {
    int opcion;
    
        system("Title CURP Consulta");
		system("COLOR 0D");
    	escribir();
    	getch();
    	system("cls");
	
    do {

    	
    	
    	
        cout << "\nMenu de Operaciones:" << endl;
        cout << "1. Generar CURP" << endl;
        cout << "2. Obtener Promedio" << endl;
        cout << "3. Buscar por Nombre y Apellido" << endl;
        cout << "4. Buscar por CURP" << endl;
        cout << "5. Ordenar por Promedio" << endl;
        cout << "6. Agregar Alumno" << endl;
        cout << "7. Eliminar Alumno" << endl;
        cout << "8. Salir" << endl;

        cout << "Ingrese la opcion deseada: ";
        cin >> opcion;

        switch (opcion) {
            case 1: 
				break; 
            case 2:
                break;
            case 3: 
                break;
            case 4: 
                break;
            case 5:
                break;
            case 6:
                break;
            case 7: 
                break;
            case 8:
                break;
            default:
            	system("cls");
                gotoxy(40,13);cout << "Operacion Por favor, elija una opcion del 1 al 8." << endl;
                getch();
                system("cls");
        }
    } while (opcion != 8);

    return 0;
}

void escribir(){
    gotoxy(45,11);cout<<"Instituto Politecnico Nacional";
    gotoxy(27,12);cout<<"Escuela Superior De Ingeneria Mecanica y Electrica UNIDAD CULHUACAN";
    gotoxy(47,13);cout<<"Cruz Hernandez William";
    gotoxy(44,13);cout<<"Monroy Cortines Jacobo Emiliano";
    gotoxy(44,13);cout<<"San Pedro Texis Emanuel Tristan";
    gotoxy(50,14);cout<<"Estructura de Datos";
    gotoxy(46,15);cout<<"PROYECTO: CONSULTA DE CURP ";
    gotoxy(51,16);cout<<"  Grupo 2CV35 \n\n";
}

void gotoxy(int x, int y){
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}
