#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<iomanip>
#include <windows.h>

using namespace std;

class Operaciones{
private:
	int a;
	int b;
	int c;
public:
	void multiplicacion();
	void suma();
	
		
};

void Operaciones::multiplicacion(){
	cout<<" Operacion Multiplicacion de 2 enteros \n";
	cout<<" dame el valor de a: "; cin>>a;
	cout<<" dame el valor de b: "; cin>>b;
	cout<<" dame el valor de c: "; cin>>c;
	cout<<"la multiplicacion es: "<<(a*b*c)<<endl;
}


void Operaciones::suma(){
	cout<<" Operacion suma de 2 enteros \n";
	cout<<" dame el valor de a: "; cin>>a;
	cout<<" dame el valor de b: "; cin>>b;
	cout<<"la suma es: "<<(a+b)<<endl;
}


void gotoxy(int x, int y); 
void escribir();


int main(){
Operaciones s1;

	system("COLOR 03");
	escribir();
	getch();
	system("cls");
	Beep(500, 100);

s1.multiplicacion();
	getch();
	system("cls");
	Beep(500, 100);
s1.suma();
	getch();
system("PAUSE");	
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
