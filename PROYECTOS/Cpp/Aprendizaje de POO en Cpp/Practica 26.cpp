#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<iomanip>
#include<windows.h>
#include<conio.h>
#include<string.h>

using namespace std;

class A
{
    public:
    void unMetodoX(){cout<<"Soy de la clase A"<<endl;}
};

class B: public A  
{
public:
    void unMetodoX(){cout<<"Soy de la clase B"<<endl;}
};

class C: public A
{
	public:
    void unMetodoX(){cout<<"Soy de la clase C"<<endl;}
};

class D: public B, public C
{
	public:
    void unMetodoX(){cout<<"Soy de la clase D"<<endl;}
};

void gotoxy(int x, int y); 
void escribir();


int main()
{
	system("COLOR 03");
	escribir();
	getch();
	system("cls");
	Beep(500, 100);
	
	A obj1;
    obj1.unMetodoX();
	B obj2;
    obj2.unMetodoX();
	C obj3;
    obj3.unMetodoX();
    D obj4;
    obj4.unMetodoX();
    return 0;
    
    getch();
	system("cls");
	Beep(500, 100);
	return 0;
	Beep(500, 100);
	getch();
	system("pause");
};

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
