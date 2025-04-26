#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y); 
void escribir();
int agenda();

struct datos{
char nombre[3][20];
char telefono[3][15];
int edad[3];
};

int main(){

system("color 03");
	escribir();
	agenda();
		
system("PAUSE");
getch();
return(0);
}


int agenda(){
	struct datos a, *n;
	
	//clrscr(); no sirve para el programa, lo puse porque esta en la practica
	cout<<"Programa para guardar Nombre, Edad y telefono de 3 Personas:";
	n=&a;
	
	for (int i=0; i<3; i++){
		cout<<"\nIngresar Nombre:";
		cin>>n->nombre[i];
	cout<<"Ingresar Edad:";
		cin>>n->edad[i];
	cout<<"Ingresar Telefono:";
		cin>>n->telefono[i];	
	}
		
	//clrscr(); no sirve para el programa, lo puse porque esta en la practica
		cout<<"Nombres:	 Edades:	Telefonos:	\n";
		for (int i=0; i<3; i++){
			cout<<setw(15)<<n->nombre[i];
			cout<<setw(10)<<n->edad[i];
			cout<<setw(20)<<n->telefono[i]<<"\n";			
		}

	return(0);
	getch();
}



void escribir(){
    gotoxy(45,11);cout<<"Instituto Politecnico Nacional";
    gotoxy(27,12);cout<<"Escuela Superior De Ingeneria Mecanica y Electrica UNIDAD CULHUACAN";
    gotoxy(44,13);cout<<"Monroy Cortines Jacobo Emiliano";
    gotoxy(43,14);cout<<"Programacion Orientada en Objetos";
    gotoxy(49,15);cout<<" Practica Numero 3";
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
