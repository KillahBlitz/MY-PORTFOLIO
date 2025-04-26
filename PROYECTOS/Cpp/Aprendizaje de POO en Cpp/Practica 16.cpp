#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<iomanip>
#include<windows.h>
#include<conio.h>
#include<string.h>

using namespace std;

class Agenda{
	private:
		char nombre[30];
		char num_telefonico[15];
	public:
		void pedir(Agenda *);
};

void Agenda::pedir(Agenda *registro){
	cout<<"Introduzca un nombre: ";
	cin.getline(registro->nombre,30);
	cout<<"Introduzca el numero telefonico";
	cin.getline(registro->num_telefonico,15);
	cout<<"\nEl contenido del registro recien creado es: "<<"\nNombre: "<<registro->nombre<<"\nNumero telefonico: "<<registro->num_telefonico<<endl;

return;	
}

void gotoxy(int x, int y); 
void escribir();


int main(){
	
	system("COLOR 03");
	escribir();
	getch();
	system("cls");
	Beep(500, 100);
	
	Agenda *nuevo;
	
	nuevo= new Agenda;
	nuevo->pedir(nuevo);
	
	getch();
	return 0;
	
	getch();
	system("cls");
	Beep(500, 100);
	return 0;
	Beep(500, 100);
	getch();
	system("pause");
	
}





void escribir(){
    gotoxy(45,11);cout<<"Instituto Politecnico Nacional";
    gotoxy(27,12);cout<<"Escuela Superior De Ingeneria Mecanica y Electrica UNIDAD CULHUACAN";
    gotoxy(44,13);cout<<"Monroy Cortines Jacobo Emiliano";
    gotoxy(43,14);cout<<"Programacion Orientada en Objetos";
    gotoxy(49,15);cout<<" Practica Numero 8";
    gotoxy(51,16);cout<<"  Grupo 2CV35";
    gotoxy(45,17);cout<<"Profesor Osornio Soto Roberto \n\n";  
}



void gotoxy(int x, int y){
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}