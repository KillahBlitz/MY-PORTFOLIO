#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y); 
void escribir();
int recopilador();

struct evaluacion
{
    char nombres[5][30];
    int edades[5];
    char boletas[5][20];
};

int main(){

system("color 03");
	escribir();
	recopilador();
		
system("PAUSE");
getch();
return(0);
}


int recopilador(){
    struct evaluacion n;

    for(int i=0; i<5; i++){
    cout<<"Ingrese nombre: "<<endl;
    cin>>n.nombres[i];
    cout<<"Ingrese edad: "<<endl;
    cin>>n.edades[i];
    cout<<"Ingrese boleta: "<<endl;
    cin>>n.boletas[i];
    }

	cout<<"NOMBRES:		EDADES:		BOLETAS:"<<endl;
    for(int i=0; i<5; i++){
    cout<<setiosflags(ios::left)
        <<setw(25)
        <<n.nombres[i];
    cout<<setiosflags(ios::left)
        <<setw(15)
        <<n.edades[i];
    cout<<setiosflags(ios::left)
        <<setw(30)
        <<n.boletas[i]
        <<endl;
    }

		getch();
}


void escribir(){
    gotoxy(45,11);cout<<"Instituto Politecnico Nacional";
    gotoxy(27,12);cout<<"Escuela Superior De Ingeneria Mecanica y Electrica UNIDAD CULHUACAN";
    gotoxy(44,13);cout<<"Monroy Cortines Jacobo Emiliano";
    gotoxy(43,14);cout<<"Programacion Orientada en Objetos";
    gotoxy(49,15);cout<<" Practica Numero 2A";
    gotoxy(51,16);cout<<"  Grupo 2CV32";
    gotoxy(45,17);cout<<"Profesor Osornio Soto Roberto \n\n";  
}



void gotoxy(int x, int y){
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}
